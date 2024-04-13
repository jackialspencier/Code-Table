bicycles=['trek','cannondale','redline','specialized']
print(bicycles)
print(bicycles[0])
print(bicycles[0].title())
print(bicycles[2])
print(bicycles[1])
print(bicycles[3])
print(bicycles[-1])
print(bicycles[-3])
message=f"{bicycles[0].title()} is a kind of biycles."
print(message)
message=f"My first bicycle was a {bicycles[0].title()}."#拼写message not massage
print(message)
#练习
names=['Lily','Julia','Maria']
print(names[0])
print(names[1])
print(names[2])
message1=f"Hello, {names[0]}. How is everything going ?"
message2=f"Hello, {names[1]}. How is everything going ?"
message3=f"Hello, {names[2]}. How is everything going?"
print(message1)
print(message2)
print(message3)
commute=['walk','bike','bus','motorcycle','car']
claim1=f"I think going out by {commute[0]}ing is good for my health."
claim2=f"Ride a {commute[1]} out is fit and convenient."
claim3=f"I want to register a card for {commute[2]}."
claim4=f"I would like to own a Honda {commute[3]}"
claim5=f"Driving a {commute[4]} can be fast unless there is a traffic jam."
print(claim1)
print(claim2)
print(claim3)
print(claim4)
print(claim5)
motorcycles=['honda','yamaha','suzuki']
print(motorcycles)
motorcycles[0]='ducati'
print(motorcycles)
motorcycles=['honda','yamaha','suzuki']
motorcycles.append('ducati')
print(motorcycles)
motorcycles=[]
motorcycles.append('honda')
motorcycles.append('yamaha')
motorcycles.append('suzuki')
print(motorcycles)
motorcycles.insert(0,'ducati')
print(motorcycles)
motorcycles.insert(2,'yady')
print(motorcycles)

motorcycles=['honda','yamaha','suzuki']
print(motorcycles)
del motorcycles[0]
print(motorcycles)
motorcycles.insert(0,'honda')
del motorcycles[1]
print(motorcycles)

motorcycles=['honda','yamaha','suzuki']
print(motorcycles)
popped_motorcycles=motorcycles.pop()
print(motorcycles)
print(popped_motorcycles)

motorcycles=['honda','yamaha','suzuki']
last_owned=motorcycles.pop()
print(f"The last bicycle I owned was a {last_owned.title()}")

message=motorcycles
print(message)

message="print"
print(message)

motorcycles=['honda','yamaha','suzuki']
first_owned=motorcycles.pop(0)
print(f"The first bicycle I owned was a {first_owned.title()}.")

motorcycles=['honda','yamaha','suzuki','ducati']
too_expensive='ducati'
motorcycles.remove(too_expensive)#也可以替换为‘ducati’
print(motorcycles)
print(f"\nA {too_expensive.title()} is too expensive for me.")

#练习3.2
man_invited=['Parker','Sun','Kai']
print(f"Please come for a dinner on May 16th, {man_invited[0]}.")
print(f"Please come to my home to have a dinner on May 18th, {man_invited[1].title()}.")
print(f"Would you like to have a dinner with me on May 23th, {man_invited[2].title()}?")
cannot_come='Parker'
print(f"{cannot_come.title()} has a task to do taht night.")
man_invited.remove(cannot_come)
man_invited.insert(0,"Emily")
print(f"{man_invited[0]}, please come to have a dinner with me.")
print(f"Would you like to have dinner with me, {man_invited[1].title()}?")
print(f"Would you like to have a dinner with me, {man_invited[2]}?")
print("I've found a much larger table for more friends to have dinner together!")
man_invited.insert(0,"Hardison")
man_invited.insert(2,'Spencer')
man_invited.append('Ross_Micheal_Norlan')#非变量别忘了引号！！！
print(f"{man_invited[0]}, I would like to invite you come and have a dinnwe with me.")
print(f"{man_invited[1]}, why don't you come and have dinner with me if you are not busy?")
print(f"{man_invited[2]}, please come and have dinner with me.")
print(f"{man_invited[3].title()}, I hope you would come to have dinner with me if possible.")
print(f"{man_invited[4].title()},I hope you would be willing to have dinner with me.")
print(f"{man_invited[5].title()}, I wonder if you would have time to have a dinner with me.")
print("I'm so sorry that my ordered table would not arrive in time and I can only invite two guests.")
print(man_invited)
popped_guest1=man_invited.pop()
popped_guest2=man_invited.pop(1)
popped_guest3=man_invited.pop(1)
popped_guest4=man_invited.pop(2)
print(f"{man_invited[0].title()},I sincerely hope that you can still have a dinner with me.")
print(f"{man_invited[1]}, I am still looking forward to your attendance.")
del man_invited[0]
del man_invited[0]
print(man_invited)



