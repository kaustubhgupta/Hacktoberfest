public class TowerOfHanoi {
    public static void towerOfHanoiPrint(int n, char source, char destination, char helper) {
        if (n == 1) {
            System.out.println("Move the 1st disk from " + source + " to Destination " + destination);
            return;
        }
        towerOfHanoiPrint(n - 1, source, helper, destination);
        System.out.println("Move the " + n + "th disk from " + source + " to Destination " + destination);
        towerOfHanoiPrint(n - 1, helper, destination, source);
    }

    public static long toh(int N, char from, char to, char aux) {
        long count = 0;
        if (N > 0) {
            count = toh(N - 1, from, aux, to);
            // System.out.println("move disk " + N + " from rod " + from + " to rod " + to);
            count++;
            count += toh(N - 1, aux, to, from);
        }
        return count;
    }

    public static void main(String args[]) {
        System.out.print("Steps required : \n");
        towerOfHanoiPrint(3, 'A', 'C', 'B');

        System.out.print("Count of Steps : ");
        System.out.println(toh(3, 'A', 'C', 'B'));
    }
}