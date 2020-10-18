#include<iostream> 
#include<climits> 
using namespace std;
int maxsubarray(int a[],int size)  // Create a Function to find the maximum value of the subarray
{
    int max=INT_MIN;  //Max will store the maximum value of the subarray.
    int sum=0;  // Sum will store the value of different subarray combinations.
    for(int i=0;i<size;i++)
    {
        sum = sum +a[i];
        if(max<sum)  //If the value stored in max is less than the calculated sum of the array then max will be equal to sum.
        {
            max=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    cout << "Maximum value of subarray: " << max;  //Prints Maximum Value.
    return 0;
}

int  main()
{
    int size;
    cout << "Enter number of terms: ";  // Enter the size of array.
    cin >> size;
    int a[size];
    cout<<"Enter Elements array: ";  // Enter the elements in the array .
    for(int i=0;i<size;i++)
    {
        cin >> a[i];
    }
    maxsubarray(a,size);  // Pass the values of the array to the function maxsubarray().
    return 0;
}