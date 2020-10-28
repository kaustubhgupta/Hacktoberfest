// A simple C++ program to find the largest
// subarray with equal number of 0s and 1s
#include <bits/stdc++.h>

using namespace std;

// This function Prints the starting and ending
// indexes of the largest subarray with equal
// number of 0s and 1s. Also returns the size
// of such subarray.

int findSubArray(int arr[], int n)
{
	int sum = 0;
	int maxsize = -1, startindex;

	// Pick a starting point as i
	for (int i = 0; i < n - 1; i++) {
		sum = (arr[i] == 0) ? -1 : 1;

		// Consider all subarrays starting from i
		for (int j = i + 1; j < n; j++) {
			(arr[j] == 0) ? (sum += -1) : (sum += 1);

			// If this is a 0 sum subarray, then
			// compare it with maximum size subarray
			// calculated so far
			if (sum == 0 && maxsize < j - i + 1) {
				maxsize = j - i + 1;
				startindex = i;
			}
		}
	}
	if (maxsize == -1)
		cout << "No such subarray";
	else
		cout << startindex << " to "
			<< startindex + maxsize - 1;

	return maxsize;
}

/* Driver code*/
int main()
{
	int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	findSubArray(arr, size);
	return 0;
}

// This code is contributed by rathbhupendra


