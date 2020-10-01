#include<iostream>
using namespace std;
int main() {
    int a, sum=0;
    while(1){
        cin>>a;
        sum += a;
        if(sum<0) break;
        cout<<a<<endl;
    }
    return 0;
}

/*

Input: 
    1
    2
    88
    -100
    49
Output:
    1
    2
    88

*/
