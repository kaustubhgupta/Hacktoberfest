#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int a,decimal,i,n;
    cin>>n;
    while(n--){
    	cin>>a;
    	i=0;
    	decimal=0;
	    while(a){
	        decimal += (a%2)*pow(2,(i++));
	        a/=10;
	    }
	    cout<<decimal<<endl;
    }
    return 0;
}

/*

Input: 
    4
	101
	1111
	00110
	111111
Output:
    5
	15
	6
	63

*/
