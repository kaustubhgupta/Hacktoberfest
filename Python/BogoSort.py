import random 

#BogoSort is an extremely inefficient sorting algorithm.
#It is based on the random reordering of the elements.
#It is not used in practice, but it can be used to teach more efficient algorithms.
def bogoSort(array): 
    while (not is_sorted(array)): 
        shuffle(array)
        
#check if it is sorted
def is_sorted(array): 
    for i in range(0, len(array)-1): 
        if (array[i] > array[i+1] ): 
            return False
    return True

#random permutation
def shuffle(array): 
    array_size = len(array) 
    for i in range (0,array_size): 
        r = random.randint(0,array_size-1) 
        array[i], array[r] = array[r], array[i]