cars=['bmw','audi','toyota','subaru']
cars.sort()
print(cars)
cars.sort(reverse=True)
print(cars)
print("Here is the original list:")
print(cars)
print("\nHere is the sorted list:")
print(sorted(cars,reverse=True))
print("\nHere is the sorted list")
print(sorted(cars))
print("\nHere is the original list:")
print(cars)

cars=['bmw','audi','toyata','subaru']
print(cars)
cars.reverse()
print(cars)
cars.reverse()
print(cars)
print(len(cars))
print(cars[3])


magicians=['alice',"david",'carolina']
for magician in magicians:
    print(magician)
for magician in magicians:
    print(f"{magician.title()},that was a great trick!")
    print(f"I can't wait to see your next trick,{magician.title()}.\n")
print("THank you, everyone. That was a great magic show!")

for magician in magicians:
             print(magician)
message="Hello, Python world!"
print(message)

magicians=['alice','david','carolina']
for magician in magicians:
    print(f"{magician.title()}, that was a great trick!")
    print(f"I can't wait to your next show, {magician.title()}.\n")
    print("Thank you, everyone, that was g great magic show!")
    
pizzas=['spicy pizza','fruit pizza','meat pizza']
#字符串是可以有空格哒。
for pizza in pizzas:
    print(pizza)
for pizza in pizzas:
    print(f"I like {pizza}.")
#别忘了句号，别忘了逗号，别忘了冒号，别忘了字符串的引号。
#执行for循环时，其下每个操作执行一遍再循环，不是每个对第一个操作循环完再对第二个操作循环。
print("I really love pizzas!")

animals=['dog','cat','mouse']
for animal in animals:
    print(animal)
for animal in animals:
    print(f"A {animal} would make a perfect pet.\n")
print("All of these animals make a great pet!")

for value in range(1,5):
    print(value)
for value in range(1,6):
    print(value)
for value in range(6):
    print(value)
    
numbers=list(range(1,6))
print(numbers)

even_numbers=list(range(2,11,2))
print(even_numbers)

even_numbers=list(range(2,10,2))
print(even_numbers)
#注意变量名的拼写。

squares=[]
#创建空列表
for value in range(1,11):
#遍历1-10的值
    square=value**2
#计算平方
    squares.append(square)
#将计算结果（平方）赋给变量square     (获取元素值加到列表中，给予（空）列表相应元素值（以打印）)
#为啥空一行？习惯？通俗？
print(squares)
#循环结束后，打印列表

squares=[]
#创建空列表
for value in range(1,11):
    squares.append(value**2)
#获取需要元素值并加到列表中
print(squares)

squares=[value**2 for value in range(1,11)]
print(squares)
#指定列表，获取元素值（对对象用表达式计算），附加

numbers=list(range(1,2_1))
for number in numbers:
    print(number)
    
numbers=list(range(1_000_001))
#到一百万不是10000000，是1000001！！！！！

print(min(numbers))
print(max(numbers))
print(sum(numbers))

odd_numbers=list(range(1,21,3))
#第三个参数不是3是2！！！
odd_numbers=list(range(1,21,2))
#第二个参数为20就ok，21更方便平时的注意（加一弥补差一行为）。但是19应该不符合本题题意。
for odd_number in odd_numbers:
    print(odd_number)

