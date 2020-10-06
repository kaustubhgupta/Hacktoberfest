#include <stdio.h>
#include <stdlib.h>

int main(){
int N; //Number of elements in the array
printf("\n Enter the number of elements in the array\n");
scanf("%d",&N);
int *arr=malloc(N*sizeof(*arr)); //Dynamic creation of an Integer array of Size N
printf("\n Enter the elemnts of the array\n");
for(int i=0;i<N;i++){
  scanf("%d",&arr[i]); //Inputting the elements of array
}
printf("\n Original Array\n"); //Printing the original array
for(int i=0;i<N;i++){
  printf("%d ",arr[i]);
}
int temp; //Temporary variable used for swapping later
for(int i=0;i<N-1;i++){ //Sorting process begins
  for(int j=0;j<N-i-1;j++){
    if(arr[j]>arr[j+1]){ //Checking if a number at the previous index is greater than the number at its next,if so, swapping takes place
      temp=arr[j];
      arr[j]=arr[j+1];
      arr[j+1]=temp;
    }
  }
}
printf("\n Sorted Array\n"); //Printing sorted array
for(int i=0;i<N;i++){
  printf("%d ",arr[i]);
}
}
