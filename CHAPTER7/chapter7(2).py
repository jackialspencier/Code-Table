current_number=1
while current_number<=5:
    print(current_number)
    current_number += 1#current_number=current_number+1

prompt="Tell me something, and I will repeat it back to you: "
prompt += "\nEnter 'quit' to end the program."
message=""
#while message!='quit':
    #message=input(prompt)
    #print(message)
    
#输入一次后不断运行va每循环一次等待一次输入防止陷入s循环
#输入在陷入循环前vs输入卡在循环过程中
#需要重复进行的不只有打印，输入也是要多次进行的所以在循环内。

#message=input(prompt)
#while message!="quit":
#    print(message)
prompt="Tell me something and I will repeat it back to you."
prompt+="Enter 'quit' to stop the program.q"
message=""
#while message != 'quit':
    #message=input(prompt)
    #if message != 'quit':
    #    print(message)
#7.2.3使用标志
prompt="Tell me aomething and I will repeat it to you."
prompt+="\nEnter 'quit' to stop the program."

active=True
#while active:
    #message=input(prompt)
    
    #if message != 'quit':
        #print(message)
    #else:
        #active=

prompt="\nPlease enter the name of a city you have visited."
prompt+="\nEnter quit to stop the program."

#while True :
    #city=input(prompt)#记得把用户输入的值赋给一个变量。
    
    #if city == 'quit':
     #   break
    #else:
     #   print(f"I'd love to go to {city}!")
#直接再次运行无效？
cities=['Beijing','Shanghai','London','New York','San Francisco']
for city in cities:
    if city == 'London':
        break
    else:
        print(city)
#7.2.5在循环中使用continue
current_number = 0
while current_number<=7:
    if current_number==0:
        current_number+=1
    else:
        current_number+=2
    print(current_number)

current_number=0
while current_number < 10:
    current_number+=1
    if current_number%2==0:
        continue
    else:
        print(current_number)
        
x=1
while x <=5:
    print(x)
    x+=1
    
x=1
while x <= 5:
    print(x)
    x+=1
#练习
#7-4
#prompt="\nEnter a topping of pizza that you want."
#prompt+="\nEnter 'quit' to stop the program."
#topping=" "
#while topping != 'quit':
#    topping=input(prompt)
#    if topping != 'quit':
#        print(f"We will put some {topping} into the pizza.")

prompt="\nEnter a topping that you want to have in your pizza."
prompt+="\nEnter 'quit' to stop the program."    

#active=True
#while active:
#    topping=input(prompt)
#    if topping == 'quit':
#        active=False
#    else:
#        print(f"We will get your pizza some {topping}.")    
    
#prompt="\nEnter a topping you want in your pizza."
#prompt+="\nEnter 'quit' to stop the program."
#先检查决定执行再输入，vs输入后影响执行
#while True:
 #   topping=input(prompt)
  #  if topping == 'quit':
   #     break
  #  else:
  #      print(f"We will add some {topping} to your pizza.")
#7-5
prompt="\nHello. How old are you?"
prompt+="\nEnter 'quit' to stop the program."
age=""
while age != 'quit':
    age=input(prompt)
    if age!='quit':
        age = int(age)#为什么这里非空不可？
        if age < 3:
            print("You are free to get in the cinema.")
        elif age <= 12:
            print("Your ticket to the cinema costs 10 dollars.")
        else:
            print("Your ticket to the cinema costs 15 dollars.")

#prompt="\nHow old are you?"
#prompt+="\nEnter quit to stop the program."

#active=True
#while active:
#    age=input(prompt)
#    if age == 'quit':
#        active=False
#    else:
#        age = int(age)
#        if age < 3:
#            print("Your ticket to the cinema costs $0.")
#        elif age <= 12:
#            print("Your ticket to the cinema costs $10.")
#        else:
#            print("Your ticket to the cinema costs $15.")
            
#prompt="\nHow old are you?"
#prompt+="\nEnter 'quit' to stop the program."

#while True:
#    age = input(prompt)    
#    if age == 'quit':
#        break
#    else:
#        age = int(age)
#        
#        if age < 3:
#            print("\nYou are free to enter the cinema.")
#        elif age <= 12:
#            print("\nA ticket to the cinema for you would cost $10.")
#        else:
#            print("\nA ticket to the cinema for you would cost $15."q)