#include<iostream>
using namespace std;
int main() {
    int n,d,c=0;
    cin>>n>>d;
    while(n){
        if(n%10==d) c++;
        n/=10;
    }
    cout<<c<<endl;
    return 0;
}

/*

Input: 
    5433231 
    3
Output:
    3

*/
