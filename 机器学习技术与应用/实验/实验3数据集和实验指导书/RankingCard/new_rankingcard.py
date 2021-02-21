#导库
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression as LR

#获取数据
data=pd.read_csv(r'rankingcard.csv',index_col=0)

#观察数据类型
data.head()

#观察数据结构
data.shape
data.info()

#去除重复值
data.drop_duplicates(inplace=True)
data.info()

#恢复索引
data.index=range(data.shape[0])
data.info()

#探索缺失值
data.info()
data.isnull().sum()/data.shape[0]  #缺失值占比
#data.isnull().mean()

#家属人数缺失值比较少，直接用均值填充
data['NumberOfDependents'].fillna(int(data['NumberOfDependents'].mean()),inplace=True)


# 随机森林填补缺失值包装成函数
def fill_missing_rf(X, y, to_fill):
    # X是要填补的特征矩阵，y是没有缺失值的标签，to_fill是要填补列的名称

    # 构建新特征矩阵和新标签
    df = X.copy()
    fill = df.loc[:, to_fill]
    df = pd.concat([df.loc[:, df.columns != to_fill], pd.DataFrame(y)], axis=1)

    # 找出训练集和测试集
    Ytrain = fill[fill.notnull()]
    Ytest = fill[fill.isnull()]
    Xtrain = df.iloc[Ytrain.index, :]
    Xtest = df.iloc[Ytest.index, :]

    # 用随机森林回归来填补缺失值
    from sklearn.ensemble import RandomForestRegressor as rfr
    rfr = rfr(n_estimators=100)
    rfr = rfr.fit(Xtrain, Ytrain)
    Ypredict = rfr.predict(Xtest)

    return Ypredict

X=data.iloc[:,1:]
y=data['SeriousDlqin2yrs']
X.shape

y_pred=fill_missing_rf(X,y,'MonthlyIncome')
#确认结果合理后，就可以将缺失数据覆盖
data.loc[data.loc[:,'MonthlyIncome'].isnull(),'MonthlyIncome']=y_pred

#描述性统计
data.describe([0.01,0.1,0.25,0.5,.75,.9,.99]).T

#年龄的最小值为0，不符合业务需求。年龄为0的只有一条数据，直接删除
(data['age']==0).sum()
data=data[data['age']!=0]

#有三个过去两年内预期次数的指标，最大值为98，不太合理。
#有255个样本是这种情况，而且标签并不都是1，异常样本，直接删除。
data[data.loc[:,'NumberOfTimes90DaysLate'] > 90].count()
data[data.loc[:,'NumberOfTimes90DaysLate'] > 90]['SeriousDlqin2yrs'].value_counts()

data=data[data.loc[:,'NumberOfTimes90DaysLate'] < 90]
#充值索引
data.index=range(data.shape[0])
data.info()

#探索标签的分布
X=data.iloc[:,1:]
y=data.iloc[:,0]

y.value_counts()

n_sample=X.shape[0]

n_1_sample=y.value_counts()[1]
n_0_sample=y.value_counts()[0]

print('样本个数：{}; 1占{:.2%}; 0占{:.2%}'.format(n_sample,n_1_sample/n_sample,n_0_sample/n_sample))
#样本严重不均衡，金融行业违约率本身就比较低。

#上采样法平衡样本
import imblearn
from imblearn.over_sampling import SMOTE

sm=SMOTE(random_state=42)  #实例化
X,y=sm.fit_sample(X,y)

n_sample_=X.shape[0]

pd.Series(y).value_counts()

n_1_sample=pd.Series(y).value_counts()[1]
n_0_sample=pd.Series(y).value_counts()[0]

print('样本个数：{}; 1占{:.2%}; 0占{:.2%}'.format(n_sample_,n_1_sample/n_sample_,n_0_sample/n_sample_))

#分训练集和测试集
from sklearn.model_selection import train_test_split
X=pd.DataFrame(X)
y=pd.DataFrame(y)

