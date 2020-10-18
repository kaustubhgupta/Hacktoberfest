# Bucket Sort is used when input is uniformly distributed over a range
# We first divide the array into small ranges put in buckets
# Each of these buckets are sorted and then all of these are merged together

def bucketSort(array, slots=10):
    # Initialize empty buckets according to number of ranges or slots
    buckets = [[] for _ in range(slots)]

    # Add the element in the corresponding bucket. Here the number of slots
    # is multiplied with element to ensure that floating point values don't give
    # all zeroes.
    for i in array:
        buckets[int(i*slots)].append(i)

    # Sort each bucket separately
    for bucket in buckets:
        # Insertion sort can be used here since it's runtime is based on distance between current and correct position
        for i in range(1, len(bucket)):
            temp = bucket[i]
            j = i - 1
            while j >= 0 and bucket[j] > temp:
                bucket[j + 1] = bucket[j]
                j -= 1
            bucket[j + 1] = temp

    # Combine all buckets
    x = 0
    for bucket in buckets:
        for element in bucket:
            array[x] = element
            x += 1
    return array


# Driver code
a = [0.22, 0.53, 0.12, 0.25, 0.78]
print(bucketSort(a))

# For including negative numbers in the same, the array can be split into positive and neagative arrays
# Convert -ve to +ve by taking absolute value.
# Apply bucket sort to both separately and then combine by putting +ve part after -ve
# Worst case complexity is O(N2)
# Average case complexity is O(N) on uniformly distributed input
