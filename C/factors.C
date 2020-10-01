#include<stdio.h>
#include<conio.h>

int main()
{
    int a,b,i;
    pritf("Enter a no:");
    scanf("%d", &a);
    for(i=1;i<=a;i++)    /* This function shows factorization */
    {
      if(a%i=0)
      {
         b=a/i;
         printf("%d\n",b);
      }

    }
   return 0;
 }
