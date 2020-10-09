#Function to check if the number exists ,the array is sorted
def search (arr,l,r,x):
    if l > r:
        return -1
    mid = (l + r) // 2
    if x == arr[mid]:
        return mid
    if x < arr[mid]:
        return search(arr, l, mid-1,x)
    return search(arr, mid+1, r,x)  
        
    

num = input("Enter Number of terms:")#Accepting number of terms in an array
num=int(num)#Since input() accepts in string datatype we convert it to int
arr=[0]*num

print("Enter array elements")#accept array elements
for i in range(0,num):
    arr[i]=input()

x=input("number to search:")#Enter number you want to search 

result = search (arr,0,num-1,x)#pass the array,the number of terms and the number to be searched to the Search function
if(result==-1):
    print("Number not found")
else:
    print("Number found")