# 第四章 概率论与数理统计
## 4.1 随机变量的概率统计和数字特征
### 4.1.1 随机变量的概率计算
例4.1   X~N(3,25), (1) P(x<X<6), (2)P(-3c < X < 2c), 求c 
``` py
# 程序文件Pex4_1.py
from scipy.stats import norm
from scipy.optimize import fsolve
print("p = ", norm.cdf(6, 3, 5) - norm.cdf(2, 3, 5))
f = lambda c: norm.cdf(2*x, 3, 5) - norm.cdf(-3*c, 3, 5) - 0.6
print("c = ", fsolve(f, 0))
```

上α分位数, α分位数, 标准正态分布的上$\alpha$分位数 $z_{\alpha}$
计算常用的几个$z_{\alpha}$, 画出$z_{0.1}$示意图
``` py
# 程序文件Pex4_2.py
from scipy.stats import norm
from pylab import plot, fill_between, show, text, savefig, rc
from numpy import array, linspace, zeros
alpha = array([0.001, 0.005, 0.01, 0.025, 0.05, 0.10])
za = norm.ppf(1-alpha, 0, 1)    # 求上$\alpha$分位数
print("上alpha分位数分别为", za)
x = linspace(-4, 4, 100); y = norm.pdf(x, 0, 1)
rc('font', size = 16); rc('text', usetex = True)
plot(x, y)
x2 = linspace(za[-1], 4, 100); y2 = norm.pdf(x2)
y1 = [0] * len(x2)
fill_between(x2, y1, y2, color = 'r')   # y1, y2之间填充
plot([-4, 4], [0, 0])
text(1.9, 0.07, "\\leftarrow\\alpha\$=0.1")
# savefig("figure4_2.png", dpi = 500)
show()
```

### 4.1.2 随机变量数字特征简介
绝对收敛,数学期望,

### 4.1.3 随机变量数字特征计算及应用
例4.3 计算二项分布b(20, 0.8)的均值和方差
``` py
# 程序文件Pex4_3.py
from scipy.stats import binom
n, p = 20, 0.8
print("期望和方差分布为: ", binom.stats(n, p))
```

例4.4 计算二项分布b(20, 0.8)的均值,方差,偏差和峰度
``` py
# 程序文件Pex4_4.py
from scipy.stats import binom
n, p = 20,  0.8
mean, variance, skewness, kurtosis = binom.stats(n, p, moments='mvsk')
print("所求的数字特征: ", binom.stats(n, p, moments = 'mvsk'))
```

## 4.2 描述性统计和统计图
### 4.2.1 统计的基础知识
#### 1. 样本和总体
总体
样本容量
样本观察值
#### 2. 频数表和直方图
频率与频数
#### 3. 统计量
- 表示位置--算数平均值和中位数
- 表示变异程度--标准差,方差,极差
- 分布形状--偏度和峰度
  偏度:
  v1 > 0, 右偏态
  v1 < 0, 左偏态
  接近0, 可认为对称
  峰度:
  正态分布偏度为3, 笔3大得多说明有沉重的尾巴,含较多远离均值的数据

### 4.2.2 用Python计算统计量
#### 1. 使用NumPy计算统计量
``` py
# 程序文件Pex4_6.py
from numpy import reshape, hstack, mean, median, ptp, var, std
cov, corrcoef
import pandas as pd
df = pd.read_excel("Pdata4_6_1.xlsx", header = None)
a = df.values
h = a[:, ::2]
w = a[:, 1::2]
h = reshape(h, (-1, 1))
w = reshape(w, (-1, 1))
hw = hstack([h, w])
print([mean(h), median(h), ptp(h), var(h), std(h)])
# 计算均值,中位数,极差,方差,标准差
print("协方差为:{}\n相差系数为:{}".format(cov(hw.T)[0,1], corrcoef(hw.T)[0,1]))
```

#### 2. 使用Pandas的DataFrame计算统计量
Pandas的describe方法计算相关统计量
计算身高,体重的偏度峰度的25%,50%,90%分位数
``` py
# 程序文件Pex4_7.py
from numpy import reshape, c_
import pandas as pd
df = pd.read_excel("Pdata4_6_1.xlsx", header = None)
a = df.values; h1 = a[:, ::2]; w1 = a[:, 1::2]
h2 = reshape(h1, (-1, 1))
w2 = reshape(w1, (-1, 1))
df2 = pd.DataFrame(c_[h2, w2], columns = ["身高","体重"]) # 构造数据框
print("求得的描述统计量如下: \n", df2.describe())
print("偏度为: \n", df2.skew())
print("峰度为: \n", df2.kurt())
print("分位数为: \n", df.quantile(0.9))
```

