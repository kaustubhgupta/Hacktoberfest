/*
* Linear search is the simplest search algorithm.
* Starting from index 0, all the elements in the array are compared with target value sequentially.
* Time complexity :
        Best case : O(1)
        Worst case : O(n)
*/

import java.util.Scanner;

public class LinearSearch {
    public static int linearSearch(int[] arr, int target) {
        // Here I have used a 'for loop' to compare the elements of the array with the target value.
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        int[] a1 = {10, 1, 6, -100, 20, 63, 11, -5, 30, 50, 70, 100, 42, 0, 99, 7, 90};
        System.out.println("Please enter an integer to search it in the array : ");
        int target = input.nextInt();
        int returnedindex = linearSearch(a1, target);
        if (returnedindex == -1) {
            System.out.println(target + " is not found in the array.");
        } else {
            System.out.println(target + " is found in the array at index " + returnedindex);
        }
    }
}