//java program to get factorial of an number using stack
import java.util.Scanner;
import java.util.Stack; 

public class factorial{ 
    public static void main(String[] args) 
    { 
        //Enter a number
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        
        //factorial of negative numbers doesnot exist
        if(n<0)
        {
            System.out.println("0");
            return;
        }
        
	Stack<Integer> stack = new Stack<>();
        
        //factorial can be calculated by multiplying all numbers from 1 to itself(i.e. n)
        //Initially push 1 into the stack
        stack.push(1);
        
        //pop the stack and multiply it with the incremented number and push it back into the stack
        //Repeat this till we multiply the last number i.e. "n"
        for(int i=1; i<=n; ++i)
        {
            stack.push(stack.pop()*i);
        }
        
        //pop the last value in the stack which is the required factorial and print it.
        System.out.println(stack.pop());
    }
}
