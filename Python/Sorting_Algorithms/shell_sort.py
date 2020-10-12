# Shell sort is an improvement over classic insertion sort
# We do classic insertion but over a particular gap. That is we first take a considerable gap, [length/2]
# And we compare elements in that particular gap to perform insertion sort on those.
# In our final pass, our gap would be one and our algorithm would do a step of classical Insertion Sort.

def ShellSort(array):
    length = len(array)
    gap = length//2

    # Let the initial gap be half of total length
    # We reduce the gap by two in each pass till our gap becomes zero

    while gap > 0:

        # Just like insertion sort, the elements from 0 to gap are considered sorted
        # We need to take care of gap to n

        for i in range(gap, length):
            # The element which we are going to insert at the right place
            x = array[i]
            j = i

            # Shift all elements at the given gap till a position for our element is found
            while j >= gap and array[j-gap] > x:
                array[j] = array[j-gap]
                j -= gap

            # Finally insert the element at its correct position
            array[j] = x
        gap //= 2
    return array


# Driver code to test
a = [5, 3, 8, 19, 4]
print(ShellSort(a))

# The worst case time complexity for this particular gap sequence in O(n2).
# We can improve efficiency with different gap sequences.
# Optimal best known sequence is 1, 4, 10, 23, 57, 132, 301, 701, ...
# OEIS A102549 by Marcin Ciura
