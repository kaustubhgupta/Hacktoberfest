#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int n,num,esum,osum;
	cin>>n;
    while(n--){
        esum=0,osum=0;
        cin>>num;
        while(num){
            int k=num%10;
            if((k)%2==0){
                esum+=k;
            }else{
                osum+=k;
            }
            num/=10;
        }
        if((osum&1 && osum%3==0) || (esum&1==0 && osum%4==0))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}

/*

Input: 
    2
    12345
    12134
Output:
    Yes
    No

*/
