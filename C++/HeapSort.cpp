#include<bits/stdc++.h>   
using namespace std; 
void heapify(int *,int,int);
void heap_sort(int A[],int n) 
{  
    for (int i=(n/2)-1;i>=0;i--) 
        heapify(A,n,i); 
  
    for (int i=n-1;i>0;i--)            //extracting elements one by one from heap 
    { 
        swap(A[0],A[i]);  
        heapify(A,i,0); 
    } 
}    
   
void heapify(int A[],int n,int i)                //arr with index i and size n, heapifying the subtree rooted at i 
{ 
                      
    int left = 2*i + 1;                   
    int right = 2*i + 2;
	int largest = i;                   //largest is assigned the value of root index i
   
    if (left<n && A[left] > A[largest])   
        largest = left; 
   
    if (right<n && A[right]>A[largest]) 
        largest=right; 
   
    if (largest != i) 
    { 
        swap(A[i],A[largest]);  
        heapify(A, n, largest); 
    } 
} 
   
int main() 
{  
    int n;
	cout<<"Enter the size of array: \n";
	cin>>n;
	cout<<"\n";
	cout<<"Enter the elements of the array : ";
	int A[n];
	for(int i=0;i<n;i++)
	cin>>A[i];  
	
    heap_sort(A, n);
	 
    cout << "Sorted array is \n"; 
    for (int i=0; i<n; ++i) 
        cout <<A[i]<<" ";  
} 
