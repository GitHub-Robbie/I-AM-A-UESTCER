import shutil,os

f = open("../demo/index", 'r', encoding='gbk')
dic = []
for line in f.readlines():
    line = line.strip('\n')  # 去掉换行符\n
    b = line.split(' ')  # 将每一行以空格为分隔符转换成列表
    dic.append(b)

x = dic[0][0]
# dic = dict(dic)
# print(dic)

spam_num = 1000
norm_num = 000
spam_count = 0
norm_count = 0

for i in range(len(dic)):
    if dic[i][0]=='spam':
        shutil.copy(dic[i][1], "../demo/spam/" + str(spam_num))
        print("spam: " + str(spam_num))
        spam_num = spam_num + 1
        spam_count = spam_count + 1
    else:
        shutil.copy(dic[i][1], "../demo/norm/" + str(norm_num))
        print("norm: " + str(norm_num))
        norm_num = norm_num + 1
        norm_count = norm_count + 1

print("spam_count: " + str(spam_count))
print("norm_count: " + str(norm_count))