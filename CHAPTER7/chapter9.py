# 第九章 类
# 编写类——通用行为，基于类创建对象（实例化）——可赋予独特个性
# 编写类并创建实例，指定在类中储存什么信息，可执行哪些操作
# 编写类来拓展已有类，类存在模块中，导入其他程序员写的类

##### 9.1 创建和使用类
# 使用类几乎可以模拟任何东西
# 编写一个表示小狗的简单类Dog，用它来创建表示特定小狗的实例

### 9.1.1 创建Dog类
# 示例：Dog类创建的每个实例都将储存名字和年龄，赋予每条小狗蹲下和打滚的能力
# dog.py
class Dog:# 定义了一个名为Dog的类，根据约定，首字母大写的名称是类
          # 没有圆括号，因为要从空白创建这个类
    """一次模拟小狗的简单尝试"""# 文档字符串，对类的功能描述
    
    def __init__(self, name, age):
        """初始化属性name和age"""
        self.name = name#获取与形参关联的值，赋给变量name，关联该变量到当前创建的实例
        self.age = age
    
    def sit(self):
        """模拟小狗收到命令蹲下"""
        print(f"{self.name} is now sitting.")
    
    def roll_over(self):
        """"模拟小狗收到命令时打滚"""
        print(f"{self.name} rolled over!")

# 类中的函数称为方法
# 与前面函数目前唯一差别：调用方式

# 方法_init_()（下划线与自动调用，self与自动传入，）
# 方法__init__()是一个特殊方法，每次创建Dog类实例时自动运行
#      约定：开头与末尾各两个下划线，避免默认方法与普通方法 名称冲突
#     （务必确保下划线，否则不会在创建实例时自动调用）
# 方法__init__()的形参self必不可少
#      每个与实例关联的方法调用都自动(调用时不需自己传递)传入形参self，是一个指向实例本身的调用
#      作用：让实例能访问类中的属性和方法
# ——self为前缀的变量
#       可供类中的所有方法使用，可通过类的任何实例来访问
# 属性，像这样可通过实例访问的变量

# Dog类另外两个方法，不需额外信息，只有形参self

### 9.1.2 根据类创建实例
# 可将类视为如何创建实例的说明（让Python知道如何创建表示小狗的特定实例）
# 实例：创建一个表示特定小狗的实例
class Dog:
    """一次模拟小狗的简单尝试"""#别忘了描述类的文档字符串！
    
    def __init__(self, name, age):
        """初始化属性name和age。"""
        self.name = name
        self.age = age
        
    def sit(self):
        """模拟小狗收到命令时蹲下。"""
        print(f"{self.name} is now sitting.")
    
    def roll_over(self):
        """模拟小狗收到命令时打滚。"""
        print(f"{self.name} rolled over!")
        
my_dog = Dog('Willie', 6)# 创建一只小狗，让Python用实参调用方法__init__()
                         # 返回一个表示这个小狗的实例，被赋给变量my_dog

print(f"My dog's name is {my_dog.name}.")
print(f"My dog is {my_dog.age} years old.")
# 命名约定：通常可认为首字母大写的名称是类，小写的名称是实例

# a.访问属性
# 访问实例的属性：句点表示法（先找到实例，在查找相关联的对应属性）

# b.调用方法
# 创建实例后，句点表示法调用（在类中，查找方法，运行其代码）
# 示例：
my_dog.sit()
my_dog.roll_over()

# c.创建多个实例
# 示例：再创建一个名为your_dog的实例
# class Dog:
#     --snip--

# my_dog = Dog('willie', 6)
your_dog = Dog('Lucy', 3)

print(f"My dog's name is {my_dog.name}.")
print(f"My dog is {my_dog.age} years old.")
my_dog.sit()

print(f"\nYour dog's name is {your_dog.name}.")
print(f"Your dog is {your_dog.age} years old.")
your_dog.sit()

# 即使指定同样名字年龄，Python会根据Dog类创建另一个实例
# 可根据一个类创建任意数量实例
# 条件：储存在不同变量or列表/字典的不同位置


##### 9.2 使用类和实例
### 9.2.1 car类
# 示例：一个表示汽车的类，储存汽车信息，一个汇总这些信息的方法
# cars.py
class Car:
    """一次模拟汽车的简单尝试"""
    
    def __init__(self, make, model, year):
        """初始化描述汽车的属性"""
        self.make = make
        self.model = model
        self.year = year
        
    def get_descriptive_name(self):
        """返回整洁的描述性信息。"""
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()
my_new_car = Car('audi', 'a4', 2019)
print(my_new_car.get_descriptive_name())
# 预告：增加一个随时间变化的属性，用于储存汽车总里程

