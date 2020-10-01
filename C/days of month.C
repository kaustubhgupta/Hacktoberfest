#include<stdio.h>
#include<conio.h>

int main()
{
   int month,year;
   printf("\n Enter any month no:");
   scanf("%d", &month);
   if(month==1||month==3||month==5||month=7||month==8||month==10||month==12)
   {
     printf("It has 31 days");
   }
   else
   {
     if(month==4||month==6||month==9||month==11)
     {
       printf("It has 30 days");
     }
     else
     {
	if(a==2)
	{
	   printf("Enter year:");
	   scanf("%d", &year);

	   if(y%4==0)
	   {
	    printf("It has 29 days");
	   }
	   else
	   {
	     printf("It has 28 days");

	   }
	}
	else
	{
	 printf("This is not a valid input");
	}
     }
   }

   return 0;
   }
