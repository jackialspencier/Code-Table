# 数据处理与可视化
## 2.1 数值计算工具Numpy
Numpy拓展库完成大数据量的数组操作，
提供了两个基本对象：ndarray和ufunc，前者储存单一数据类型的多维数组，或者为能对数组处理的通用函数


### 2.1.1 数组的创建、属性和操作
- 函数：array函数
- 参数：一个列表/元组——一维数组，多个嵌套的列表/元组——多维数组
#### 1. 数组的创建
利用array函数创建数组
``` py
# 程序文件Pex2_1.py
import numpy as np  # 导入模块并命名为np
# 单个列表创建一维数组
a = np.array([2, 4, 8, 20, 16, 30])
# 嵌套元组创建二维数组
b = np.array(((1, 2, 3, 4, 5), (6, 7, 8, 9, 10), 
                (10, 9 , 1, 2, 3), (4, 5, 6, 8, 9.0)))
print("一维数组：", a)
print("二维数组：\n", b)
```


利用arange，empty，linspace等函数生成数组示例
（empty只分配内存，不初始化）
``` py
# 程序文件Pex2_2.py
import numpy as np
a = np.arange(4, dtype = float)     # 创建浮点型数组[0., 1., 2., 3.]
b = np.arange(0, 10, 2, dtype = int)    # 创建整型数[0, 2, 4, 6, 8]
c = np.empty((2, 3), int)               # 创建2x3的空矩阵
d = np.linspace(-1, 2, 5)               # 创建数组：[-1., -0.25, 0.5, 1.25, 2.]
e = np.random.randint(0, 3, (2, 3))     # 生成[0, 3)上的2行3列的随机整数数组
```


使用虚数单位“j”生成数组_一种生成网格点的方式
其中np.mgrid会生成两个二维数组x和y，它们分别代表网格点的x坐标和y坐标。
``` py
# 程序文件Pex2_3.py
import numpy as np
a = np.linspace(0, 2, 5)        # 生成数组：[0., 0.5., 1., 1.5, 2.]
b = np.mgrid[0: 2: 5j]            # 等价于np.linspace(0, 2, 5)
x, y = np.mgrid[0: 2: 4j, 10: 20: 5j]# 生成[0,2]x[10,20]上4x5的二维数组
print(x = {}\ny={}.format(x, y))
```


#### 2. 数组的属性
- ndim：维数
- shape：数组的尺寸
- size：元素总数
- dtype：数据类型
- itemsize：int，数组内每个元素的大小（以字节为单位）

``` py
# 程序文件Pex2_4.py
import numpy as np
a = np.random.randint(1, 11, (3, 5))    # 生成[1, 10]区间上3行5列的随机整数数组
print("维数： ", a.ndim)                 # 维数：2
print("维度： ", a.shape)               # 维度：(3, 5)
print("元素总数： ", a.size)            # 元素总数：15
print("类型： ", a.dtype)               # 类型：int64
print("每个元素字节数： ", a.itemsize)   # 字节数：8
```

例2.5 生成数学上一维向量的三种模式
``` py
import numpy as np
a = np.array([1, 2, 3])
print("维度为： ", a.shape)     # (3,)
b = np.array([[1, 2, 3]])      
print("维度为： ", b.shape)     # (1, 3)
c = np.array([[1], [2], [3]])c
print("维度为： ", c.shape)     # (3, 1)
```


#### 3.数组元素的索引
- 切片：数组名[start: end: step]
- 数据引用：a[i, j]（instead of 原始列表的a[i][j]）
1. 一般索引
   一维数组索引，可以将任意位置索引组装成列表
   二维数组索引，位置索引必须写成[rows, cols]形式，前者控制行索引，后者控制列索引
   例2.6(P42)
   #程序文件Pex2_6.py
   ``` py
   import numpy as np
   a = np.array([2, 4, 6, 8, 20, 16, 30])
   b = np.array((1, 2, 3, 4, 5), (6, 7, 8, 9, 10),
                (10, 9, 1, 2, 3), (4, 5, 6, 8, 9.0))
   print(a[[1, 3, 5]])     # 一维数组索引
   print(a[[-1, -2, -3]])  # 一维数组索引
   print(b[1, 2])
   print(b[2])
   print(b[2, :])
   print(b[:, 1])
   print(b[[2, 3], 1:4])
   print(b[1:3, 1:3])
   ```
