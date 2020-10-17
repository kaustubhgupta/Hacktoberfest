// Program to print all prime factors 
import java.util.*; 
import java.lang.Math; 
  
public class PrimeFactorsOfNumbers
{ 
    // A function to print all prime factors 
    // of a given number n 
    public static void primeFactors(int num) 
    { 
        // Print the number of 2s that divide n 
        while (num%2==0) 
        { 
            System.out.print(2 + " "); 
            num /= 2; 
        } 
  
        // n must be odd at this point.  So we can 
        // skip one element (Note i = i +2) 
        for (int i = 3; i <= Math.sqrt(num); i+= 2) 
        { 
            // While i divides n, print i and divide n 
            while (num%i == 0) 
            { 
                System.out.print(i + " "); 
                num /= i; 
            } 
        } 
  
        // This condition is to handle the case whien 
        // n is a prime number greater than 2 
        if (num > 2) 
            System.out.print(num); 
    } 
  
    public static void main (String[] args) 
    { 
        Scanner in=new Scanner(System.in);
        //Enter the number as input
        int number=in.nextInt();
        
        primeFactors(number); 
    } 
} 