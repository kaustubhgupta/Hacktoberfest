/**
	Description: Take a number as input and displays the factorial of the number
*/

import java.util.Scanner;

public class factorial {

	// fact method to calculate factorial, takes integer n as parameter and returns the factorial
	public static int fact(int n)
	{	if (n >= 1)
            return n * fact(num - 1);
        else
            return 1;
	}

	// main method
	public static void main(String[] args)
	{
		int num, res;
		// scanner object sc
		Scanner sc = new Scanner(System.in);
		// input number
		System.out.println("Enter a number to find factorial: ");
		num = sc.nextInt();
		// calling fact method with num argument
		res = fact(num);
		System.out.println("The factorial of "+ num + " is " + res);
	}
	
}
