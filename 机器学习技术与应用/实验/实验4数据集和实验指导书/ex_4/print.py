import cv2

def pre_treat(img):
    height_ = 8

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)    # 颜色空间转换函数R，第二个参数将BG格式转换为灰度图
    gray = cv2.resize(gray, (28,28) )  # 尺寸缩放，参数分别为(源图片，(尺寸))，指定高度按比例缩放
    cv2.imwrite("1_gray.png", gray)
    gray = cv2.equalizeHist(gray)   # 直方图均值化，使得明暗更加平衡
    _, binary = cv2.threshold(gray, 40, 255, cv2.THRESH_BINARY) # 图像阈值处理函数，将灰度图片转换为黑白图片

     # 反转：文字置为白色，背景置为黑色
    return binary

img = cv2.imread("1.png")
img_new = pre_treat(img)
cv2.imwrite("1_after.png", img_new)