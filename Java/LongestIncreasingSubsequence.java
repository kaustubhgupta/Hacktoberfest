 /*
 * Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence.
 * The longest increasing subsequence means to find a subsequence of a given sequence in which the 
 * subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as 
 * long as possible. This subsequence is not necessarily contiguous, or unique.
 */

package Hacktoberfest2020_.Java;

public class LongestIncreasingSubsequence {
	public static class LIS_Memoization {
		public static int lis(final int arr[]) {
            final int n = arr.length;
            final int lis[] = new int[n];
            int max = 0;

            for (int i = 0; i < n; i++) {
                lis[i] = 1;
            }

            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                if (max < lis[i]) {
                    max = lis[i];
                }
            }

            return max;
        }
    }

    public static void main(final String[] args) {
        final int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
        System.out.println("Length of lis using memoization is " + LIS_Memoization.lis(arr));
	}
}
