#第二章：变量和简单数据类型
#可用的各种数据和表示


##### 2.1 运行hello_world.py时发生的情况
#hello_world.py
print("Hello Python World!")


##### 2.2 变量
# hello_world.py
message = "hello Python world!"
print(message)

# hello_world.py
message = "hello Python world!"
print(message)

message = "Hello Python Crash Course world!"
print(message)

### 2.2.1 变量的命名和使用
#变量规则：
# 1、字母、下划线、数字（不打头）
# 2、不用Python关键字、函数名以及特殊用途单词如print
# 3、简短描述性
# 4、l和O易被混淆为1和0
# 5、大写字母在变量名的特殊含义

### 2。2.2 使用变量时避免命名错误
message = "Hello Python Crash Course reader!"
mesage = "Hello Python Crash Course reader!"
print(mesage)

### 2.2.3 变量是标签
# 变量是可以赋给值的标签 / 变量指向特定的值


##### 2.3 字符串
# 用引号（单双皆可）括起的是字符串
"This is a string."
'This is also a string.'
# 该灵活性意义：在字符串中包含引号和撇号
'I told my friend, "Python is my favorite language!"'
"The language 'Python' is named after Monty Python, not the snake."
"One of Python's srengths is its diverse and supportive community"

### 2.3.1 使用方法修改字符串的大小写
# name.py
name = "ada lovelace"
print(name.title())

name = "aDa ADA ada"
print(name.title())
# 方法title()——以首字母大写（其他字母小写）的方式显示每个单词
name = "Ada Lovelace"
print(name.upper())
print(name.lower())
# 方法upper()——将单词字母全部改为大写
# 方法lower()——将单词字母全部改为小写

## 2.3.2 在字符串中使用变量
# full_name.py
first_name = "ada"
last_name = "lovelace"
full_name = f"{first_name} {last_name}"
print(full_name)
# 要在字符串中插入变量的值，可以在前引号前加上字母f
#                        并将要插入的变量放在花括号中
# ——f字符串
# f是format的缩写，Python通过将花括号内的变量替换为其值来设置字符串的格式

# 使用f字符串的可以做的事
# 1、利用与变量相关联的信息创建完整的消息
first_name = "ada"
last_name = "lovelace"
full_name = f"{first_name} {last_name}"
print(f"Hello, {full_name.title()}!")

print("add".upper()) #try

# 2、使用f字符串创建消息，并把整条消息赋给变量
first_name = "ada"
last_name = "lovelace"
full_name = f"{first_name} {last_name}"
message = f"Hello, {full_name.title()}!"
print(message)

# format方法与f字符串
# 圆括号内列出要在字符串中使用的变量
# 对于每个变量用一个花括号引用
# 按顺序将花括号替换为圆括号内 列出的变量的值
full_name = "{} {}".format(first_name, last_name)#.title()
print(full_name)

### 2.3.3 使用制表符或换行符来添加空白
# 空白：泛指非打印字符，如空格、制表符、换行符
# 制表符\t
print("Python")
print("\tPython")
# 换行符\n
print("Languages:\nPython\nC\nJavaScript")
# 同时使用
print("Languages:\n\tPython\n\tC\n\tJavaScript")

### 2.3.4 删除空白
# 以下在交互环境中进行

#  方法rstrip()删除字符串后面的空白（不是改变原字符串），删除是暂时的
favorite_language = 'python '
print(favorite_language)
print(favorite_language.rstrip())
print(favorite_language)

# 永久地删除字符串的空白
# ——将删除操作的结果关联到变量
favorite_language = 'python '
favorite_language = favorite_language.rstrip()
print(favorite_language)

# 方法lstirp()剔除字符串开头的空白
# 方法strip()同时剔除字符串两边的空白
favorite_language = ' python '
favorite_language.rstrip()
favorite_language.lstrip()
favorite_language.strip()

### 2.3.5 使用字符串时避免语法错误
# 非法的python代码
# 如单引号括起的字符串内用撇号，引发
# message = 'One of Python's strengths is its diverse community'
# print(message)
# 正确使用方法
#撇号位于两个双引号之间
message = "One of Python's strengths is its diverse community."
print(message)
# 高亮功能
# Python代码和普通句子的颜色混淆时，说明可能存在引号不匹配


##### 2.4 数
### 2.4.1 整数
# 加+减-乘*除/
2 + 3
3 - 2
2 * 3
3 / 2
# 乘方运算**
3 ** 2
3 ** 3
10 ** 6
# 运算次序
2 + 3 * 4
# 圆括号修改运算次序
(2 + 3) * 4
# in examples空格不影响计算表达式方式，存在旨在帮助程序员阅读理解

### 2.4.2 浮点数
# Python将所有带小数点的数称为浮点数
# 小数点可以出现在数的任何位置
# 很大程度上无需考虑其行为
0.1 + 0.1
0.2 + 0.2
2 * 0.1
2 * 0.2
# 运算结果包含的小数位数可能不确定
0.2 + 0.1
3 * 0.1
# 忽略多于位数/学习处理多于小数位的方式

### 2.4.3 整数和浮点数
# 两数相除结果总是浮点数，即使都是整数整除
4 / 2
# 其他运算中，一个操作数整数，一个浮点数，结果总是浮点数
1 + 2.0
2 * 3.0
3.0 ** 2
# 无论何种运算，有浮点数操作数，默认得到总是浮点数，即使结果本为整数

### 2.4.4 数中的下划线
# 下划线将大的数字分组
# universe_age = 14_000_000_000
# 打印时不打印下划线
# print(universe_age)
# 因为储存时忽略下划线
# 是用于整数和浮点数

### 2.4.5 同时给多个变量赋值
# 可以在一行中给多个变量赋值
x, y, z = 0, 0, 0
# 逗号分隔变量名&赋给的值
# 个数相同，按顺序关联

### 2.4.6 常量
# 没有内置的常量类型
# 全大写（“字母全大写”）指出某个变量视为常量，其值应该不变
MAX_CONNECTIONS = 5000


##### 2.5 注释
### 2.5.1 如何编写注释
# 注释用#标识，其后内容都被Python解释器忽略
# 如：
# 向大家问好。
print("Hello Python people!")

### 2.5.2 该编写什么样的注释
# 要做什么，怎么做


##### 2.6 Python之禅
# 获悉代码指导原则，解释器中执行命令import this
# 简单，尽可能简单，漂亮，易于维护
# 易于阅读，注释
# Now is better than never,先写行之有效的代码，再决定改进还是编写新的

##### 2.7 小结
# 变量的使用，具有描述性变量名的创建，消除名称错误和语法错误
# 字符串是什么，大小写显示字符串，使用空白，剔除空白
# 整数和浮点数的使用，使用数值数据的方法
# 代码尽可能简单
# 预告：列表+遍历（储存及操作）
# 在被称为列表的变量中储存一系列信息，以及遍历以操作其中信息





# 第三章：列表简介
# 在一个地方储存成组的信息


##### 3.1列表是什么
# bicycles.py
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles)
# 打印列表，打印内部表示，包括方括号

### 3.1.1 访问列表元素
# 语法：列表名称 + 列表索引（方括号内）
print(bicycles[0])
# 对任意列表元素调用第2章介绍的字符串方法
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[0].title())
### 3.1.2 索引从0而不是1开始
# 位置-1作为索引
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[1])
print(bicycles[3])
# 访问列表最后一个元素的特殊语法：将索引指定-1
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[-1])
# 适用于其他负数索引
# 例如：-2返回倒数第二个元素，-3返回倒数第三个
# useful:在不知道列表长度情况下访问最后的元素

### 3.1.3 使用列表的各个值
# 像使用其他变量一样使用列表的各个值
# 如：用f字符串     根据列表中的值创建消息
#  从列表中提取第一款自行车，并用该值创建一条消息：
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
message = f"My first bicycle was a {bicycles[0].title()}."
print(message)


##### 3.2 修改、添加和删除元素
# 动态，如外星人列表，射杀（删除）与出现（添加）

### 3.2.1 修改列表元素
# 修改语法类似访问语法
# 列表名 + 要修改的元素的索引 + 指定该元素的新值
#motorcycles.py
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
motorcycles[0] = 'ducati'
print(motorcycles)

### 3.2.2 在列表中添加元素
# 添加新元素     多种方式

# 01在列表末尾添加元素
# 附加(append)将添加到列表末尾
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
motorcycles.append('ducati')
print(motorcycles)
# use:动态地创建列表
# ——先创建空列表，再用一系列函数调用append()添加元素
motorcycles = []
motorcycles.append('honda')
motorcycles.append('yamaha')
motorcycles.append('suzuki')
print(motorcycles)
# 应用：常见，为控制用户，先创建一新空列表，再以附加方式储存用户输入值

# 02在列表中插入元素
# 方法insert() 可在列表的任何位置添加新元素
# 指定新元素的索引和值
motorcycles = ['honda', 'yamaha', 'suzuki']
motorcycles.insert(0, 'ducati')
print(motorcycles)
# 右移

### 3.2.3 从列表中删除元素
# 删除一个或多个元素
# 根据位置或值来删除元素
# 01 使用del语句删除元素
# 前提：已知待删元素在列表中的位置，del语句
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
del motorcycles[0]
print(motorcycles)
# 可删除任意位置处的列表元素，条件是知道其索引
# 演示删除前述列表第二个元素'yamaha'
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
del motorcycles[1]
print(motorcycles)
# 使用del语句将值从列表删除后，便无法再访问了

# 02使用方法pop()删除元素
# 需要：将元素从列表删除，并接着使用它的值
# 方法pop()删除列表末尾的元素，并让你能继续使用它
# 弹出（pop）：列表就像一个栈，删除列表末尾的元素相当于弹出栈顶的元素
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
popped_motorcycle = motorcycles.pop()
print(motorcycles)
print(popped_motorcycle)
# 应用举例：列表中摩托车按购买时间排序，应用方法pop()指出最新购买的摩托车
motorcycles = ['honda', 'yamaha', 'suzuki']
last_owned = motorcycles.pop()
print(f"The last motorcycle I owned was a {last_owned.title()}.")

