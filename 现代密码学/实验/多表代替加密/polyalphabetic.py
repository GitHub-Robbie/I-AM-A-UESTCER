import numpy as np
import math


# 生成随机矩阵
def random(m, n):
    x = np.random.randint(1, 5, (m, n))
    return x


# 扩展欧几里得
def ex_gcd(a, b, arr):
    if b == 0:
        arr[0] = 1
        arr[1] = 0
        return a
    g = ex_gcd(b, a % b, arr)
    t = arr[0]
    arr[0] = arr[1]
    arr[1] = t - int(a / b) * arr[1]
    return g


# 求对模n的乘法逆元
def mod_reverse(a, n):
    arr = [0, 1, ]
    gcd = ex_gcd(a, n, arr)
    if gcd == 1:
        return (arr[0] % n + n) % n
    else:
        return -1


# 求矩阵行列式
def mat_det(mat):
    x = np.linalg.det(mat)
    return round(x) % 26


# 将矩阵mod n
def mod_mat(mat, n=26):
    for i in range(mat.shape[0]):
        for j in range(mat.shape[1]):
            mat[i, j] = mat[i, j] % n
    return mat


# 求伴随矩阵
def adjoint_mat(mat):
    new = np.zeros(mat.shape, dtype=np.int64)
    for i in range(mat.shape[0]):
        for j in range(mat.shape[1]):
            new[j, i] = pow(-1, i + j) * mat_det(cofactor(mat, i, j))

    return mod_mat(new, 26)


# 求代数余子式
def cofactor(self, i, j):
    d = self.shape[0] - 1
    M = np.zeros((d, d), dtype=np.int64)
    for r in range(self.shape[0]):
        if r == i:
            continue
        for c in range(self.shape[1]):
            if c == j:
                continue
            rr = r - 1 if r > i else r
            cc = c - 1 if c > j else c
            M[rr, cc] = self[r, c] % 26
    return M


# 求逆矩阵
def mat_inv(mat):
    arr = [0, 1, ]
    new = np.zeros(mat.shape, dtype=np.int64)
    temp = adjoint_mat(mat)
    det = mat_det(mat)
    if ex_gcd(det, 26, arr) == 1:
        rev = mod_reverse(det, 26)
    new = mod_mat(temp * rev, 26)
    return new


# 将字母转化为数字
def letter_num(letter):
    return ord(letter) - 64


# 将数字转化为字母
def num_letter(num):
    if num == 0:
        return chr(90)
    else:
        return chr(num + 64)


n = int(input("请输入分组长度: "))

# 生成随机方阵A且det(A)与26互素
A = random(n, n)
arr = [0, 1, ]
while ex_gcd(mat_det(A), 26, arr) != 1:
    A = random(n, n)

# A的逆
A_inv = mat_inv(A)

# 生成随机B矩阵
B = random(n,1)

message = input("请输入明文: ")
new_message = []
for i in message:
    if i == ' ':
        continue
    new_message.append(letter_num(i));
message = new_message

print("密钥矩阵A: ")
print(A)
print("密钥矩阵B: ")
print(B)
print("inv(A): ")
print(A_inv)

# 加密
count = len(message)
split = math.ceil(len(message) / n)
C = np.zeros((n, split), dtype=np.int64)
k = 0

for i in range(split):
    for j in range(n):
        if k < count:
            C[j, i] = message[k]
            k = k + 1
        else:
            C[j, i] = 0

for i in range(split):
    C[:, i] = np.matmul(A, C[:, i]) + B.T

C = mod_mat(C, 26)

Enc = []

for i in range(split):
    for j in range(n):
        Enc.append(num_letter(C[j, i]))

Enc_message = "".join(Enc)
print("密文: " + Enc_message)

# 解密
B_ex = np.tile(B, (1, n))
C = C - B
C = mod_mat(C, 26)
for i in range(split):
    C[:, i] = np.matmul(A_inv, C[:, i])
C = mod_mat(C, 26)

Dec = []
for i in range(split):
    for j in range(n):
            Dec.append(num_letter(C[j, i]))

Dec_message = "".join(Dec)
print("解密: " + Dec_message)
