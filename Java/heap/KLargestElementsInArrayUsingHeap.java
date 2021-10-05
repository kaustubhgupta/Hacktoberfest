import java.util.Collections;
import java.util.PriorityQueue;

public class KLargestElementInArrayUsingHeap {
    public static void main(String[] args) {
        int arr[] = { 1, 3, 98, 1, 15, 5, 4,64, 88, 96, 50, 45 };
        int size = arr.length;
        int k = 3;
        findKLargestElements(arr,size,k);

    }
    public static void findKLargestElements(int arr[], int size, int k)
    {
        PriorityQueue<Integer> max_heap = new PriorityQueue<>(Collections.reverseOrder());
        for(int index = 0;index < size;index++)
        {
            //add every elements into the max_heap
            max_heap.add(arr[index]);
        }
        while (k-- > 0)
        {
            //print first k elements
            System.out.println(max_heap.poll());
        }



    }
}
