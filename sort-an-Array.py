# Python3 program to find
#minimum number of swaps
# required to sort an array
 
# Return the minimum number
# of swaps required to sort 
# the array
def minSwaps(arr, N):
     
    ans = 0
    temp = arr.copy()
    temp.sort()
    for i in range(N):
       
        # This is checking whether
        # the current element is
        # at the right place or not
        if (arr[i] != temp[i]):
            ans += 1
 
            # Swap the current element
            # with the right index
            # so that arr[0] to arr[i] 
            # is sorted
            swap(arr, i, 
                 indexOf(arr, temp[i]))
   
    return ans
   
def swap(arr, i, j):
     
    temp = arr[i]
    arr[i] = arr[j]
    arr[j] = temp
     
def indexOf(arr, ele):
    
    for i in range(len(arr)):        
        if (arr[i] == ele):
                return i
    return -1
 
# Driver code
if __name__ == "__main__":
      a = [101, 758, 315, 730, 
           472, 619, 460, 479]
      n = len(a)
       
      # Output will be 5
      print(minSwaps(a, n))
