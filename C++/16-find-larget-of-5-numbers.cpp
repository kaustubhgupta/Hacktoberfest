#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int a,n=5,largest;
	//cin>>n;
    cin>>a;
    largest = a;
    while(n-- - 1){
        cin>>a;
        if(a>largest)
            largest = a;
    }
    cout<<largest<<endl;
    return 0;
}

/*

Input: 
    3
    3 4 5
Output:
    43

*/
