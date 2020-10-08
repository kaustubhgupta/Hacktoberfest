/**
	Description: Display fibonacci series upto n, taken as input
	Fibonacci: starts from 0,1 and next number of the series is obtained by adding the previous two terms
*/

import java.util.Scanner;
public class fibonacci {

	// fibo method calculates the next term in the series and runs till n
	public static void fibo(int n)
	{
		// variable initialization
		int first = 0, second = 1, next = 0;
		// displaying the first and second term
		System.out.println(first + "\n" + second);

		for (int i=0; i<n; i++)
		{
			// finding the next term by adding the previous two terms
			next = first + second;
			System.out.println(next);
			// updating first and second
			first = second;
			second = next;
		}
	}

	// main method
	public static void main(String[] args)
	{
		int n;
		Scanner sc = new Scanner(System.in);
		// input range	
		System.out.println("Enter the range of the fibonacci series: ");
		n = sc.nextInt();
		// calling fibo with n as argument
		fibo(n);
	}
}