### 9.2.2 给属性指定默认值
# 创建实例时，有些属性可在方法__init__()中指定默认值，不需要通过形参来定义
# 示例：添加一个初始值总为0的odometer_reading属性，添加一个名为read_odometer的方法
class Car:
    
    def __init__(self, make, model, year):
        """初始化描述汽车的属性"""
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0
    def get_descriptive_name(self):
        """返回整洁的描述性信息。"""
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()
    def read_odometer(self):
        """打印一条指出汽车里程的消息"""
        print(f"This car has {self.odometer_reading} miles on it.")    
my_new_car = Car('audi', 'a4', 2019)
print(my_new_car.get_descriptive_name())
my_new_car.read_odometer()
# 预告：出售时里程数为0不常见，需有方式修改属性的值

### 9.2.3 修改属性的值
# 三种修改属性的值得方式：直接通过实例，通过方法设置，通过方法递增(增加特定的值)
# a.直接修改属性的值
# 通过实例，句点表示法直接访问并设置
# 示例：将里程表读数设置为23
my_new_car.odometer_reading = 23
my_new_car.read_odometer()

# b.通过方法修改属性的值
# 无需直接访问属性。将值传递给方法，由方法在内部更新。
# 示例：update_odometer()方法
class Car:
    def __init__(self, make, model, year):
        """初始化汽车的属性。"""
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0
    def get_descriptive_name(self):
        """返回整洁的描述性信息。"""
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()
    def read_odometer(self):
        """打印一条指出汽车里程的信息。"""
        print(f"This car has {self.odometer_reading} miles on it.")
    # -- snip --
    def update_odometer(self, mileage):
        """将里程表读数设置为指定的值。"""
        self.odometer_reading = mileage

my_new_car = Car('audi', 'a4', '2019')
print(my_new_car.get_descriptive_name())

my_new_car.update_odometer(23)
my_new_car.read_odometer()

# 示例：拓展
class Car:
    def __init__(self, make, model, year):
        """初始化汽车的属性。"""
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0
    def get_descriptive_name(self):
        """返回整洁的描述性信息。"""
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()
    def read_odometer(self):
        """打印一条指出汽车里程的信息。"""
        print(f"This car has {self.odometer_reading} miles on it.")
    # --snip--
    def update_odometer(self, mileage):
        """
        将里程表读数设置为指定的值。
        禁止将里程表数往回调。
        """
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back an odometer!")# 发出警告
            
# c.通过方法对属性的值进行递增
# 有时需要将属性值递增而非设置为全新的值
# 示例：购买二手车，购买到等级期间增加100英里里程，通过方法传递增量并相应增大里程表读数
class Car:
    def __init__(self, make, model, year):
        """初始化汽车的属性。"""
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0
    def get_descriptive_name(self):
        """返回整洁的描述性信息。"""
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()
    def read_odometer(self):
        """打印一条指出汽车里程的信息。"""
        print(f"This car has {self.odometer_reading} miles on it.")
    # --snip--
    def update_odometer(self, mileage):
        """
        将里程表读数设置为指定的值。
        禁止将里程表数往回调。
        """
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back an odometer!")# 发出警告
    # --snip--
    def increment_odometer(self, miles):
        """将里程表读数增加指定的量。"""
        self.odometer_reading += miles# 可修改该方法禁止增量为负值
    
    my_used_car = Car('subaru', 'outback', 2015)
    print(my_used_car.get_descriptive_name)
    
    my_used_car.update_odometer(23_500)
    my_used_car.read_odometer()
    
    my_used_car.increment_odometer(100)
    my_used_car.read_odometer()
    
    
##### 9.3 继承
# 继承父类的所有定义和属性，可以自己定义自己的方法和属性
### 9.3.1 子类的方法__init__()
# 在既有类基础上编写新的类时，通常要调用父类的方法__init__()
# 初始化在其中定义的所有属性，从而让子类包含这些属性
# 示例：模拟电动汽车，特殊的汽车——在创建的Car类的基础上创建新类ElectricCar
# electric_car.py
class Car:
    """一次模拟汽车的简单尝试"""
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0
    
    def get_descriptive_name(self):
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()
    
    def read_odometer(self):
        print(f"This car has {self.odometer_reading} miles on it.")
    
    def update_odometer(self, mileage):
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back an odometer!")
            
    def increment_odometer(self, miles):
        self.odometer_reading += miles
    
class ElectricCar(Car):
    """电动汽车的独特之处"""
    def __init__(self, make, model, year):
        """初始化父类的属性"""
        super().__init__(make, model, year)

my_tesla = ElectricCar('tesla', 'model s', 2019)
print(my_tesla.get_descriptive_name())

