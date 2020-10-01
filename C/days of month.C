#include<stdio.h>
#include<conio.h>
void main()
{
   int a,y;
   printf"\nEnter any month no:");
   scanf("%d", &a);
   if(a==1||a==3||a==5||a=7||a==8||a==10||a==12)
   {
     prinf("It has 31 days");
     }
   else
   {
     if(a==4||a==6||a==9||a==11)
     {
       printf("It has 30 days");
       }
     else
     {
	if(a=2)
	{
	   printf("Enter year:");
	   scanf("%d", &y);

	   if(y%4=0)
	   {
	    printf("It has 29 days");
	   }
	   else
	   {
	     printf("It has 28 days")

	   }


	}
	else
	{
	 printf("This is not valid input");
	}

   getch();
   }