# 03弹出列表中任何位置处的元素
# pop()来删除列表中任意位置的元素
# 在圆括号中指定要删除的元素的索引
motorcycles = ['honda', 'yamaha', 'suzuki']
first_owned = motorcycles.pop(0)
print(f"The first motorcycle I owned was a {first_owned.title()}.")

# 别忘了使用pop后被弹出的元素不再在列表中
# del语句与pop()方法选择：
#del: 删除，不再以任何方式使用
#pop：删除，还能继续使用

# 04 根据值删除元素
# 方法remove()
# 例：从列表motorcycles删除值'ducati'
motorcycles = ['honda', 'yamaha', 'suzuki', 'ducati']
print(motorcycles)
motorcycles.remove('ducati')#让Python确定'ducati'在列表出现的位置，并将该元素删除
print(motorcycles)

# 使用remove()删除时，也可接着用被删元素的值
# 例：删除'ducati',并打印消息指出删除原因
motorcycles = ['honda', 'yamaha', 'suzuki', 'ducati']
print(motorcycles)
too_expensive = 'ducati'#赋给变量
motorcycles.remove(too_expensive)#用变量告知待删值
print(motorcycles)
print(f"\nA {too_expensive.title()} is too expensive for me.")

# 方法remove只删除第一个指定的值
# # 若待删值在列表出现多次，需用循环确保都删除
# 将在第七章介绍

##### 3.3 组织列表
# 最初排列顺序、调整排列顺序
# 组织列表的方式

### 3.3.1 使用方法sort()对列表永久排列
# 已有汽车列表，要按字母排列
# cars.py
cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.sort()
print(cars)
# 方法sort()永久地修改列表元素的排列顺序
# 可以按与字母顺序相反的顺序排列元素，向sort()方法传递参数reverse = True
cars = ['bmx', 'audi', 'toyota', 'subaru']
cars.sort(reverse = True)
print(cars)

### 3.3.2 使用函数sorted()对列表临时排列
# 保留元素原来的保留顺序，同时以特定顺序呈现
# 函数sorted()按特定顺序显示列表元素，同时不影响他们在列表中的原始排序
cars = ['bmw', 'audi', 'toyota', 'subaru']

print("Here is the original list:")
print(cars)

print("\nHere is the sorted list:")
print(sorted(cars))

print("\nHere is the original list again:")
print(cars)
# 如果要按与字母顺序相反的顺序显示列表，也可向函数sorted()传递参数reverse = True
# try:print(sorted(cars, reverse = True)) // 貌似可以
# try:print(sorted(reverse = True, cars)) // 貌似不行
# 非所有值小写时，情况复杂

### 3.3.3 倒着打印列表
# 反转元素排列顺序，方法reverse()
cars = ['bmw', 'audi', 'toyota', 'subaru']
print(cars)

cars.reverse()
print(cars)
# 方法reverse()是：反转列表元素的顺序。而不是按与字母顺序相反的顺序排列元素。
# 方法reverse()永久地修改列表元素的排列顺序
# 但可以随时恢复，只需再次调用reverse()

### 3.3.4 确定列表的长度
# 函数len(),获悉列表的长度
cars = ['bmw', 'audi', 'toyota', 'subaru']
len(cars)
# print(len(cars)) 
# 计算元素从1开始，应该不会遇到差一错误


##### 3.4 使用列表时避免索引错误
# 1
# motorcycles.py
#   motorcycles = ['honda', 'yamaha', 'suzuki']
#   print(motorcycles[3])
# 索引差一
# 遇到索引错误时，可尝试索引减一，运行程序看是否为想要的结果
# 2
# 索引-1
# 总是返回最后一个元素的值，不管列表长度是否改变
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles[-1])
# 仅当列表为空时，该方式才回导致错误
# motorcycles = []
# print(motorcycles[-1])
# 3
# 发生索引错误，可以打印列表长度，或与你以为的不同
# 对其动态处理时尤为如此
# 查看列表或其元素数，可帮助找出逻辑错误


##### 3.5 小结
# 列表是什么，其中元素使用
# 定义列表和增删元素
# 永久排序，临时排序，确定长度
# 避免索引错误
# 预告： 高效处理列表元素——遍历





# 第四章：操作列表
# 上一章：列表创建和简单操作
# 本章：遍历整个列表，循环采取相同措施


##### 4.1 遍历整个列表
# 使用for循环打印魔术师列表中的所有名字
magicians = ['alice', 'david', 'carolina']
for magician in magicians:#从列表magicians中取出一个名字，并将其与变量magician关联
    print(magician)#打印前面赋给magician变量的名字
# 定义一个for循环

### 4.1.1 深入研究循环
# 让计算机完成重复工作的常见方式
# 以上代码为例解释执行过程
# 不管多少元素，对每个元素执行循环的指定步骤
# 可以给依次与列表中每个值相关联的临时变量指定任意名称
# 有意义，单数式与复数式有益于区分单个列表元素还是整个列表

### 4.1.2 在for循环中执行更多操作
# 可对每个元素执行任何操作
# 对每个魔术师打印一条消息指出表演精彩
# magicians.py
magicians = ['alice', 'david', 'carolina']
for magician in magicians:
    print(f"{magician.title()}, thst was a great trick!")
# 在for循环中，想包含多少行代码都可以
# 在for...in...:后每个缩进的代码行都是循环的一部分，将针对列表中的每个值都执行一次
# 故可对列表中的每个值执行任意次数/众多不同的操作
# 例：再添一行代码告诉每位魔术师，期待下一次表演
magicians = ['alice', 'david', 'carolina']
for magician in magicians:
    print(f"{magician.title()}, that was a great trick!")
    print(f"I can't wait to see your next trick, {magician.title()}.\n")
    
# 4.1.3 在for循环结束后执行一些操作
# for循环结束后，通常需要总结性输出或接着执行程序其他任务
# for循环后，没有缩进的代码都只执行一次，不会重复执行
# 例：向全体魔术师致谢，在给各位魔术师消息的后面
magicians = ['alice', 'david', 'carolina']
for magician in magicians:
    print(f"{magician.title()}, that was a great trick!")
    print(f"I can't wait to see your next trick, {magician.title()}.\n")
        
print("Thank you, everyone. That was a great magic show!")
# 使用for循环处理数据是对数据集执行整体操作的方式


##### 4.2 避免缩进错误
# Python根据缩进来判断代码行与前一个代码行的关系
# 缩进让代码更易读，代码整洁而结构清晰
# 注意缩进错误：
#   将不需要的代码块缩进
#   必须缩进的代码块忘记缩进
# 避开与修复

### 4.2.1 忘记缩进
# magicians.py
# magicians = ['alice', 'david', 'carolina']
# for magician in magicians:
# print(magician)
# Python没有找到期望缩进的代码块，会让你知道哪行代码有问题
# 通常将紧跟在for语句后的代码行缩进，可消除这种缩进错误

### 4.2.2 忘记缩进额外的代码行
# 有时能运行不报告错误但结果出人意料
# 执行多项任务，却忘记缩进其中一些代码行
magicians = ['alice', 'david', 'carolina']
for magician in magicians:
    print(f"{magician.title()}, that was a great trick!")
print(f"I can't wait to see your next trick,{magician.title()}!")
# 语法合法，逻辑错误
# 若预期某项操作将对每个列表元素执行一次，但总共执行了一次，确定将一行还是多行代码缩进

### 4.2.3 不必要的缩进
# 不小心缩进了无需缩进的代码行。Python将指出这一点
# message = "Hello Python world"
#     print(message)#无需缩进，因为不是循环的组成部分
# Python将指出这种错误
# 只缩进需要缩进的代码，目前已学只有for循环中对每个元素执行的代码需要缩进

### 4.2.4 循环后不必要的缩进
# 不小心缩进了应在循环结束后执行的代码，这些代码将针对每个列表元素重复执行
# 可能导致语法错误，但大多只导致逻辑错误
# 例子：不小心缩进感谢全体魔术师精彩表演的代码行
# magicians.py
magicians = ['alice', 'david', 'carolina']
for magician in magicians:
    print(f"{magician.title()}, that was a great trick!")
    print(f"I can't wait to see your next trick, {magician.title()}.\n")
    
    print("Thank you everyone, that was a great magic show!")
# 若原本只应执行一次的操作执行了多次，可能要对执行该操作的代码取消缩进

### 4.2.5 遗漏了冒号
# for循环的冒号告诉Python，下一行是循环的第一行
# magicians = ['alice', 'david', 'carolina']
# for magician in magicians
#     print(magician)
# 语法错误，Python不知道你意欲何为
# 单字符错误，难以找出，常在人意料之外

##### 4.3 创建数值列表

### 4.3.1 使用函数range()
# 函数range()轻松地生成一系列数
# 例：使用函数range()来打印一系列数
# first_numbers.py
for value in range(1,5):
    print(value)
# 打印数字1~4
# 差一行为
# range()让Python从第一个值开始，在第二个值停止
# 第二个值处停止，故不会包含该值
# 要打印1~5
for value in range(1, 6):
    print(value)
# 使用range时不符合预期尝试加减一
# 使用range()可以指指定一个参数，这样自动从0开始
# range(6)返回数0 ~ 5
# print(range(5))#居然是打印一个这样的字符串

### 4.3.2 使用range)创建数字列表
# 函数list()
# 创建数字列表，使用函数list()将range的结果直接转换为列表
# 将range()作为list()的的参数，输出结果将是一个数字列表
numbers = list(range(1, 6))
print(numbers)

# range()函数：的使用：可以指定步长，第三个参数
# 例：打印1~10的偶数
# even_numbers.py
even_numbers = list(range(2, 11, 2))
print(even_numbers)
# 从2开始数，不断加2，直到到达或超过11

# 函数range():创建任何需要的数集
# 包含前十个整数的平方
# 两个星号(**)表示乘方运算
# squares.py
squares = []
for value in range(1, 11):
    square = value ** 2;
    squares.append(square)
print(squares)
# 代码更简洁，可不使用临时变量square
squares = []
for value in range(1,11):
    squares.append(value ** 2)
print(squares)
# 有时临时变量让代码更易读，有时无谓变长

# 应该首先考虑清晰易懂且完成所需功能的代码
# 审核代码时，再考虑采用更高效的方法

