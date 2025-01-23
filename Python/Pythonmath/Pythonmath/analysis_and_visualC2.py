### 第二章 数据处理与可视化
### 2.1 数值计算工具Numpy
## 2.1.1
# 程序文件Pex2_1.py
import numpy as np  # 导入模块并命名为np
# 单个列表创建一维数组
a = np.array([2, 4, 8, 20, 16, 30])
# 嵌套元组创建二维数组
b = np.array(((1, 2, 3, 4, 5), (6, 7, 8, 9, 10), 
                (10, 9 , 1, 2, 3), (4, 5, 6, 8, 9.0)))
print("一维数组：", a)
print("二维数组：\n", b)

# 程序文件Pex2_3.py
import numpy as np
a = np.linspace(0, 2, 5)        # 生成数组：[0., 0.5., 1., 1.5, 2.]
b = np.mgrid[0: 2: 5j]            # 等价于np.linspace(0, 2, 5)
x, y = np.mgrid[0: 2: 4j, 10: 20: 5j] # 生成[0,2]x[10,20]上4x5的二维数组
print("x = {}\ny={}".format(x, y))

# 程序文件Pex2_4.py
import numpy as np
a = np.random.randint(1, 11, (3, 5))    # 生成[1, 10]区间上3行5列的随机整数数组
print("维数： ", a.ndim)                 # 维数：2
print("维度： ", a.shape)               # 维度：(3, 5)
print("元素总数： ", a.size)            # 元素总数：15
print("类型： ", a.dtype)               # 类型：int32
print("每个元素字节数： ", a.itemsize)   # 字节数：4

import numpy as np
a = np.array([1, 2, 3])
print("维度为： ", a.shape)     # (3,)
b = np.array([[1, 2, 3]])      
print("维度为： ", b.shape)     # (1, 3)
c = np.array([[1], [2], [3]])
print("维度为： ", c.shape)     # (3, 1)

# 例2.7 布尔索引示例
#程序文件Pex2_7.py
from numpy import array, nan, isnan
a = array([[1, nan, 2], [4, nan, 3]])
b = a[~isnan(a)]
print(isnan(a))
print(~isnan(a))
print(a[[1, 1, 1], [0, 1, 0]])# 不是布尔索引
print(array([1, 1, 1]))
print("b = ", b)
print("b中大于2的元素有：", b[b>2])

from numpy import array
x = array([[1, 2], [3, 4], [5, 6]])
print("前两行元素为: \n", x[[0, 1]])
print("x[0][0]和x[1][1]为: ", x[[0,1],[0, 1]])#作为索引的二维数组维度相同
print("以下两种格式是一样的：")
print(x[[0, 1]][:, [0, 1]])
print(x[0:2, 0:2])# 不算 作为索引的二维数组维度相同
print(x[[0,1,2], [0,1]]) #作为索引的二维数组维度不同呢?

import numpy as np
x = np.array([[1, 2], [3, 4], [5, 6]])
x[2, 0] = -1   # 修改第3行、第1列元素为-1
y = np.delete(x, 2, axis = 0) # 删除数组的第三行（数组，行列数，行/列）
z = np.delete(y, 0, axis = 1) # 删除数组的第一列
t1 = np.append(x, [[7, 8]], axis = 0)  # 增加一行（数组，新增内容[]，行/列）
t2 = np.append(x, [[9], [10], [11]])
print(x)
print(y)
print(z)
print(t1)
print(t2)


import numpy as np
a = np.arange(4).reshape(2, 2) # 生成数组[[0, 1], [2, 3]]
b = np.arange(4).reshape(2, 2) # 生成数组[[0, 1], [2, 3]]
print(a.reshape(4,), '\n', a)    # 输出[0, 1, 2, 3]和[[0, 1], [2, 3]]
print(b.resize(4,), '\n', b)     # 输出None和[0, 1, 2, 3]


# 程序文件 Pex2_11.py
import numpy as np
a = np.arange(4).reshape(2, 2)
b = np.arange(4).reshape(2, 2)
c = np.arange(4).reshape(2, 2)
print(a.reshape(-1), '\n', a) # 输出：[0, 1, 2, 3]和[[0, 1], [2, 3]]
print(b.ravel(), '\n', b)     # 输出：[0, 1, 2, 3]和[[0, 1], [2, 3]]
print(c.flatten(), '\n', c)   # 输出：[0, 1, 2, 3]和[[0, 1], [2, 3]]

# 程序文件Pex2_14.py
import numpy as np
a = np.arange(10, 15); b = np.arange(5, 10)
c = a + b; d = a * b
e1 = np.modf(a/b)[0]
e2 = np.modf(a/b)[1] 
print(c, '\n', d, '\n', e1, '\n', e2)

# 2.比较运算
import numpy as np
a = np.array([[3, 4, 9], [12, 15, 1]])
b = np.array([[2, 6, 3], [7, 8, 12]])
print(a > 10)
print(a[a > b])
print(a[a > 10])
print(np.where(a > 10, -1, a))   # a中大于10的地方改为-1
print(np.where(a > 10, -1, 0))   # a中大于10的元素改为-1，否则为0
print(a)

