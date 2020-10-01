#include<iostream>
using namespace std;
template <class T>
void swap(T *x,T *y) //defining swap function
{	T temp=*x;
	*x=*y;
	*y=temp;
}
int main()
{	int m,n;
	float a,b;
	cout<<"enter values of m and n:";
	cin>>m>>n;
	swap(&m,&n);
	cout<<"values of m and n after swapping:"<<m<<","<<n<<"\n";
	cout<<"enter values of a and b:";
	cin>>a>>b;
	swap(&a,&b);
	cout<<"values of a and b After swapping:"<<a<<","<<b<<"\n";
	return 0;
}


