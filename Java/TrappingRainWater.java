import java.util.*;

public class TrappingRainWater {
    public static void main(String[] args) {
        int no_of_bldg;
        Scanner sc  = new Scanner(System.in);

        //taking the "number of buildings" input from user
        no_of_bldg = sc.nextInt();
        int[] arr = new int[no_of_bldg];

        //taking the height of each building from the user and storing in the array arr[]
        for (int i = 0; i < no_of_bldg; i++) {
            arr[i] = sc.nextInt();
        }

        //printing the returned variable in the Calculation() function
        System.out.println(Calculation(arr));
    }

    static int Calculation(int[] a) {

        int result = 0;
        int[] left = new int[a.length];
        int[] right = new int[a.length];

        //comparing the 0th bldg height to each building from left to right and storing the max of both
        left[0] = a[0];
        for (int i = 1; i < a.length; i++) {
            left[i] = Math.max(left[i-1],a[i]);
        }

        //comparing the last bldg height to each building from right to left and storing the max of both
        right[(a.length)-1] = a[(a.length)-1];
        for (int i = (a.length)-2; i >= 0; i--) {
            right[i] = Math.max(right[i+1],a[i]);
        }

//        Now finding the min at a location from right[] and left[] array, because water stored will be the difference
//        of min of left[]and right[] and height of that particular building.
        for (int i = 0; i < a.length; i++) {
            result += Math.min(left[i],right[i]) - a[i];
        }
        return result;
    }
}