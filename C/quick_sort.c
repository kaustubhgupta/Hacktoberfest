#include<stdio.h>

void printArray(int array[], int size)
{
  int i;
  for (i=0; i < size; i++)
    printf("%d\t", array[i]);
  printf("\n");
}

void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int array[], int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);
  int j;

  for (j = low; j <= high- 1; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}


void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int pivot_index;
    pivot_index = partition(array, low, high);
    printf("Pivot element is %d \n",array[pivot_index]);
    printf("Array after pivot partitioning : \n");
    printArray(array,8);


    quickSort(array, low, pivot_index - 1);
    quickSort(array, pivot_index + 1, high);
  }
}
int main()
{
  int array[] = {17, 13, 20, 16, 19, 24, 22, 21};
  int n = sizeof(array)/sizeof(array[0]);
  printf("Given array: \n");
  printArray(array, n);
  quickSort(array, 0, n-1);
  printf("Sorted array: \n");
  printArray(array, n);
  return 0;
}