2. 布尔索引
   例2.7 布尔索引示例
   nan实际上是一个特殊的浮点数，用于标识“非数值”数据
   nan在此表示缺失/无意义数据，isnan返回一个布尔数组（True，False）指出那些位置是nan
   ``` py
   #程序文件Pex2_7.py
   from numpy import array, nan, isnan
   a = array([[1, nan, 2], [4, nan, 3]])
   b = a[~isnan(a)]
   print("b = ", b)
   print("b中大于2的元素有：", b[b>2])
   ```

3. 花式索引
   例2.8 花式索引示例
   ``` py
   # 程序文件Pex2_8.py
   from numpy import array
   x = array([[1, 2], [3, 4], [5, 6]])
   print("前两行元素为: \n", x[[0, 1]])
   print("x[0][0]和x[1][1]为: ", x[[0,1],[0, 1]])#作为索引的二维数组维度相同
   print("以下两种格式是一样的：")
   print(x[[0, 1]][:, [0, 1]])
   print(x[0:2, 0:2])# 不算 作为索引的二维数组维度相同
   #print(x[[0,1,2], [0,1]]) #作为索引的二维数组维度不同呢?——不行
   ```


#### 4. 数组的修改
数组元素的修改、数组元素的扩大和缩小
例2.9 数组修改示例
``` py
import numpy as np
x = np.array([1, 2], [3, 4], [5, 6])
x[2, 0] = -1   # 修改第3行、第1列元素为-1
y = np.delete(x, 2, axis = 0) # 删除数组的第三行（数组，行列数，行/列）
z = np.delete(y, 0, axis = 1) # 删除数组的第一列
t1 = np.append(x, [[7, 8]], axis = 0)  # 增加一行（数组，新增内容[]，行/列）
t2 = np.append(y, [[9], [10], [11]])   # 增加一列
```

#### 5. 数组的变形
1. 数组变形
   例2.10 reshape和resize示例
   reshape不改变原数组，返回符合要求的组织方式的数组视图
   resize改变原数组，无返回值
   ``` py
   import numpy as np
   a = np.arange(4).reshape(2, 2) # 生成数组[[0, 1], [2, 3]]
   b = np.arange(4).reshape(2, 2) # 生成数组[[0, 1], [2, 3]]
   print(a.reshape(4,), '\n', a)    # 输出[0, 1, 2, 3]和[[0, 1], [2, 3]]
   print(b.resize(4,), '\n', b)     # 输出None和[0, 1, 2, 3]
   ```

2. 数组降维
   例2.11 数组降维示例
   将多维数组降为一维数组，ravel，flatten，reshape
   reshape(-1)，原数组不修改，返回视图（可用于赋值）
   ravel()，原数组不修改，返回视图（可用于赋值b=a.ravel()）
   flatten()，原数组不修改，分配了新的空间
   ``` py
   # 程序文件 Pex2_11.py
   import numpy as np
   a = np.arange(4).reshape(2, 2)
   b = np.arange(4).reshape(2, 2)
   c = np.arange(4).reshape(2, 2)
   print(a.reshape(-1), '\n', a) # 输出：[0, 1, 2, 3]和[[0, 1], [2, 3]]
   print(b.ravel(), '\n', b)     # 输出：[0, 1, 2, 3]和[[0, 1], [2, 3]]
   print(c.flatten(), '\n', c)   # 输出：[0, 1, 2, 3]和[[0, 1], [2, 3]]
   ```
   
3. 数组组合
   例2.12 数组组合效果示例
   c_列组合——hstack数组横向/水平组合——concatenate((a, b), axis = 1)
   r_行组合——vstack数组纵向/垂直组合——concatenate((a, b), aixs = 0)
   of course不改变原数组
   ``` py
   # 程序文件2_12.py
   import numpy as np
   a = np.arange(4).reshape(2, 2)      # 生成数组[[0, 1], [2, 3]]
   b = np.arange(4, 8).reshape(2, 2)   # 生成数组[[4, 5], [6, 7]]
   c1 = np.vstack([a, b])     # 垂直方向组合
   c2 = np.r_[a, b]           # 垂直方向组合
   d1 = np.hstack([a, b])     # 水平方向组合
   d2 = np.c_[a, b]           # 水平方向组合
   ```

