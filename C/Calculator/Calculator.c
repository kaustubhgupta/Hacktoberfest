//By Shreya Bera
//https://github.com/shreya-bera
#include<stdio.h>
#include<math.h>
int main()
{
    float num1,num2, result=1,total=0;
    float a, b, c, discriminant, root1, root2, realPart, imagPart,number;
    int num3,op, modulus,x,y, k=0,n;
    printf("\n*******WELCOME TO C CALCULATOR*******\n ");
    printf("\n**************MENU**************\n");
    printf("1. Addition \n");
    printf("2. Subtraction \n");
    printf("3. Multiplication \n");
    printf("4. Division \n");
    printf("5. Modulus\n");
    printf("6. Power \n");
    printf("7. Factorial \n");
    printf("8. Square root \n");
    printf("9. nth root \n");
    printf("10. Natural Logarithm \n");
    printf("11. Roots of quadratic equation \n");
    printf("\nEnter the Number of the operation to be performed:\n ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("\nEnter the number of elements you want to add:");
        scanf("%d",&n);
        printf("Please enter %d numbers one by one: \n",n);
        while(k<n)
        {
            scanf("%f",&number);
            total=total+number;
            k=k+1;
        }
        printf("Sum of %d numbers = %.2f \n",n,total);
        break;
    case 2:
        printf("Enter the Numbers:\n");
        scanf("%f%f",&num1,&num2);
        result=num1-num2;
        printf("The result is%.2f",result);
        break;
    case 3:
        printf("Enter the Numbers:\n");
        scanf("%f%f",&num1,&num2);
        result=num1*num2;
        break;
    case 4:
        printf("Enter the Numbers:\n");
        scanf("%f%f",&num1,&num2);
        result=num1/num2;
        printf("The result is%.2f",result);
        break;
    case 5:
        printf("Enter the Numbers:\n");
        scanf("%d%d",&x,&y);
        modulus =x%y;
        printf("The result is %d",modulus);
        break;
    case 6:
        printf("\nEnter two numbers to find the power \n");
        printf("Number: ");
        scanf("%f",&num1);
        printf("Power : ");
        scanf("%f",&num2);
        result=pow(num1,num2);
        printf("The result is%.2f",result);
        break;
    case 7:
        if(num3>0)
        {
            printf("\nEnter the number to find its factorial\n");
            printf("Number:");
            scanf("%d",&num3);
            for(int i=1;i<=num3;i++)
            result=result*i;
            printf("The result is %d",result);
        }
        else
        {
            printf("\nFor finding factorial the number should be positive and integer value.\n ");
        }
        break;
    case 8:
        printf("\nEnter the number to find it's square root :x^2 \n");
        printf("Number: ");
        scanf("%f",&num1);
        result=sqrt(num1);
        printf("The result is%.2f",result);
        break;
    case 9:
        printf("\nEnter a number to find n th root");
        printf("Number:");
        scanf("%f",&num1);
        printf("\nEnter a number to set n : ");
        scanf("%f",&num2);
        result = pow(num1,1/num2);
        printf("The result is%.2f",result);
        break;
    case 10:
        printf("\nEnter a number to find its Logarithm value\n");
        printf("Number:");
        scanf("%f",&num1);
        result=log(num1);
        printf("The result is %.2f",result);
        break;
    case 11:
        printf("\nEnter coefficients a, b and c: \n");
        scanf("%f %f %f", &a, &b, &c);

        discriminant = b * b - 4 * a * c;
        discriminant = b * b - 4 * a * c;
        discriminant = b * b - 4 * a * c;
        if (discriminant > 0)
            {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
            }
        else if (discriminant == 0)
            {
            root1 = root2 = -b / (2 * a);
            printf("root1 = root2 = %.2lf\n", root1);
            }
        else
            {
            realPart = -b / (2 * a);
            imagPart = sqrt(-discriminant) / (2 * a);
            printf("root1 = %.2f+%.2fi and root2 = %.2f-%.2fi\n", realPart, imagPart, realPart, imagPart);
            }
        break;
      }

}
