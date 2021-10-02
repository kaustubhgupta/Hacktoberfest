//Shell Sort is an sorting algoritm in which we sort numbers by using gap of particular position.
//As we move forward we keep on decreasing the gap.
//We take use insertion sort algorithm to implement shell sort algorithm.

import java.io.*;
import java.util.*;

public class ShellSort 
{ 
	static void shellSort(int arr[], int len) 
	{ 
		int temp=0;
		for (int i = len / 2; i> 0; i = i / 2){    
			for (int j = i; j<len; j++){    
				for(int k = j - i; k>= 0; k = k - i){    
					if (arr[k+i] >= arr[k]){    
						break;
					}    
					else{    
						temp = arr[k];    
						arr[k] = arr[k+i];    
						arr[k+i] = temp;    
					}    
				}    
			}    
		}   
	} 
	public static void main(String args[]) 
	{ 
		int arr[] = {118,50,21,90,655,1,29,11};
		System.out.println("Original Array: " + Arrays.toString(arr));
		shellSort(arr, arr.length);
		System.out.println("Array after Shell Sort: " + Arrays.toString(arr)); 
	} 
} 
