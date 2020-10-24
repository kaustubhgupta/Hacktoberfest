#include <stdio.h>

//to count the swaps
int MinSwaps(int arr[], int size)
{
    int countswap = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int temp, loc = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[loc])
            { //if value is smaller update the loc
                loc = j;
            }
        }
        /*if loc change that means array is unsorted
		and we have to swap the element*/
        if (loc != i)
        {
            temp = arr[loc];
            arr[loc] = arr[i];
            arr[i] = temp;
            ++countswap; //increament the counts
        }
    }
    //return the value of swaps
    return countswap;
}

int main()
{
    int size;
    printf("Enter the size of an array: ");
    scanf("%d", &size);
    int arr[size];
    //run only when size>0
    if (size > 0)
    {
        printf("Enter the elements: ");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
        //for storing the value return from MinSwaps function
        int result = MinSwaps(arr, size);
        //print the result
        printf("%d\n", result);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}