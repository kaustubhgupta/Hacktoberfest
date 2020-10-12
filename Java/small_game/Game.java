/*
        Simple program based on basics of java
        i.e. Input/Output and simple decision making
        with very well formatted Output
*/
import java.util.Scanner;
public class Game
{
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        System.out.println("==========================================================");
        System.out.println("welcome to WHO WHANT TO BE TOKEN KING");
        System.out.println("==========================================================");
        System.out.print("enter your name : ");
        String name;
        name=in.nextLine(); // Name of Player is inputted here
        System.out.println("==========================================================");
        System.out.println();
        System.out.println();
        System.out.println();
        int s=0;
        System.out.println("%%%%%%%%Instruction are as follows%%%%%%%%%");// Instruction for Playing
        System.out.println("1.You should not do any cheating");
        System.out.println("2.Five question will be asked answer them by giving its respective  letter");
        System.out.println("3.If you give all 5 questions correctly u will be given ur token back");
        System.out.println("==========================================================");
        System.out.println("==========================================================");

        System.out.println();
        System.out.println("1.How many members are nominated by president in lok sabha in india"); // Question 1
        System.out.println("\ta(1)\tb(2)\n\tc(10)\td(12)");
        char a;
        a=in.next().charAt(0);
        if((a=='b')||(a=='B'))
        {
            s=s+1;
            System.out.println("your answer is correct");
        }
        else
        {
            System.out.println("your answer is wrong");
        }
        System.out.println("==========================================================");
        System.out.println();
        System.out.println("2.The reserve bank of india was nationalised in the year of"); // Question 2
        System.out.println("\ta(1935)\tb(1947)\n\tc(1948)\td(1949)");
        char a1;
        a1=in.next().charAt(0);
        if((a1=='d')||(a1=='D'))
        {
            s=s+1;
            System.out.println("ur answer is correct");
        }
        else
        {
            System.out.println("your answer is wrong");
        }
        System.out.println("==========================================================");
        System.out.println();
        System.out.println("3.Indian army day is celebrated in india every year on"); // Question 3
        System.out.println("\ta(8 oct)\tb(7 oct)\n\tc(7 dec)\td(8 sept)");
        char a2;
        a2=in.next().charAt(0);
        if((a2=='a')||(a2=='A'))
        {
            s=s+1;
            System.out.println("ur answer is correct");
        }
        else
        {
            System.out.println("your answer is wrong");
        }
        System.out.println("==========================================================");
        System.out.println();
        System.out.println("4.Which among the following standard protocols is the most widely used by the internet"); // Question 4
        System.out.println("\ta(HTTP)\tb(TCP/IP)\n\tc(SMTP)\td(SLIP)");
        char a3;
        a3=in.next().charAt(0);
        if((a3=='b')||(a3=='B'))
        {
            s=s+1;
            System.out.println("ur answer is correct");
        }
        else
        {
            System.out.println("your answer is wrong");
        }
        System.out.println("==========================================================");
        System.out.println();
        System.out.println("5.Which part of the computer is used for storing information"); // Question 5
        System.out.println("\ta(monitor)\t\tb(keyboard)\n\tc(disk drive)\td(printer)");
        char a4;
        a4=in.next().charAt(0);
        if((a4=='c')||(a4=='C'))
        {
            s=s+1;
            System.out.println("ur answer is correct");
        }
        else
            System.out.println("your answer is wrong");
        System.out.println("==========================================================");
        System.out.println();
        System.out.println("************RESULTS*******************"); // Result will be displayed
        System.out.println("Name of Player is "+name);
        if(s==5)
            System.out.println("CONGRATULATION U HAVE WON UR TOKKEN BACK");
        else
        {
            System.out.println("BETTER LUCK NEXT TIME");
        }
        System.out.println("Your score is = "+s+"/5");
        System.out.println("thank you for playing our game");
    }
}







