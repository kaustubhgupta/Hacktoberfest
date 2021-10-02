def heapify(array,n,i):
    max=i
    left=i*2+1
    right=i*2+2
    if left<n and array[left]>array[max]:
        max=left
    if right<n and array[right]>array[max]:
        max=right
    if max!=i:
        array[i],array[max]=array[max],array[i]
        heapify(array,n,max)

def heap(array):
    n=len(array)
    for i in range(n//2-1,-1,-1):
        heapify(array,n,i)
    print("heap array ",array)
    for i in range(n-1,0,-1):
        array[i],array[0]=array[0],array[i]
        heapify(array,i,0)

array=list(map(int,input('Enter Tree Elements ').split()))
print(array)
heap(array)
print("Ascending Sort of Given Array is ",array)


#input: 6 7 13 15 11 8 5

#output: 5 6 7 8 11 13 15
