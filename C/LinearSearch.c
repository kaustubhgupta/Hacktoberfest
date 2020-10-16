// Linear search is also known as Sequential search.
// Linear search: Start from the leftmost element of arr[] and one by one compare the element to be searched with each element of arr[].(A loop is used).Here one doesn't have to sort the array.
// Time Complexity: O(n)

#include <stdio.h>

int LinearSearch(int arr[], int num, int numSearch) // num is no of elements in the array and numSearch is the element to be searched in the array
{
    int i;
    for(i = 0; i < num; i++){
        if (arr[i] == numSearch)
            return i;
    }
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
    int numSearch = 50;
    int num = sizeof(arr) / sizeof(arr[0]);
    int result = LinearSearch(arr, num, numSearch);
    (result == -1) ? printf("Element is not present in the array") : printf("Element is present at index %d", result);
    
    return 0;
}

