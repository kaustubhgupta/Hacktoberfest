#include<iostream>

using namespace std;

int main()
{
    int n,count=0;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Divisors are: ";
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        {
            count+=i;
            cout<<i<<" ";
        }
    }
    cout<<endl;
    cout<<"sum is: "<<count<<endl;
    cout<<"Result is: ";
    if(count==n)
    {
        cout<<"Yes, a perfect number"<<endl;
    }
    else
    {
        cout<<"Not a perfect number"<<endl;
    }
    return 0;
}