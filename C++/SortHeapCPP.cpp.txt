    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
#define parent(i) ((i-1)/2)
#define left(i)   (2 * i + 1)
#define right(i)  (2 * i + 2)
void swap(int arr[], int i1, int i2)
{
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()
void heapify(int arr[], int n, int i)  {
      // Your Code Here
      int max = i;
      int l = left(i);
      int r = right(i);
      if (l < n && arr[max] < arr[l]) {
          max = l;
      }
      if (r < n && arr[max] < arr[r]) {
          max = r;
      }
      if (max != i) {
          swap(arr, i, max);
          heapify(arr, n, max);
      }
}

// Rearranges input array so that it becomes a min heap
void buildHeap(int arr[], int n)  { 
    // Your Code Here
    for (int i = (n-1)/2; i >= 0; i--) {
        heapify(arr, n, i);
        
    }
}
