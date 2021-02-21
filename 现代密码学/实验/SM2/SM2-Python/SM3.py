"""
SM2
Constantine3 fork Internet
SM3.py
核心函数实现
"""


class MySM3:
    IV = "7380166f 4914b2b9 172442d7 da8a0600 a96f30bc 163138aa e38dee4d b0fb0e4e"
    a = []
    T_j = []

    def __init__(self):
        self.IV = int(self.IV.replace(" ", ""), 16)
        for i in range(0, 8):
            self.a.append(0)
            self.a[i] = (self.IV >> ((7 - i) * 32)) & 0xFFFFFFFF
        self.IV = self.a

        for i in range(0, 16):
            self.T_j.append(0)
            self.T_j[i] = 0x79cc4519
        for i in range(16, 64):
            self.T_j.append(0)
            self.T_j[i] = 0x7a879d8a

    @staticmethod
    def rotate_left(a, k):
        k = k % 32
        return ((a << k) & 0xFFFFFFFF) | ((a & 0xFFFFFFFF) >> (32 - k))

    @staticmethod
    def FF_j(X, Y, Z, j):
        ret: int = -1
        if 0 <= j < 16:
            ret = X ^ Y ^ Z
        elif 16 <= j < 64:
            ret = (X & Y) | (X & Z) | (Y & Z)
        return ret

    @staticmethod
    def GG_j(X, Y, Z, j):
        ret: int = -1
        if 0 <= j < 16:
            ret = X ^ Y ^ Z
        elif 16 <= j < 64:
            ret = (X & Y) | ((~ X) & Z)
        return ret

    @staticmethod
    def P_0(X):
        return X ^ (MySM3.rotate_left(X, 9)) ^ (MySM3.rotate_left(X, 17))

    @staticmethod
    def P_1(X):
        return X ^ (MySM3.rotate_left(X, 15)) ^ (MySM3.rotate_left(X, 23))

    def CF(self, V_i, B_i):
        W = []
        for i in range(16):
            weight = 0x1000000
            data = 0
            for k in range(i * 4, (i + 1) * 4):
                data = data + B_i[k] * weight
                weight = int(weight / 0x100)
            W.append(data)

        for j in range(16, 68):
            W.append(0)
            W[j] = self.P_1(W[j - 16] ^ W[j - 9] ^ (self.rotate_left(W[j - 3], 15))) ^ (MySM3.rotate_left(W[j - 13], 7
                                                                                                          )) ^ W[j - 6]
        W_1 = []
        for j in range(0, 64):
            W_1.append(0)
            W_1[j] = W[j] ^ W[j + 4]

        A, B, C, D, E, F, G, H = V_i
        for j in range(0, 64):
            SS1 = MySM3.rotate_left(((MySM3.rotate_left(A, 12)) + E + (MySM3.rotate_left(self.T_j[j], j))) & 0xFFFFFFFF,
                                    7)
            SS2 = SS1 ^ (MySM3.rotate_left(A, 12))
            TT1 = (MySM3.FF_j(A, B, C, j) + D + SS2 + W_1[j]) & 0xFFFFFFFF
            TT2 = (MySM3.GG_j(E, F, G, j) + H + SS1 + W[j]) & 0xFFFFFFFF
            D = C
            C = MySM3.rotate_left(B, 9)
            B = A
            A = TT1
            H = G
            G = MySM3.rotate_left(F, 19)
            F = E
            E = MySM3.P_0(TT2)

            A = A & 0xFFFFFFFF
            B = B & 0xFFFFFFFF
            C = C & 0xFFFFFFFF
            D = D & 0xFFFFFFFF
            E = E & 0xFFFFFFFF
            F = F & 0xFFFFFFFF
            G = G & 0xFFFFFFFF
            H = H & 0xFFFFFFFF

        V_i_1 = [A ^ V_i[0], B ^ V_i[1], C ^ V_i[2], D ^ V_i[3], E ^ V_i[4], F ^ V_i[5], G ^ V_i[6], H ^ V_i[7]]
        return V_i_1

    def hash_msg(self, msg):
        # print(msg)
        i: int = -1
        len1 = len(msg)
        reserve1 = len1 % 64
        msg.append(0x80)
        reserve1 = reserve1 + 1
        # 56-64, add 64 byte
        range_end = 56
        if reserve1 > range_end:
            range_end = range_end + 64

        for i in range(reserve1, range_end):
            msg.append(0x00)

        bit_length = len1 * 8
        bit_length_str = [bit_length % 0x100]
        for i in range(7):
            bit_length = int(bit_length / 0x100)
            bit_length_str.append(bit_length % 0x100)
        for i in range(8):
            msg.append(bit_length_str[7 - i])

        group_count = round(len(msg) / 64)

        B = []
        for i in range(0, group_count):
            B.append(msg[i * 64:(i + 1) * 64])

        V = [self.IV]
        for i in range(0, group_count):
            V.append(self.CF(V[i], B[i]))

        y_list = V[i + 1]
        result = ""
        for i in y_list:
            result = '%s%08x' % (result, i)
        return result

    def hash_sm3(self, msg, hex_flag=True):
        if hex_flag:
            msg_byte = MySM3.hex2byte(msg)
        else:
            msg_byte = MySM3.str2byte(msg)
        return self.hash_msg(msg_byte)

    @staticmethod
    def out_hex(hex_str_list: list):
        for hex_str in hex_str_list:
            print("%08x" % hex_str)
        print("\n")

    @staticmethod
    # 字符串转换成byte数组
    def str2byte(msg):
        ml = len(msg)
        msg_byte = []
        msg_bytearray = msg.encode('utf-8')
        for i in range(ml):
            msg_byte.append(msg_bytearray[i])
        return msg_byte

    @staticmethod
    # byte数组转字符串
    def byte2str(msg):
        ml = len(msg)
        str1 = b""
        for i in range(ml):
            str1 += b'%c' % msg[i]
        return str1.decode('utf-8')

    @staticmethod
    # 16进制字符串转换成byte数组
    def hex2byte(msg):
        ml = len(msg)
        if ml % 2 != 0:
            msg = '0' + msg
        ml = int(len(msg) / 2)
        msg_byte = []
        for i in range(ml):
            msg_byte.append(int(msg[i * 2:i * 2 + 2], 16))
        return msg_byte

    @staticmethod
    # byte数组转换成16进制字符串
    def byte2hex(msg):
        ml = len(msg)
        str_hex = ""
        for i in range(ml):
            str_hex = str_hex + ('%02x' % msg[i])
        return str_hex
