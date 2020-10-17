import math

def primefactor(num):

    #Check for negative numbers or zero
    if num<=0:
        return

    #Displays the number of 2s as the Prime Factors
    while num%2==0:
        print(2,end=" ")
        num/=2

    #Displays the other Prime Factors of that number
    for i in range(3, int(math.sqrt(num))+1,2):
        while num%i==0:
            print(i,end=" ")
            num/=i

    #Displays the final Prime Factor
    if num>2:
        print(int(num))

def main():
    primefactor(int(input("Enter a number: ")))

if __name__ == '__main__':
    main()