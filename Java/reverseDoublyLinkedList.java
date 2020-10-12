// Java implementation to reverse  
// a doubly linked list  
public class GFG 
{ 
  
// a node of the doubly linked list  
static class Node  
{  
    int data;  
    Node next, prev;  
};  
  
// function to get a new node  
static Node getNode(int data)  
{  
    // allocate space  
    Node new_node = new Node();  
  
    // put in the data  
    new_node.data = data;  
    new_node.next = new_node.prev = null;  
    return new_node;  
}  
  
// function to insert a node at the beginging  
// of the Doubly Linked List  
static Node push(Node head_ref, Node new_node)  
{  
    // since we are adding at the beginning,  
    // prev is always null  
    new_node.prev = null;  
  
    // link the old list off the new node  
    new_node.next = (head_ref);  
  
    // change prev of head node to new node  
    if ((head_ref) != null)  
        (head_ref).prev = new_node;  
  
    // move the head to point to the new node  
    (head_ref) = new_node; 
      
    return head_ref; 
}  
  
// function to reverse a doubly linked list  
static Node reverseList(Node head_ref)  
{  
    // if list is empty or it contains  
    // a single node only  
    if ((head_ref) == null || ((head_ref).next) == null)  
        return null;  
  
    Node new_head = null;  
    Node curr = head_ref, next;  
  
    while (curr != null) 
    {  
  
        // get pointer to next node  
        next = curr.next;  
  
        // push 'curr' node at the beginning of the  
        // list with starting with 'new_head'  
        new_head = push(new_head, curr);  
  
        // update 'curr'  
        curr = next;  
    }  
  
    // update 'head_ref'  
    head_ref = new_head; 
      
    return head_ref; 
}  
  
// Function to print nodes in a  
// given doubly linked list  
static void printList(Node head)  
{  
    while (head != null)  
    {  
        System.out.print(head.data + " ");  
        head = head.next;  
    }  
}  
  
// Driver program to test above  
public static void main(String args[]) 
{  
    // Start with the empty list  
    Node head = null;  
  
    // Create doubly linked: 10< - >8< - >4< - >2 /  
    head = push(head, getNode(2));  
    head = push(head, getNode(4));  
    head = push(head, getNode(8));  
    head = push(head, getNode(10));  
  
    System.out.print("Original list: ");  
    printList(head);  
  
    // Reverse doubly linked list  
    head = reverseList(head);  
  
    System.out.print("\nReversed list: ");  
    printList(head);  
} 
}  
