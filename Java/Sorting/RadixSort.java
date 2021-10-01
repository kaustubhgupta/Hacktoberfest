//Radix Sort is an sorting algorithm in which we sort numbers by digigt by digit from least to most significant.
//We take use count sort algorithm to implement radix sort algorithm.

import java.io.*;
import java.util.*;

public class RadixSort {
	
	static void radixSort(int arr[], int len)
	{	
		//get maximum value from array
		int max = findMaximum(arr, len);
		for (int mul = 1; max / mul > 0; mul *= 10){
			countSort(arr, len, mul);
		}		
	}
	static int findMaximum(int arr[], int len)
	{
		int maximum = arr[0];
		for (int i = 1; i < len; i++){
			if (arr[i] > maximum){
				maximum = arr[i];
			}
		}		
		return maximum;
		
	}

	static void countSort(int arr[], int len, int mul)
	{
		int output[] = new int[len]; 
		int count[] = new int[10];
		Arrays.fill(count, 0); //initialize array "count" with initial value 0
		
		//count the occurences
		for (int i = 0; i < len; i++){
			++count[(arr[i] / mul) % 10];
		}
		//actual spots of digits
		for (int i = 1; i < 10; i++){
			count[i] += count[i - 1];
		}

		for (int i = len - 1; i >= 0; i--) {
			output[count[(arr[i] / mul) % 10] - 1] = arr[i];
			--count[(arr[i] / mul) % 10];
		}
		for (int i = 0; i < len; i++){
			arr[i] = output[i];
		}	
	}
	public static void main(String[] args)
	{
		int arr[] = {118,50,21,90,655,1,29,11};
		System.out.println("Original Array: " + Arrays.toString(arr));
		radixSort(arr, arr.length);
		System.out.println("Array after Radix Sort: " + Arrays.toString(arr));
	}
}
