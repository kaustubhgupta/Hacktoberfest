package ARRAY;

import java.util.Scanner;

public class bubbleSort {

	static Scanner scn = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int[] array = takeInput();
    
		display(array);
    
    bubbleSort(arr);
    
    display(arr);
    
    }
    
    public static int[] takeInput() {
		
		System.out.println(" size? ");
		int n = scn.nextInt();
		
		int[] arr = new int[n];
		
		for(int i = 0; i < arr.length; i++) {
			System.out.println("enter the value for " + i + " index");
			arr[i] = scn.nextInt();
		}
		return arr;
	}
	
	public static void display(int[] arr) {
		
		for(int i = 0; i < arr.length; i++) {
			System.out.println(arr[i]);
		}
	}
  
  public static void bubbleSort(int[] arr) {
		
		for(int counter = 0; counter < arr.length-1; counter++) {
			for(int j = 0; j < arr.length-1-counter; j ++) {
				if(arr[j] > arr[j+1]) {
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
//					Swap(arr[j],arr[j+1]);
				}
			}
		}
	}
  
}
