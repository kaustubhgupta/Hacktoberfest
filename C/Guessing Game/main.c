//Libraries of C
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int random=0,guess=0;
    int max;
    time_t t;//time datatype defined in C library of time
    srand((unsigned)time(&t));//It generates pseudo random number by using rand() function
    random=rand()%21;//It provides a range between 1 to 20 number

    printf("\n This is a guessing game.");
    printf("\n I have chosen a number from 0 and 20\n");

    for(max=5;max>0;max--)//It allow users to play upto 5 times in a sngle play
    {
        printf("\n You have %d tr%s left",max,max==1?"y":"ies"); //It returns pural form of try when try is greater than zero and singular form when try equals to one
        printf("\n Enter a guess: ");
        scanf("%d",&guess); 

        if(guess==random)
        {
            printf("\nCongratulation: You have guessed it correct.\n");
            return;
        }

        else if(guess<0 || guess>20)
        {
            printf("I said that the number is between 0 and 20\n");
        }
        else if(guess<random)
        {
            printf("Sorry, %d is wrong. My number is greater than this.\n",guess);
        }
         else if(guess>random)
        {
            printf("Sorry, %d is wrong. My number is less than this.\n",guess);
        }
    }
    printf("\n You had 5 tries but you are failed to guess. The number is %d\n",random);
    return 0;
}
