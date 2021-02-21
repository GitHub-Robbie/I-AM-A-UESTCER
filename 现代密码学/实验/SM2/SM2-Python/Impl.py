"""
SM2
Constantine3
Impl.py
核心函数实现
"""
import binascii
from math import ceil
import random

from Const import Const
from ECPoint import ECPoint
from SM3 import MySM3


class Impl:
    C: str
    p_dec: int
    a_dec: int
    sm3: MySM3
    v: int

    def __init__(self):
        self.p_dec = int(Const.p_hex, 16)
        self.a_dec = int(Const.a_hex, 16)
        self.v = 256
        self.sm3 = MySM3()
        print("明文:", Const.Plaintext.M)

    def encrypt(self):

        # 产生随机数k, k>=1 and k<=n-1
        # TODO 用于调试
        n_dec: int = int(Const.G.n_hex, 16)
        k_dec: int = random.randint(1, n_dec)
        k_hex: str = hex(k_dec)
        # k_hex: str = '4C62EEFD6ECFC2B95B92FD6C3D9575148AFA17425546D49018E5388D49DD7B4F'

        # 计算椭圆曲线点C_1=[k]G=(x_1, y_1)
        k_dec: int = int(k_hex, 16)
        C_1: ECPoint = self.ec_finite_field_multiply(k_dec, Const.G)
        C_1_hex: str = Const.PC + C_1.x_hex + C_1.y_hex

        # 计算椭圆曲线点[k]P_B=(x_2, y_2)
        S: ECPoint = self.ec_finite_field_multiply(k_dec, Const.P_B)
        # TODO 验证S是否是无穷远点

        # 计算t=KDF(x_2||y_2, klen)
        t_hex: str = self.KDF(S.x_hex + S.y_hex, Const.Plaintext.klen)
        # TODO 验证t是否为0

        # 计算C_2=M^t
        t_dec: int = int(t_hex, 16)
        M_dec: int = int(Const.Plaintext.M_hex, 16)
        C_2_dec: int = M_dec ^ t_dec
        C_2_hex: str = hex(C_2_dec)[2:]

        # 计算C_3=Hash(x_2||M||y_2)
        src: str = S.x_hex + Const.Plaintext.M_hex + S.y_hex
        C_3_hex: str = self.sm3.hash_sm3(src, True)

        # 输出密文C
        self.C = C_1_hex + C_2_hex + C_3_hex
        print("密文:", self.C)

    def decrypt(self):
        C: str = self.C
        d_B_dec = int(Const.d_B_hex, 16)

        # 验证C_1
        C_1_hex: str = C[0:130]
        C_1: ECPoint = ECPoint(C_1_hex[2:66], C_1_hex[66:130], "")
        # TODO 验证C_1是否在椭圆曲线上

        # 计算S=[d_B]C_1
        S: ECPoint = ECPoint(Const.ENDLESS, Const.ENDLESS, "")
        S = self.ec_finite_field_multiply(d_B_dec, C_1)
        # TODO 验证S是否是无穷远点

        # 计算t=KDF(x_2||y_2, klen)
        t_hex: str = self.KDF(S.x_hex + S.y_hex, Const.Plaintext.klen)
        # TODO 验证t是否为0

        # 计算M_=C_2^t
        t_dec: int = int(t_hex, 16)
        C_2_hex: str = C[130:168]
        C_2_dec: int = int(C_2_hex, 16)
        M__dec: int = C_2_dec ^ t_dec
        M__hex = hex(M__dec)[2:]

        # 验证u=Hash(x_2||M_||y_2)
        src: str = S.x_hex + M__hex + S.y_hex
        u: str = self.sm3.hash_sm3(src, True)
        # TODO 验证u是否等于C_3

        # 打印明文M_
        print("恢复:", binascii.a2b_hex(M__hex))

    # 密钥派生函数
    def KDF(self, Z: str, klen: int):
        v: int = self.v
        ct: int = 0x00000001
        count: int = ceil(klen/v)
        H_a: list = [None] * (count + 1)
        K: str = ""

        for i in range(1, count + 1):
            ct_hex = hex(ct)[2:]
            while len(ct_hex) < 8:
                ct_hex = '0' + ct_hex
            src_hex: str = Z + ct_hex
            src_list = MySM3.hex2byte(src_hex)
            H_a[i] = self.sm3.hash_msg(src_list)
            ct += 1
        if klen % v == 0:
            end_element = H_a[count]
        else:
            end_element = H_a[count][0: (klen-(v*(klen//v)))//4]

        for i in range(1, len(H_a)-1):
            K += H_a[i]
        K += end_element
        return K

    # 改进欧几里得算法求线性方程的x与y
    @staticmethod
    def get_xy(a: int, b: int):
        if b == 0:
            return 1, 0
        else:
            k: int = a // b
            remainder: int = a % b
            x_1, y_1 = Impl.get_xy(b, remainder)
            x, y = y_1, x_1 - k * y_1
        return x, y

    # 欧几里得算法求最大公约数
    @staticmethod
    def get_gcd(a: int, b: int):
        remainder: int = a % b
        while remainder != 0:
            a = b
            b = remainder
            remainder = a % b
        return b

    # 获取逆元
    @staticmethod
    def get_inverse_element(a: int, b: int):
        m: int = abs(b) if b < 0 else b
        gcd: int = Impl.get_gcd(a, b)

        # 判断gcd是否为1，若不是则没有逆元
        if gcd == 1:
            x, y = Impl.get_xy(a, b)
            x_0: int = x % m
            return x_0
        else:
            print("[Error]get_inverse_element")
            return -1

    # 判定两个点是否相等
    @staticmethod
    def ec_finite_field_equal(P: ECPoint, Q: ECPoint):
        if P.x_hex == Q.x_hex and P.y_hex == Q.y_hex:
            return True
        else:
            return False

    # 椭圆曲线两点相加
    def ec_finite_field_add(self, P: ECPoint, Q: ECPoint):
        if P.x_hex == Const.ENDLESS and P.y_hex == Const.ENDLESS:
            return Q
        elif Q.x_hex == Const.ENDLESS and Q.y_hex == Const.ENDLESS:
            return P
        p_dec: int = self.p_dec
        a_dec: int = self.a_dec
        P_x_dec: int = int(P.x_hex, 16)
        P_y_dec: int = int(P.y_hex, 16)
        Q_x_dec: int = int(Q.x_hex, 16)
        Q_y_dec: int = int(Q.y_hex, 16)

        if Impl.ec_finite_field_equal(P, Q):
            numerator: int = 3 * pow(P_x_dec, 2) + a_dec
            denominator: int = 2 * P_y_dec
            if numerator % denominator != 0:
                val: int = Impl.get_inverse_element(denominator, p_dec)
                m: int = (numerator * val) % p_dec
            else:
                m: int = (numerator // denominator) % p_dec
        else:
            numerator: int = Q_y_dec - P_y_dec
            denominator: int = Q_x_dec - P_x_dec
            if denominator == 0:
                point = ECPoint(Const.ENDLESS, Const.ENDLESS, "")
                return point
            if numerator % denominator != 0:
                val: int = Impl.get_inverse_element(denominator, p_dec)
                m: int = (numerator * val) % p_dec
            else:
                m: int = (numerator // denominator) % p_dec
        R_x_dec: int = (pow(m, 2) - P_x_dec - Q_x_dec) % p_dec
        R_y_dec: int = (m * (P_x_dec - R_x_dec) - P_y_dec) % p_dec
        R_x_hex: str = hex(R_x_dec)[2:]
        R_y_hex: str = hex(R_y_dec)[2:]
        point = ECPoint(R_x_hex, R_y_hex, "")
        return point

    # 椭圆曲线两点相乘
    def ec_finite_field_multiply(self, k: int, G: ECPoint):
        result_point: ECPoint = ECPoint(Const.ENDLESS, Const.ENDLESS, "")
        addend_point: ECPoint = G

        for bit in Impl.bits(k):
            if bit == 1:
                result_point = self.ec_finite_field_add(result_point, addend_point)
            addend_point = self.ec_finite_field_add(addend_point, addend_point)
        return result_point

    @staticmethod
    def bits(n: int):
        while n:
            yield n & 1
            n >>= 1
