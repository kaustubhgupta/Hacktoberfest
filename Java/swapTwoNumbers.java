/**
	Description: swap the value of two numbers without using temporary variable
*/

import java.util.Scanner;

public class swapTwoNumbers {

	// swap method, to swap the values, takes two integer numbers as parameter
	public static void swap(int num1, int num2)
	{
		System.out.println("Before swapping: " + num1 + " " + num2);
		// swapping
		num1 = num1 + num2;
		num2 = num1 - num2;
		num1 = num1 - num2;
		System.out.println("After swapping: " + num1 + " " + num2);
	}


	// main method
	public static void main(String[] args)
	{
		// variable declaration
		int num1, num2;
		Scanner sc = new Scanner(System.in);
		// input prompt
		System.out.println("Enter two numbers: ");
		num1 = sc.nextInt();
		num2 = sc.nextInt();
		// calling swap method, num1 and num2 as arguments
		swap(num1,num2);
	}
}

