#Sieve Of Eratosthenes
#Author - https://www.github.com/yatocodes
'''
About - The programme is created for the purpose of calculating
prime numbers; between two of the user given numbers.
'''

print("Welcome To Sieve Of Eratosthenes \n")
print("Plese Dont't Enter 1 as Starting Number\n")

starting_num = int(input("Enter the starting number :  "))
ending_num = int(input("Enter the ending number :  "))

for numbers in range(starting_num, ending_num+1):
    if(starting_num>1):
        for i in range(2,numbers):
            if(numbers%i)==0:
                break
        else:
            print(numbers)
            


       


