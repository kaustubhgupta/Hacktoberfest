import java.util.Scanner;

public class JugglingAlgorithm {

  //GCD calculator
	
	static int gcd(int a, int b) {
		if(b==0)
		{
			return a;
		}
		else
		{
			return gcd(b,a%b);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		for(int i=0;i<n;i++) {
			a[i] = sc.nextInt();
		}
    
    //Juggling Algorithm starts
    
		System.out.println("Enter the number upto which you want to rotate the array :- ");
		int k = sc.nextInt();
		int gcd = gcd(k, n);
		for(int i=0;i<gcd;i++)
		{
			int temp = a[i];
			int j = i;
      //Infinite loop
			for(;;)
			{
				int d = j + k; 
	            if (d >= n) 
	            {
	                d = d - n; 
	            }
	  
	            if (d == i) 
	            {
	                break; 
	            }
	  
	            a[j] = a[d]; 
	            j = d;
			}
			a[j] = temp;
		}
		for(int i : a) {
			System.out.print(i+" ");
		}
	}

}
