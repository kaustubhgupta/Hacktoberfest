#include<iostream>
#include <cmath>
using namespace std;
int main() {
    int n,digits=0,num, sum=0;
    cin>>n;
    num=n;
    while(num){
    	digits++;
    	num/=10;
    }
    num=n;
    while(num){
    	sum += pow((num%10),digits);
    	num /=10;
    }
    (n==sum)? cout<<"true\n" : cout<<"false\n";
    return 0;
}

/*

Input: 
    371
Output:
    true

*/