### 4.3.3 对数字列表执行简单的统计计算
# 专门用于处理数字的python函数
# 例如，最大值，最小值，总和
digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
min(digits)
max(digits)
sum(digits)

print('\n')
### 4.3.4 列表解析
# 列表解析将for循环和创建新元素的代码合并成一行，并自动附加新元素
sqaures = [value ** 2 for value in range(1, 11)]
print(squares)
# 列表解析语法的使用方法
# 描述性的列表名
# 左方括号
# 表达式，用于生成要储存的值
# 编写for循环，用于给表达式提供值(注意！这里for语句末尾没有冒号)
# 右方括号

#try:
# 练习4-9 立方解析
cubes = [value ** 3 for value in range(1,11)]
print(cubes)


##### 4.4 使用列表的一部分
# 第3章中，学习了访问单个元素
# 本章此前：处理所有元素
# 还可以：处理列表部分元素——Python称之为切片

### 4.4.1 切片
# 创建切片
# 指定要使用的第一个元素和最后一个元素的索引
# 和range()一样，在到达第二个索引之前的元素后停止
# 示例：处理一个运动队成员的列表
# players.py
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players[0:3])
# 打印该列表一个切片，输出也是个列表

# 可以生成列表的任意子集
# 示例：提取列表第二三四个元素
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players[1:4])

# 没有指定第一个索引，Python自动从列表头开始（默认0？）
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players[:4])

# 切片终止于列表末尾，可用类似语法
# 省略终止索引
players = ['charles', 'martina', 'michael', 'florence','eli']
print(players[2:])
# 无论列表多长，此法可用于输出特定位置到列表末尾所有元素

# recall：负数索引返回离列表末尾相应距离的元素
# 因此可输出列表末尾任意切片
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players[-3:])

# 注意
# 可以在表切片的方括号内指定第三个值，告诉Python在指定范围内每个多少元素提取一个
# 个人感觉，与其说隔，不如认为是认为是打印后计数“步长”个时打印并将计数重置为0
# 注意，若第二个索引写-1，会在最后一个前停止

### 4.4.2 遍历切片
# 遍历列表的部分元素，可在for循环中使用切片
# 示例：遍历前三名队员，并打印他们的名字
player = ['charles', 'martina', 'michael', 'florence', 'eli']
print("Here are the first three players on my team:")
for player in player[:3]:
    print(player.title())

### 4.4.3 复制列表
# 复制列表工作原理，常运用情形
# 复制列表：
# 常见一个包含整个列表的切片，同时省略起始索引和终止索引
# 该切片即为列表的副本
# 示例：自己和朋友(复制来创建)最喜欢的四种食品
# foods.py
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]#提取一个切片，从而创建这个列表的副本，并赋给变量friend_foods

print("My favorite foods are:")
print(my_foods)

print("\nMy friend's favorite foods are:")
print(friend_foods)
# 核实确实有两个列表，在每个列表中添加一种食品，并核实每个列表都记录了相应人员喜欢的食品
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]

my_foods.append('cannoli')
friend_foods.append('ice cream')

print("My favorite foods are:")
print(my_foods)

print("\nMy friend's favorite foods are:")
print(friend_foods)
# 如果只是将my_foods赋给friend_foods，不能得到两个列表
my_foods = ['pizza', 'falafel', 'carrot cake']

# 这行不通：
friend_foods = my_foods

my_foods.append('cannoli')
friend_foods.append('ice cream')

print("My favorite foods are:")
print(my_foods)

print("\nMy favorite foods are:")
print(friend_foods)
# 将my_foods赋给friend_foods，而不是将my_foods的副本赋给friend_foods
# 实际上，让Python将新变量关联到已于my_foods相关联的列表
# 两个变量指向同一个列表
# 暂时不要考虑这个示例的细节。试图使用列表副本是若出乎意料，确认是否使用切片复制列表

# self_try
a = 5
b = a
b = 6
print(a)
print(b)
# 对此，似乎是对于基本变量可以直接用赋值运算符完成复制，而列表的赋值运算符是浅复制，需要自己创建副本来复制


##### 4.5 元组
# 不能修改的值——不可变的
# 不可变的列表——元组

### 4.5.1 定义元组
# 圆括号（instead of中括号）来标识
# 定义后可用索引访问（如访问列表）
# 示例：一个大小不应变的矩形，储存长宽于元组，确保不能修改
# dimensions.py
dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])
# 示例：试修改元组第一个元素看看结果：
# dimensions = (200, 50)
# dimensions[0] = 250
# 导致返回类型错误消息，指出不能给元组元素赋值
# try:
# listss = [1,]
# listss[0] = 2 
# print(listss[0])
# 注意：
# 元组严格来说以逗号标识，圆括号让其更整洁，单元素元组（常无意义，自动生成的可能）必须在元素后加逗号
my_t = (3,)
# emmm否则貌似变int赋值？
# try
# singles = (1,)
# print(singles[0])

### 4.5.2 遍历元组中的所有值
# for循环来遍历
dimensions = (200, 50)
for dimension in dimensions:#别忘了分号！
    print(dimension)

### 4.5.3 修改元组变量
# 不能修改元组元素，可以给储存元组的变量赋值
# 示例：因此若要修改矩形长宽，可重新定义整个元组
dimensions = (200, 50)
print("Original dimensions:")
for dimension in dimensions:
    print(dimension)

dimensions = (400, 100)# 将一个新元组关联到变量dimensions
print("\nModified dimensions:")
for dimension in dimensions:
    print(dimension)
# 给元组变量重新赋值合法


##### 4.6 设置代码格式
# 代码格式设置约定

### 4.6.1 格式设置指南
# 要提出Python语言修改建议，需编写Python改进提案（Python Enhancement Proposal，PEP）
# PEP8 最古老的PEP之一
# 易于编写与易于阅读
# 阅读次数多

### 4.6.2 缩进
# PEP键易每级缩进4个空格
# 制表符转换为空格
# 混用可能导致问题
# 可将制表符转换为空格，编辑器大多提供该功能

### 4.6.3 行长
# 建议代码标准行长79
# 建议注释行长不超过72（有些工具生成文档注释开头添加格式化字符）

### 4.6.4 空行
# 不同部分分开
# 空行组织程序文件
# 不能滥用
# 空行不影响代码运行，但影响代码可读性
# Python解释器根据水平缩进情况解释代码，不关心垂直间距

### 4.6.5 其他格式设置指南
# 更多，大多针对更加复杂的程序


##### 4.7 小结
# 高效处理列表中的元素
# for循环遍历列表，
# 缩进确定程序结构，常见缩进错误
# 简单数字列表与操作
# 切片——一部分or复制
# 元组
# 格式
#预告：用if语句，在不同条件下采取不同措施，组合复杂条件测试，用于遍历时





# 第五章：if语句
# 检查条件，据此决定采取措施
# if语句检查程序当前状态并采取相应措施
# 条件测试，if语句（简单与复杂），用于编写for循环（一种方式处理大多元素，另一方式处理包含特定值元素）


##### 5.1 简单示例
# 示例：如何用if语句正确处理特殊形式
cars = ['audi', 'bmw', 'subaru', 'toyota']

for car in cars:
    if car == 'bmw':
        print(car.upper())
    else:
        print(car.title())
        
        
##### 5.2 条件测试
# 在程序中检查条件的测试
# 条件测试——if语句的核心，一个值为true / false的表达式

### 5.2.1 检查是否相等
# 将一个变量当前值与特定值进行比较
car = 'bmw'
car == 'bmw'
# 相等运算符==，相等返回True否则返回false
car = 'audi'
car == 'bmw'
# 一个等号陈述，两个等号发问

### 5.2.2 检查是否相等时忽略大小写
# 在Python中检查相等时忽略大小写
# 例如，以下视为不相等
car = 'Audi'
car == 'audi'
# 若大小写无关紧要，可将变量的值转换为小写后比较
car = 'Audi'
car.lower() == 'audi'
# 函数lower()不会修改最初赋给变量car的值，不影响原来的变量（不关联则只是暂时修改）

### 5.2.3 检查是否不相等
# 判断两个值是否不等！=，其中惊叹号！表示不
# 不等运算符
# 示例：指出顾客要求配料是否是意式小银鱼
# topppings.py
requested_topping = 'mushrooms'

if requested_topping != 'anchovies':
    print("Hold the anchovies!")
# 编写的大多条件表达式检查是否相等，但有时检查不等效率更高

### 5.2.4 数值比较
# 示例：检查是否18岁
age = 18
age == 18
# 检查两数是否不等
# 示例：下面的代码在提供的答案不正确时打印一条消息
# magic_number.py
answer = 17
if answer != 42:
    print("That is not the correct answer. Please try again!")
# 条件语句可包含各种数值比较：小于，小于等于，大于，大于等于
age = 19
age < 21
age <= 21
age > 21
age >= 21

### 5.2.5 检查多个条件
# 同时检查多个条件
# and 和 or 关键字

# a.使用and检查多个条件
# 检查两个条件是否都为true
# 测试都通过了——True，至少一个没通过——False
# 示例：检查两人是否都不小于21岁
age_0 = 22
age_1 = 18
age_0 >= 21 and age_1 >= 21
age_1 = 22
age_0 >= 21 and age_1 >= 21
# 改善可读性，每个测试放在一对圆括号内，并非必须
(age_0 >= 21) and (age_1 >= 21)

# b.使用or检查多个条件
# 只要一个满足就能通过测试
# 仅当两个都没通过才为False
# 示例：检查的条件是至少一个人的年龄不小于21岁
age_0 = 22
age_1 = 18
age_0 >= 21 or age_1 >= 21# 前测试通过了
age_0 = 18
age_0 >= 21 or age_1 >= 21# 两个测试都没有通过

### 5.2.6 检查特定值是否包含在列表中
# 关键字in
# 示例：披萨店，创建以列表包含用户点的比萨配料，检查特定配料是否包含在该列表中
requested_toppings = ['mushrooms', 'onions', 'pineapple']
'mushrooms' in requested_toppings
True
'pepperoni' in requested_toppings
False
# 关键字in让Python检查列表是否包含'mushrooms'与'pepperoni'
# 检查列表是否包含特定值

