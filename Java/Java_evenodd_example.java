import java.util.Scanner;
//This code tells whether a given number is even or odd
public class Java_evenodd_example {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int num = sc.nextInt();
        System.out.println(num % 2 == 0 ? "The number is even" : "The number is odd");
        sc.close();
    }
}
