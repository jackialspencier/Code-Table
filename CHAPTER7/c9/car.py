# 9.4.1 导入单个类
# # car.py
# """一个可用于表示汽车的类"""# 模块级字符串

# class Car:
#     """一次模拟汽车的简单尝试"""
    
#     def __init__(self, make, model, year):
#         self.make = make
#         self.model = model
#         self.year = year
#         self.odometer_reading = 0
    
#     def get_descriptive_name(self):
#         """返回整洁的名称"""
#         long_name = f"{self.year} {self.make} {self.model}"
#         return long_name.title()
    
#     def read_odometer(self):
#         """打印一条消息，指出汽车的里程。"""
#         print(f"This car has {self.odometer_reading} miles on it.")
        
#     def update_odometer(self, mileage):
#         """
#         将里程表读数设置为指定的值。
#         拒绝将里程表往回调。
#         """
#         if mileage >= self.odometer_reading:
#             self.odometer_reading = mileage
#         else:
#             print("You can't roll back an odometer!")
    
#     def increment_odometer(self, miles):
#         """将里程表读书增加指定的值。"""
#         self.odometer_reading += miles
    

# 9.4.2 在一个模块中储存多个类
"""一组用于表示燃油汽车和电动汽车的类。"""

class Car:
    """一次模拟汽车的简单尝试。"""
    def __init__(self, make, model, year):
        """初始化汽车的属性"""
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0
    
    def get_descriptive_name(self):
        """返回一个整洁的描述性名称。"""
        long_name = f"{self.year} {self.make} {self.model}"
        return long_name.title()# print(long_name)
    
    def read_odometer(self):
        """打印一条信息，指出汽车的里程。"""
        print(f"This car has {self.odometer_reading} miles on it.")
        
    def update_odometer(self, mileage):
        """
        将里程表读数设置为指定的值。
        拒绝将里程表往回调。
        """
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back the odometer!")
    
    def increment_odometer(self, miles):
        """将里程表读数增加指定的量。"""
        self.odometer_reading += miles
        
class Battery:
    """一次模拟电动汽车电瓶的简单尝试。"""
    
    def __init__(self, battery_size = 75):
        """初始化电瓶的属性。"""
        self.battery_size = battery_size
    
    def describe_battery(self):
        """打印一条描述电瓶容量的消息。"""
        print(f"This car has a {self.battery_size}-kWh battery.")
    
    def get_range(self):
        """打印一条描述电瓶续航里程的消息。"""
        if self.battery_size == 75:
            range = 260
        elif self.battery_size == 100:
            range = 315
        
        print(f"This car can go {range} miles on a full charge.")
    
class ElectricCar(Car):
    """模拟电动汽车的独特之处。"""
    
    def __init__(self, make, model, year):
        """
        初始化父类的属性。
        再初始化电动汽车特有的属性。
        """
        super().__init__(make, model, year)# 注意这个调用方法调用父类的初始化函数
        self.battery = Battery()# 注意这个创建类的调用


# 9.4.4 导入整个模块
# 导入整个模块，再使用句点表示法访问需要的类
# module_name.ClassName



# 9.4.5 导入模块中的所有类
# from module_name import *
# 不推荐的原因：
# 1、开头能表明程序使用了哪些类，有益
# 2、名称冲突（导入的与文件中其他的同名引发难以诊断错误）

# 需要从一个模块导入很多类时
# ——最好导入整个模块
#   module_name.Class 语法访问
# 没有列出所有类——但清楚知道程序哪里使用了导入的模块
# 不会引发名称冲突



# 9.4.6 在一个模块中导入另一个模块
