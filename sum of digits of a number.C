#include<stdio.h>
void main()
{
  int a,b;
  printf("Enter a no:");
  scanf("%d", &a);
  for(a!=0)
   {
   b=a%10;
   sum=sum+b;
   a=a/10;
   }
   printf("Sum of digits is %d",sum);
}
