/#Function to check if the number exists
def search (arr,n,x):
    for i in range (0,n):
        if(arr[i]==x):
            return i;
    return -1;


#Accepting number of terms in an array
num = input("Enter Number of terms:");
#Since input() accepts in string datatype we convert it to int
num=int(num)
arr=[0]*num;
#accept array elements
print("Enter array elements")
for i in range(0,num):
    arr[i]=input();
#Enter number you want to search 
x=input("number to search:");
#pass the array,the number of terms and the number to be searched to the Search function
result = search (arr,num,x)
if(result==-1):
    print("Number not found")
else:
    print("Number found")