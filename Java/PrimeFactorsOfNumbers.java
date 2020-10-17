import java.util.Scanner;

public class PrimeFactorsOfNumbers {

    public static void main(String args[]){

        Scanner in=new Scanner(System.in);
        //input the number
        int num= in.nextInt();
        for(int i=1;i<=num;i++){
            if(num%i==0){
                //Calling fuction Prime to check whether the factor is prime or not
                boolean isPrime=Prime(i);
                if(isPrime){
                    //The prime factors eventually printed
                    System.out.print(i+" ");
                }
            }
        }
        System.out.println();
    }
    //Prime is the function that finds the Prime factors of number
    public static boolean Prime(int fact)
    {
        int count=0;
        for(int j=1;j<=fact;j++){
            if(fact%j==0){
                count++;
            }
        }
        // A prime condition that it has only 2 factors
        if(count==2){
            return true;
        }
        else{
            return false;
        }
    }
}
		