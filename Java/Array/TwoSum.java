import java.util.*;

public class TwoSum
{
    
    public static boolean twoSum(int[] array, int target){
        
        Arrays.sort(array); // Sort the array.
        int startIndex=0, endIndex=array.length-1, sum=0; // Declare variables.
        
        // Compute two sum operations.
        while(startIndex < endIndex){
            
            sum = array[startIndex] + array[endIndex];
            
            if(sum == target) return true;
            else if(sum < target) startIndex++;
            else endIndex--;
            
        }
        
        return false;
        
    }
    
	public static void main(String[] args) {
	    
	    Scanner scan = new Scanner(System.in);
	    int sizeOfArray = 0, target = 0; // Declare variables.
	    
		System.out.print("Enter the size of an array: "); // Message for user.
		sizeOfArray = scan.nextInt(); // Take input from user.
		
		int[] array = new int[sizeOfArray]; // Declare array.
		System.out.println("Enter the elements of an array: "); // Message for user.
		for(int index=0; index<sizeOfArray; index++){
		    array[index] = scan.nextInt(); // Take input from user.
		}
		
		System.out.print("Enter the target value: "); // Message for user.
		target = scan.nextInt(); // Take target input from user.
		
		if(twoSum(array,target)){
		    System.out.println("Yes");
		}else{
		    System.out.println("No");
		}
		
	}
}