# 例2.16 ufunc函数效率示例
# 程序文件2_16.py
import numpy as np, time, math
x = [i*0.01 for i in range(1000000)]
start = time.time()                    # 1970纪元后经过的浮点秒数
for (i, t) in enumerate(x): x[i] = math.sin(t)
print("math.sin:", time.time()-start)

y = np.array([i*0.01 for i in range(1000000)])
start = time.time()
y = np.sin(y)
print("numpy.sin:", time.time()-start)



import numpy as np
a = np.arange(0, 20, 10).reshape(-1, 1)    # 变形为1列的数组，行数将自动计算
b = np.arange(0, 3)
print(a + b)




### 2.2 文件操作
# 程序文件Pex2_18.py
import numpy as np
a = np.arange(0, 3, 0.5).reshape(2, 3) # 生成2x3的数组
np.savetxt("Pdata2_18_1.txt", a)
b = np.loadtxt("Pdata2_18_1.txt")      # 返回浮点型数组
print("b = ", b)

np.savetxt("Pdata2_18_2.txt", a, fmt = "%d", delimiter = ",")  # 保存为整型数据，用逗号分隔
c = np.loadtxt("Pdata2_18_2.txt", delimiter = ",")             # 读入时也要指定逗号分隔
print("c = ", c)


# 例2.19 文本文件Pdata2_19.txt中存放如下格式的数据，
# 把其中的数据读入到数组a，并提取数组a前2行、前2列到第4列的元素，构造一个数组b
# 程序文件Pex2_19.py
import numpy as np
a = np.loadtxt("Pdata2_19.txt")
b = a[:2,1:4]
print("b = ", b)

# 例2.20 文本文件Pdata2_20.txt中存放如下格式的数据，提取其中的数值数据
# 程序文件Pex2_20.py
import numpy as np
a = np.loadtxt("Pdata2_20.txt", dtype = str, delimiter = "，")
b = a[1:, 1:].astype(float)   # 提取a矩阵的数值行和数值列，并转换类型
print("b = ", b)

import numpy as np
a = np.genfromtxt("Pdata2_21.txt", max_rows = 6, usecols = range(8))# 读前6行前8列数据
b = np.genfromtxt("Pdata2_21.txt", dtype = str, max_rows = 6, usecols = 8) # 读第九列数值数据
b = [float(v.rstrip('kg')) for (i, v) in enumerate(b)]   # 删除kg并切换为浮点型数据
c = np.genfromtxt("Pdata2_21.txt", skip_header = 6)      # 读最后一行数据
print(a, '\n', b, '\n', c)


import numpy as np
a = np.arange(6).reshape(2, 3)
a.tofile('Pdata2_22.bin')
b = np.fromfile('Pdata2_22.bin', dtype = int).reshape(2, 3)
print(b)

import numpy as np
a = np.arange(6).reshape(2, 3)
np.save("Pdata2_23_1.npy", a)
b = np.load("Pdata2_23_1.npy")

c = np.arange(6, 12).reshape(2, 3)
d = np.sin(c)
np.savez("Pdata2_23_2", c, d)
e = np.load("Pdata2_23_2.npz")
f1 = e["arr_0"]
f2 = e["arr_1"]

# print(b, '\n', e, '\n', f1, '\n', f2)
print(e)
### 2.3 数据处理工具Pandas
import pandas as pd
import numpy as np
s1 = pd.Series(np.array([10.5, 20.5, 30.5])) # 由数组构造序列
s2 = pd.Series({"北京": 10.5, "上海": 20.5, "广东": 30.5})  # 由字典构造序列
s3 = pd.Series([10.5, 20.5, 30.5], index = ['b', 'c', 'd'])
print(s1);
print("--------------")
print(s2);
print("--------------")
print(s3)

import pandas as pd
import numpy as np
s = pd.Series([10.5, 20.5, 98], index = ['a', 'b', 'c'])
a = s['b']     # 取出序列第二个元素，输出20.5
b1 = np.mean(s)   # 输出：43.0
b2 = s.mean()  # 通过数列（序列吧）方法求平均值，输出：43.0
print(a, '\n', b1, '\n', b2)

import pandas as pd
import numpy as np
a = np.arange(1, 7).reshape(3, 2)
df1 = pd.DataFrame(a)
df2 = pd.DataFrame(a, index = ['a', 'b', 'c'], columns = ['x1', 'x2'])
df3 = pd.DataFrame({'x1': a[:,0], 'x2': a[:,1]})
print(df1)
print("---------")
print(df2)
print("---------")
print(df3)

import pandas as pd
a = pd.read_csv("Pdata2_32.txt", sep = ',', parse_dates = {'birthday': [0, 1, 2]},
skiprows = 2, skipfooter = 2, comment = '#', thousands = '&', engine = 'python')
print(a)

# 程序文件Pex2_34.py
import pandas as pd
import numpy as np
a = pd.read_excel("Pdata2_33.xlsx", usecols = range(1, 4))
b = a.values
c = a.describe()
print(c)
### 2.4 Matplotlib可视化
### scipy.stats模块简介
