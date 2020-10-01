#include<iostream>
#include<cmath>
using namespace std;
int main() {
    long long int a,n,fac,sum=0, mod=107;
	cin>>a;
    while(a--){
        fac=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            fac*=i;
            fac%=mod;
        }
        sum = (sum%mod + fac%mod)%mod;
    }
    cout<<sum<<endl;
    return 0;
}

/*

Input: 
    3
    3 4 5
Output:
    43

*/
