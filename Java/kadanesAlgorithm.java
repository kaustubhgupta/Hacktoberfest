//This algorithm gives the sum of the largest sum contiguous subarray

import java.util.*;
public class kadaneAlgo {
	public static void main(String[] args) {
		//Implementing scanner for Input
		Scanner sc = new Scanner(System.in);
		//n will be size of array
		int n = sc.nextInt();
		int array[] = new int[n];
		for(int i=0;i<n;i++) {
			array[i] = sc.nextInt();
		}
		int sum = 0, result = 0;
		for(int i=0;i<n;i++) {
			sum += array[i];
			if(sum<0) {
				sum = 0;
			}
			else if(result < sum) {
				result = sum;
			}
		}
		System.out.println(result);
	}
}
