import java.util.*;
public class TwoSum {
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter the array size:");
      int n = sc.nextInt();
      System.out.print("Enter the target value:");
      int target = sc.nextInt();
      System.out.print("Enter array inputs:");
      int[] nums = new int[n];
      for(int i = 0; i < n; i++)
      {
          nums[i] = sc.nextInt();
      }
      boolean res = twoSum(nums, target);
      System.out.print(res);
    }
    
    public static boolean twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map=new HashMap<>(); 
        int diff;
        for(int i = 0;i < nums.length; i++)
        {
            diff = target - nums[i];
            if(map.containsKey(diff))
                return true;
            map.put(nums[i], i);
        }
        return false;
    }

}