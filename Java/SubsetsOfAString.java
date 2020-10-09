import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class StringSubsets {
	private static void printSubsets(String str, String current, int index)
	{	// Prints an Empty String as the first subset.
		
		// Base Case: The recursion bottoms out when index equals the length of the string.
		if(index == str.length())
		{	// All the subsets of the given string are printed one after the other.
			System.out.print(current + " ");
			return;
		}
		
		// Recursive Case: Recurse until the base case is reached.
		printSubsets(str, current, index + 1);
		printSubsets(str, current + str.charAt(index), index + 1);
	}
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter a String for which subsets are to be found and printed:");
		String input = reader.readLine();
		printSubsets(input, " ", 0);
	}
}
