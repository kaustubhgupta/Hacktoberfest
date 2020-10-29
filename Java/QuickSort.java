public class QuickSort {
    static void swap(int [] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    static int partition(int [] arr, int left, int right) {
        int pivot = arr[right];
        int i = (left-1);
        for (int j=left; j<right; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i+1, right);
        return i+1;
    }

    static void sort(int [] arr, int left, int right) {
        if (left < right) {
            int pivot = partition(arr, left, right);
            sort(arr, left, pivot-1);
            sort(arr, pivot+1, right);
        }
    }

    public static void main(String[] args) {
        // print
        int [] arr = {10, 7, 8, 9, 1, 5};
        System.out.println("before quick sort");
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("");

        // quick sort
        QuickSort.sort(arr, 0, arr.length-1);

        // print
        System.out.println("quick sort!");
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
} 