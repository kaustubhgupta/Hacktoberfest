#include<stdio.h>
    int main()
{
    int n,k;
    long int aray[20];

    printf("Enter the number range:\n");
    scanf("%d",&n);
    aray[0]=-1;
    aray[1]=1;
    printf("\n FIBONACCI SERIES: \n");
    for(k=2;k<=n+1;k++)
    {
      aray[k]=aray[k-1]+aray[k-2];
      printf(" %ld",aray[k]);
    }
  return 0;
}