import java.io.*;
import java.util.Scanner;
class linkList
{
   Node head;
     static class Node
     {
      int data;
      Node next;
       Node(int d)
       {
       data=d;
       next=null;
       }

     } 
       public static void fun (Node head)
{
if (head==null)
return;
fun (head. next) ;
System. out.println (head.data) ;


    }
    public static linkList insert(linkList list,int data)
    {
    Node new_node=new Node(data);
    new_node.next=null;
    if(list.head==null)
    {
    list.head=new_node;
    }
    else
    {
    Node last=list.head;
    while(last.next!=null)
    {
    last=last.next;
    }
    last.next=new_node;
    }
      return list;
    }
    public static void printList(linkList list)
    {
    Node currNode=list.head;
    System.out.println("The Linked list is : ");
    while(currNode!=null)
    {
    System.out.println(currNode.data+ " ");
    currNode=currNode.next;
    }
    }
	public static void main(String args[])
	{
	int n;
	Scanner obj=new Scanner(System.in);
     linkList list=new linkList();

     System.out.println("Enter the number you want to enter in the list");
     n=obj.nextInt();

     for(int i=0;i<n;i++)
     {
     list=insert(list,obj.nextInt());
     }
     printList(list);
   fun(list.head);
 } 

}