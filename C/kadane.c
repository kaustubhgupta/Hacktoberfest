#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
  
int maxSubArraySum(int a[], int size) 
{ 
  int current_sum=0;
  int best_sum=0;
  for(int i=0;i<size;i++)
  {
    current_sum+=a[i];
    //i will store maximum sum in the best_sum
    if(best_sum<current_sum)
        best_sum=current_sum;
    //if added no. make current_sum<0 then i make current_sum=0 again
    if(current_sum<0)
        current_sum=0;
  }
  return best_sum;
} 
int main() 
{ 
    int n;
    printf("enter the number of elements in the array");
    scanf("%d",&n);
    int a[n+1];
    printf("enter the elements in the array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    int max_sum = maxSubArraySum(a, n); 
    printf("Maximum contiguous sum is %d",max_sum);
    
    return 0; 
} 
/*run the test case
INPUT:
n=5
a[5]={1,2,3,4,5}
OUTPUT:
15
*/
