if __name__=="__main__":

    """

    Example:
    Enter the number of digits to be sorted:5
    33
    25
    7
    7
    23
    Sorted array is [7, 7, 23, 25, 33]
    
    """

    #  Get number of elements 
    size=int(input('Enter the number of digits to be sorted:'))
     

    #  get elements in a list by iteration
    list=[]
    for i in range(0,size ): 
        e = int(input()) 
        list.append(e)  # add the element to list

    #  Calculating the maximum value
    max=0
    for i in range(0,len(list) ): 
        if(list[i]>max):
            max=list[i]

    #  Calculating the minimum value
    min=0
    for i in range(0,len(list)): 
        if(list[i]<min):
            min=list[i]
    element_range = max - min + 1

    #  Setting all elements to zero
    freq = [0 for _ in range(element_range)] 
    listsorted = [0 for _ in range(len(list))] 
  
    #  Count storing
    for i in range(0, len(list)): 
        freq[list[i]-min] += 1
  
    #  Position elements 
    for i in range(1, len(freq)): 
        freq[i] += freq[i-1] 
  
    #  Setting to output array 
    for i in range(len(list)-1, -1, -1): 
        listsorted[freq[list[i] - min] - 1] = list[i] 
        freq[list[i] - min] -= 1
  
    print("Sorted array is " + str(listsorted)) 
     
