#Function to check if the number exists ,the array is sorted
def search (arr,l,r,x):
    if l > r:
        return -1

    mid = (l + r) // 2
    if x == arr[mid]:
        return mid

    if x < arr[mid]:
        return search(arr, l, mid-1,x)
    else:
        return search(arr, mid+1, r,x)  
        
    


#Accepting number of terms in an array
num = input("Enter Number of terms:")
#Since input() accepts in string datatype we convert it to int
num=int(num)
arr=[0]*num
#accept array elements
print("Enter array elements")
for i in range(0,num):
    arr[i]=input()
#Enter number you want to search 
x=input("number to search:")
#pass the array,the number of terms and the number to be searched to the Search function
result = search (arr,0,num-1,x)
if(result==-1):
    print("Number not found")
else:
    print("Number found")