#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int a,b,c,d,root1, root2;
    cin>>a>>b>>c;
    d = b*b - 4*a*c;
    if(d==0){
        root1 = -1*b/(2*a);
        cout<<"Real and Equal\n"<<root1<<" "<<root1<<endl;
    }
    else if(d<0){
        cout<<"Imaginary\n";
    }
    else{
        root1 = (-1*b + sqrt(d))/(2*a);
        root2 = (-1*b - sqrt(d))/(2*a);
        cout<<"Real and Distinct\n"<<root1<<" "<<root2<<endl;
    }
	return 0;
}

/*

Input: 
    1 -11 28
Output:
    Real and Distinct
    4 7

*/
