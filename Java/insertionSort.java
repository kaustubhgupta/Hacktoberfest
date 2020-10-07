package ARRAY;

import java.util.Scanner;

public class INSERTIONSORT {

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		int[] array = takeInput();

		display(array);

    insertionSort(arr);

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

		for(Integer element : arr) {
            		System.out.println(element);
        	}
	}

public static void insertionSort(int[] arr) {
		
		for(int counter = 1; counter <= arr.length - 1; counter++) {
			
			int val = arr[counter];
			
			int j = counter - 1;
			
			while(j >= 0 && arr[j] > val) {
				arr[j+1] = arr[j];
				j--;
			}
			
			arr[j+1] = val;
		}
	}

}