X_train,X_vali,Y_train,Y_vali=train_test_split(X,y,test_size=0.3,random_state=420)
model_data=pd.concat([Y_train,X_train],axis=1)  #合并，利于后续分箱

model_data.index=range(model_data.shape[0])
model_data.columns=data.columns

vali_data=pd.concat([Y_vali,X_vali],axis=1)
vali_data.index=range(vali_data.shape[0])
vali_data.columns=data.columns

model_data.to_csv(r'model_data.csv')
vali_data.to_csv(r'vali_data.csv')

# #以age为例，按照等频对需要分箱的列进行分箱
# model_data['qcut'],updown=pd.qcut(model_data['age'],retbins=True,q=20)
#
# #添加新列qcut，即每个样本对应的箱子
# model_data['qcut']
#
# #所有箱子的上限和下限
# updown
#
# #统计每个分箱中0和1的数量
# coount_y0=model_data[model_data['SeriousDlqin2yrs']==0].groupby(by='qcut').count()['SeriousDlqin2yrs']
# coount_y1=model_data[model_data['SeriousDlqin2yrs']==1].groupby(by='qcut').count()['SeriousDlqin2yrs']
#
# #num_bins值分别为每个区间的上界，下界，0出现的次数，1出现的次数
# num_bins=[*zip(updown,updown[1:],coount_y0,coount_y1)]
#
# #zip会按照最短列来进行结合
# num_bins
#
# # 确保每个箱中都有0和1
# for i in range(20):
#     # 如果第一个组没有包含正样本或负样本，向后合并
#     if 0 in num_bins[0][2:]:
#         num_bins[0:2] = [
#             (num_bins[0][0], num_bins[1][1], num_bins[0][2] + num_bins[1][2], num_bins[0][3] + num_bins[1][3])]
#         continue
#     # 已经确认第一组中肯定包含两种样本了，如果其他组没有包含两种样本，就向前合并
#     for i in range(len(num_bins)):
#         if 0 in num_bins[i][2:]:
#             num_bins[i - 1:i + 1] = [(num_bins[i - 1][0], num_bins[i][1], num_bins[i - 1][2] + num_bins[i][2],
#                                       num_bins[i - 1][3] + num_bins[i][3])]
#             break  # 只有发生合并的时候，打破循环，重新开始
#
#     else:
#         break  # 如果对第一组和对后面所有组的判断中，都没有进入if去合并，则提前结束所有的循环
#
#
# # 定义WOE和IV函数
# # bad rate是一个箱中，坏样本所占的比例
# # bad%是一个箱中的坏样本占整个特征中的坏样本的比例
# def get_woe(num_bins):
#     # 通过num_bins数据计算woe
#     columns = ['min', 'max', 'count_0', 'count_1']
#     df = pd.DataFrame(num_bins, columns=columns)
#
#     df['total'] = df.count_0 + df.count_1
#     df['percentage'] = df.total / df.total.sum()
#     df['bad_rate'] = df.count_1 / df.total
#     df['good%'] = df.count_0 / df.count_0.sum()
#     df['bad%'] = df.count_1 / df.count_1.sum()
#     df['woe'] = np.log(df['good%'] / df['bad%'])
#
#     return df
#
#
# # 计算IV值
# def get_iv(df):
#     rate = df['good%'] - df['bad%']
#     iv = np.sum(rate * df.woe)
#     return iv
#
#
# num_bins_ = num_bins.copy()
#
import matplotlib.pyplot as plt
import scipy
#
# IV = []
# axisx = []
#
# while len(num_bins_) > 2:
#     pvs = []
#     # 获取num_bins_两两之间的卡方检验的置信度（或卡方值）
#     for i in range(len(num_bins_) - 1):
#         x1 = num_bins_[i][2:]
#         x2 = num_bins_[i + 1][2:]
#         # 0返回chi2值，1返回p值
#         pv = scipy.stats.chi2_contingency([x1, x2])[1]
#         pvs.append(pv)
#     # 通过p值进行处理，合并p值最大的两组
#     i = pvs.index(max(pvs))
#     num_bins_[i:i + 2] = [(num_bins_[i][0], num_bins_[i + 1][1], num_bins_[i][2] + num_bins_[i + 1][2],
#                            num_bins_[i][3] + num_bins_[i + 1][3])]
#
#     bins_df = get_woe(num_bins_)
#     axisx.append(len(num_bins_))
#     IV.append(get_iv(bins_df))
#
# plt.figure()
# plt.plot(axisx, IV)
# plt.xticks(axisx)
# plt.xlabel('number of box')
# plt.ylabel('IV')
# plt.show()
#
#
# def get_bin(num_bins_, n):
#     while len(num_bins_) > n:
#         pvs = []
#         for i in range(len(num_bins_) - 1):
#             x1 = num_bins_[i][2:]
#             x2 = num_bins_[i + 1][2:]
#
#             pv = scipy.stats.chi2_contingency([x1, x2])[1]
#             pvs.append(pv)
#
#         i = pvs.index(max(pvs))
#         num_bins_[i:i + 2] = [(num_bins_[i][0], num_bins_[i + 1][1], num_bins_[i][2] + num_bins_[i + 1][2],
#                                num_bins_[i][3] + num_bins_[i + 1][3])]
#     return num_bins_
#
#
# afterbins = get_bin(num_bins, 4)
# afterbins
#
# bins_df = get_woe(num_bins)
# bins_df
#

