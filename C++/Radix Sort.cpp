#include<iostream>
using namespace std;

void countSort(int a[],int n,int exp)
{
    int output[n];
    int i,count[10]={0};
    for(i=0;i<n;i++)
        count[(a[i]/exp)%10]++;
        
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    
    for(i=n-1;i>=0;i--)
    {
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        a[i]=output[i];
    
}

void radix_sort(int a[],int n,int max)
{
    for(int exp=1;max/exp>0;exp*=10)
        countSort(a,n,exp);
}

int main()
{
    int n;
    cout<<"Enter the size of an Array:"<<endl;
    cin>>n;
    int a[n];
    int max=0;
    cout<<"Enter the Array elements one by one:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>max)
            max=a[i];
    }
    radix_sort(a,n,max);
    cout<<"After Sorting:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