### 5.2.7 检查特定值是否不包含在列表中
# 关键词not in
# 确定特定值未包含在列表中
# 示例：有一个列表包含被禁言用户，允许用户提交前检查是否被禁言
# banned_users.py
banned_users = ['andrew', 'carolina', 'david']
user = 'marie'

if user not in banned_users:# 如果user的值未包含在列表banned_users中，Python将返回True
    print(f"{user.title()}, you can post a response if you wish.")# 邀请发布评论

### 5.2.8 布尔表达式
# 条件测试的别名
# 结果要么true要么false
# 布尔值通常用于记录条件
game_active = True#游戏是否在运行
can_edit = False#用户是否可以编辑网站内容

##### 5.3 if语句
### 5.3.1 简单的if语句
# 最简单的if语句只有一个测试和一个操作
# if conditinal_test:
#     do something
# 示例：某人年龄是否符合投票年龄
age = 19
if age >= 18:
    print("You are old enough to vote!")
# 缩进，在if语句和在for语句中作用相同
# 所有缩进的代码行
age = 19
if age >= 18:
    print("You are old enough to vote!")
    print("Have you registered to vote yet?")

### 5.3.2 if-else语句
# 通过时一个操作，不通过另一个操作
# 示例：符合投票年龄时显示与前相同的消息，不符合显示一条新消息
age = 17
if age >= 18:
    print("You are old enough to vote!")
    print("Have you registered to vote yet?")
else:
    print("Sorry, you are too young to vote.")
    print("Please register to vote as soon as you turn 18.")
# 可行，因为只存在两种情形，总执行两操作之一

### 5.3.3 if-elif-else结构
# 超过两个情形，只执行语句中一个代码块
# 依次执行直到遇到通过的，执行后，跳过剩余测试
# 示例：按年龄段收费的游乐场门票价格
# amusement_park.py
age = 12
if age < 4:
    print("Your admission cost is $0.")
elif age < 18:
    print("Your admission cost is $25.")
else:
    print("Your admission cost is $40.")
# 代码更简洁，只设置价格不打印消息，效率高，易于修改
age = 12
if age < 4:
    price = 0
elif age < 18:
    price = 25
else:
    price = 40
print(f"Your admission cost is ${price}.")
### 5.3.4 使用多个elif代码块
# 示例：游乐园门票，增加一个条件测试，65岁以上半价
age = 12
if age < 4:
    price = 0
elif age < 18:
    price = 25
elif age < 65:
    price = 40
else:
    price = 20# 记得设置这一部分，改为20

print(f"Your admission cost is ${price}.")
### 5.3.5 省略else代码块
# 有时else很有用，有时一条elif处理特定情形更清晰
# 示例5.3.4游乐园门票无else版
age = 12
if age < 4:
    price = 0
elif age < 18:
    price = 25
elif age < 65:
    price = 40
elif age >= 65:
    age = 20
print(f"Your admission cost is ${price}.")

### 5.3.6 测试多个条件
# if elif else适用于仅一个条件满足
#   一个通过，跳过余下
# 检查所有关心的条件——一系列不含elif和else的简单if语句
# 在多个条件可能为true，且需要每个条件true时采取相应措施时适合使用
# 示例：比萨店配料包含
# toppings.py
requested_toppings = ['mushrooms', 'extra cheese']

if 'mushrooms' in requested_toppings:
    print("Adding mushrooms.")
if 'pepperoni' in requested_toppings:
    print("Adding pepperoni.")
if 'extra cheese' in requested_toppings:# 可用双引号
    print("Adding extra cheese.")

print("\nFinished making your pizza!")
# if-elif-else结构，有一个测试通过后，跳过余下测试
# 示例：比萨店配料包含
requested_toppings = ['mushrooms', 'extra cheese']
if 'mushrooms' in requested_toppings:
    print("Adding mushrooms.")
elif 'pepperoni' in requested_toppings:
    print("Adding pepperoni.")
elif 'extra cheese' in requested_toppings:
    print("Adding extra cheese.")

print("\nFinished making your pizza!")
# 总结：只执行一个代码块，if-elif-else语句
#       执行多个代码块，一系列独立的if语句

##### 5.4 使用if语句处理列表

### 5.4.1 检查特殊元素
# 检查列表的特殊值，对其做合适的处理
# toppings.py
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']
for requested_topping in requested_toppings:
    print(f"Adding {requested_topping}.")
print("\nFinished making your pizza!")
# 青椒用完了，处理
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']
for requested_topping in requested_toppings:
    if requested_topping == 'green peppers':
        print("Sorry, we are out of green peppers right now.")
    else:
        print(f"Adding {requested_topping}.")
print("\nFinished making your pizza!")

### 5.4.2 确定列表不是空的
# 此前假设列表非空
# 需在for循环前确定列表是否为空
# 示例：制作前检查配料表是否为空，空则确认是否原为比萨，不为空像前面一样制作
requested_toppings = []

if requested_toppings:#列表名做条件表达式，至少含一个元素返回True，空返回False
    for requested_topping in requested_toppings:
        print(f"Adding {requested_topping}.")
    print("\nFinished making your pizza!")
else:
    print("Are you sure you want a plain pizza?")

### 5.4.3 使用多个列表
# 示例：顾客要求的拒绝与满足，拒绝怪异的要求
# 比萨店供应的配料，顾客点的配料。顾客点的，先检查是否为供应的，再决定添加与否
available_toppings = ['mushrooms', 'olives', 'green peppers', 'pepperoni',
                      'pineapple', 'extra cheese'] # 若固定可用元组储存
requested_toppings = ['mushrooms', 'french fries', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping in available_toppings:
        print(f"Adding {requested_topping}.")
    else:
        print(f"Sorry, we don't have {requested_topping}.")
        
print(f"\nFinished making your pizza!")

##### 5.5 设置if语句的格式
# 良好的格式设置习惯
# if age < 4:#better
# if age<4:
# 诸如==，>=、<=等比较运算符两边各添加一个空格
# 不影响python对代码的解读，阅读起来更容易

##### 5.6 小结
# 结果要么True要么False，条件测试
# 简单if语句，if-else、if-elif-else
# for循环同时，对特定列表元素处理（特殊元素，空列表，多个列表）
# 代码格式
# 预告：Python字典，关联不同信息。创建、遍历、同列表和if语句结合使用





# 第六章：字典
# 将相关信息关联起来的Python字典，访问与修改，遍历
# 储存字典的列表，储存列表的字典1，储存字典的字典
# 建模

##### 6.1 一个简单的字典
# 示例：一个外星人的游戏，颜色分数各不同
# # alien.py
alien_0 = {'color': 'green', 'points': 5}

print(alien_0['color'])
print(alien_0['points'])
# 储存与访问

##### 6.2 使用字典
# 字典是一系列键值对，用放在花括号内的一系列键值对表示
# 每一个键与值关联，可以用键访问关联的值
# 与键关联的值可以是任何Python对象（数、字符串、列表、字典）
alien_0 ={'color': 'green', 'points': 5}
# 键值对是两个相关联的值，指定键返回相关联的值，键值间用冒号分隔，键值对间逗号分隔
# 键值对数量多少个都行
alien_0 = {'color': 'green', 'points': 5}

### 6.2.1 访问字典中的值
# 获取与键相关的值，指定字典名和放在方括号内的键
# alien.py
alien_0 = {'color': 'green'}
print(alien_0['color'])
# 任意键值对
alien_0 = {'color': 'green', 'points': 5}
new_points = alien_0['points']
print(f"You just earned {new_points} points!")

### 6.2.2 添加键值对
# 动态结构，可随时添加键值对，依次指定字典名，方括号括起的键、相关联的值
# 示例：添加外星人的x坐标和y坐标（坐标系原点通常在左上角）
alien_0 = {'color': 'green', 'points': 5}
print(alien_0)

alien_0['x_position'] = 0
alien_0['y_position'] = 25
print(alien_0)
# 在Python 3.7中，字典中元素的排列顺序与定义时相同
# 打印/遍历字典元素，发现排列顺序和添加顺序相同

### 6.2.3 先创建一个空字典
# 在空字典中添加键值对——便利/必须(储存用户提供数据/自动生成大量键值对)
# 先使用一对花括号定义一个字典
# 再分行添加各个键值对
# alien_0.py
alien_0 = {}

alien_0['color'] = 'green'
alien_0['points'] = 5

print(alien_0)

### 6.2.4 修改字典中的值
# 依次指定字典名，方括号括起的键，与该键关联的新值
# 示例：外星人绿色变黄色
# alien.py
alien_0 = {'color': 'green'}
print(f"The alien is {alien_0['color']}.")

alien_0['color'] = 'yellow'
print(f"The alien is now {alien_0['color']}.")

# 示例：追踪以不同速度移动的外星人（储存当前速度，确定其向右移动多远）
alien_0 = {'x_position': 0, 'y_position': 25, 'speed': 'medium'}
print(f"Original position: {alien_0['x_position']}")

# 向右移动外星人。
# 根据当前速度确定将外星人移动多远
if alien_0['speed'] == 'slow':
    x_increment = 1
elif alien_0['speed'] == 'medium':
    x_increment = 2
else:
    # 这个外星人移动速度肯定很快
    x_increment = 3

# 新位置为旧位置加上移动距离
alien_0['x_position'] = alien_0['x_position'] + x_increment
print(f"New position: {alien_0['x_position']}")

# more：通过修改字典中外星人的值，可改变外星人的行为
alien_0['speed'] = 'fast'
# 再次运行时if-elif-else结构将赋更大值予x_increment

### 6.2.5 删除键值对
# 对于不再需要的信息，del语句彻底删除
# 指定字典名和要删除的键
# 示例：删除alien_0中键'points'及其值
# alien.py
alien_0 = {'color': 'green', 'points': 5}
print(alien_0)
del alien_0['points']
print(alien_0)
# 删除的键值对永远消失

### 6.2.6 由类似对象组成的字典
# 前：一个对象多种信息
# 也可：众多对象的同一信息
# 示例：调查很多人，询问其编程语言
favorite_languages = {
    'jen': 'python',
    'sarah': 'c', 
    'edward': 'ruby',
    'phil': 'python',
    }
# 使用多行来定义字典
# 输入左花括号，回车键
# 下一行缩进四个空格，指定第一个键值对，加逗号，
# 后回车自动缩进后续键值对
# 定义好后，最后一个键值对下一行右花括号，缩进对齐字典中的键
# good：最后一个键值对后也加逗号

# 注意：大多编辑器提供较长字典列表类似方式格式设置功能，
# 较长字典还有 其他 可行格式设置方式

# 示例：可从字典获取任何人喜欢的语言
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python',
    }
