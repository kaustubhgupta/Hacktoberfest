import java.util.Scanner;

/**
 * Description: with num1 = a, num2 = b,
 * finds the multiplicative inverse a^{-1} of a (mod b) using Extended Euclid's
 * such that a^{-1}*a = 1 (mod b)
 */

public class MultiplicativeInverse {
    /**
     * Runs Extended Euclid's algorithm.
     * inverses[0] = a^{-1}
     * inverses[1] = b^{-1}
     * @return gcd(num1, num2)
     */
    public static int egcd(int num1, int num2, int[] inverses) {
        if (num2 == 0) {
            inverses[0] = 1;
            inverses[1] = 0;
            return num1;
        }

        int gcd = egcd(num2, num1 % num2, inverses);
        int temp = inverses[0];
        inverses[0] = inverses[1];
        inverses[1] = temp - ((num1/num2) * inverses[1]);
        return gcd;
    }

    /**
     * Finds inverses of num1 and num2
     * where num1 and num2 are distinct coprime integers
     */
    public static void findInverse(int num1, int num2) {
        int[] inverses = {0,0};

        int gcd = egcd(num1, num2, inverses);
        if (gcd != 1) {
            System.out.println("Inputs are not coprime!");
        } else {
            System.out.println(num1 + "^{-1} = " + inverses[0] + " (mod " + num2 + ")");
            System.out.println(num2 + "^{-1} = " + inverses[1] + " (mod " + num1 + ")");
        }
    }

    /**
     * Runs some tests to make sure code works. Std out should match comments.
     */
    public static void test() {
        System.out.println("-------------");
        findInverse(10, 23);
        // 10^{-1} = 7 (mod 23)
        // 23^{-1} = -3 (mod 10)

        System.out.println("-------------");
        findInverse(11, 2);
        // 11^{-1} = 1 (mod 2)
        // 2^{-1} = -5 (mod 11)

        System.out.println("-------------");
        findInverse(60, 30);
        // Inputs are not coprime!
    }

    /**
     * Given two distinct coprime integers, finds multiplicative inverses of both.
     * @param args run with argument "test" to run test cases
     */
    public static void main(String args[]) {
        // for testing
        if (args.length == 1 && args[0].compareTo("test") == 0) {
            test();
            return;
        }

        int num1;
        int num2;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two coprime integers separated by a space: ");
        num1 = sc.nextInt();
        num2 = sc.nextInt();
        findInverse(num1,num2);
    }

}
