import java.io.*;
import java.util.Scanner;
class stack
{
private int arr[];
private int  top;
private int size;
stack(int s)
{

	arr=new int[s];
	size=s;
	top=-1;
}
public void push(int num)
{
if(isFull())
{
System.out.println("Stack Overflow");
System.exit(1);
}
System.out.println("Inserting "+num);
arr[++top]=num;
 	
 	}
public int pop()
{
	if(isEmpty())
	{
	System.out.println("Stack is underflow!!!");
	System.exit(1);
	}
	System.out.println("Removing "+peek());
	return arr[top--];

}
public int peek()
{
	if(!isEmpty())
	  return arr[top];
	else 
	 System.exit(1);

	return -1;
}
public int s()
{
	return top+1;
}
public boolean isEmpty()
{
	return top==-1;
}
public boolean isFull()
{
	return top==size-1;
}
public static void main(String[] args)

{
 Scanner myObj = new Scanner(System.in);
 System.out.println("Enter the number of elements!!");
 int i=myObj.nextInt();
 stack S=new stack(i);

 for(int j=0;j<i;j++)
 {
  int myInt=myObj.nextInt();
  S.push(myInt);

 }
 S.pop();

	
}
}