### 4.2.3 统计图
#### 1. 频数表和直方图
``` py
# 程序文件Pex4_8.py
import numpy as np
import matplotlib.pylot as plt
a = np.loadtxt("Pdata4_6_2.txt")
h = a[:, ::2]; w = a[:, 1::2]
h = np.reshape((-1, 1)); w = reshape((-1, 1))

plt.rc('font', size = 16); plt.rc('font', family = 'SimHei')

plt.subplot(121)
plt.xlabel("身高")
plt.hist(h, 10) # 只画直方图不返回频数表

plt.subplot(122)
ps = plt.hist(2, 10)
plt.xlabel("体重")

print("体重的频数表为: ", ps)
plt.savefig("figure4_8.png", dpi = 500)
plt.show()
```

#### 2. 箱线图
样本分位数, Q1, Q2/M, Q3
箱线图:中心位置, 散布程度, 对称性
画箱线图命令boxplot, 调用格式:
``` py
boxplot(x, notch=None, sym = None,  vert = None, whis = None, 
        positions = None, widths = None)
```
例4.9(Pdata4_9.txt), 绘制男女组肺活量箱线图
``` py
# 程序文件Pex4_9.py
import numpy as np
import matplotlib.pyplot as plt

a = np.loadtxt("Pdata4_9.txt")
b = a.T # 转置成两列的数据

plt.rc('font', size = 16)
plt.rc('font', family = 'SimHei')
plt.boxplot(b, labels = ['女子', '男子'])

plt.savefig('figure4_9.png', dpi = 500)
plt.show()
```
- 疑似异常值
  IQR四分位数间距 = Q3 - Q1
  疑似异常值: 数据 < Q1-1.5IQR 或数据 > Q3+1.5IQR

例4.10(续例4.6)身高体重箱线图
``` py
import numpy as np
import matplotlib.pyplot as plt

a = np.loadtxt("Pdata4_6.txt")
h = a[:, ::2]
w = a[:, 1::2]
h = np.reshape(h, (-1, 1))
w = np.reshape(w, (-1, 1))
hw = np.hstack(h, w)        # 组合

plt.rc('font', size = 16)
plt.rc('font', family = 'SimHei')
plt.boxplot(hw, labels = ["身高", "体重"])

plt.savefig("figure4_10.png", dpi = 500)
plt.show()
```

#### 3. 经验分布函数
经验分布函数Fn(x), 分布函数F(x)
当n-> ∞ 时, Fn(x)以概率1收敛于分布函数F(x)
例4.11 体重的经验分布函数
``` py
# 程序文件4_11.py
import numpy as np
import matplotlib.pyplot as plt

a = np.loadtxt("Pdata4_6_2.txt")
w = a[:, 1::2]
w = np.reshape(-1, 1)

plt.rc('font', size = 16)
h = plt.hist(w, 20, density = True, histtype = 'step', cumulative = True)
print(h)
plt.grid()
# plt.savefig("figure4_11.png", dpi = 500)
plt.show()
```

#### 4. Q-Q图
``` py
# 程序文件Pex4_12.py
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm, probplot

a = np.loadtxt("Pdata4_6_2.txt")
h = a[:, ::2]
h = h.flatten()

mu = np.mean(h)
s = np.std(h)
print([mu, s])

sh = np.sort(h)
n = len(sh)
xi = (np.arange(1, n+1) - 1/2)/n
yi = norm.ppf(xi, mu, s)

plt.rc('font', size = 16)
plt.rc('font', family = 'SimHei')
plt.rc('axes', unicode_minus = False)   # 用来正常显示负号
plt.subplot(121)
plt.plot(yi, sh, 'o', label = 'QQ图')
plt.plot([155, 185], [155, 185], 'r-', label = '参照直线')
plt.legend()

plt.subplot(122)
res = probplot(h, plot = plt)

plt.savefig("figure4_12.png", dpi = 500)
plt.show()
```
<br>

## 4.3 参数估计和假设检验
### 4.3.1 参数估计
#### 1. 极大似然估计
``` py
import numpy as np
from scipy.stats import norm

a = np.loadtxt("Pdata4_6_2.txt")
h = a[:, ::2]
h = h.flatten()
mu = np.mean(h)
s = np.std(h)

print("样本均值和标准差: ", [mu, s])
print("极大似然估计值：", norm.fit(h))
```

#### 2. 区间估计
统计量SEM：样本均值的标准误差
对应Python函数stats.sem(x),x为样本的观测值向量

