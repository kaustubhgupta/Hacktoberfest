#include<bits/stdc++.h>
using namespace std;
int par(int a[],int s,int e)
{
	int pivot = a[s];
	int pidx = s;
	int i = s;
	for(int j=s+1;j<=e;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i],a[pidx]);
	return i;
}
int quick_sort(int a[], int start, int end)
{	int idx;
	if(start < end)
	{
		idx = par(a,start,end);
		
		quick_sort(a,start,idx - 1);
		quick_sort(a,idx + 1, end);
	}
	
}
int main()
{
	int a[] = {12,4,5,15,6};
	cout<<"The array before sorting is: ";
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	quick_sort(a,0,4);
	cout<<"The array after sorting is: ";
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
