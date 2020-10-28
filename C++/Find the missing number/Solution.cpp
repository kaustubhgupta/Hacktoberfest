#include <bits/stdc++.h>
using namespace std;
// Function to get the missing number
int getMissingNo(int a[], int n)
{    int total = (n + 1) * (n + 2) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}
// Driver Code
int main()
{ int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = getMissingNo(arr, n);
    cout << miss;
}
