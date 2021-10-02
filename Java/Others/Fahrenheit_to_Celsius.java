import java.util.Scanner;

public class Fahrenheit_to_Celsius {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		float f, c;
		System.out.print("Enter temperature in Fahrenheit : ");
		f = s.nextFloat();
		//formula to convert Fahrenheit to Celsius 
		c = (float) ((f - 32)/1.8);
		System.out.println("Temperature in Celsius : "+c);
		

	}

}
