#include <bits/stdc++.h>
using namespace std;
// O(n) solution
int Kadane(vector<int> a,int n) // n = size of vector a
{
    int sum=0,max=0,i;
    int x = *max_element(a.begin(),a.end()); // function for finding the maximum element in a vector
    // if largest element of the vector is a negative number then other
    // elements of the vector are definitely negative
    // therefore the answer is x only
    if(x < 0)
        return x; 
    for(i = 0; i < n; i++)
    {
        sum += a[i];
        // if sum is negative then sum will be taken as 0 
        if(sum < 0)
            sum = 0;
        // else whenever the sum would be either positive or 0 then max is updated 
        else
        {
            if(sum > max)
                max = sum;
        }
    }
    return max;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<Kadane(a,n);
    return 0;
}