# 创建新变量让函数调用print()更整洁得多
language = favorite_languages['sarah'].title()
print(f"Sarah's favorite language is {language}.")

### 6.2.7 使用get()来访问值
# 使用方括号内键获取字典中的值时，可能引发问题：指定键不存在时，出错
# 示例：获取没有分数的外星人 的分数
# alien_no_points.py
# alien_0 = {'color': 'green', 'speed': 'slow'}
# print(alien_0['points'])
# 导致Python显示traceback，指出存在键值错误（KeyError）

# 对字典，可使用方法get()在指定键不存在时返回一个默认值，从而避免这样的错误
# 第一个参数指定键（必要），第二个参数指定键不存在时的返回值（可选）
alien_0 = {'color': 'green', 'speed': 'slow'}

print_value = alien_0.get('points', 'No point value assigned.')
print(print_value)
# 若指定键可能不存在，考虑方法get()而不是方括号表示法

# 注意：方法get()不指定第二个参数且指定键不存在，返回值None
# None并非错误，而是一个表示所需值不存在的特殊值


##### 6.3 遍历字典
# 多种遍历方式

### 6.3.1 遍历所有键值对
# for k,v in user_0.items()
# 遍历字典的for循环，生命两个变量，用于储存字典的键和值（任意名称）
# for循环的第二部分包含字典名和方法items()，返回一个键值对列表
# 接下来，for循环依次将每个键值对赋给指定的两个变量
# 示例：储存有关网站用户的信息
# user.py
user_0 = {
    'username': 'efermi',
    'first': 'enrico',
    'last': 'fermi',
    }
for key, value in user_0.items():
    print(f"\nKey: {key}")
    print(f"Value: {value}")
# 示例：遍历6.2.6的示例favorite_language.py
favorite_language = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python',
    }
for name, language in favorite_languages.items():
    print(f"{name.title()}'s favorite language is {language.title()}.")

### 6.3.2 遍历字典中所有键
# 方法keys()--不需要使用字典中的值
# 示例：
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python',
    }
for name in favorite_language.keys():# 显式更易理解
    print(name.title())
    
# 遍历字典时默认遍历键，因此方法keys()可省略
for name in favorite_languages:
    print(name.title())
    
# 在这种循环中可用当前键访问相关联的值
# 示例：
friends = ['phil', 'sarah']
for name in favorite_languages.keys():
    print(f"Hi {name.title()}.")
    
    if name in friends:
        language = favorite_languages[name].title()
        print(f"\t{name.title()}, I see you love {language}!")

# 使用方法keys()确定键是否存在
# 示例：使用方法keys()确定某个人是否接受了调查
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python',
    }
if 'erin' not in favorite_languages:
    print("Erin, please take your poll!")
    
# 方法keys()实际上返回一个包含字典中所有键的列表

### 6.3.3 按特定顺序遍历字典中的所有键
# 遍历字典时将按插入的顺序返回其中的元素
# 特定顺序返回元素的方法：
# 1.for循环中对返回的键排序
# 2.使用 函数 sorted() 获得按特定顺序排列的副本# 105,方法sort()永久改变，sorted()获得副本，参数reverse=True，方法reverse，函数len()
# 示例：
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python',
    }
for name in sorted(favorite_languages.keys()):
    print(f"{name.title()}, thank you for taking your poll.")
    
### 6.3.4 遍历字典中所有值
# 方法values()来返回一个值列表
# 示例：获得调查者选择的各种语言的列表
favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python',
    }
print("The following languages have been mentioned:")
for language in favorite_languages.values():
    print(language.title())# 没有考虑重复
    
# 剔除重复项，使用集合(set)
# 集合中每个元素独一无二
# 示例：
print("The following languages have been mentioned:")
for language in set(favorite_languages.values()):# 用列表生成集合？
    print(language.title())# 得到集合顺序各次可能会不同

# 注意：集合：
# 可用一对花括号直接创建集合，逗号分隔元素
languages = {'python', 'ruby', 'python', 'c'}
languages # {'ruby', 'python', 'c'}，这个编辑器得到{'python', 'c', 'ruby'}
# 1 集合字典易混淆，都用花括号定义。
#   没有键值对时很可能是集合
# 2 集合不以特定顺序储存元素(不同于列表和字典)


##### 6.4 嵌套
# 嵌套：一系列字典储存在列表中，列表作为值储存在字典中，字典嵌套字典

### 6.4.1 字典列表
# 示例：管理成群的外星人——创建一个外星人列表，每个外星人是一个字典
# aliens.py
alien_0 = {'color': 'green', 'points': 5}
alien_1 = {'color': 'yellow', 'points': 10}
alien_2 = {'color': 'red', 'points': 15}

aliens = [alien_0, alien_1, alien_2]#列表用方括号

for alien in aliens:
    print(alien)

# 示例：更符合现实：外星人多，代码自动生成——range()生成30个外星人
# 创建一个用于储存外星人的空列表
aliens = []
# 创建30个绿色的外星人
for alien_number in range(30):# 告诉Python循环重复几次
    new_alien = {'color': 'green', 'points':5, 'speed': 'slow'}
    aliens.append(new_alien)
#     print(alien_number)
# print(alien_number)# 最后的30甚至没赋
# 显示前五个外星人
for alien in aliens[:5]:
    print(alien)
print("...")
# 显示创建了多少外星人
print(f"Total number of aliens: {len(aliens)}")

# 可以独立修改每个外星人
# 示例：前三个外星人改为黄色，速度中等，值10分
# 创建一个用于储存外星人的空列表
aliens = []
# 创建30个绿色的外星人
for alien_number in range(30):
    new_alien = {'color': 'green', 'points': 5, 'speed': 'slow'} #为什么不放在循环外面呢
    aliens.append(new_alien)
# （两边的green都没打错啊喂）
for alien in aliens[:3]:
    if alien['color'] == 'green':# 情况并非总如此，编写一条if语句确保只修改绿色外星人
        alien['color'] = 'yellow'
        alien['speed'] = 'medium'
        alien['points'] = 10
# 显示前五个外星人
for alien in aliens[:5]:
    print(alien)
print("...")
# 示例：进一步拓展循环，黄色外星人改成移动速度快值15的红色外星人
for alien in aliens[:3]:
    if alien['color'] == 'green':
        alien['color'] = 'yellow'
        alien['speed'] = 'medium'
        alien['points'] = 10
    elif alien['color'] == 'yellow':
        alien['color'] = 'red'
        alien['speed'] = 'fast'
        alien['points'] = 15
for alien in aliens[:5]:
    print(alien)
print("...")
# 常需要列表中包含大量字典，每个字点包含特定对象众多信息
# 如网站用户字典的列表，遍历列表以相同方式处理字典（“字典结构都相同”）

### 6.4.2 在字典中储存列表
# 示例：储存配料列表和比萨描述（外皮类型）
# pizza.py
# 储存所点的比萨信息
pizza = {
    'crust': 'thick',
    'toppings': ['mushrooms', 'extra cheese'],
    }
# 概述所点的比萨
print(f"You ordered a {pizza['crust']}-crust pizza "
    "with the following toppings:")
for topping in pizza['toppings']:
    # print("\"f+topping)?????????????????????????????????????????????????????????????????
    print(topping)
# 字符串很长：
# 在合适的位置分行，每行行首行尾加引号（非第一行加缩进），Python自动合并括号内字符串）

# 需要在字典中将一个键关联到多个值时，字典中嵌套一个列表
# 遍历字典的for循环中再一个for循环遍历字典内的列表
# 示例：被调查者选择多种喜欢的语言
# favorite_languages.py
favorite_languages = {
    'jen': ['python', 'ruby'],
    'sarah': ['c'],
    'edward': ['ruby', 'go'],
    'phil': ['python', 'haskell'],
    }
for name, languages in favorite_languages.items():
    print(f"\n{name.title()}'s favorite languages are:")
    for language in languages:
        print(f"\t{language.title()}")
# 改进：遍历字典的for循环开头加一条for语句，查看len(languages)值确定是否多种语言
# 一种——修改相应措辞——language

# 嵌套层级不应太多，若嵌套层级比前示例多得多，may有更多解决方案


### 6.4.3 在字典中储存字典
# 代码可能很快复杂起来
# 示例：储存多个网站用户的信息：名，姓，居住地
# many_users.py
# 遍历每个用户名，访问与之相关的信息字典
# many_users.py
users = {
    'aeinstein': {
        'first': 'albert',
        'last': 'einstein',
        'location': 'princeton',
        },
    'mcurie': {
        'first': 'marie',
        'last': 'curie',
        'location': 'paris',
        },
    }
for username, user_info in users.items():
    print(f"\nUsername: {username}")
    full_name = f"{user_info['first']} {user_info['last']}"# 开始访问内部字典
    location = user_info['location'] # 表示每位用户的字典都有相同结构
    print(f"\tFull name: {full_name.title()}")
    print(f"\tLocation: {location.title()}")

# Python并不要求字典内嵌套的字典结构必须相同，但若相同更易处理
# 若列表表示每位用户的字典包含不同的键，for循环内部的代码将更复杂


### 6.5 小结
# 定义字典，使用字典内储存的信息，访问和修改（访问，添加，修改，删除）
# 遍历（键值对，键，值）
# 嵌套：列表中嵌套字典，字典中嵌套列表，字典中嵌套字典
# 预告：while循环，获取用户输入——交互性，对用户输入响应





# 第七章：用户输入和while循环
# 接受用户输入——提示用户输入，print()
# 让程序不断运行——while循环，运行至条件不满足为止
# 获取用户输入+控制程序运行时间=>交互式程序

