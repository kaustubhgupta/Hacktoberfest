import java.io.*;
import java.util.*;
public class KMaxMinElement {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        while(T-->0){
            int x = Integer.parseInt(br.readLine());
        
            int[] arr = new int[x];
            
            String[] st = br.readLine().split(" ");
            
            int k = Integer.parseInt(br.readLine());
            
            for(int i=0;i<x;i++){
                arr[i] = Integer.parseInt(st[i]);
            }
            
            Arrays.sort(arr);
    
            System.out.println("Kth min element: " +arr[k-1]);
            System.out.println("Kth max element: " +arr[x-k]);
        }
    }
}