4. 数组分割
   例2.13 数组分割示例
   hsplit(a, n)横向分割，把a平均分成n个列数组——split(a, n, axis = 1)
   vsplit(a, n)纵向分割，把a平均分成n个行数组——split(a, n, axis = 0)
   ？？？？？split(a, n)把a沿深度方向平均分成n个数组
   ``` py
   #程序文件Pex2_13.py
   import numpy as np
   a = np.arange(4).reshape(2, 2)
   b = np.hsplit(a, 2)  # 把a“平均”分成2个列数组
   c = np.vsplit(a, w)  # 把a“平均”分成2和行数组
   ```


### 2.1.2 数组的运算、通用函数和广播运算
#### 1. 四则运算
运算符号+-*/，函数add，substract，multiply，divide(函数直接收两个对象，多个需嵌套方法)
例2.14 数组简单运算示例
``` py
# 程序文件Pex2_14.py
import numpy as np
a = np.arange(10, 15); b = np.arange(5, 10)
c = a + b; d = a * b
e1 = np.modf(a/b)[0]
e2 = np.modf(a/b)[1] 
print(c, '\n', d, '\n', e1, '\n', e2)
```

#### 2. 比较运算
比较运算符返回的是bool类型的值
多维数组通过bool索引返回的是一维数组
np.where返回的数组保持原来的形状
``` py
import numpy as np
a = np.array([[3, 4, 9], [12, 15, 1]])
b = np.array([[2, 6, 3], [7, 8, 12]])
# print(a > 10)
print(a[a > b])
print(a[a > 10])
print(np.where(a > 10, -1, a))   # a中大于10的地方改为-1
print(np.where(a > 10, -1, 0))   # a中大于10的元素改为-1，否则为0
# print(a)                       # 当然改的都不是原数组
```

#### 3.ufunc函数（通用函数）
- 一种对数组中的元素逐个进行操作的函数
- 以Numpy数组输出
- 比使用math库中的函数效率高得多
例2.16 ufunc函数效率示例
``` py
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
```

#### 4. ufunc函数的广播机制
- 广播：不同形状的数组之间执行算数运算的方式
- 广播生效：ufunc函数计算前提，数组维度相容。不相容——广播
- 广播机制：
  各数组维度可以不相等，确保从右到左的对应维度相等
  对应维度值不相等，确保其一为

例2.17 广播机制示例
``` py
# 程序文件2_17.py
import numpy as np
a = np.arange(0, 20, 10).reshape(-1, 1)    # 变形为1列的数组，行数将自动计算
b = np.arange(0, 3)
print(a + b)
```


### 2.1.3 NumPy.random模块的随机生成
Python内置的random模块，每次只生成一个随机数，随机数种类不丰富
NumPy.random模块的随机数生成函数——随机向量and函数丰富

### 2.1.4 文本文件和二进制文件存取
#### 1.文本文件的存取
1. savetxt()和loadtxt()存取文件
   例2.18 文本文件存取示例
   ``` py
   # 程序文件Pex2_18.py
   import numpy as np
   a = np.arange(0, 3, 0.5).resharp(2, 3) # 生成2x3的数组
   np.savetxt("Pdata2_18_1.txt", a)
   b = np.loadtxt("Pdata2_18_1.txt")      # 返回浮点型数组
   print("b = ", b)

   np.savetxt("Pdata2_18_2.txt", a, fmt = "%d", delimiter = ",")  # 保存为整型数据，用逗号分隔
   c = np.loadtxt("Pdata2_18_2.txt", delimiter = ",")             # 读入时也要指定逗号分隔
   print("c = ", c)
   ```

   例2.19 文本文件Pdata2_19.txt中存放如下格式的数据，
   把其中的数据读入到数组a，并提取数组a前2行、前2列到第4列的元素，构造一个数组b
   ``` py
   # 程序文件Pex2_19.py
   import numpy as np
   a = np.loadtxt("Pdata2_19.txt")
   b = a[:2,1:4] ### b = a[0:2, 1:4]
   print("b = ", b)
   ```

   例2.20 文本文件Pdata2_20.txt中存放如下格式的数据，提取其中的数值数据
   ``` py
   # 程序文件Pex2_20.py
   import numpy as np
   a = np.loadtxt("Pdata2_20.txt", dtype = str, delimiter = "，")
   b = a[1:, 1:].astype(float)   # 提取a矩阵的数值行和数值列，并转换类型
   print("b = ", b)
   ```

