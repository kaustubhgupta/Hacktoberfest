import math
from builtins import print

print ("*************************")

op = input("Enter the operator: ").lower()

# functions of the calculator
if op == "+":
    firstNumber = float(input("Enter the first number: "))
    secondNumber = float(input("Enter the second number: "))
    print (firstNumber, "+", secondNumber, "=", firstNumber + secondNumber )
elif op == "-": 
    firstNumber = float(input("Enter the first number: "))
    secondNumber = float(input("Enter the second number: "))
    print (firstNumber, "-", secondNumber, "=", firstNumber - secondNumber )
elif op == "*":
    firstNumber = float(input("Enter the first number: "))
    secondNumber = float(input("Enter the second number: "))
    print (firstNumber, "*", secondNumber, "=", firstNumber * secondNumber )
elif op == "/":
    firstNumber = float(input("Enter the first number: "))
    secondNumber = float(input("Enter the second number: "))
    print (firstNumber, "/", secondNumber, "=", firstNumber / secondNumber )
elif op == "^":
    firstNumber = float(input("Enter the first number: "))
    secondNumber = float(input("Enter the second number: "))
    print (firstNumber, "^", secondNumber, "=", firstNumber ** secondNumber )
elif op == "r":
    firstNumber = float(input("Enter the first number: "))
    secondNumber = float(input("Enter the second number: "))
    print (firstNumber, "root", secondNumber, "=", secondNumber ** (1 / firstNumber) )
elif op == "%":
    firstNumber = float(input("Enter the first number: "))
    secondNumber = float(input("Enter the second number: "))
    print(firstNumber, "%", secondNumber, "=", firstNumber % secondNumber )
elif op == "!":
    secondNumber = float(input("Enter the number: "))
    theNumber = firstNumber = secondNumber 
    secondNumber = 1
    while firstNumber > 1:
        secondNumber *= firstNumber 
        firstNumber = firstNumber - 1  
    print ("n!(", theNumber, ")=", secondNumber )
elif op == "sin":
    secondNumber = float(input("Enter the number: "))
    print ("sin(", secondNumber, ")=", math.sin(secondNumber ))
elif op == "cos":
    secondNumber = float(input("Enter the number: "))
    print ("cos(", secondNumber, ")=", math.cos
    (secondNumber ))
elif op == "tan":
    secondNumber = float(input("Enter the number: "))
    print ("tan(", secondNumber, ")=", math.tan(secondNumber ))
elif op == "pie" or op == "pi":
    print ("Pie =", math.pi)
elif op == "e":
    print = ("E =", math.e)
elif op == "ln":
    secondNumber = float(input("Enter the number: "))
    print ("ln(", secondNumber , ")= ", math.log(secondNumber))
else:
    print ("incorrect operator") 