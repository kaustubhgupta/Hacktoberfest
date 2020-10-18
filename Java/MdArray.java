package Self;
import java.util.Scanner;

public class MdArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the matrces:");
        int n = sc.nextInt();                                                                                                
        int arr[][] = new int[n][n];
        int brr[][] = new int[n][n];
        int crr[][] = new int[n][n];
        System.out.println("First Matrix:");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        System.out.println("Second Matrix:");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                brr[i][j] = sc.nextInt();
            }
        }
        System.out.println("The Entered Matrices Are:");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                System.out.print(arr[i][j]+" ");
            }
            System.out.println("");
        }
        System.out.println("And");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                System.out.print(brr[i][j]+" ");
            }
            System.out.println("");
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                crr[i][j]=arr[i][j]+brr[i][j];
            }
        }
        System.out.println("The Sum of 2 is:");
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                System.out.print(crr[i][j]+" ");
            }
            System.out.println("");
        }
    } 
}
