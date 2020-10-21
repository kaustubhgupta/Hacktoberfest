import java.io.*;
import java.util.Scanner;
class Pqueue
{
	public int max;
	public int arr[];
	public int count;
	public Pqueue(int s)
	{
		arr=new int[s];
		max=s;
		count=0;
	}
	public void insert(int item)
	{
		if(count==0)
			arr[count++]=item;
		else
		{
			int j;
			for(j=count-1;j>=0;j--)
			{
				if(item<arr[j])
					arr[j+1]=arr[j];
				else
					break;
			}
			arr[j+1]=item;
			count++;
		}
	}
	public int delete()
	{
		return arr[--count];
	}
	public static void main(String[] args)
	{
		int num;
		Pqueue P=new Pqueue(5);
		Scanner myObj=new Scanner(System.in);
		for(int i=0;i<5;i++)
		{
			num=myObj.nextInt();
			P.insert(num);

		}

		for(int i=0;i<5;i++)
		{
			System.out.println(P.delete());
		}
	}
}