#include <stdio.h>
int main()
{
  int a,b,choice;
  long long result = 1;
      int i,fact=1;
  printf("\n**********welcome*********\n");
  printf("TO MY CALCULATOR\n");
  printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.power of numbers\n6.Factorial of a number\n");
  printf("what do you want to do: ");
  scanf("%d",&choice);
  switch (choice)
  {
  case 1:
    printf("number 1: ");
    scanf("%d",&a);
    printf("number 2: ");
    scanf("%d",&b);
    printf("%d + %d = %d\n",a,b,a+b);
    break;
  case 2:
    printf("number 1: ");
    scanf("%d",&a);
    printf("number 2: ");
    scanf("%d",&b);
    printf("%d - %d = %d\n",a,b,a-b);
    break;
  case 3:
    printf("number 1: ");
    scanf("%d",&a);
    printf("number 2: ");
    scanf("%d",&b);
    printf("%d * %d = %d\n",a,b,a*b);
    break;
  case 4:
    printf("number 1: ");
    scanf("%d",&a);
    printf("number 2: ");
    scanf("%d",&b);
    printf("%d / %d = %d\n",a,b,a/b);
    break;
 case 5:
    printf("Enter a base number: ");
    scanf("%d",&a);
    printf("Enter an exponent: ");
    scanf("%d",&b);
    while (b!=0){
      result *= a;
      --b;
    }
    printf("Answer = %lld\n", result);
    break;
 case 6:
    printf("number : ");
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
      fact=fact*i;
    }
    printf("Factorial of %d is: %d\n",a,fact);
    break;
 }
}
