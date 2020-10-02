#include<stdio.h>
int main(){
    int t,n,i;
    scanf("%d",&t);
        while(t--){
           scanf("%d",&n);
            int v[n],sum=0;
           for(i=0;i<n;i++){
                scanf("%d",&v[i]);
            if(v[i] & 1){
                    continue;
            }
           else{
            sum+=v[i];
           }
           }
           printf("%d\n",sum);
        }
}
