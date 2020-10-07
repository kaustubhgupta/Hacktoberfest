package ARRAY;

import java.util.Scanner;

public class SELECTIONSORT {
    static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        Integer[] array = takeInput();
        display(array);
        selectionSort(array);
        display(array);
    }

    public static Integer[] takeInput() {

        System.out.println(" Insert size: ");
        Integer n = scn.nextInt();

        Integer[] arr = new Integer[n];
        for(Integer i = 0; i < arr.length; i++) {
            System.out.println("enter the value for " + i + " index");
            arr[i] = scn.nextInt();
        }
        return arr;
    }

    public static void display(Integer[] arr) {

        for(Integer element : arr) {
            System.out.println(element);
        }
    }

    public static void selectionSort(Integer[] arr) {

        for(Integer counter = 0; counter < arr.length-1; counter++) {
            Integer min = counter;
            for(Integer j = counter + 1; j < arr.length; j++) {
                if(arr[j] < arr[min]) {
                    min = j;
                }
                Integer temp = arr[min];
                arr[min] = arr[counter];
                arr[counter] = temp;
            }
        }
    }
}
