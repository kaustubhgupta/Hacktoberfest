// Created by : Samarth Bhandari
// Github : github.com/b-samarth


package Calculator;

import java.lang.*;
import java.util.Scanner;

public class Calculator {

    public static double add(double num1, double num2) {
        return num1 + num2;
    }

    public static double subtract(double num1, double num2) {
        return num1 - num2;
    }

    public static double divide(double num1, double num2) {
        return num1 / num2;
    }

    public static double multiply(double num1, double num2) {
        return num1 * num2;
    }

    public static double modulus(double num1, double num2) {
        return num1 % num2;
    }


    public static int factorial(int num) {
        if (num == 0)
            return 1;
        else 
            return num * factorial(num-1);
    }

    public static double exponent(double num1, double num2) {
        return Math.pow(num1,num2);
    }

    public static double squareroot(double num) {
        return Math.pow(num,0.5);
    }
    
    public static double nthroot(double num1, double num2) {
        return Math.pow(num1, (1 / num2));
    }

    public static String root(double num1, double num2, double num3) {
        double d = Math.pow(num2,2) - (4 * num1 * num3);
        double r1,r2,i;
        String sb = "The roots are ";
        if (d == 0) {
            r1 = num2/(-2 * num1);
            r2 = r1;
            sb = sb + "equal, they are : " + r1 + " and " + r2 + ".";
        }

        else if (d < 0) {
            r1 = num2/(-2 * num1);
            r2 = r1;
            i = Math.pow(-d,0.5) / (2 * num1);
            sb = sb + r1 + i + "i and " + r2 + i + "i.";
        }
        else if (d > 0) {
            r1 = -num2 + Math.pow(d,0.5) / (2 * num1);
            r2 = -num2 - Math.pow(d,0.5) / (2 * num1);
            sb = sb + r1 + " and " + r2 + ".";
        }
        return sb;
    }

    public static double naturalLog(double num) {
        return Math.log(num);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        double num1, num2, num3;
        int a;
        System.out.println("=============================================================================");
        System.out.println("1. Addition");
        System.out.println("2. Subtraction");
        System.out.println("3. Multiplication");
        System.out.println("4. Division");
        System.out.println("5. Modulus");
        System.out.println("6. Factorial");
        System.out.println("7. Power");
        System.out.println("8. Square Root");
        System.out.println("9. nth root");
        System.out.println("10. Roots of quadratic equation");
        System.out.println("11. Natural Logarithm");
        System.out.print("Type the number with respect to your desired operation : ");
        choice = sc.nextInt();
        switch (choice) {
            case 1:
                System.out.println("You chose Addition");
                System.out.print("Enter first number : ");
                num1 = sc.nextDouble();
                System.out.print("Enter second number : ");
                num2 = sc.nextDouble();
                System.out.println("The result is : " + add(num1, num2));
                break;
            case 2:
                System.out.println("You chose Subtraction");
                System.out.print("Enter first number : ");
                num1 = sc.nextDouble();
                System.out.print("Enter second number : ");
                num2 = sc.nextDouble();
                System.out.println("The result is : " + subtract(num1, num2));
                break;
            case 3:
                System.out.println("You chose Multiplication");
                System.out.print("Enter first number : ");
                num1 = sc.nextDouble();
                System.out.print("Enter second number : ");
                num2 = sc.nextDouble();
                System.out.println("The result is : " + multiply(num1, num2));
                break;
            case 4:
                System.out.println("You chose Division");
                System.out.print("Enter first number : ");
                num1 = sc.nextDouble();
                System.out.print("Enter second number : ");
                num2 = sc.nextDouble();
                System.out.println("The result is : " + divide(num1, num2));
                break;
            case 5:
                System.out.println("You chose Modulus");
                System.out.print("Enter first number : ");
                num1 = sc.nextDouble();
                System.out.print("Enter second number : ");
                num2 = sc.nextDouble();
                System.out.println("The result is : " + modulus(num1, num2));
                break;
            case 6:
                System.out.println("You chose Factorial");
                System.out.print("Enter the number : ");
                a = sc.nextInt();
                System.out.println("The result is : " + factorial(a));
                break;
            case 7:
                System.out.println("You chose Power");
                System.out.print("Enter first number : ");
                num1 = sc.nextDouble();
                System.out.print("Enter second number : ");
                num2 = sc.nextDouble();
                System.out.println("The result is : " + exponent(num1, num2));
                break;
            case 8:
                System.out.println("You chose Square Root");
                System.out.print("Enter the number : ");
                num1 = sc.nextDouble();
                System.out.println("The result is : " + squareroot(num1));
                break;
            case 9:
                System.out.println("You chose nth root");
                System.out.print("Enter first number : ");
                num1 = sc.nextDouble();
                System.out.print("Enter second number : ");
                num2 = sc.nextDouble();
                System.out.println("The result is : " + nthroot(num1, num2));
                break;
            case 10:
                System.out.println("You chose Roots of Quadratic Equation");
                System.out.print("Enter power of x^2 : ");
                num1 = sc.nextDouble();
                System.out.print("Enter power of x : ");
                num2 = sc.nextDouble();
                System.out.print("Enter constant value : ");
                num3 = sc.nextDouble();
                System.out.println(root(num1, num2, num3));
                break;
            case 11:
                System.out.println("You chose Natural Logarithm");
                System.out.print("Enter the number : ");
                num1 = sc.nextDouble();
                System.out.println("The result is : " + naturalLog(num1));
                break;
            default:
                System.out.println("Invalid Choice, Please Try Again!");
                try {
                    Thread.sleep(2000);
                } catch (Exception e) {
                    e.printStackTrace();
                }

                main(null);
                break;
        }
        System.out.println("=============================================================================");
        
    }
}