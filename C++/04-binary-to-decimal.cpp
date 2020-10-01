#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int a,decimal=0,i=0;
	cin>>a;
    while(a){
        decimal +=  (a%2)*pow(2,i++);
        a/=10;
    }
    cout<<decimal<<endl;
    return 0;
}

/*

Input: 
    101010
Output:
    42

*/
