#include<iostream>
using namespace std;
int main() {
	long long int N,a,b,c;
	cin>>N;
	if (N&1){
		//a = ((N+1)*(N+1) - (N-1)*(N-1))/4;
		a = 2*(N+1)*(N-1)/4;
		b = ((N+1)*(N+1) + (N-1)*(N-1))/4;
	}else{
		a = (N/2)*(N/2) - 1;
		//b = N;
		b = (N/2)*(N/2) + 1;
	}
	if(a*a + N*N == b*b && a>N)
		cout<<a<<" "<<b<<endl;
	else
		cout<<"-1\n"

    return 0;
}

/*

Input: 
    3
Output:
    4 5

*/
