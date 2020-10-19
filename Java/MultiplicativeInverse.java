/**
 * Description: finds the multiplicative inverse a^{-1} of a (mod b)
 * such that a^{-1}*a = 1 (mod b)
 * Runtime: O(log(b)) (I think)
 */

public class MultiplicativeInverse {
    /**
     * inverses[0] = a^{-1}
     * inverses[1] = b^{-1}
     * @return gcd(a, b)
     */
    public static int egcd(int a, int b, int[] inverses) {
        if (b == 0) {
            inverses[0] = 1;
            inverses[1] = 0;
            return a;
        }

        int gcd = egcd(b, a % b, inverses);
        int temp = inverses[0];
        inverses[0] = inverses[1];
        inverses[1] = temp - ((a/b) * inverses[1]);
        return gcd;
    }

    /**
     * a and b are 2 distinct coprime integers
     */
    public static void findInverse(int a, int b) {
        int[] inverses = {0,0};

        int gcd = egcd(a, b, inverses);
        if (gcd != 1) {
            System.out.println("Inputs are not coprime!");
        } else {
            System.out.println(a + "^{-1} = " + inverses[0] + " (mod " + b + ")");
            System.out.println(b + "^{-1} = " + inverses[1] + " (mod " + a + ")");
        }
    }

    public static void main(String args[]){
        int a = 7;
        int b = 60;
        findInverse(a,b);
    }
}