#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int random=0,guess=0;
    int max;
    time_t t;
    srand((unsigned)time(&t));
    random=rand()%21;

    printf("\n This is a guessing game.");
    printf("\n I have chosen a number from 0 and 20\n");

    for(max=5;max>0;max--)
    {
        printf("\n You have %d tr%s left",max,max==1?"y":"ies");
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
