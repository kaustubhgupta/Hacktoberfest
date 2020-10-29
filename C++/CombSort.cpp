//Comb Sort is an sorting algorithm in which we sort numbers by using gap of size more than 1 and shrinks by a factor of 1.3 in each iteration until it reaches 1.
//Comb sort algorithm is improvised form of bubble sort algorithm.

#include<iostream>

using namespace std;

void combSort(int array[], int length) 
{
   int gap = length; 
   bool flag = true;
   while(gap != 1 || flag == true) 
   {
      gap = (gap)/1.3; 
      if(gap<1)
         gap = 1;
      flag = false;

      for(int i = 0; i< length - gap; i++) 
      { 
         if(array[i] > array[ i + gap ]) 
         {
			int temp = array[i];  
            array[i] = array[ i + gap ];  
            array[ i + gap ] = temp;  
            flag = true;
         }
      }
   }
}

int main()
{
	int arr[] = {118,50,21,90,655,1,29,11};
	int len=sizeof(arr)/sizeof(arr[0]);
	combSort(arr, len);
	cout<<"The sorted order is \n";
	for (int i = 0; i < len; ++i)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}