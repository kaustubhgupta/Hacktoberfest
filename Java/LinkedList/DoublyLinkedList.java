import java.util.Scanner;

public class DoublyLinkedList {
	
	class Node{
		int data;
		Node pre;
		Node next;
		Node(int data){
			this.data = data;
			pre = null;
			next = null;
		}
	}
	
	Node head;
	public static void main(String[] args) {
		DoublyLinkedList dll = new DoublyLinkedList();
//		dll.creatDLL(5);
//		dll.print();
//		dll.insertAtEnd(7);
//		dll.print();
//		dll.insertAtFirst(5);
//		dll.print();
//		dll.insertAtKthPosition(7 , 10);
//		dll.print();
//		dll.deleteAtFirst();
//		dll.print();
//		dll.deleteAtLast();
//		dll.print();
//		dll.deleteAtKthPosition(2);
//		dll.print();
	}
	
	/*********************Delete the element present at Kth position***********************/
	public void deleteAtKthPosition(int k) {
		Node temp = head;
		if(k < 1) {
			System.out.println("Underflow");
			return;
		}
		if(k == 1) {
			deleteAtFirst();
			return;
		}
		for(int i = 1 ; i < k-1 ; i++) {
			temp = temp.next;
		}
		Node store = temp;
		temp.next = temp.next.next;
		temp.pre = store;
	}

	/*********************Delete the last element of the List***********************/
	
	public void deleteAtLast() {
		Node temp = head;
		if(head == null) {
			System.out.println("List was already empty.");
			return;
		}
		if(head.next == null) {
			head = null;
			System.out.println("List becomes empty.");
			return;
		}
		while(temp.next.next != null) {
			temp = temp.next;
		}
		temp.next = null;
//		System.out.println("Last element deleted");
	}

	/*********************Delete the first element of the List***********************/
	public void deleteAtFirst() {
		Node temp = head;
		if(head == null) {
			System.out.println("List was already empty.");
			return;
		}
		if(temp.next == null) {
			head = null;
			System.out.println("List becomes empty.");
			return;
		}
		head = temp.next;
		temp.pre = null;
	}

	/******************Add an element at Kth position of the LinkedList*********************/
	public void insertAtKthPosition(int k, int a) {
		
		Node temp = head;
		Node newnode = new Node(a);
		if(k < 1) {
			System.out.println("Invalid input!");
			return;
		}
		if(k == 1) {
			insertAtFirst(a);
			return;
		}
		for(int i = 1 ; i < k-1 && temp != null ; i++) {
			temp = temp.next;
		}
		if(temp == null) {
			System.out.println("Invalid input!");
			return;
		}
		Node store = temp.next;
		temp.next = newnode;
		newnode.pre = temp;
		newnode.next = store;
	}


/********************Add an element at the beginning of the LinkedList*********************/
	public void insertAtFirst(int a) {
		Node newnode = new Node(a);
		newnode.next = head;
		newnode.pre = null;
		head = newnode;
	}

	
/**********************Add an element at the end of the LinkedList***********************/
	public void insertAtEnd(int a) {
		Node temp = head;
		Node newnode = new Node(a);
		if(head == null) {
			head = newnode;
			return;
		}
		while(temp.next != null) {
			temp = temp.next;
		}
		
		temp.next = newnode;
		newnode.pre = temp;
	}

	/***********************Print the List forward and reverse order*************************/
	public void print() {
		Node temp = head;
		System.out.print("Printing List:");
		while(temp.next != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println(temp.data);
		System.out.println();
		System.out.println("Printing List in reverse direction:");
		while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.pre;
		}
	}

	/*********************Create LinkedList of size n***********************/
	public void creatDLL(int n) {
		Scanner sc = new Scanner(System.in);
		
		for(int i = 0 ; i < n ; i++) {
			Node temp = head;
			int val = sc.nextInt();
			Node newnode = new Node(val);
			if(i == 0) {
				
				head = newnode;
				newnode.pre = null;
				newnode.next = null;
			}
			else {
				while(temp.next != null) {
					temp = temp.next;
				}
				temp.next = newnode;
				newnode.pre = temp;
			}
		}
		
	}

}