##### 7.1函数input()的工作原理
# 函数input()让程序暂停运行，等待用户输入文本(在用户按回车键后继续进行)
# 获取用户输入后，Python将其赋给一个变量方便使用
# 示例：下面程序让用户输入一些文本，再将文本呈现给用户
# parrot.py
message = input("Tell me something, and I will repeat it back to you: ")
print(message)
#input()接受一个参数——向用户显示的提示(prompt)/说明，让用户知道怎么做

### 7.1.1 编写清晰的程序
# 指定提示，指数需要用户输入何种信息
# 示例
# greeeter.py
name = input("Please enter your name: ")#末尾空格，提示和用户输入分开，让用户明晰输入起始
print(f"\nHello, {name}!")
# 提示可能超过一行
# 将提示赋给一个变量，变量传递给函数input()
# 示例：
# greeter.py
prompt = "If you tell us who you are, we can personaliza the messages you see."
prompt += "\nWhat is your first name? "# 空格，使提示更清晰

name = input(prompt)
print(f"Hello, {name}!")
# 一种创建多行字符串的方式：前半部分赋给变量prompt，+=在前面赋给变量的字符串末尾附加一个字符串

### 7.1.2 使用int()来获取数值输入
# # 使用函数input()，Python将用户输入解释为字符串
# # 示例：让用户输入年龄的解释器对话
#                           age = input("How old are you? ")
# # How old are you? 21
#                           age
# # '21' # 用户输入数值的字符串表示(引号括起)
# # 打印输入——no problem
# # 作为数使用——引发错误
#                           age = input("How old are you? ")
# # How old are you? 21
#                           age >= 18
# # => 引发错误

# 解决问题——函数int()——让Python将输入视为数值
# 函数int()将数的字符串表示转化为数值表示
# 示例：
age = input("How old are you? ")
age = int(age)
age >= 18

# 如何在实际程序中使用int()
# 示例：判断一个人身高是否满足坐过山车的身高要求
# rollercoaster.py
height = input("How tall are you, in inches? ")
height = int(height)

if height >= 48:
    print("\nYou're tall enough to ride!")
else:
    print("\nYou'll be able to ride when you're a little older.")
# 将数值用于比较和计算前，务必将其转换为数值表示

### 7.1.3 求模运算符
# 求模运算符% —— 处理数值信息 —— 两数相除返回余数
# 应用：判断奇偶
# even_or_odd.py
number = input("Enter a number, and I'll tell you if it's even or odd: ")
number = int(number)
if number % 2 == 0:
    print(f"\nThe number {number} is even.")
else:
    print(f"\nThe number {number} is odd.")


##### 7.2 while循环

### 7.2.1 使用while循环
# 示例：用while循环数数
# counting.py
current_number = 1
while current_number <= 5:
    print(current_number)
    current_number += 1

### 7.2.2 让用户选择何时退出
# while循环让程序在用户愿意时不断运行
# 示例：parrot.py——定义“退出值”，用户输入不是这个值，程序继续运行
prompt = "\nTell me something, and I will repeat it back to you: "
prompt += "\nEnter 'quit' to end the program. "
message = ""# 让Python首次执行while代码行时有可执行的东西
while message != 'quit': # 需给message指定初始值
    message = input(prompt)
    print(message)
# 很好，但美中不足：'quit'也作为一条消息被打印出来
# 示例：添加一个简单的if测试
prompt = "\nTell me something, and I will repeat it back to you: "
prompt += "\nEnter 'quit' to end the program. "
message = ""
while message != 'quit':
    message = input(prompt)
    if message != 'quit':
        print(message)

### 7.2.3 使用标志
# 前：满足条件时程序执行
# 现：不同事件导致程序停止
# 导致程序结束的事件很多，若一条while语句中检查，复杂又困难

# 方法：要求很多条件都满足才继续运行的程序，定义一个变量，用于判断程序是否处于活动状态
# 即——标志(flag)

# 这样，while仅检查标志当前值，其余测试（是否发生将标志设为false的事件）放在其他地方——程序更整洁
# 示例：parrot.py，添加标志active，判断程序是否继续运行
prompt = "\nTell me something, and I will repeat it back to you:"
prompt += "\nEnter 'quit' to end the program. "

active = True
while active:
    message = input(prompt)
    if message == 'quit':
        active = False
    else:
        print(message)
# 这样，若要添加测试检查是否发生其他导致active变False的事件很容易。

### 7.2.4 使用break退出循环
# 立即退出
# 控制哪些代码执行，哪些代码不执行
# 示例：让用户指出到过哪些地方——输入quit后使用break语句立即退出while循环
# cities.py
prompt = "\nPlease enter the name of city you have visited: "
prompt += "\n(Enter 'quit' when you are finished.) "
while True:# 不断运行直到遇到break语句
    city = input(prompt)
    if city == 'quit':
        break
    else:#这里貌似可以不用else，与C++函数方法中的if和return结合后类似
        print(f"I'd love to go to {city.title()}!")

### 7.2.5 在循环中使用continue
# continue语句：返回循环开头，根据条件测试结果决定是否继续执行循环
# 示例：从数1到10但只打印其中奇数的循环
# counting.py
current_number = 0
while current_number < 10:
    current_number += 1# （与放在循环末尾的区别在于，当次循环结束时数字当前值是否被使用/处理，前则已使用，后则未使用，while num < = 10）# 若不改测试，区别在于以使用过的10结束还是未使用的10结束
    if current_number % 2 == 0:
        continue# 执行continue，忽略余下代码，返回循环开头
    print(current_number)# 不能被2整除，执行循环余下的代码

### 7.2.6 避免无限循环
# 每个while循环都必须有停止的途径，否则没完没了
# countings.py
x = 1
while x <= 5:
    print(x)
    x += 1# 若遗漏，没完没了，x初始值1始终不变，条件测试始终True，导致while没完没了打印
# 若陷入无限循环：
# 可ctrl + C
# 可关闭显示程序输出的终端窗口

# 避免编写无限循环：
# 对每个while循环测试，确保按预期结束
# (输入预期用于结束的特定值，若无结束检查处理该值的方式)
# 确认程序至少有一个地方能让循环条件为False 或 break语句得以执行


##### 7.3 使用while循环处理列表和字典
# 对于用户信息的大量处理，须在hile循环使用列表和字典
# for循环可遍历列表，但不应在for循环中修改，否则Python难以跟踪其中元素 ？？？？？？？？？？？？？？？？？
# 遍历列表，同时修改，用while循环
# 将while循环同列表和字典结合使用——可收集、储存并组织大量输入，供以后查看和显示

### 7.3.1 在列表之间移动元素
# 示例：验证未验证用户后将其移入已验证列表
# ——使用while循环，验证用户的同时从列表提取，再加入另一个已验证用户列表中
# condirmed_users.py
# 首先，创建一个待验证用户列表
# 和一个用于储存已验证用户的空列表
unconfirmed_users = ['alice', 'brian', 'candace']
confirmed_users = []

# 验证每个用户，直到没有未验证用户为止
# 将每个经过验证的用户都移到已验证用户列表中
while unconfirmed_users:# while循环不断运行直到列表为空
    current_user = unconfirmed_users.pop()
    print(f"Verifying user: {current_user.title()}")
    confirmed_users.append(current_user)

# 显示所有已验证用户
print("\nThe following users have been confirmed:")
for confirmed_user in confirmed_users:
    print(confirmed_user.title())


### 7.3.2 删除为特定值的所有元素
# 删除特定值元素：函数（方法）remove()
# 可行——因为值只在列表中出现一次
# 删除所有为特定值的元素
# 示例：宠物列表，含多个cat的元素，要删除所有这些，不算运行一个while循环直至列表不含cat
# pets.py
pets = ['dog', 'cat', 'dog', 'goldfish', 'cat', 'rabit', 'cat']
print(pets)

while 'cat' in pets:
    pets.remove('cat')

print(pets)

### 7.3.3 使用用户输入来填充字典
# 使用while循环提示用户输入任意多的信息
# 示例：创建一调查程序，其中的循环每次执行时提示输入被调查者名字和回答，收集数据存入字典，以便回答与被调查者关联
# mountain_poll.py
responses = {}

# 设置一个标志指出调查是否继续
polling_active = True

while polling_active:
    # 提示输入被调查者名字和回答：
    name = input("\nWhat is your name? ")
    response = input("Which mountain would you like to climb someday? ")
    
    # 将回答储存在字典中
    responses[name] = response
    
    # 看看是否还有人要参与调查
    repeat = input("Would you like to let another person respond? (yes/ no) ")
    if repeat == 'no':
        polling_active = False
    
# 调查结束，显示结果
print("\n--- Poll Results ---")
for name, response in responses.items():
    print(f"{name} would like to climb {response}.")

##### 7.4 小结
# 如何使用input()让用户提供信息，如何处理文本和数的输入
# while循环来让程序按用户要求不断运行，多种控制while循环流程的方式  # 活动标志，break，continue
# 使用while循环在列表间移动元素，删除列表所有含特定值的元素，如何结合使用while循环与字典
# 预告：函数，将程序分成多个小部分，每部分一项具体任务，调用同一函数任意次，函数独立存在具体文件中
#       效率更高，易于维护，排除故障，不同程序重用





##### 第八章：函数
# 函数是带名字的代码块，用于完成具体工作
# 执行函数定义的特定任务——调用函数，多次执行——调用执行该任务的函数
# 功能：显示信息，处理数据返回一个/一组值
# 储存在模块独立文件中

##### 8.1 定义函数
# 示例：打印问候语的简单函数
# greeter.py
def greet_user():#紧跟其后的所有缩进行构成函数体
    """显示简单的问候语""" # 文本字符串注释，描述函数做啥，三引号括起
    print("Hello!")      # 唯一一行代码

greet_user()# 函数调用，欲调用函数，依次指定函数名及圆括号括起的必要信息
# 用def告诉Python你要定义一个函数
# and这是函数定义：向Python指出函数名，圆括号内可能指出函数为完成任务需要什么信息

### 8.1.1 向函数传递信息
# 示例：稍作修改，让greet_user显示Hello时将用户名字作为抬头
# 为此：在def greet_user内添加username，让函数接受你给username指定的任意值
# now：函数要求你调用它时给username指定一个值
def greet_user(username):
    """显示简单的问候语"""
    print(f"Hello, {username.title()}!")
