#include<iostream>
using namespace std;
int main() {
    char ch;
    int a,b,ex=1;
    while(ex){
    	cin>>ch;
    	switch(ch){
	    	case '+': cin>>a>>b; cout<<a+b<<endl; break;
	    	case '-': cin>>a>>b; cout<<a-b<<endl; break;
	    	case '*': cin>>a>>b; cout<<a*b<<endl; break;
	    	case '/': cin>>a>>b; cout<<a/b<<endl; break;
	    	case '%': cin>>a>>b; cout<<a%b<<endl; break;
	    	case 'x':
	    	case 'X': ex =0; break;
	    	default: cout<<"Invalid operation. Try again.\n";
    	}

    }
    return 0;
}

/*

Input: 
    * 
	1 
	2 
	/ 
	4 
	2 
	+ 
	3 
	2 
	; 
	X
Output:
    2 
	2 
	5 
	Invalid operation. Try again.

*/