例 求μ的置信区间
``` py
# 程序文件4_14_1.py
from numpy import array, sqrt
from scipy.stats import t

a = array([506, 508, 499, 503, 504, 510, 497, 512, 514, 505, 493, 496, 506,
           502, 509, 496])
mu = a.mean()
s = a.std(ddof = 1)
print(mu, s)
alpha = 0.5
n = len(a)

val = (mu-s/sqrt(n)*t.ppf(1-alpha/2, n-1), mu+s/sqrt(n)*t.ppf(1-alpha/2, n-1))
print("置信区间： ", val)
```
直接调用库函数求
``` py
# 程序文件4_14_2.py
import numpy as np
import scipy.stats as ss
# from scipy import stats

a = np.array([506, 508, 499, 503, 504, 510, 497, 512, 514, 505, 493, 496, 506,
           502, 509, 496])
alpha = 0.95
df = len(a) - 1
ci = ss.t.interval(alpha, loc = a.mean(), scale = ss.sem(a))

print("置信区间为： ", ci)
```
<br>

### 4.3.2 参数假设检验
#### 1. 单个总体均值的假设检验
1) 正态总体标准差σ已知的Z检验法
   statsmodels库中做总体均值检验的函数为statsmodels.stats.weightstats.ztest,
   调用格式:
   ``` py
   tstat, pvalue = statsmodels.stats.weightstats.ztest(x1, x2=None, value=0,
   alternative = 'two-sided', usevar = 'pooled', ddof = 1.0)
   ```
   ztest函数的统计量是t,z=t*s/σ
   例4.15 检验包装机是否正常,σ=0.015,μ未知(正常情况为0.5)
   ``` py
   # 程序文件4_15.py
   import numpy as np
   frpm statsmodels.stats.weightstats import ztest
   sigma = 0.015
   a = np.array([0.497, 0.0506, 0.518, 0.524, 0.498, 0.511, 0.520, 0.515, 0.512])
   tstat1, pvalue = ztest(a, value = 0.5)   # 计算T统计量的观测值和p值
   print('t值为: ', round(stats1, 4))
   print('z值为: ', round(stats2, 4))
   print('p值为: ', round(pvalue, 4))
   ```

2) 正态总体标准差σ未知的t检验法
   例4.16 矿砂中的5个样品的镍含量%为: 3.25, 3.27, 3.24, 3.26, 3.24
   ``` py
   import numpy as np
   from statsmodels.stats.weightstats import ztest
   a = np.array([3.25, 3.27, 3.24, 3.26, 3.24])
   tstat, pvalue = ztest(a, value = 3.25)
   print('检验统计量为: ', tstat)
   print('p值为: ', pvalue)
   ```
   例4.17 100g番茄汁维生素含量不得少于21mg/g, 抽取17个, 100g番茄汁的维生素含量如下
   16, 25, 21, 20, 23, 21, 19, 15, 13, 23, 17, 20, 29, 18, 22, 16, 22
   ``` py
   import numpy as np
   from statsmodels.stats.weightstats import ztest
   a = np.array([16, 25, 21, 20, 23, 21, 19, 15, 13, 23, 17, 20, 29, 18, 22, 16, 22])
   tstat, pvalue = ztest(a, value = 21, alternative = 'smaller')
   print('检验统计量为: ', tstat)
   print('p值为', pvalue)
   ``` 

#### 2. 两个总体均值的假设检验
``` py
import numpy as np
from statsmodels.stats.weightstats import ttest_ind
a = np.array([0.225, 0.262, 0.217, 0.240, 0.230, 0.229, 0.235, 0.217])
b = np.array([0.209, 0.205, 0.196, 0.210, 0.202, 0.207, 0.224, 0.223, 
              0.220, 0.201])
tstat, pvalue, df = ttest_ind(a, b, value = 0)
print('检验统计量：', tstat)
print('p值为：', pvalue)
print('自由度为：'， df)
```

### 4.3.3 非参数假设检验
#### 1. 分布拟合检验
卡方检验法
``` py
import numpy as np
import scipy.stats as ss

# 计算统计量的观察值
bins = np.array([36, 23, 29, 31, 34, 60, 25])
n = mi.sum()
p = np.ones(7)/7
cha = (mi-n*p)**2/n*p
st = cha.sum()

# 获取拒绝域临界值
bd = ss.chi2.ppf(0.95, len(bins-1))

print("统计量为: {}， 临界值为: {}".format(st, bd))
```

例 是否正态分布
``` py
# 程序文件Pex4_20.py
import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as ss

n = 50; k = 8
a = np.loadtxt("Pdata4_20.txt")
a = a.flatten()
mu = a.mean()
s = a.std()
print("均值为: ", mu)
print("标准差为: ", s)
print("最大值为: ", a.max())
print("最小值为: ", a.min())

bins = np.array([14.2, 14.625, 14.8375, 15.05, 15.2625, 15.475, 15.9])# why not np.linspace(14.2, 15.9, 7)
h = plt.hist(a, bins) #H?
f = h[0]; x = h[0]  # 提取各个小区间的频数，和小区间端点的取值
dp = np.diff(p)     # 计算各个小区间取值的理论概率(p?)
dp[0] = ss.norm.cdf(x[1], mu, s)
dp[-1] = 1 - ss.norm.cdf(x[-2], mu, s)
print("各个小区间的理论概率为: ", dp)
cha = (n2 - n*dp)**2/(n*dp)
st = cha.sum()    # 计算卡方统计量的观察值
bd = ss.chi2.pdf(0.95, k-5) # 计算上α分位数and软编码k-5

print("统计量为: {}, 临界值为: {}".format(st, bd))
```

