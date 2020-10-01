package doublylinkedlist;

public class DoublyLinkedList<T> {
    Node<T> head;
    Node<T> tail;
    int size;

    static class Node<T> {
        T data;
        Node next;
        Node prev;
    }

	public boolean isEmpty() {
		return (head == null);
	}

	// used to insert a node at the start of linked list
	public void insertFirst(int data) {
		Node newNode = new Node();
		newNode.data = data;
		newNode.next = head;
		newNode.prev=null;
		if(head!=null)
			head.prev=newNode;
		head = newNode;
		if(tail==null)
			tail=newNode;
		size++;
	}

	// used to insert a node at the start of linked list
	public void insertLast(int data) {
		Node newNode = new Node();
		newNode.data = data;
		newNode.next = null;
		newNode.prev=tail;
		if(tail!=null)
			tail.next=newNode;
		tail = newNode;
		if(head==null)
			head=newNode;
		size++;
	}
}
