#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int n,m,i=1,j=1,k;
    cin>>n>>m;
    while(j<=n){
        k = 3*i++ + 2;
        if(k%m==0) continue;
        cout<<k<<endl;
        j++;
    }
    return 0;
}

/*

0 < N1 < 100 0 < N2 < 100

Input: 
    10
    4
Output:
    5 
    11 
    14 
    17 
    23 
    26 
    29 
    35 
    38 
    41

*/
