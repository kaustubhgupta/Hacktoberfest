//Bucket Sort is an sorting algoritm in which we sort numbers by distributing among buckets.
//Further they are individually sorted.
import java.io.*;
import java.util.*;
 
public class BucketSort {
 
	public static void bucketSort(int[] arr, int len) {
		int max = findMaximum(arr, len);
		int temp = 0;
		int[] bucket = new int[max + 1];
	
		for (int i = 0; i < bucket.length; i++) {
			bucket[i] = 0;
		}
		for (int i = 0; i < arr.length; i++) {
			bucket[arr[i]]++;
		}
		for (int i = 0; i < bucket.length; i++) {
			for (int j = 0; j < bucket[i]; j++) {
				arr[temp++] = i;
			}
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
	public static void main(String[] args) {
      
      int arr[] = {118,50,21,90,655,1,29,11};
	  System.out.println("Original Array: " + Arrays.toString(arr));
	  bucketSort(arr, arr.length);
	  System.out.println("Array after Bucket Sort: " + Arrays.toString(arr));
		
   }
}