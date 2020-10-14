/*
Description : Application is to find all the subsets of given string
Input : String
Output : Prints subsets of string
author : yashnavgire
Date   : 11/10/2020
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void copy(char *clone,char *current,char *input,int index){
    int iCnt=0;
    while(current[iCnt]!='\0')
    {
        clone[iCnt]=current[iCnt];
        iCnt++;
    }
    clone[iCnt]=input[index];
}

void subsets(char *input,char *current,int length,int start)
{
    //base case
    if(start==length)
    {
        printf("%s \n",current);
        free(current);                              //free-up memory since the subset has reached base case and not needed further
        return;
    }

    //making copy and adding character to current string
    char *clone=(char *)calloc(length,sizeof(char));
    copy(clone,current,input,start);

    subsets(input,clone,length,start+1);             //combinations of clone string
    subsets(input,current,length,start+1);           //combinations of current string

}


int main()
{
    char input[100];
    scanf("%[^\n]s",input);
    int length=strlen(input);

    printf("printing subsets of %s \n",input);
    subsets(input," ",length,0);

    return 0;
}