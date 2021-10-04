import java.util.Scanner;

public class SinglyLinkedList {
    class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            next = null;
        }
    }

    Node head;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        SinglyLinkedList ll = new SinglyLinkedList();
        ll.creatLLofSizeN(1);
        ll.print();
        // ll.insertAtEnd(4);
        // ll.insertAtEnd(6);
        // ll.print();
        // ll.deleteLast();
        // ll.print();
        // ll.deleteFirst();
        // ll.print();
        // ll.insertAtKthPosition(1,10);
        // ll.print();
        // ll.insertAtFirst(4);
        // ll.print();
        // ll.deleteAtKthPosition(1);
        // ll.print();
        // int value = ll.findKthElement(3);
        // System.out.println(value);
    }

    /********************* Create LinkedList of size n ***********************/
    public void creatLLofSizeN(int n) {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            int k = sc.nextInt();
            Node newnode = new Node(k);
            if (i == 0) {
                head = new Node(k);
            } else {
                newnode.next = null;
                Node temp = head;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = newnode;
            }
        }
    }

    /*********************** Print the List *************************/
    public void print() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }
        Node temp = head;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    /********************
     * Add an element at the beginning of the LinkedList
     *********************/
    public void insertAtFirst(int a) {
        if (head == null) {
            head = new Node(a);
            head.next = null;
            return;
        }
        Node temp = head;
        head = new Node(a);
        head.next = temp;
    }

    /**********************
     * Add an element at the end of the LinkedList
     ***********************/
    public void insertAtEnd(int a) {
        if (head == null) {
            head = new Node(a);
            return;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = new Node(a);
        }
    }

    /******************
     * Add an element at Kth position of the LinkedList
     *********************/
    public void insertAtKthPosition(int k, int d) {

        k = k - 2;
        Node temp = head;
        while (temp != null && k-- > 0) {
            temp = temp.next;
        }
        Node y = new Node(d);
        if (k == -2) {
            Node p = head;
            head = y;
            head.next = p;
            return;
        } else if (temp != null) {
            Node aa = temp.next;
            temp.next = y;
            y.next = aa;
        } else {
            insertAtEnd(d);
        }
    }

    /*********************
     * Delete the first element of the List
     ***********************/
    public void deleteFirst() {
        if (head == null) {
            return;
        }
        Node temp = head;
        head = temp.next;
    }

    /*********************
     * Delete the last element of the List
     ***********************/
    public void deleteLast() {
        Node temp = head;
        if (head == null) {
            return;
        }
        if (head.next == null) {
            head = null;
            return;
        }
        while (temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
    }

    /*********************
     * Delete the element present at Kth position
     ***********************/
    public void deleteAtKthPosition(int k) {
        int count = 1;
        Node temp = head;
        if (k == 1) {
            deleteFirst();
        } else {
            while (count + 1 < k) {
                temp = temp.next;
                count++;
            }
            Node after = temp.next.next;
            temp.next = after;
        }
    }

    /********************* Find an element at Kth position ***********************/
    public int findKthElement(int k) {
        Node temp = head;
        int count = 1;
        while (count != k) {
            temp = temp.next;
            count++;
        }
        return temp.data;
    }

}
