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
    """一次模拟电动车电瓶的简单尝试。"""
    def __init__(self, battery_size = 75):
        """初始化电瓶的属性。"""
        self.battery_size = battery_size
    
    def describe_battery(self):
        """打印一条描述电瓶容量的消息。"""
        print(f"This car has a {self.battery_size}-kwh battery.")
        
    # --snip--
    
    my_tesla = ElectricCar('tesla', 'model s', 2019)
    print(my_tesla.get_descriptive_name)
    # my_tesla.battery.describe_battery()
    my_tesla.battery.get_range()
    