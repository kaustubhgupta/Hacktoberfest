#Function to check if the number exists ,the array is sorted
def search (arr,l,r,x):
    if r>=l:
        mid = (l+(r-l))//3
     #Checks if the  element is present in the array , if yes returns index is sent back to the driver function.
        if arr[mid] == x: 
            return mid 
        #Checks if the number to be searched lies in the first half or the second half of the array
        elif arr[mid] > x: 
            return search(arr, l, mid-1, x) 
        #Checks is the number to be searched lies in the first half or the second half of the array
        else: 
            return search(arr, mid + 1, r, x) 
    else:
        return -1


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