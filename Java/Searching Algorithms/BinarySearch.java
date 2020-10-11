public class BinarySearch{  
 public static void binarySearch(int arr[], int first, int last, int key){  
   int mid = (first + last)/2;  
   while( first <= last ){ 
            // If element is greater than mid, then 
            // it can only be present in right subarray 
      if ( arr[mid] < key ){  
        first = mid + 1;     
      }
     // If the element is present at the 
            // middle itself 
    else if ( arr[mid] == key ){    
        System.out.println("Element is found at index: " + mid);  
        break;  
      }
    // If element is less than mid, then 
    // it can only be present in left subarray 
    else{  
         last = mid - 1;  
      }  
      mid = (first + last)/2;  
   }  
   if ( first > last ){  
      System.out.println("Element is not found!");  
   }  
 }  
 public static void main(String args[]){  
        int arr[] = {10,20,30,40,50};  
        int key = 30;  
        int last=arr.length-1;  
        binarySearch(arr,0,last,key);     
 }  
}  
