
package mergesort;

public class MergeSort {

    //method to merge left and right sublist which are passed as argument
    public static void Merge(int[] L, int[] R, int[] A){
        
        //length of left half of the passed array
        int nl = L.length;
        
        //length of right half of the passed array
        int nr = R.length;
        
        int i, j, k;
        i = j = k = 0;
        
        //this loop fills or overwrites an array A with the elements in arrays L and R
        //the filling of elements is such that at the end Merge() function call,
        //the array A passed as argument will have elements in sorted order 
        while(i < nl && j < nr)
        {
            if(L[i] <= R[j]){
                A[k] = L[i];
                i++;
            }
            else{
                A[k] = R[j];
                j++;
            }
            k++;
        }
        
        //either of the below two while loops will run after the execution of above while loop
        //beacause either the array L or R will have the element/s in it lesser than the other
        while(i < nl)
        {
            A[k] = L[i];
            i++;
            k++;
        }
        while(j < nr)
        {
            A[k] = R[j];
            j++;
            k++;
        }
    }
    
    //A recursive MergeSort() function which will have the array that needs to be sorted as its argument
    public static void MergeSort(int[] A){
        int n = A.length;
        
        //Base condition
        //if length of A is 1 or less than 2, it means the array is already sorted
        if(n < 2)
            return;
        
        int mid = n/2;
        
        //declaring left sublist or subarray
        int[] left = new int[mid];
        
        //declaring right sublist or subarray
        int[] right = new int[n-mid];
        
        int i = 0;
        
        //populating left subarray
        for(i = 0; i < mid; i++)
        {
            left[i] = A[i];
        }
        
        //populating right subarray
        for(i = mid; i < n; i++)
        {
            right[i-mid] = A[i];
        }
        
        //recursive call to MergeSort() to sort left sublist
        MergeSort(left);
        
        //recursive call to MergeSort() to sort right sublist
        MergeSort(right);
        
        //call to Merge() to merge two halfs(left and right
        //the arguments here are left subarray, right subarray and the Array A 
        Merge(left, right, A);        
    }
    
    public static void main(String[] args) {
        
        int[] arr = {15,48,100,0,6,1,15,1,4,5};
        System.out.println("Array before Merge Sort:");
        for(int i = 0;i < arr.length;i++)
        {
            System.out.print(arr[i]+" ");
        }
        
        //call to MergeSort() passing arr as an argument
        MergeSort(arr);
        
        System.out.println("\nArray after Merge Sort:");
        for(int i = 0;i < arr.length;i++)
        {
            System.out.print(arr[i]+" ");
        }        
    }
    
}
