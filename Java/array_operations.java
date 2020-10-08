package start;
import java.util.*;
public class array_operations 
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("inserting elements in array");
		System.out.println("enter number of elements:");
		int n=sc.nextInt();
		System.out.println("enter "+n+" elements");
		int array[]=new int[n+1];
		for(int i=0;i<n;i++)
			array[i]=sc.nextInt();
		System.out.println("Searching element");
		System.out.println("enter the element to be searched:");
		int k=sc.nextInt();
		int flag=0,i=0;
		for(i=0;i<n;i++)
		{
			if(array[i]==k)
			{
				System.out.println("element found at "+i+1+" position");
				flag=1;
			}
		}
		if(i>=n && flag==0)
			System.out.println("element not found");
		System.out.println("sorting elements in an array");
		Arrays.sort(array);
		for(i=0;i<n;i++)
			System.out.print(array[i]+" ");
	}
}
