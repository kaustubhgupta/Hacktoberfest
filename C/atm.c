#include<stdio.h>
int withdraw();
int balance();
int deposit();
int amt=0;
int main()
{
	int pin, check=1234;
	int ch;
	printf("Enter your PIN number \n");
	scanf("%d",&pin);
	if(pin==check)
	{
		printf(" PIN Matched \n");
		while(1)
		{
			printf("-----------------------------------------------\n");
			printf(" \n 1. Withdraw \t 2. Deposit \t 3. Balance \n");
			printf("\n Enter your choice \n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: withdraw(); break;
				case 2: deposit(); break;
				case 3: balance(); break;
				default : printf("Select the valid number \n");
			}
		}
	}
	else
	{
		printf(" PIN inncorrect \n");
	}
}
	int withdraw()
	{
		int draw;
		printf("\n Enter the Amount to Withdraw \n");
		scanf("%d",&draw);
		if(amt==0)
		{
			printf("SORRY...! Transaction Failed \n");
			printf("Your Account Balance is 0 \n");
		}
		else if(draw>amt)
		{
			printf("SORRY...! Transaction Failed \n");
			printf("Insufficient Balance \n");
		}
		else
		{
			amt=amt-draw;
			printf("Withdraw of %d is Successful..! \n",draw);
		}
	}
	
	int deposit()
	{
		int depo;
		printf("Enter the Amount for Deposit \n");
		scanf("%d",&depo);
		amt=amt+depo;
		printf("Amount %d is Deposited Successfully..!! \n",depo);
	}
	
	int balance()
	{
		printf("Your Account Balance is %d \n",amt);
	}
