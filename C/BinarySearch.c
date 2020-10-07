// Binary Search: Search a sorted array by repeatedly dividing the search interval in half.
// Time Complexity: O(nlogn)

#include <stdio.h>

int BinarySearch(int arr[], int low, int high, int numSearch) // low is the first index of the array and high is the last index of the array and numSearch is the number to be searched
{
    if(high >= low){
        int mid = low + (high-1) /2;

        // If the element to be searched is present at the mid itslef 
        if(arr[mid] == numSearch)
            return mid;

        // If the element to be searched is smaller than the mid element, then it can only be present in left subarray
        if(arr[mid] > numSearch)
            return BinarySearch(arr, low, mid-1, numSearch);

        // If the element to be searched is greater than the mid element, then it can only be present in right subarray
        if(arr[mid] < numSearch)
            return BinarySearch(arr, mid+1, high, numSearch);
    }

    // When the element to be searched is not present in the array
    return -1;
}

int printArray(int arr[], int num)
{
   int i;
   for(i = 0; i < num; i++){
       printf("%d", arr[i]); 
    printf("\n");
   } 
}

int main()
{
    int arr[] = {2, 3, 5, 15, 40};
    int numSearch = 15;
    int num = sizeof(arr) / sizeof(arr[0]);
    int result = BinarySearch(arr, 0, num-1, numSearch);
    (result == -1) ? printf("Element is not present in the array") : printf("Element is present at index %d", result); 
    
    return 0;
}
