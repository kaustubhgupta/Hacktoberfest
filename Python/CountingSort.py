if __name__=="__main__":

    #  Get number of elements 
    size=int(input('Enter the number of digits to be sorted:'))
     
    #  get elements in a list by iteration
    ls=[]
    for i in range(0,size ): 
        e = int(input()) 
        ls.append(e)  # add the element to list

    element_range = max(ls) - min(ls) + 1

    #  Setting all elements to zero
    freq = [0 for _ in range(element_range)] 
    listsorted = [0 for _ in enumerate(ls)] 
  
    #  Count storing
    for i,j in enumerate(ls): 
        freq[ls[i]-min(ls)] =freq[ls[i]-min(ls)]+ 1
  
    #  Position elements 
    for i in range(1, len(freq)): 
        freq[i] += freq[i-1] 
  
    #  Setting to output array 
    for i in range(len(ls)-1, -1, -1): 
        listsorted[freq[ls[i] - min(ls)] - 1] = ls[i] 
        freq[ls[i] - min(ls)] -= 1
  
    print("Sorted array is " + str(listsorted)) 
     
