/*To check whether a number is prime or not in a given range(1 to n)*/


import java.util.Arrays;

public class SOE {

	public static void main(String[] args) {
 		// TODO Auto-generated method stub
 		//input a number n using Scanner
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();		
		find(n);

	}

	public static void find(int n) {
		boolean a[] = new boolean[n + 1];
//initialise array a with true
		Arrays.fill(a, true);
//as 0 and 1 are not prime numbers, assign it with false
		a[0] = false;
		a[1] = false;
//check for multiples
		for (int table = 2; table * table <= n; table++) {
			if (a[table] == false)
				continue;
			for (int mul = 2; mul * table <= n; mul++) {
				a[table * mul] = false;

			}
		}
		for (int i = 0; i < n; i++) {
//if a[i]is true then that number is a prime number
			if (a[i])
				System.out.println(i);
		}

	}

}