2. genfromtxt读入文本文件数据
   调用格式与常见参数（P51）
   - fname：文件名
   - dtype：默认浮点型，含字符"str"
   - comments：注释符，默认#
   - delimiter：列分隔符
   - skip_header,skip_footer
   - converters:将指定列的数据换成其他数值。默认None
   - missing_values：指定缺失值的标记，含该标记解释为缺失
   - filling_values：填充 缺失 值。
   - usecols：需读入的列
   - names：为读入的列设置列名称
   - encoding：含中文，需指定字符编码

   例2.21 纯文本文件Pdata2_21.txt，分别读取前六行前八列数据、第九列的数值数据、最后一行数据
   ``` py
   # 程序文件Pez2_21.py
   import numpy as np
   a = np.genfromtxt("Pdata2_21.txt", max_rows = 6, usecols = range(8))# 读前6行前8列数据
   b = np.genfromtxt("Pdata2_21.txt", dtype = str, max_rows = 6, usecols = 8) # 读第九列数值数据
   b = [float(v.rstrip('kg')) for (i, v) in enumerate(b)]   # 删除kg并切换为浮点型数据
   c = np.genfromtxt("Pdata2_21.txt", skip_header = 6)      # 读最后一行数据
   print(a, '\n', b, '\n', c)
   ```

#### 2. 二进制格式文件存取
1. tofile()和fromfile()存取二进制格式文件示例
   tofile()将数据以二进制格式写进文件，不保存数组形状、元素类型等信息
   fromfile()需要用户指定数据类型，  并对形状进行适当修改
   ``` py
   #程序文件Pex2_22.py
   import numpy as np
   a = np.arange(6).reshape(2, 3)
   a.tofile('Pdata2_22.bin')
   b = np.fromfile('Pdata2_22.bin', dtype = int).reshape(2, 3)
   print(b)
   ```
2. load(), save()和savez()存取NumPy专用的二进制格式文件
   savez()保存多个文件，第一个为文件名，后面的参数是要保存的数组
   load()自动识别npz文件，返回一个类似字典的对象，通过以数组名作为键获取数组内容
   ``` py
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
   ```

## 2.2 文件操作

## 2.3 数据处理工具pandas
查看函数
``` py
import pandas as pd
```
常用子类
``` py
from pandas import Series, DataFrame
```
统计特征计算
- mean()：算术平均值
- std()：标准差
- cov()：协方差
- var()：方差
- 
- describe()：非NaN数据个数，均值，标准差，最小值，最大值，分位数
### 2.3.1 Pandas的序列和数据框
#### 1. 序列
序列的三种构造方式：
``` py
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
```

序列索引和计算
``` py
# 程序文件Pex2_30.py
import pandas as pd
import numpy as np
s = pd.Series([10.5, 20.5, 98], index = ['a', 'b', 'c'])
a = s['b']     # 取出序列第二个元素，输出20.5
b1 = np.mean(s)   # 输出：43.0
b2 = s.mean()  # 通过数列（序列吧）方法求平均值，输出：43.0
```

#### 2. 数据框
数据框的创建方法：
``` py
DataFrame(data = [二维数据], index =[行索引], columns = [列索引], dtype = 数据类型)

# data可以实二维NumPy数组；若是字典，其值为一维数组，键为数组框的列名
```

例2.31 构造数据框示例
``` py
# 程序文件Pex2_31.py
import pandas as pd
import numpy as np
a = np.arange(1, 7).reshape(3, 2)
df1 = pd.DataFrame(a)
df2 = pd.DataFrmae(a, index = ['a', 'b', 'c'], columns = ['x1', 'x2'])
df3 = pd.DataFrame({'x1': a[:,0], 'x2': a[:,1]})
print(df1)
print("---------")
print(df2)
print("---------")
print(df3)
```

### 2.3.2 外部文件的存取
文本文件和eexcel文件的存取

#### 1. 文本文件的存取
重要参数：
- filepath_or_buffer
- sep
- delimiter
- header
- names
- index_col
- skiprows
- skipfooter
- nrows
- na_values
- sklip_blank_lines
- parse_dates
- thousands

例2.32
``` py
# 程序文件Pex2_32.py
import pandas as pd
a = pd.read_csv("Pdata2_32.txt", sep = ',', parse_dates = {'birthday': [0, 1, 2]},
skiprows = 2, skipfooter = 2, comment = '#', thousands = '&', engine = 'python')
print(a)
```

#### 2. Excel文件的存取

``` py
# 程序文件Pex2_34.py
import pandas as pd
import numpy as np
a = pd.read_excel("Pdata2_33.xlsx", usecols = range(1, 4))
b = a.values
c = a.describe()
print(c)
```

### 3. 数据子集的获取



## 2.4 Matplotlib可视化
