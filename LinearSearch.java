import java.util.*;
public class LinearSearch {
    public static void main(String [] args){
        Random rd = new Random();
        Scanner sc= new Scanner(System.in);
        System.out.println("enter the lower limit of your array");
        int min = sc.nextInt();
        System.out.println("enter the highest limit of your arrray");
        int max = sc.nextInt();
        int[] arr = new int[151515];
        for (int i = 0; i < arr.length; i++){
        arr[i] = min + rd.nextInt(max-min);
        }
        System.out.println("enetr the number that you want to check in the array");
        int num = sc.nextInt();
        long start = System.nanoTime();
        linearSearch(num, arr);
        long end = System.nanoTime();
        long elapsedTime = end - start;
        System.out.println("the time taken is "+(elapsedTime/1000+" micro seconds"));
        sc.close();
    }

    public static void linearSearch(int num,int[] arr){
        int i;
        //for loop to search element by index wise
        for(i=0;i<arr.length;i++){
            if(arr[i]==num){
                System.out.println("element found at : index "+i);
                //break loop we need the first index
                break;
            }
        }
        //if index reaches arr.length then search is unsuccesssful
        if(i==arr.length)
        System.out.println("element not found : index -1");
    }
}
