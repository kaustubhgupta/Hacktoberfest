#include<stdio.h>
int main()    
{    
 int a=0,b=1,c,i,n;    
 printf("Enter the number of terms in fibonacci series:");    
 scanf("%d",&n);    
 printf("Fibonacci series");
 printf("\n%d %d",a,b);
 for(i=2;i<n;++i)
 {    
  c=a+b;    
  printf(" %d",c);    
  a=b;    
  b=c;    
 }  
 }  