def graphforbestbin(DF, X, Y, n=5, q=20, graph=True):
    # DF:需要输入的数据
    # X:需要分箱的列名
    # Y:分箱数据对应的标签Y列名
    # n:保留分箱个数
    # q:初始分箱的个数
    # graph:是否要画出IV图像
    DF = DF[[X, Y]].copy()
    DF['qcut'], bins = pd.qcut(DF[X], retbins=True, q=q, duplicates='drop')
    coount_y0 = DF.loc[DF[Y] == 0].groupby(by='qcut').count()[Y]
    coount_y1 = DF.loc[DF[Y] == 1].groupby(by='qcut').count()[Y]
    num_bins = [*zip(bins, bins[1:], coount_y0, coount_y1)]

    for i in range(q):
        if 0 in num_bins[0][2:]:
            num_bins[0:2] = [
                (num_bins[0][0], num_bins[1][1], num_bins[0][2] + num_bins[1][2], num_bins[0][3] + num_bins[1][3])]
            continue

        for i in range(len(num_bins)):
            if 0 in num_bins[i][2:]:
                num_bins[i - 1:i + 1] = [(num_bins[i - 1][0], num_bins[i][1], num_bins[i - 1][2] + num_bins[i][2],
                                          num_bins[i - 1][3] + num_bins[i][3])]
                break
        else:
            break

    def get_woe(num_bins):
        columns = ['min', 'max', 'count_0', 'count_1']
        df = pd.DataFrame(num_bins, columns=columns)
        df['total'] = df.count_0 + df.count_1
        df['percentage'] = df.total / df.total.sum()
        df['bad_rate'] = df.count_1 / df.total
        df['good%'] = df.count_0 / df.count_0.sum()
        df['bad%'] = df.count_1 / df.count_1.sum()
        df['woe'] = np.log(df['good%'] / df['bad%'])
        return df

    def get_iv(df):
        rate = df['good%'] - df['bad%']
        iv = np.sum(rate * df.woe)
        return iv

    IV = []
    axisx = []
    while len(num_bins) > n:
        pvs = []
        for i in range(len(num_bins) - 1):
            x1 = num_bins[i][2:]
            x2 = num_bins[i + 1][2:]
            pv = scipy.stats.chi2_contingency([x1, x2])[1]
            pvs.append(pv)

        i = pvs.index(max(pvs))
        num_bins[i:i + 2] = [(num_bins[i][0], num_bins[i + 1][1], num_bins[i][2] + num_bins[i + 1][2],
                              num_bins[i][3] + num_bins[i + 1][3])]

        global bins_df
        bins_df = pd.DataFrame(get_woe(num_bins))
        axisx.append(len(num_bins))
        IV.append(get_iv(bins_df))

    if graph:
        plt.figure()
        plt.plot(axisx, IV)
        plt.xticks(axisx)
        plt.xlabel('number of box')
        plt.ylabel('IV')
        plt.show()
    return bins_df


