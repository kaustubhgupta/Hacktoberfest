#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define e(a) cin>>a
#define o(a) cout<<a
#define rep(i,a,b) for(int i=a;i<b;i++)
#define test() int t;cin>>t;while(t--)
#define fst_io ios_base::sync_with_stdio(false);cin.tie(NULL);


/*--------------------------------------------------*/
int partition(int a[],int l ,int h){
	* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
	int pi = a[l];
	int i=l;int j=h+1;
	do{
		do{
			i++;
		}while(a[i]<pi && i<=h);
		do
			j--;
		while(pi<a[j]);
		if(i<j){
			int temp =a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}while(i<j);
	a[l]=a[j];
	a[j] = pi;
	return j;	
}
void quicksort(int a[],int l,int h)
{
	//function to sort the elements in an array
	int j;
	if(l<h){
		j=partition(a,l,h);
		quicksort(a,l,j-1);
		quicksort(a,j+1,h);
	}	
}


int main()
{
	fst_io;
	int n;e(n);
	int a[n];
	rep(i,0,n) e(a[i]);
	quicksort(a,0,n-1);
	rep(i,0,n) cout<<a[i]<<" ";
	return 0;
}
