/*
 * Dynamic Programming ALgorithm for Coin Change Problem.
 * CoinChangeI:
 * Given a value N, if we want to make change for N cents, and we have infinite supply of 
 * each of C = { C1, C2, .. , Cm} valued coins, how many ways can we make the change? 
 * The order of coins doesn’t matter.
 * 
 * Time complexity of this function: O(mn)
 * Space Complexity of this function: O(n) 
 * 
 * CoinChangeII:
 * Given a value V. You have to make change for V cents, given that you have infinite supply 
 * of each of C = { C1, C2, .. , Cm} valued coins. Find the minimum number of coins to make the change.
 * 
 * Time complexity of this function: O(mn)
 * Space Complexity of this function: O(n) 
 */

package Hacktoberfest2020_.Java;

import java.util.Arrays;

public class CoinChange {
	public static class CoinChangeI {
		public static long countWays(final int[] S, final int n, final int m) {
            final long table[] = new long[m + 1];

            table[0] = 1;

            for (int i = 0; i < n; i++) {
                for (int j = S[i]; j <= m; j++) {
                    table[j] += table[j - S[i]];
                }
            }

            return table[m];
        }
    }

    public static class CoinChangeII {
        public static int minCoins(final int[] coins, final int amount) {
            final int dp[] = new int[amount + 1];
            Arrays.fill(dp, amount + 1);
            dp[0] = 0;

            for (int i = 1; i <= amount; i++) {
                for (int j = 0; j < coins.length; j++) {
                    if (coins[j] <= i) {
                        dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }

            return (dp[amount] > amount) ? -1 : dp[amount];
        }
    }

    public static void main(final String[] args) {
        final int arr[] = { 1, 2, 3 };
        final int n = arr.length;
        final int m = 4;
        System.out.println(CoinChangeI.countWays(arr, n, m));
        System.out.println(CoinChangeII.minCoins(arr, m));
	}
}