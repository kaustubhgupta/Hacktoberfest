import java.util.Scanner;

public class LongestPalindromicSubsequence {

	public static void main(String[] args) {
		
		
		Scanner s = new Scanner(System.in);
		// input the string
		String str=s.next();
		
		// call the LPS function
		int ans=LPS(str);
		System.out.println(ans);
		
		
		

	}
	// LPS is the function finding the longest palindromic subsequence
	public static int LPS(String str)
	{
		int n= str.length();
	// create a 2d array for DP
		int L[][]= new int[n][n];
	// fill all the diagonal elements in the array  with 1 because string of length 1 is always a palindrome
		for(int i=0;i<n;i++)
		{
			L[i][i]=1;
		}
	// In the outer for loop l is the length of the string. We are looping for l=2 to l=dtr.length()
		for(int l=2;l<=str.length();l++)
		{
			for(int i=0;i<n-l+1;i++)
			{
				int j=i+l-1;
				if(str.charAt(i)==str.charAt(j)&& i+1==j)
				{
					L[i][j]=2;
				}
				else if(str.charAt(i)==str.charAt(j))
				{
					L[i][j]=L[i+1][j-1]+2;
				}
				else
				{
					L[i][j]=Math.max(L[i][j-1], L[i+1][j]);
				}
			}
		}
		return L[0][n-1];
	}

}
