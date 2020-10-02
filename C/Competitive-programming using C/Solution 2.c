#include <stdio.h>
int main()
{
    long long int t,n,m,i,max,lcm;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        scanf("%lld",&m);
        max=(n>m)?n:m;
        i=max;
        while(1){
            if(i%n==0 && i%m==0)
            {
                lcm=i;
                break;
            }
            i+=max;
        }
        printf("%lld\n",lcm);
    }

    return 0;
}