model_data.columns

for i in model_data.columns[1:-1]:
    print(i)
    graphforbestbin(model_data,i,'SeriousDlqin2yrs',n=2,q=20)


auto_col_bins={'RevolvingUtilizationOfUnsecuredLines':6,
               'age':5,
               'DebtRatio':4,
               'MonthlyIncome':3,
               'NumberOfOpenCreditLinesAndLoans':5}

#不能使用自动分箱的变量，手动分
hand_bins={'NumberOfTime30-59DaysPastDueNotWorse':[0,1,2,13],
           'NumberOfTimes90DaysLate':[0,1,2,17],
           'NumberRealEstateLoansOrLines':[0,1,2,4,54],
           'NumberOfTime60-89DaysPastDueNotWorse':[0,1,2,8],
           'NumberOfDependents':[0,1,2,3]}
#保证区间覆盖使用np.inf替换最大值，-np.inf替换最小值
hand_bins={k:[-np.inf,*v[:-1],np.inf] for k,v in hand_bins.items()}


bins_of_col={}

for col in auto_col_bins:
    bins_df=graphforbestbin(model_data,col,'SeriousDlqin2yrs',n=auto_col_bins[col],q=20,graph=False)
    bins_list=sorted(set(bins_df['min']).union(bins_df['max']))  #两个集合的并集
    #保证区间覆盖使用np.inf替换最大值，-np.inf替换最小值
    bins_list[0],bins_list[-1]=-np.inf,np.inf
    bins_of_col[col]=bins_list

#合并手动分箱数据
bins_of_col.update(hand_bins)
bins_of_col


data=model_data.copy()

#函数pd.cut，可以根据已知的分箱间隔把数据分箱
data=data[['age','SeriousDlqin2yrs']].copy()
data['cut']=pd.cut(data['age'],[-np.inf, 45.0, 46.98277343010937, 58.65715423057309, 64.0,np.inf])
data

#将数据按分箱结果聚合，并取出其中的标签值
data.groupby('cut')['SeriousDlqin2yrs'].value_counts()

#使用unstack()来将树状结构变成表状结构
data.groupby('cut')['SeriousDlqin2yrs'].value_counts().unstack()

bins_df=data.groupby('cut')['SeriousDlqin2yrs'].value_counts().unstack()
bins_df['woe']=np.log((bins_df[0]/bins_df[0].sum())/(bins_df[1]/bins_df[1].sum()))
bins_df


#将以上过程包装成函数
def get_woe(df,col,y,bins):
    df=df[[col,y]].copy()
    df['cut']=pd.cut(df[col],bins)
    bins_df=df.groupby('cut')[y].value_counts().unstack()
    woe=bins_df['woe']=np.log((bins_df[0]/bins_df[0].sum())/(bins_df[1]/bins_df[1].sum()))
    return woe

#将所有特征的WOE存储到字典当中
woeall={}
for col in bins_of_col:
    woeall[col]=get_woe(model_data,col,'SeriousDlqin2yrs',bins_of_col[col])

woeall


#不希望覆盖掉原本的数据，创建一个新的DataFrame，索引和原始数据model_data一模一样
model_woe=pd.DataFrame(index=model_data.index)

