/*
 * Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of 
 * minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse 
 * through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path 
 * (including both source and destination). You can only traverse down, right and diagonally lower cells 
 * from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. 
 * You may assume that all costs are positive integers.
 * 
 * Time complexity of this function: O(M*N)
 * Space Complexity of this function: O(M*N) 
 */

package Hacktoberfest2020_.Java;

public class MinimumPathSum {
	public static class MinPathSum {

        // Function to calculate the cost to reach the bottom right index
		public static int minCost(int[][] grid) {
			int m = grid.length; // no. of rows
	        int n = grid[0].length; // no. of columns
	        
            // Dp cost matrix to calculate the min cost till index[i][j]
            int cost[][] = new int[m][n];
	        
	        cost[0][0] = grid[0][0];
	        
	        for(int row = 1; row < m; row++){
	            cost[row][0] = cost[row-1][0] + grid[row][0];
	        }
	        
	        for(int col = 1; col < n; col++){
	            cost[0][col] = cost[0][col-1] + grid[0][col];
	        }
	        
	        for(int row = 1; row < m; row++){
	            for(int col = 1; col < n; col++){
	                cost[row][col] = grid[row][col] + min(cost[row-1][col], cost[row][col-1], cost[row-1][col-1]);
	            }
	        }
	        
	        return cost[m-1][n-1];
		}
        
        // Function to calculate the min among three variables
		public static int min(int a, int b, int c){
	        if(a < b && a < c) {
	        	return a;
	        } else if(b < a && b < c) {
	        	return b;
	        } else {
	        	return c;
	        }
	    }
	}
	
	public static void main(String[] args) {
		int cost[][] = {{1, 7, 9, 2}, 
						{8, 6, 3, 2}, 
						{1, 6, 7, 8},
						{2, 9, 8, 2}}; 
        
                        
		System.out.println("Minimum Path sum from top-left(0,0) to bottom-right(m,n) is " + MinPathSum.minCost(cost));
	}
}