digits=list(range(3,31,3))
for digit in digits:
    print(digit)

tri_numbers=[value**3 for value in range(1,11)]
print(tri_numbers)

tri_values=[]
for value in range(1,11):
    tri_value=value**3
    tri_values.append(tri_value)
print(tri_values)

tris=[value**3 for value in range(1,11)]
print(tris)

players=['charles','martina','micheal','florence','eli']
print(players[0:3])
print(players[1:4])
print(players[:4])
print(players[2:])
print(players[-3:])
print(players[1:3:2])
#注意列表名。注意第一个和第二个之间冒号不变。而第二个和第三个之间也应该是冒号。
print(players[1:4:2])

print("Here are the first three players in my team:")
for player in players[0:3]:
    print(player.title())

print("THe first three terms in the list are")
for term in players[0:3]:
    print(term.title())
#注意item和term.
print("THree items fr:om the middle in the list are")
for item in players[1:4]:
    print(item.title())
print("The last three items in the list are")
for item in players[-3:]:
    print(item.title())
#如果第二个参数输入-1的话，那么最后一个元素不会被打印出来。
#影响造成后一个数差一行为的不是编号的方式负数还是正数从0，而是指令含义“停止于”。
my_foods=['pizza','falafel','carrot cake']
friend_foods=my_foods[:]
print("My favorite foods are:")
print(my_foods)
print("\nMy fried's favorite foods are")
print(friend_foods)
my_foods=['pizza','falafel','carrot cake']
friend_foods=my_foods[:]
#本来只是提取一个切片（例如在最后再print（my_foods[:]）），但是赋给了一个新的列表变量标签，赋予进了这个标签指向的空间？所以“创建”了副本。
my_foods.append('cannoli')
friend_foods.insert(3,'ice_cream')
#准备插入的元素别忘了用引号引起来
print("My favorite foosd are")
print(my_foods)
print("My friend's favorite foods are")
print(friend_foods)


#不用切片创建副本的情况示例
my_foods=['pizza','falafel','carrot_cake']
friend_foods=my_foods
my_foods.append('ice_cream')
friend_foods.append("cannnoli")
print("My favorite foods are")
print(my_foods)
print("My friend's favorite foods are")
print(friend_foods)

my_pizzas=['fruit pizza','spicy pizza','meat pizza']
friend_pizzas=my_pizzas[:]
my_pizzas.append("sweet pizza")
friend_pizzas.append("salty pizza")
print("My favorite pizzas are:")
for pizza in my_pizzas:
    print(pizza)
print("\nMy friend's favorite pizzas are:")
for pizza in friend_pizzas:
    print(pizza)
    
my_foods=['pizza','falafel','carrot_cake']
friend_foods=my_foods[:]
my_foods.append('calonni')
friend_foods.append('ice_cream')
print("My  favorite foods are:")
for food in my_foods:
    print(food)
print("\nMy frined's favorite foods are")
for food in friend_foods:
    print(food)
    
dimensions=(200,50)
print(dimensions[0])
print(dimensions[1])
#dimensions[0]=250
print(dimensions[0])
#my_tt=(3)
#print(my_tt[0])
#my_tt[0]=4
#print(my_tt)
#my_t=(3,)
#print(my_t[0])
print(dimensions)
print("Original dimensions: ")
for dimension in dimensions:
    print(dimension)
dimensions=(9150,500)
print("\nModified dimensions:")
for dimension in dimensions:
    print(dimension)
    
#练习4-13
foods=('vegetables','french chips','hamburger','soup','cola')
for food in foods:
    print(food)
#food[1]='ice-cream'，还有，str是个啥啊所以
#foods=('ice-cream',)
#foods[0]='vegetables'#这个对应显示的是tuple所以str出现不是字符串的缘故？
foods=('vegetables','french chips','hamburger','potato','juice')
for food in foods:
    print(food)
