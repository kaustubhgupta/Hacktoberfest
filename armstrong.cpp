#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int reg,org,i,sum,power,n;
    printf("Armstrong numbers b/w 1-500 are :- \n");

    for(i=1;i<=500;i++)
    {
        n=org=i;
        sum=0;
        power =(int) log10(n)+1;
        while(org>0)
        {
            reg=org%10;
            sum=sum+ ceil(pow(reg,power)) ;
            org=org/10;
        }
        if(i==sum)
            printf("%d \n",i);

    }
    getch();
    return 0;
}
