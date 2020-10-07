public class LongestCommonSubsequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		// Input String 1
		String str1=s.next();
		// Input String 2
		String str2=s.next();
		// Convert the string to character array
		char arr1[]= str1.toCharArray();
		char arr2[]= str2.toCharArray();
		int n=str1.length();
		int m=str2.length();
		// Call the LCS function
		int ans=LCS(arr1, arr2, n, m);
		System.out.println(ans);
		
		
		
		
	}
	public static int LCS(char[] arr1 , char[] arr2 , int  n , int m)
	{
		// L is the 2D array to Apply the DP approach to find length of Longest Commmon Subsequence
		int L[][]= new int[n+1][m+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				// if i=0 or j=0 , the size of common subsequence will also be zero
				if(i==0 || j==0)
				{
					L[i][j]=0;
				}
				// when the characters are same
				else if(arr1[i-1]==arr2[j-1])
				{
					L[i][j]=L[i-1][j-1]+1;
				}
				// when characters are different
				else
				{
					L[i][j]=Math.max(L[i-1][j], L[i][j-1]);
				}
			}
		}
		return L[n][m];
		
	}

}
