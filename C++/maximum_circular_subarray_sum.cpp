#include<iostream>
#include<climits>
using namespace std;

// // METHOD 1
// int main() {

//     int n;
//     cout<<"Enter n: ";
//     cin>>n;

//     int arr[n];
//     cout<<"Enter array elements: ";
//     for(int i=0; i<n; i++)
//         cin>>arr[i];

//     int currSum=0, maxSum=INT_MIN;

//     // Case 1: No wrapping
//     if(arr[0]<0 || arr[n-1]<0) {
//         for(int i=0; i<n; i++) {
//         currSum += arr[i];
//         maxSum = max(currSum, maxSum);
//         if(currSum<0)
//             currSum=0;
//         }
//         cout<<"Maximum subarray sum = "<<maxSum;
//         return 0;
//     }


//     // Case2: Wrapping
//     for(int i=0; i<n; i++) {
//         arr[i] = -arr[i];
//     }

//     //  To find sum of non-contributing elements
//     for(int i=0; i<n; i++) {
//         currSum += arr[i];
//         maxSum = max(currSum, maxSum);
//         if(currSum<0)
//             currSum=0;
//     }
    
//     // Max subarray sum = Total sum of array - Sum of non-contributing elements
//     int arraySum = 0;
//     for(int i=0; i<n; i++)
//         arraySum += arr[i];

//     cout<<"Maximum circular subarray sum = ";
//     cout<<(-arraySum)+maxSum;

//     return 0;
// }


// METHOD 2
int kadane(int arr[], int n) {
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<n; i++) {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}

int main() {
    int n;
    cout<<"Enter array size: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int wrapsum = kadane(arr, n);

    int nonwrapsum;
    int totalsum = 0;
    for(int i=0; i<n; i++){
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    nonwrapsum = totalsum + kadane(arr, n);
    
    cout<<"Maximum circular subarray sum = "<<max(wrapsum, nonwrapsum)<<endl;

    return 0;
}