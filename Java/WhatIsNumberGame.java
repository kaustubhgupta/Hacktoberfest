

import java.util.Random;
import java.util.Scanner;


/**
 * Game to guess the number, 
 * the program will generate an random number and the player will have 5 chances to try 
 * to get the number that the program generated, this number is between 1 to 20.
 * 
 * @author Jackson Roberio (http://jacksonroberio.com.br)
 **/
public class WhatIsNumberGame {

	//This is the number that the user will have to guess to win the game.
	private static int victoryNumber;
	
	//Count of user attempts
	private static int attempts;
	
	//redemption of the amount entered
	private static Scanner scan;
	
	public static void main(String[] args) throws InterruptedException  {
		System.out.println("Welcome to the Game: What's the Number?!!\n");
		startVariables();
		
		System.out.println("Let's start?\n -> choose a number, that number must be between 1 to 20 and you will have 5 attempts to get the number right.");
		System.out.println("Enter the chosen number:");
	
	
		for (int attempts = 4; attempts >= 0; attempts--) {
			int numberSelected = scan.nextInt();
			wait3Seconds();
			if(isNumberTrue(numberSelected)) {
				System.out.println("Congratulation, you do select number true!!!");
				System.out.println("The End Game, thank you for playing.");
				return ;
			} else if(attempts > 0) {
				System.out.println("You have " + attempts + " attempts.\n");
				System.out.println("Let's go again? Enter a new number between 1 to 20:");
			}
		}
		
		System.out.println("You have wasted all your attempts and cannot guess the correct number.");
		System.out.println("The correct number is: " + victoryNumber);
	}
	
	
	/**
	 * checks if the chosen number is the hidden number.
	 **/
	private static boolean isNumberTrue(int number) {
		if(number == victoryNumber) {
			return true;
		} else if(number > victoryNumber) {
			System.out.println(number + " is not the correct number, the value is less.");
			return false;
		} else {
			System.out.println(number + " is not the correct number, the value is higher.");
			return false;
		}
	}
	
	
	/**
	 * Generates an random number from 1 to 20, this number is the number that the user needs to guess.
	 **/
	private static int generateRandomNumber() {
        Random random = new Random();
        return random.nextInt(20);
	}
	
	/**
	 * time to wait to make a suspense and make the game more fun.
	 **/
	private static void wait3Seconds() throws InterruptedException  {
		for(int seconds = 3; seconds > 0; seconds--) {
			System.out.println(".");
			new Thread().sleep(1000);
		}
	}
	
	/**
	 * Instance the variables defined in the class.
	 **/
	private static void startVariables(){
		victoryNumber = generateRandomNumber();
		scan = new Scanner(System.in);
		attempts = 1;
	}
	
}