greet_user('jeese')
# 此时greet_user()不行

### 8.1.2 实参和形参
# 形参(parameter)，函数完成工作所需的信息
# 实参(argument)，调用函数时传递给函数的信息
# 调用时将要让函数使用的信息放在圆括号内，实参传递给了函数，值赋给了形参

##### 8.2 传递实参
# 函数定义may包含多个形参，函数调用may包含多个实参
# 传递实参方式很多：位置实参，要求实参与形参顺序相同；关键字实参，每个实参由变量名和值组成；字典和列表

### 8.2.1 位置实参
# 函数调用中每个实参关联到函数定义中的一个形参
# ——为此，最简单的关联方式：基于实参顺序：关联实参
# 示例：显示宠物信息的函数
# pets.py
def describe_pet(animal_type, pet_name):
    """显示宠物的信息。"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")
    
describe_pet('hamster', 'harry')

# a.多次调用函数
# 根据需要调用函数任意次
# 示例：再描述一个宠物，再调用一次即可
def describe_pet(animal_type, pet_name):
    """显示宠物的信息。"""
    print(f"\nI have a {animal_type}.")
    print("My {animal_type}'s name is {pet_name.title()}.")

describe_pet('haster', 'harry')
describe_pet('dog', 'willie')

    
# 效率高
# 任意数量的位置实参，Python将按顺序将函数调用中的实参与函数定义中的形参关联

# b.位置实参的顺序很重要
# 使用位置实参调用函数时，实参位置不正确，结果可能出乎意料
def describe_pet(animal_type, pet_name):
    """显示宠物的信息。"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet('harry', 'hamster')
# harry被赋给animal_type,hamster被赋给pet_name
# 结果是有一个名为Hamster的harry

# 结果“可笑”时，注意确认函数调用中实参与函数定义中形参顺序一致

### 8.2.2 关键字实参
# 关键字实参是传递给函数的名称值对
# 因为直接在实参中将名称与值关联，所以传递实参时不会混淆
# so无需考虑函数调用中实参顺序，指出各个值用途
# 示例：重新编写pets.py，在其中用关键字实参来调用describe_pet():
def describe_pet(animal_type, pet_name):
    """显示宠物的信息。"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet(animal_type= 'hamster', pet_name = 'harry')
# 关键字实参的顺序无关紧要，因为Python直到各个值该付给哪个形参
# 两个等效的调用
describe_pet(animal_type = 'hamster', pet_name = 'harry')
describe_pet(pet_name = 'harry', animal_type = 'hamster')

# 使用关键字实参时，务必准确指定函数定义中的形参名

### 8.2.3 默认值
# 编写函数时，可给每个形参指定默认值
# 调用函数中给形参提供实参时，Python将使用指定实参值，否则，使用默认值
# so默认值的使用可简化函数调用，可清楚指出函数典型用法
# 示例：大多描述的是小狗，设置默认值'dog'，这样调用其描述小狗时不提供此信息
def describe_pet(pet_name, animal_type = 'dog'):
    """显示宠物信息"""
    print(f"\nI hve a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet(pet_name = 'willie')

# 注意：修改了形参排列顺序，因为仍视为位置实参
# 因为，若函数调用只包含宠物，不改顺序则赋给animal_name
describe_pet('willie')

# 要描述的不是小狗，可使用
describe_pet(pet_name = 'harry', animal_type = 'hamster')
describe_pet('harry', 'hamster')# 貌似也可
# 显示提供实参时忽略形参的默认值

# 注意：使用默认值时，需先在形参列表中列出没有默认值的形参，在列出有默认值的实参
#       让Python能正确解读位置实参

### 8.2.4 等效的函数调用
# 因为可混合使用位置实参、关键字实参和默认值——故有多种等效的函数调用方式
# 如这样的一个定义：
def describe_pet(pet_name, animal_type = 'dog'):
    """显示宠物的信息。"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name}.")
# 则任何情况必须给pet_name提供实参——可用位置方式，可关键字方式
# 要描述的动物不是小狗，则也需给animal_type提供实参——可用位置方式，可用关键字方式

# 以下对该函数调用方式都可行：
# 一条名为Willie的小狗：
describe_pet('willie')
describe_pet(pet_name = 'willie')

# 一只名为Harry的仓鼠
describe_pet('harry', 'hamster')
describe_pet(pet_name = 'harry', animal_type = 'hamster')
describe_pet(animal_type = 'hamster', pet_name = 'harry')
# 这样呢，貌似也可以，用位置和关键字同时给一个形参提供实参会报错
describe_pet('harry', animal_type = 'hamster')# 位置实参·不能出现在关键字之后
# 使用哪种调用方式没关系，只要自己认为易于理解即可

### 8.2.5 避免实参错误
# 实参不匹配错误
# 实参多于或少于函数完成工作所需信息时，将出现实参不匹配错误
# 示例：调用describe_pet()时不指定任何实参
def describe_pet(animal_type, pet_name):
    """显示宠物的信息。"""
    print(f"\nI have a {animal_type}.")
    print(f"My {animal_type}'s name is {pet_name.title()}.")

describe_pet()
# describe_pet('han', 'hen', 'more')
# traceback指出的错误，能让不用查看may在独立文件的函数即可重新编写正确的函数调用
# Python读取函数代码指出需要为那些形参提供实参——指定描述性函数名变量名的另一原因
# (提供实参过多出现类似traceback，帮助你确保函数调用和函数定义匹配)

##### 8.3 返回值
# 并非总直接输出（前），还可处理数据返回一个or一组值——返回值
# return语句将值返回到调用函数的代码行
# 简化主程序

### 8.3.1 返回简单值
# 示例：一个函数，接受名和姓，返回整洁的姓名
# formatted_name.py
def get_formatted_name(first_name, last_name):
    """返回整洁的姓名。"""
    full_name = f"{first_name} {last_name}"
    return full_name.title()

musician = get_formatted_name('jimi', 'hendrix')
print(musician)
# 调用返回值的函数时，需提供一个变量，以便将返回值赋给它

### 8.3.2 让实参变成可选的
# 作用：让实参可选，则使用者只在必要时提供额外信息
# 方式：可用默认值让实参变成可选的
# 示例：拓展函数get_formatted_name()，使其同时处理中间名
def get_formatted_name(first_name, middle_name, last_name):
    """返回整洁的姓名"""
    full_name = f"{first_name} {middle_name} {last_name}"
    return full_name.title()
musician = get_formatted_name('john', 'lee', 'hooker')
print(musician)
# 示例：并非所有人有中间名，让中间名可选，给形参midd_name一个空字符串默认值，移到形参列表末尾
def get_formatted_name(first_name, last_name, middle_name = ''):
    """显示整洁的姓名。"""
    if middle_name:# 检查是否提供中间名
        full_name = f"{first_name} {middle_name} {last_name}"
    else:
        full_name = f"{first_name} {last_name}"
    return full_name.title()
musician = get_formatted_name('jimi', 'hendrix')
print(musician)

musician = get_formatted_name('john', 'hooker', 'lee')
print(musician)#实用性更广

# Python将非空字符串解读为True

### 8.3.3 返回字典
# 可返回任意类型的值，包括列表和字典等较复杂的数据结构
# 示例：函数接受姓名的组成部分，返回一个表示人的字典
# person.py
def build_person (first_name, last_name):
    """返回一个字典"""
    person = {'first': first_name, 'last': last_name}
    return person

musician = build_person('jimi', 'hendrix')
print(musician)
# 该函数接受简单的文本信息，并放在更合适的数据结构中
# 可打印，可以其他方式处理

# 示例：拓展函数，使其接受可选值，如以下修改使其可储存年龄
def build_person(first_name, last_name, age = None):
    """返回一个字典，其中包含有关一个人的信息"""
    person = {'first': first_name, 'last': last_name}
    if age:
        person['age'] = age
    return person
musician = build_person('jimi', 'hendrix', age = 27)
print(musician)
# 特殊值none，表示没有值。可将None视为占位值。条件测试中，None相当于False

### 8.3.4 结合使用函数和while循环
# 示例：结合函数get_formatted_name()和while循环，以更正式的方式问候用户
# greeter.py
def get_formatted_name (first_name, last_name):
    """返回整洁的姓名。"""
    full_name = f"{first_name} {last_name}"
    return full_name.title()
# 这是一个无限循环！
# while True:
#     print("\nPlease tell me your name: ")
#     f_name = input("First name: ")
#     l_name = input("Last name: ")
    
#     formatted_name = get_formatted_name(f_name, l_name)
#     print(f"\nHello, {formatted_name}!")                                      #不打注释会显示代码无法访问Pylance

# 存在问题：没有定义退出条件：
# 示例：每次定义用户输入时，都用break语句提供退出循环的简单途径
def get_formatted_name(first_name, last_name):
    """返回整洁的姓名。"""
    full_name = f"{first_name} {last_name}"
    return full_name.title()

while True:
    print("\nPlease tell me your name: ")
    print("(enter 'q' at anytime to quit: )")
    
    f_name = input("First name: ")
    if f_name == 'q':
        break
    
    l_name = input("Last name: ")
    if l_name == 'q':
        break
    
    formatted_name = get_formatted_name(f_name, l_name)
    print(f"\nHello, {formatted_name}!")
    
##### 8.4 传递列表
# 向函数传递列表，函数可直接访问其内容
# 用函数提高处理列表的效率
# 示例：有一个用户列表，要问候其中每位用户（将包含名字的列表传递给一个名为greet-users的函数）
# greet_users.py
def greet_users(names):
    """向列表中每位用户发出简单的问候。"""
    for name in names:
        msg = f"Hello, {name.title()}!"
        print(msg)
usernames = ['hannah', 'ty', 'margot']
greet_users(usernames)

