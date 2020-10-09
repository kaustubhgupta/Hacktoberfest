/*
Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.

Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.
*/

/*
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
*/

#include<iostream>
using namespace std;
int partition(int *arr, int start, int end)
{
	int pivot=arr[start];
	int count=0;
	for(int i=start+1; i<=end; i++)
	{
		if(arr[i]<=pivot)
		{
			count+=1;
		}
	}
	int pivotindex=start+count;
	int temp=arr[start];
	arr[start]=arr[pivotindex];
	arr[pivotindex]=temp;
	
	int i=start, j=end;
	while(i<=pivotindex&&j>=pivotindex)
	{
		while(arr[i]<=pivot)
		{
			i++;
		}
		while(arr[j]>pivot)
		{
			j--;
		}
		if(i<pivotindex && j>pivotindex)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
	}
	return pivotindex;
}

void quickSort(int *arr, int start, int end)
{
	if(start>=end)
	{
		return;
	}
	int c=partition(arr, start, end);
	quickSort(arr, start, c-1);
	quickSort(arr, c+1, end);
}
void quickSort(int *arr, int n)
{
	quickSort(arr, 0, n-1);
}



int main(){
    int n;
    cin >> n; // Taking input size of array
  
    int *input = new int[n];  
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];        // Taking input element of array
    }
    
    quickSort(input, n);      // This function will sort the array in increasing order 
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}

// Time complexity of best and average case is O(nlogn)
// Time complexity of worst case is O(n^2)
// Space complexity is O(1)