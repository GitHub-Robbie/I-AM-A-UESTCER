"""
SM2
Constantine3
ECPoint.py
椭圆曲线点的数据结构
"""


class ECPoint:
    x_hex: str
    y_hex: str
    n_hex: str

    def __init__(self, x_hex, y_hex, n_hex):
        self.x_hex = x_hex
        self.y_hex = y_hex
        self.n_hex = n_hex