#### 2.Kolmogorov-Smirnov检验
- EDF经验分布函数统计量：经验分布函数Fn(x)和所拟合的分布函数F(x)之间的距离统计量，记为T
- 目的：依据EDF统计量判断分布函数F(x)是否可以接受
- 方法：假设检验，零假设接受，对立假设拒绝
- 关键：计算 **由样本计算出的t值** 对应的 **p值** 是否可以接受（得到较小的p时拒绝原假设）

定义：Kolmogorov统计量为T=sup|Fn(x)-F(x)|    (最常用，因为上确界)

例：（续例4.6）检验学生体重是否服从正态分布
``` py
# 程序文件4_21.py
import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as ss

a = np.loadtxt("Pdata4_6_2.txt")
w = a[:, ::2]
w = w.flatten()
mu = w.mean()
s = w.std(ddof = 1)
print("均值和标准差分别为: ", (mu, s))

statVal, pVal = ss.kstest(w, 'norm', (mu, s))   # 关键句
print("统计量和p值分别为: ", [statVal, pVal])
```

重要补充：Numpy中的标准差方差默认除以n，statsmodels库中的方差默认除以n-1
<br>

## 4.4 方差分析

## 4.5 一元线性回归模型

## 4.6 常用的数据清洗方法
### 4.6.1 重复观测处理
``` py
# 程序文件4_26.py
import pandas as pd

a = pd.read_excel("Pdata4_26_1.xlsx")
print("是否存在重复观测: ", any(a.duplicated()))

a.drop_duplicates(inplace = True)       # inplace = True时，直接删除a中的重复数据
f = pd.ExcelWriter('Pdata4_26_2.xlsx')  # 创建文件对象
a.to_excel(f)                           # 把a写入新的excel文件中
f.save()
```

### 4.6.2 缺失值处理
#### 1. 数据过滤（dropna）
语法格式
``` py
dropna(axis = 0, how = 'any', thresh = 3)
```
axis = 0(删除行/记录) axis = 1(删除列/变量)
how = 'any', how = 'all'删除全有NaN的行
thresh整数类型，表删除的条件，如thresh=3，则一行至少三个非NaN值才保留
例 续例2.33
``` py
from pandas import read_excel
a = read_excel("Pdata2_33.xlsx", usecols = range(1, 4))
b1 = a.dropna()                     # 删除所有缺失值
b2 = a.dropna(axis = 1, thresh = 9) # 删除有效数据少于9的列
b3 = a.drop('用户B', axis = 1)      # 删除用户b的数据
print(b1, '\n-----------\n', b2, '\n-----------\n', b3)
```

#### 2. 数据填充（fillna）
语法格式
``` py 
fillna(value = None, method = None, axis = None, inplace = False)
```
value除了基本类型，还可以使用字典-- 实现对不同的列填充不同的值
method表示采用的填补数据的方法，默认None

例4.29 对Pdata4_29.xlsx的缺失数据填充
(未来版本更新，支持bfill()，ffill()而不是method的'ffill'和'bfill')
``` py
# 程序文件Pex4_29.py
from pandas import read_excel
a = read_excel("Pdata4_29.xlsx")
b1 = a.fillna(0)                    # 用0填补所有缺失值
b2 = a.fillna(method = 'ffill')     # 用前一行的值填补缺失值
b3 = a.fillna(method = 'bfill')     # 用后一行的值填补缺失值
b4 = a.fillna(value = {'gender': a.gender.mode()[0],  # 性别用众数替换
                      'age' = a.age.mean(),           # 年龄用均值替换
                      'income' = a.income.median()})  # 收入用中位数替换
```

#### 3. 插值法
第七章介绍插值的数学原理
插值方法可以使用：'linear', 'nearest', 'zero', 'slinear', 'quadratic', 'cubic', 
'spline', 'barycentric', 'polynomial'
例4.30 对数据型缺失数据利用插值法进行替换
``` py
from pandas import read_excel
import numpy as np
a = read_excel("Pdata4_29.xlsx")
b = a.fillna(value = {'gender': a.gender.mode()[0], # 性别用众数替换
            'age': a.age.interplate(method = 'polynomial', order = 2),  # 年龄用二次多项式插值替换
            'income': a.income.interpolate()})   # 收入用线性插值替换
```

### 4.6.3 异常值处理
``` py

```