### 8.4.1 在函数中修改列表
# 列表传给函数后，即可对其进行修改，永久性
# 示例：为用户提交的设计制作3D打印模型的公司，需打印设计存在一列表中，打印后存到另一列表中
# 示例一：不用函数的模拟
#printing_models.py
# 首先创建一个列表，其中包含一些要打印的设计
unprinted_designs = ['phone case', 'robot pendant', 'dodecahedron']
completed_models = []
# 模拟打印每个设计，直到没有未打印设计为止
# 打印每个设计后，都将其移到列表completed_designs中
while unprinted_designs:
    current_design = unprinted_designs.pop()
    print(f"Printing model: {current_design}")
    completed_models.append(current_design)
# 显示所有打印好的模型
print("\nThe following models have been printed:")
for completed_model in completed_models:
    print(completed_model)

# 示例二：为重新组织这些代码，重新编写两个函数，每个做一件具体工作
# （大部分代码同前，但效率更高）
# 第一个：处理打印设计的工作，两个列表形参，模拟逐个取出放入打好列表中的打印过程
# 第二个：概述打印了那些设计，一个列表形参，显示打印出的每个模型名称
def print_models(unprinted_designs, completed_models):
    """
    模拟打印每个设计，直到没有未打印的设计为止，
    打印每个设计后，都将其移到列表completed_models中
    """
    while unprinted_designs:
        current_design = unprinted_designs.pop()
        print(f"Printing model: {current_design}")
        completed_models.append(current_design)

def show_completed_models(completed_designs):
    """显示打印好的所有模型"""
    print("\nThe following models have been printed:")
    for completed_model in completed_models:
        print(completed_model)

unprinted_designs = ['phone case', 'robot pendant', 'dodecahedron']
completed_models = []

print_models(unprinted_designs, completed_models)
show_completed_models(completed_models)
# 输出相同，组织更有序，主程序更易于理解，程序功能更清晰
# 更易于拓展和维护，修改函数代码可影响所有调用函数的地方（比分别修改效率高）

# 理念：每个函数都只负责一项具体工作，优于一个函数完成所有函数
#      若一个函数工作太多，尝试代码划分到两个函数中
#      总可以在一个函数中调用另一个函数，有利于将复杂任务化为一系列步骤

# ### 8.4.2 禁止函数修改列表
# 问题：：即使打印好所有设计，保留原为打印列表供备案
# 解决方法：传递副本而非原件
#          具体途径：切片表示法创建列表副本

# 语法：要向函数传递副本，如此调用：
# function_name(list_name_[:])

# 示例：要解决上述问题，可像这样调用print_models
print_models(unprinted_designs[:], completed_models)

# 总结：
# 传递副本可保留原始列表内容，但无充分理由应传递原始列表
# 避免花时间和内存创建副本，提高效率。  大型列表尤为如此

##### 8.5 传递任意数量的实参
# 问题：有时不知道函数接受多少个实参
# Python允许函数从调用语句中收集任意数量的实参
# 示例：比萨配料，接受很多配料，但无法确定用户要多少种
# pizza.py
def make_pizza(*toppings):
    """打印顾客点的所有配料"""
    print(toppings)# 输出证明Python能处理一个也可处理三个值来调用函数的情形

make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')
# 形参*toppings中星号让Python创建一个名为toppings的空元组，将收到的所有值封装在内
# 即便只收到一个值

# 示例：print()替换为循环，遍历配料列表并对顾客点的比萨进行描述
def make_pizza(*toppings):
    """概述要制作的比萨"""
    print(f"\nMaking a pizza with the following toppings:")
    for topping in toppings:
        print(f"- {topping}")
    
make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')

# 不管多少个实参，这种语法都管用

### 8.5.1 结合使用位置实参和任意数量实参
# 接受不同类型的实参——将接纳任意数量的实参放到最后
# Python先匹配位置实参和关键字实参，再将余下实参收到最后一个形参中
# 示例：加一个表示比萨尺寸的形参，必须将其放在实参*toppings前面
def make_pizza(size, *toppings):
    """概述要制作的比萨"""
    print(f"\nMaking a {size}-inch pizza with the following toppings:")
    for topping in toppings:
        print(f"- {topping}")

make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
 
# 注意：通用形参名*args，收集任意数量的位置实参

### 8.5.2 使用任意数量的关键字实参
# 问题：有时需接受任意数量的实参，预先不知道传递给函数的会是什么样的信息
# 解决方法：将函数编写成能接受任意数量的键值对
# 示例：创建用户简介，接收有关用户的信息但不确定会是什么样的信息
# 函数build_profile()接受名和姓，接受任意数量的关键字实参
# user_profile.py
def build_profile(first, last, **user_info):
    """创建一个字典，其中包含我们知道的有关用户的一切"""
    user_info['first_name'] = first
    user_info['last_name'] = last
    return user_info

user_profile = build_profile('albert', 'einstein', location = 'princeton', field = 'physics')
print(user_profile)
# 形参**user_info中两个信号让Python创建一名为user_info的空字典，将收到的所有名称值对放入其中

# 编写函数时，可以各种方式混合使用 位置实参，关键字实参，任意数量的实参

# 注意：常见形参名**kwargs，用于收集任意数量的关键字实参


##### 8.6 将函数储存在模块中
# 使用函数优点之——代码块与主程序分离，函数的描述性名称让主程序更易于理解
# 更进一步——将函数储存在 称为模块的独立文件 中，再将模块导入主程序中
# import语句：允许在当前程序文件使用模块中的代码

# 隐藏程序代码细节，重点关注于程序高层逻辑
# 重用函数
# 共享独立文件而不是整个程序
# 知道如何导入函数——可使用其他程序员编写的函数库

# 以下简要介绍导入模块的多种方法

### 8.6.1 导入整个模块
# 要让函数可导入，得先创建模块——拓展名为.py的文件，包含要导入程序中的代码

# 示例：创建一个包含函数make_pizza的模块（文件pizza.py）
# pizza.py
def make_pizza(size, *toppings):
    """概述要制作的比萨。"""
    print("\nMaking a {size}-inch pizza with following toppings:")
    for topping in toppings:
        print(f"- {topping}")
# 示例续：接下来在pizza.py所在目录创建一个名为making_pizzas.py的文件
# 该文件导入刚创建的模块，在两次调用make_pizza()
# making_pizzas.py
import pizza# 让Python打开文件pizza.py，并将其中所有函数复制到这个程序中（运行时幕后）
            # 只需知道：在making_pizzas.py中可使用pizza.py中定义的所有函数
pizza.making_pizzas(16, 'pepperoni')
pizza.making_pizzas(12, 'mushrooms', 'green peppers', 'extra cheese')
# 调用被导入模块的函数，指定被导入模块名称pizza和函数名make_pizza()，用句点分隔

# 导入方法一：编写一条import语句并在其中指定模块名，即可使用该模块中所有函数
#           之后，调用函数语法：module_name.function_name()

### 8.6.2 导入特定的函数
# 导入语法二：导入模块中的特定函数
#            from module_name import function_name
#            逗号分隔函数名，可根据需要从模块导入任意数量的函数
#            from module_name import function_0, function_1, function_2
#            调用函数时不需使用文件名和句点
# 示例：对于making_pizzas.py示例，如果只想导入要使用的函数，代码应类似：
from pizza import make_pizza# 由于该语句中显示导入了该函数，调用时只需指定名称即可

make_pizza(16, 'pepperroni')
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

### 8.6.3 使用as给函数指定别名
# 指定别名通用语法：
#               from module_name import function_name as fn
# 问题：要导入的名称可能与程序现有的名称冲突，或函数名称太长
# 解决方法：可指定独一无二的别名(函数的另一个名称，类似于外号)，要取特殊外号需在导入时指定
# 示例给函数make_pizza()指定别名mp()
from pizza import make_pizza as mp# 重命名

mp(16, 'pepperoni')# 调用时可简写避免混淆
mp(12, 'mushrooms', 'green peppers', 'extra cheese')

### 8.6.4 使用as给模块指定别名
# 给模块指定别名通用语法：
#                     import module_name as mn
# 给模块指定简短的别名以更轻松地调用模块中的函数
# 示例：比pizza.make_pizza()更简洁的p.make_pizza()
import pizza as p

p.make_pizza(16, 'pepperoni')
p.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
# 代码更简洁
# 不再关注模块名，专注于描述性的函数名——明确指出函数功能

### 8.6.5导入模块中的所有函数
# （介绍，以便阅读时理解其他人编写的代码中的类似语句）
# 导入语法三：使用星号（*）运算符可让Python导入模块中所有函数
#            from module_name import *
# 由于导入了所有函数，不需据点表示法，可通过名称来调用
from pizza import *

make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

# 使用并非自己编写的大型模块时，最好不要用这种导入方法
# 原因：模块中有函数名称可能与当前项目中的名称相同，导致意想不到的结果
# Python遇到多个名称相同的函数或变量，覆盖，而不是分别导入所有函数

# 最佳做法：要么只导入需要使用的函数，要么导入整个模块用句点表示法——代码更清晰，易于阅读、理解


##### 8.7 函数编写指南

# 几个细节：描述性名称，只用小写字母和下划线（模块名命也遵守以上约定）
# 文档字符串格式 的 简要阐述本函数功能 的 注释

# ！！不要有空格：
# 1 给形参指定默认值时，等号两边不要有空格
#   def function_name(parameter_0, parameter_1='default value')
# 2 函数调用中的关键字实参亦如是
#   function_name(value_0, pameter_1='value')

# 建议代码行长不超79字符——形参多may导致定义超长
#   那么在函数定义输入左括号后按回车键，并在下一行按两次Tab键，将形参列表与只缩进一层的函数体分开
#   大多编译器自动对齐后续参数行，缩进程度与给出第一个参数列表行指定的缩进程度相同
# def function_name(
#         parameter_0, parameter_1, parameter_2,
#         parameter_3, parameter_4, parameter_5):
# function body...

# 程序/模块包含多个函数，可用量空行将相邻函数分开

# 所有import语句应都在文件开头，唯一例外：在文件开头使用了注释描述整个程序

##### 8.8 小结
# 编写函数
# 传递实参：位置实参，关键字实参，任意数量的实参
# 函数功能：显示输出，返回值
# 函数同列表，字典，if语句，while循环结合使用
# 函数储存于模块的独立文件
# 函数编写指南
# 简单，重用，易修改，易阅读，易测试和调试
# 预告：编写类，将函数和数据整洁封装，便于被灵活高效地使用

