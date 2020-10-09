#Function to check if the number exists
def search (arr,n,x):
    for i in range (0,n):
        if(arr[i]==x):
            return i
    return -1


num = input("Enter Number of terms:")#Accepting number of terms in an array
num=int(num)#Since input() accepts in string datatype we convert it to int
arr=[0]*num

print("Enter array elements")#accept array elements
for i in range(0,num):
    arr[i]=input()

x=input("number to search:")#Enter number you want to search 

result = search (arr,num,x)#pass the array,the number of terms and the number to be searched to the Search functio
if(result==-1):
    print("Number not found")
else:
    print("Number found")