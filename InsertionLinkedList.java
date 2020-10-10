/* A node can be added in three ways 
1) At the front of the linked list 
2) After a given node. 
3) At the end of the linked list.

I have implemented all 3 insertion in simple program with the hellp of 3 different classes respecively.
*/

class LinkedList 
{ 
    Node head;  
    class Node 
    { 
        int data; 
        Node next; 
        Node(int d) 
        {data = d;
        next = null; } 
    } 
  
    /* Inserts a new Node at front of the list. */
    public void push(int new_data) 
    { 
        Node new_node = new Node(new_data); 
        new_node.next = head; 
         head = new_node; 
    } 
  
    /* Inserts a new node after the given prev_node. */
    public void insertAfter(Node prev_node, int new_data) 
    { 
        if (prev_node == null) 
        { 
            System.out.println("The given previous node cannot be null"); 
            return; 
        }
        Node new_node = new Node(new_data); 
        new_node.next = prev_node.next; 
        prev_node.next = new_node; 
    } 
     
    /* Appends a new node at the end.  This method is  
       defined inside LinkedList class shown above */
    public void append(int new_data) 
    { 
        Node new_node = new Node(new_data); 
  
        if (head == null) 
        { 
            head = new Node(new_data); 
            return; 
        } 
  
        new_node.next = null; 
  
        Node last = head;  
        while (last.next != null) 
            last = last.next; 
  
        last.next = new_node; 
        return; 
    } 
  
    
    public void printList() 
    { 
        Node tnode = head; 
        while (tnode != null) 
        { 
            System.out.print(tnode.data+" "); 
            tnode = tnode.next; 
        } 
    } 
  
    public static void main(String[] args) 
    { 
        LinkedList llist = new LinkedList(); 
  
        // Insert 6.  So linked list becomes 6->NUllist 
        llist.append(6); 
  
        // Insert 7 at the beginning. So linked list becomes 
        // 7->6->NUllist 
        llist.push(7); 
  
        // Insert 1 at the beginning. So linked list becomes 
        // 1->7->6->NUllist 
        llist.push(1); 
  
        // Insert 4 at the end. So linked list becomes 
        // 1->7->6->4->NUllist 
        llist.append(4); 
  
        // Insert 8, after 7. So linked list becomes 
        // 1->7->8->6->4->NUllist 
        llist.insertAfter(llist.head.next, 8); 
  
        System.out.println("\nCreated Linked list is: "); 
        llist.printList(); 
    } 
} 
