import java.io.*;
import java.util.*;
public class Deque<Item> implements Iterable<Item> {
    private int N;
    private Node front;
    private Node rear;
    
    private class Node{
        private Item item;
        private Node next;
        private Node prev;
    }
    // construct an empty deque
    public Deque()
    {
       front=null;
       rear=null;
       N=0;
    }

    // is the deque empty?
    public boolean isEmpty()
    {
        if(front==null)
            return true;
        else
            return false;
    }

    // return the number of items on the deque
    public int size(){
        return N;
    }

    // add the item to the front
    public void addFirst(Item item)
    {
        if(item==null)
            throw new NullPointerException();
        Node newN=new Node();
        newN.item=item;
        newN.prev=null;
        if(front==null)
        {
            front=newN;
            front.next=null;
            rear=front;
        }
        else
        {
            newN.next=front;
            front.prev=newN;
            front=newN;
        }
        N++;
    }

    // add the item to the back
    public void addLast(Item item)
    {
        if(item==null)
            throw new NullPointerException("Object to add is NULL");
        Node newN=new Node();
        newN.item=item;
        newN.next=null;
        if(rear==null)
        {
          rear=newN;
          rear.prev=null;
          front=rear;
        }
        else
        {
            newN.prev=rear;
            rear.next=newN;
            rear=newN;
        }
        if(front==null)
            front=rear;
        N++;
    }

    // remove and return the item from the front
    public Item removeFirst()
    {
        if(front==null)
            throw new NoSuchElementException();
        Item item=front.item;
        front =front.next;
        if(front==null)
            rear=null;
        else{
            front.prev=null;
        }
        N--;
        return item;
    }

    // remove and return the item from the back
    public Item removeLast()
    {
        if(rear==null)
            throw new NoSuchElementException();
        Item item=rear.item;
        rear=rear.prev;
        if(rear==null)
            front=null;
        else{
            rear.next=null;
        }
        N--;
        return item;
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator()
    {
        return new DequeIterator();
    }
    private class DequeIterator implements Iterator<Item>{
        private Node current=front;
        public boolean hasNext()
        {
            return current!=null;
        }
        public Item next(){
            if(!hasNext()){
                throw new NoSuchElementException();
            }
            Item item=current.item;
            current=current.next;
            return item;
        }
        public void remove()
        {
            throw new UnsupportedOperationException();
        }
    }

    // unit testing (required)
    public static void main(String[] args)
    {
        Deque<Integer> adeque = new Deque<Integer>();
       adeque.addFirst(1);
       adeque.addFirst(2);
       adeque.addFirst(3);
       adeque.addFirst(4);
       adeque.addLast(6);
       adeque.size();
       adeque.isEmpty();
       Iterator<Integer> it = adeque.iterator();
       System.out.println(adeque.removeFirst());
       System.out.println(adeque.removeLast());
    }

}