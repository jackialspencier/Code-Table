#7.1函数input()的工作原理
#message=input("Tell me something, and I will repeat it back to you: ")
#print(message)

#name=input("Please enter your name: ")
#print(f"Hello, H{name}!")

#prompt="If you tell us who you are, we can personalize the messages you see."
#prompt+="\nWhat is your name?"
#name=input(prompt)#变量直接上。
#print(f"\nHello, {name}!")

#prompt="If you tell us who you are, we can personalize the information we offer to you."
#prompt+="\nWhat is your name? "
#name=input(prompt)
#print(f"\nHello, {name}!")#运行起来补加的在当次运行不会体现。

#height=input("How tall are you, in inches? ")
#height=int(height)
#if height>=48:
 #   print("\nYou are tall enough to ride!")
#else:
 #   print("\nYou'll be able to ride when you're a lttle older.")
 
#number=input("Enter a number, and I'll tell you if it's even or odd: ")
#number=int(number)
#if number % 2 == 0:
 #   print("It's even.")
#else:
 #   print("It's odd.")
 
#练习
#7-1
#car=input("What brand of car do you want to borrow? ")
#print(f"\nLet me see if I can find you a {car}.")
#7-2
#guests=input("How many people do you plan to have dinner together with?")
#guests=int(guests)
#if guests > 8:
#    print("Sorry, I'm afraid we don't have a table available for you.")
#else:
#    print("We have tables available for you.")
#7-3
number=input("Enter a number and I'll tell you if it can be divided by 10.")#???咋表达啊这些。
number=int(number)
if number % 10 == 0 :
    print("It can be divided by 10.")
else:
    print("It ca not be divided by 10.")