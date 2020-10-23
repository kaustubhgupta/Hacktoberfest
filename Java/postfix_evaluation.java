import java.util.*;

public class postfix_evaluation 
{ 
	static int postfixEval(String expression) 
	{ 
		Stack<Integer> stack=new Stack<>(); 
		for(int i=0;i<expression.length();i++) 
		{ 
			char d = expression.charAt(i); 
                        // if character is an operator(digit), push it to the stack
			if(Character.isDigit(d)) 
			stack.push(d - '0'); 
			
                        // if character is operand, pop 2 elements from stack and perform
                        // operation with the operator
			else
			{ 
				int num1 = stack.pop(); 
				int num2 = stack.pop(); 
				
				switch(d) 
				{ 
					case '+': 
						stack.push(num1 + num2); 
						break; 
					
					case '-': 
						stack.push(num2 - num1); 
						break; 
					
					case '/': 
						stack.push(num2/num1); 
						break; 
					
					case '*': 
						stack.push(num2*num1); 
						break;
					
					default:
						break;
						
						
			} 
			} 
		} 
		return stack.pop();	 
	} 

	public static void main(String[] args) 
	{ 
                Scanner s = new Scanner(System.in);
                System.out.println("Enter Expression: ");
                // accepting expression from user
                String expression = s.nextLine();
		System.out.println("Postfix evaluation result: "+ postfixEval(expression)); 
	} 
} 