### 9.3.2 给子类定义方法和属性
# 示例：添加一个电动车特有的属性（电瓶），储存电瓶容量，描述该属性的方法
class Car:
    """一次模拟汽车的简单尝试"""
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0
        
    def get_descriptive_name(self):
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()
    
    def read_odometer(self):
        print(f"This car has {self.odometer_reading} miles on it.")
        
    def update_odometer(self, mileage):
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print(f"You can't roll back an odometer!")
    
    def increment_odometer(self, miles):
        self.odometer_reading += miles
        
class ElectricCar(Car):
    """电动汽车的独特之处"""
    
    def __init__(self, make, model, year):
        """
        初始化父类的属性。
        再初始化电动车特有的属性。
        """
        super().__init__(make, model, year)
        self.battery_size = 75

    def describe_battery(self):
        """打印一条描述电瓶容量的消息。"""
        print(f"This car has a {self.battery_size}-kwh battery.")

my_tesla = ElectricCar('tesla', 'model s', 2019)
print(my_tesla.get_descriptive_name())
my_tesla.describe_battery()        
    
### 9.3.3 重写父类的方法
# 父类的方法，若不符合子类模拟的实物的行为，可以重写
# 子类中定义一个要重写的父类方法同名的方法——Python将不考虑父类的方法，只关注你在子类中定义的相应方法
# 实例：若Car类有fill_gas_tank()，对电动汽车无意义，要重写，以下为一种重写方式：
class ElectricCar(Car):
    # --snip--
    
    def fill_gas_tank(self):
        """电动车没有油箱。"""
        print("This car doesn't need a gas tank!")

### 9.3.4 将实例用作属性
# class Car:
    # --snip--

class Battery:
    """一次模拟电动车电瓶的简单尝试。"""
    def __init__(self, battery_size = 75):
        """初始化电瓶的属性。"""
        self.battery_size = battery_size
    
    def describe_battery(self):
        """打印一条描述电瓶容量的消息。"""
        print(f"This car has a {self.battery_size}-kwh battery.")
        
class ElectricCar(Car):
    """电动汽车的独特之处"""
    
    def __init__(self, make, model, year):
        """
        初始化父类的属性。
        在初始化电动车特有的属性。
        """
        super().__init__(make, model, year)
        self.battery = Battery()
        
my_tesla = ElectricCar('tesla', 'model s', '2019')

print(my_tesla.get_descriptive_name())
my_tesla.battery.describe_battery()

# 示例：再给Battery类添加一个方法，根据电瓶容量报告汽车的续航历程
# class Car:
    # --snip--
class Battery:
    # --snip--
    def get_range(self):
        """打印一条消息，指出电瓶的续航里程。"""
        if self.battery_size == 75:
            range = 260
        if self.battery_size == 100:
            range = 315
        
        print(f"This car can go {range} miles on a full charge.")

class Electric(Car):
    # --snip--
    my_tesla = ElectricCar('tesla', 'model s', 2019)
    print(my_tesla.get_descriptive_name)
    my_tesla.battery.describe_battery()
    my_tesla.battery.get_range()
    
### 9.3.5 模拟实物
# 此前将方法get_range()放在Battery类中
# 现考虑若要描述一家汽车制造商的整个产品线，也许应将方法移到ElectricCar类中
# 则报告一款汽车的续航里程
# 也考虑：将方法留在Battery类中，但向其传递一个参数，car_model，让方法根据电瓶容量和汽车型号报告续航里程

# 如何表示实物
# 多次重写也不必气馁！


##### 9.4 导入类
# 让文件更简洁：类储存在模块中，在主程序中导入所需模块

### 9.4.1 导入单个类

### 9.4.2 在一个模块中储存多个类
### 9.4.3 从一个模块中导入多个类
### 9.4.4 导入整个模块
### 9.4.5 导入模块中的所有类
### 9.4.6 在一个模块中导入另一个模块
### 9.4.7 使用别名
### 9.4.8 自定义工作流程

##### 9.5 Python标准库
##### 9.6 类编码风格
##### 9.7 小结














# a = [72, 76, 77, 82, 82, 83, 84, 84, 84, 84, 86, 88, 88, 89, 90, 92, 93, 93.8, 94, 94, 98, 98, 99]
# b = [0.000001,  3,  0.0000001,  3,   4, 6,  2,   1,  2,  3, 0.5, 0.5, 1, 1, 1,  2,  3,  0.5,  1,  3,   1,  4,  3]

# # b = [4,  3,  3,  3,   4, 6,  2,   1,  2,  3, 0.5, 0.5, 1, 1, 1,  2,  3,  0.5,  1,  3,   1,  4,  3]
# i = 0
# ave = 0
# sumf = 0
# while (i < 23):
#     sumf += b[i]
#     ave = (ave * (sumf - b[i]) + (a[i] * b[i])) / sumf
#     print(ave)
#     i = i + 1