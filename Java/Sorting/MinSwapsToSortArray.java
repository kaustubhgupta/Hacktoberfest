import java.util.Arrays;
import java.util.HashMap;

public class MinSwapsToSortArray {



    /*
    *This program implements the Graph Theory Algorithm for Finding the Minimum Number of Swaps ti Sort an Array
    *For More detail on Refer : https://stackoverflow.com/questions/15152322/compute-the-minimal-number-of-swaps-to-order-a-sequence/15152602#15152602
     */

    static int minSwaps(int[] arr) {

        //This map is used to store elements and thier intial position in the Array
        HashMap<Integer, Integer> maps = new HashMap<>();
        
        //Storing the elements and thier initial postion in the Array
        for (int i = 0; i < arr.length; i++) {
            maps.put(arr[i], i);
        }


        //Sorting the given Array Time Complexity of O(nlogn)
        Arrays.sort(arr);


        for (int i = 0; i < arr.length; i++) {
            arr[i] = maps.get(arr[i]);      //gets the position of each element in the sorted Array
        }
        
        maps.clear();       //Clears the HashMap

        int swaps = 0;      //Variable to store the number of swaps


        for (int i = 0; i < arr.length; i++) {
            
            int val = arr[i];
            
            
            if (val == -1)        //Checks whether the element has already been traversed or not
                continue;

            
            while (val != i)        //Checks whether the element is at its desired position and keeps on checking till it reaches the desired position
            {
                int newVal = arr[val];
                arr[val] = -1;      //Marking the current node as Traversed
                val = newVal;
                swaps++;     //Incresing the Swap as a Swapping has taken place   
            }
            arr[i] = -1;       
        }
        return swaps;       //Returns the Number of Swaps
    }

    public static void main(String[] P){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the size of the Array");
        int size = scanner.nextInt();      //Stores the size of the Array

        int[] array = new int[size];
        
        System.out.println("Enter the Elements of the Array");
        for (int i = 0; i < size; i++) {
            array[i] = Integer.parseInt(scanner.next());        //Storing the Array elements
        }
        System.out.println("Minimum number of Swaps to Sort the Given array is: "+minSwaps(array));
    }
}
