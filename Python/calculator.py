#calculator

input1 = int(input("Enter the first number!"))
input2 = input("Enter an operator: +, -, *, /")
input3 = int(input("Enter the second number!"))
answer = ""
if input2 == ("+"):
    answer = input1 + input3
elif input2 == ("-"):
    answer = input1 - input3
elif input2 == ("*"):
    answer = input1 * input3
elif input2 == ("/"):
    answer = input1 / input3
else:
    print("Sorry, please enter a valid input and try again.")


print (answer)
