/*
        Simple program based on basics of java
        i.e. Input/Output and simple decision making
        with very well formatted Output
*/
import java.util.Scanner;
import java.io.*;
public class Game
{
    public static void main(String args[])throws FileNotFoundException,IOException
    {
        FileInputStream fis=new FileInputStream("questions.txt");
        Scanner in=new Scanner(System.in);
        Scanner sc=new Scanner(fis);
        System.out.println("==========================================================");
        System.out.println("WELCOME TO WHO WANT TO BE TOKEN KING");
        System.out.println("==========================================================");
        System.out.print("enter your name : ");
        String name;
        name=in.nextLine(); // Name of Player is inputted here
        System.out.println("==========================================================");
        System.out.println();
        System.out.println();
        System.out.println();
        int s=0;
        System.out.println("%%%%%%%% Instruction are as follows %%%%%%%%%");// Instruction for Playing
        System.out.println("1.You must not attempt to use any unfair way to answer the questionss");
        System.out.println("2.Five question will be asked by us, you must answer them by giving its respective  letter/option");
        System.out.println("3.If you answer all 5 questions correctly then you will be given your token back");
        System.out.println("==========================================================");
        System.out.println("==========================================================");

        System.out.println();
        int n=sc.nextInt();
        sc.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");// skips new line character

        for(int i=1;i<=n;i++)//loop for displaying questions from file
        {
            System.out.print(i+".");
            System.out.println(sc.nextLine());
            System.out.println(sc.nextLine());
            System.out.println(sc.nextLine());
            char ans = in.next().charAt(0);
            char cans = sc.next().charAt(0);
            sc.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            if ((ans == cans) || (ans == cans - 32))
            {
                s++;
                System.out.println("Your answer is correct");
            }
            else
            {
                System.out.println("Your answer is wrong");
            }
            System.out.println("==========================================================");
            System.out.println();
        }

        System.out.println("************ RESULTS *******************"); // Displaying result
        System.out.println("Name of Player is "+name);
        if(s==5)
            System.out.println("CONGRATULATION, YOU HAVE WON YOUR TOKEN BACK");
        else
        {
            System.out.println("BETTER LUCK NEXT TIME");
        }
        System.out.println("Your score is = "+s+"/5");
        System.out.println("Thank you for playing our game");
    }
}







