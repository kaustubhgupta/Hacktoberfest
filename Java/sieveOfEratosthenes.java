import java.util.Scanner;

public class sieveOfEratosthenes {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		//Creating a boolean array prime[0..size]
		boolean prime[] = new boolean[num+1];
		
		//Implementing sieve
		for(int i=2;i*i<=num;i++) {
			//If value of prime[i] does not changes then its prime
			if(prime[i]) {
				//Multiples of prime[i] will not be prime
				for(int j=i*i;j<=num;j+=i) {
					prime[j] = false;
				}
			}
		}
		
		//Printing all prime numbers till num
		for(int i=2;i<=num;i++) {
			if(prime[i]) {
				System.out.print(i+" ");
			}
		}
	}
}
