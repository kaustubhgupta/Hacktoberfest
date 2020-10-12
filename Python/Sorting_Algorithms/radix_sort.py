# Radix Sort is an improvement over Counting Sort
# Counting Sort is highly inefficient with large ranges
# Radix sort sorts digit by digit from least to most significant digit.
# It can be imagined as a bucket sort based on place values.

def radixSort(array, base=10):
    # Get the maximum in the array to find the maximum number of digits
    # Since we are sorting digit wise
    m = max(array)

    # Initially we start by sorting the least significant digit
    placeValue = 1

    # We loop till all digits have been sorted
    while m/placeValue > 0:
        # Apply digit wise counting Sort
        # Find the occurence of each digit and store that value
        occurence = [0]*base
        for element in array:
            occurence[int((element/placeValue) % base)] += 1

        # Since occurence array is already sorted by index, the actual position of the element will
        # be the next of sum of all occurences before it
        for i in range(1, base):
            occurence[i] += occurence[i-1]

        temp = [0]*len(array)
        # Traverse array backwards to count down occurences
        for i in range(len(array)-1, -1, -1):
            pos = array[i]/placeValue
            temp[occurence[int(pos % base)]-1] = array[i]
            occurence[int(pos % base)] -= 1

        # Copy temproary array to original one
        for i, val in enumerate(temp):
            array[i] = val

        # The next digit will be the immediate next placevalue [tens, hundreds in the decimal system]
        placeValue *= base

    return array


# Driver code
a = [40, 122, 1, 5, 28, 99]
print(radixSort(a))

# Since radix sort is not a comparison based one, the time complexity is linear
# Worst case: O(d(n+b))
# Where n is the len of array, d is the number of maximum digits and b is the base
