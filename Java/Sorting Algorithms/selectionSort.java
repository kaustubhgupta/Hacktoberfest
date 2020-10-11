package ARRAY;

import java.util.Scanner;

public class selectionSort{

	static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		int[] array = takeInput();

		display(array);

    selectionSort(arr);

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

public static void selectionSort(int[] arr) {
		
		for(int counter = 0; counter < arr.length-1; counter++) {
			int min = counter;
			for(int j = counter + 1;j < arr.length; j++) {
				if(arr[j] < arr[min]) {
					min = j;
				}
			int temp = arr[min];
			arr[min] = arr[counter];
			arr[counter] = temp;
				
			}
		}
	}

}