#将原数据分箱后，按箱的结果把WOE结构用map函数映射到数据中
model_woe['age']=pd.cut(model_data['age'],bins_of_col['age']).map(woeall['age'])
model_woe

#对所有特征操作可以写成：
for col in bins_of_col:
    model_woe[col]=pd.cut(model_data[col],bins_of_col[col]).map(woeall[col])

#将标签补充到数据中
model_woe['SeriousDlqin2yrs']=model_data['SeriousDlqin2yrs']

model_woe.head()

#处理测试集
vali_woe=pd.DataFrame(index=vali_data.index)
for col in bins_of_col:
    vali_woe[col]=pd.cut(vali_data[col],bins_of_col[col]).map(woeall[col])
vali_woe['SeriousDlqin2yrs']=vali_data['SeriousDlqin2yrs']

vali_X=vali_woe.iloc[:,:-1]
vali_y=vali_woe.iloc[:,-1]


#建模
X=model_woe.iloc[:,:-1]
y=model_woe.iloc[:,-1]

from sklearn.linear_model import LogisticRegression as LR

lr=LR().fit(X,y)
lr.score(vali_X,vali_y)

#调参
c_1=np.linspace(0.01,1,20)
c_2=np.linspace(0.01,0.2,20)

score=[]
for i in c_1:
    lr=LR(solver='liblinear',C=i).fit(X,y)
    score.append(lr.score(vali_X,vali_y))
plt.figure()
plt.plot(c_1,score)
plt.show()

score=[]
for i in c_2:
    lr=LR(solver='liblinear',C=i).fit(X,y)
    score.append(lr.score(vali_X,vali_y))
plt.figure()
plt.plot(c_2,score)
plt.show()

lr.n_iter_

score=[]
for i in [1,2,3,4,5,6]:
    lr=LR(solver='liblinear',C=0.025,max_iter=i).fit(X,y)
    score.append(lr.score(vali_X,vali_y))
plt.figure()
plt.plot([1,2,3,4,5,6],score)
plt.show()


#从ROC曲线上看看效果
import scikitplot as skplt

vali_proba_df=pd.DataFrame(lr.predict_proba(vali_X))
skplt.metrics.plot_roc(vali_y,vali_proba_df,plot_micro=False,figsize=(6,6),plot_macro=False)


#计算A,B的值
B=20/np.log(2)
A=600+B*np.log(1/60)
B,A


base_score=A-B*lr.intercept_  #截距
base_score

score_age=woeall['age']*(-B*lr.coef_[0][0])  #每个特征对应的参数
score_age

file=r'ScoreData.csv'

with open(file,'w') as fdata:
    fdata.write('base_score,{}\n'.format(base_score))
for i,col in enumerate(X.columns):
    score=woeall[col]*(-B*lr.coef_[0][i])
    score.name='Score'
    score.index.name=col
    score.to_csv(file,header=True,mode='a')

B = 20 / np.log(2)
A = 600 + B * np.log(1 / 60)

B, A

# In[62]:


base_score = A - B * lr.intercept_
base_score

score_age = woeall["age"] * (-B * lr.coef_[0][0])
score_age

# In[74]:


file = "ScoreData.csv"
# score_data.to_csv(r"D:\study\Mr.huang\pingfenka\score_data")
# file = 'scoredata.csv'

# open是用来打开文件的python命令，第一个参数是文件的路径+文件名，如果你的文件是放在根目录下，则你只需要文件名就好
# 第二个参数是打开文件后的用途，"w"表示用于写入，通常使用的是"r"，表示打开来阅读
# 首先写入基准分数
# 之后使用循环，每次生成一组score_age类似的分档和分数，不断写入文件之中

with open(file, "w") as fdata:
    fdata.write("base_score,{}\n".format(base_score))

for i, col in enumerate(X.columns):
    score = woeall[col] * (-B * lr.coef_[0][i])
    score.name = "Score"
    score.index.name = col
    score.to_csv(file, header=True, mode="a")

