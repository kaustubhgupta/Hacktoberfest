class combsort{ 
    
    //return gap between elements of array
    int getGap(int gapp) 
    { 
        gapp =(gapp*10)/13; 
        if (gapp < 1) 
            return 1; 
        return gapp; 
    } 
  
    // Main sorting function
    void sortArr(int arr[]) 
    { 
	int n=arr.length;
	int gapp = n; 
        boolean swapped = true;  //keep track if swapped
  	// run while gap is more than 1 and last  
        while (gapp!= 1 || swapped==true) 
        {  
            gapp = getGap(gapp);  // Find next gap
  	    //set swap to zero to check if swap happened or not
            swapped= false; 
  	    // Compare elements
            for (int i=0;i<n-gapp;i++) 
            { 
                if (arr[i]>arr[i+gapp]) 
                { 
                    // Swap elements
                    int temp = arr[i]; 
                    arr[i] = arr[i+gapp]; 
                    arr[i+gapp] = temp; 
  		    // Set swapped to true
                    swapped = true; 
                } 
            } 
        } 
    } 
  
   //main method and starting point
    public static void main(String args[]) 
    { 
        combsort objcombSort = new combsort (); //class object instance
        int unsorted[] = {7, 5, 2, 59, 6, -4, 25, -9, 27, 0}; //array initialization
        objcombSort.sortArr(unsorted); 
  
        System.out.println("Array in sorted form"); 
        for (int i=0; i<unsorted.length; ++i){ 
             System.out.print(unsorted[i] + " ");
	} 
  
    } 
} 
