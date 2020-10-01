#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int a,octal=0,i=1;
	cin>>a;
    while(a){
        octal += (a%8)*i;
        a/=8;
        i*=10;
    }
    cout<<octal<<endl;
    return 0;
}

/*

Input: 
    63
Output:
    77

*/
