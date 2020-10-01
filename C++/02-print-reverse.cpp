#include<iostream>
using namespace std;
int main() {
    int a;
    cin>>a;
    while(a){
        cout<<a%10;
        a/=10;
    }
    return 0;
}

/*

Input: 
    123456789
Output:
    987654321

*/
