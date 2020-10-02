/*
 * Suppose you have N eggs and you want to determine from which floor in a K-floor building you 
 * can drop an egg such that it doesn't break. You have to determine the minimum number of attempts 
 * you need in order to find the critical floor in the worst case while using the best strategy.
 * There are few rules given below. 
	* An egg that survives a fall can be used again.
	* A broken egg must be discarded.
	* The effect of a fall is the same for all eggs.
	* If the egg doesn't break at a certain floor, it will not break at any floor below.
    * If the eggs breaks at a certain floor, it will break at any floor above.
 *
 * Time complexity of this function: O(N*K^2)
 * Space Complexity of this function: O(N*K) 
 */

package Hacktoberfest2020_.Java;

public class EggDroppingPuzzle {
	public static class Puzzle {

        // Function to calculate the minimum number of attemps
		public static int eggDrop(int n, int k) {
			int eggFloor[][] = new int[n+1][k+1];
			int res;
			
			for(int i = 0; i <= n; i++) {
				eggFloor[i][0] = 0;
				eggFloor[i][1] = 1;
			}
			
			for(int j = 1; j <= k; j++) {
				eggFloor[1][j] = j;
			}
			
			for(int i = 2; i <= n; i++) {
				for(int j = 2; j <= k; j++) {
					eggFloor[i][j] = Integer.MAX_VALUE;
					for(int x = 1; x <= j; x++) {
						res = 1 + Math.max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
						
						if(res < eggFloor[i][j]) {
							eggFloor[i][j] = res;
						}
					}
				}
			}
			
			return eggFloor[n][k];
		}
	}
	
	public static void main(String[] args) {
		int eggs = 2;
		int floors = 10;
		
		System.out.println("Minimum number of trials required: " + Puzzle.eggDrop(eggs, floors));
	}
}