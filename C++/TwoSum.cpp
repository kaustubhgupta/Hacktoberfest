/* Given an array and a particular number as target, the aim is to find whether there 
   exist two numbers in array such that the sum is equal to the target*/

#include<bits/stdc++.h>
using namespace std;

//Function to check whether target sum can be achieved using two numbers of given array
bool TwoSum(int arr[],int n, int target)
{
    //Sorting the array.
    sort(arr,arr+n);

    /*front and end are two pointers.
     We check at each step whether the sum of numbers at the index to which they are pointing is equal to the target.
     front initially points to the smallest number of array
     end initially points to the largest number of the array */ 
    int front=0, end=n-1;
    
    while(front!=end)
    {
        if((arr[front]+arr[end])==target)
        return true;
        else if((arr[front]+arr[end])>target) 
        end--; //if the sum is greater than the target then we try reducing the sum by moving the end pointer backward i.e pointing it to a smaller number.
        else
        front++;//if the sum is lesser than the target then we try increasing the sum by moving the front pointer forward i.e pointing it to a greater number.
    }

    return false;
}

int main()
{
    //Taking input
    cout<<"Enter number of elements in array:\n";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter numbers:\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter target sum:\n";
    int target;
    cin>>target;

    bool ans= TwoSum(arr,n,target);
    cout<<(ans==true?"Yes":"No");
}

/*
Input: 5
       1 7 5 4 3
       6
Output: Yes
*/

/*
Time Complexity: O(nlog(n)) (due to sort operation)
Space Complexity: O(n)
*/