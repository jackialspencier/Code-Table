#7.3使用while循环处理列表和字典
#7.3.1在列表之间移动元素
unconfirmed_users=['alice','brian','candance']
confirmed_users=[]
while unconfirmed_users:
    current_user=unconfirmed_users.pop()
    print(f"Verifying user: {current_user.title()}")
    confirmed_users.append(current_user)
print("\nThe following users have been confirmed:")
for confirmed_user in confirmed_users:
    print(confirmed_user.title())

pets=['dog','cat','dog','goldfish','cat','rabbit','cat']
print(pets)
while 'cat' in pets:
    pets.remove('cat')
print(pets)
#7.3.3使用用户输入来填充字典
# responses={}
# prompt1="What is your name?"
# prompt2="Which mountain would yoou like to climb someday?"
# prompt3="Would you let anothor person to answer the question?"

# polling_active=True

# while polling_active:
#     name=input("prompt1")
#     response=input(prompt2)
#     triger=input(prompt3)
#     if triger.lower()=='no':
#         polling_active=False
#自写代码与书本给出实例对比：1将用户输入的信息储存在字典里。2合适地打印出获得的信息。

# responses={}
# polling_active=True

# while polling_active:
#     name=input("What is your name?")#别忘了input（）啊啊啊！！！
#     response=input("Which mountain would you like to climb?")
#     responses[name]=response
#     repeat=input("Would you like to let another person to answer the question?")
#     if repeat=='no':
#         polling_active=False
        
# print("\n--- Poll Results ---")
# for name,reponse in responses.items():
#     print(f"{name.title()} would like to go to climb {response}.")    
#练习
#7-8熟食店
sandwich_orders=['tuna sandwich', 'beef sandwich', 'cheese andwich']
finished_sandwiches=[]
while sandwich_orders:
    sandwich_making=sandwich_orders.pop()
    print(f"I made your {sandwich_making}.")
    finished_sandwiches.append(sandwich_making)
print("The following sandwiches are finished:")
for finished_sandwich in finished_sandwiches:
    print(finished_sandwich)
    
print(sandwich_orders)
#7-9五香烟熏牛肉卖完了
sandwich_orders=['pastrami', 'beef sandwich', 'pastrami', 'chicken sandwich', 'pastrami', 'cheese sandwich']
print("Sorry, the pastrami has been sold out.")
while 'pastrami' in sandwich_orders:
    sandwich_orders.remove('pastrami')
print(sandwich_orders)

#7-10梦想的度假胜地
places_of_interest=[]
prompt="If you could visit a one place in the world, where would you go?"
while True:
    place_of_interest=input(prompt)
    places_of_interest.append(place_of_interest)
    repeat=input("Would you like to let another person to answer the question?")
    if repeat == 'no':
        break
print("\nThe following places are the holiday resorts that our users want to visit:")
for place in set(places_of_interest):
    print(place)
    

    

    
    