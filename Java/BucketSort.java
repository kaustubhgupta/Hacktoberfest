//Bucket Sort is an sorting algoritm in which we sort numbers by distributing among buckets.
//Further they are individually sorted.
import java.io.*;
import java.util.*;
 
public class BucketSort {
 
	public static int[] bucketSort(int[] arr, int len) {
	Map<Integer, Integer> frequency= new HashMap<Integer, Integer>();
	List<Integer>[] bucket = new List[arr.length + 1];
        List<Integer> result = new ArrayList();
        for (int n : arr) {
            frequency.put(n, frequency.getOrDefault(n, 0) + 1);
        }
      
        for (int i = 0; i < bucket.length; i++){ 
			bucket[i] = new ArrayList();
		}	
        for (int key : frequency.keySet()) {
            bucket[frequency.get(key)].add(key);
        }
        
        
        for (int i = bucket.length - 1; i >= 0; i--) {
            result.addAll(bucket[i]);
            if (result.size() >= len){ 
			break;
			}
        }

		return result.stream().mapToInt(Integer::intValue).toArray();
	}
    
	public static void main(String[] args) {
      
      int arr[] = {118,50,21,90,655,1,29,11};
	  System.out.println("Original Array: " + Arrays.toString(arr));
	  arr=bucketSort(arr, arr.length);
	  System.out.println("Array after Bucket Sort: " + Arrays.toString(arr));
		
   }
}
