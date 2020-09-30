package stack;
import java.util.Iterator;
import java.util.NoSuchElementException;

/*
 * @author udit
 */

public class Stack<Type> implements Iterable<Type> {
	private int size;
	private SListNode<Type> head;

	private class SListNode<Type2> {
		public Type2 val;
		public SListNode<Type2> next;
		
		public SListNode(Type2 i) {
			this.val = i;
			this.next = null;
		}
	}
		
	public Stack() {
		head = null;
		size = 0;
	}
	
	public int size() {
		//if(size==0) throw new NoSuchElementException("Stack empty!");
		return size;
	}
	
	public boolean isEmpty() {
		return size==0;
	}
	
	public Type push(Type item) {
		SListNode<Type> newHead = new SListNode<>(item);
		newHead.next = head;
		head = newHead;
		++size;
		return item;
	}
	
	public Type pop() {
		if(size==0) throw new NoSuchElementException("Stack empty!");
		Type res = head.val;
		SListNode<Type> newHead = head.next;
		head = newHead;
		--size;
		return res;
	}
	
	public Type peek() {
		if(size==0) throw new NoSuchElementException("Stack empty!");
		return head.val;
	}
	
    public Iterator<Type> iterator() {
        return new ListIterator<Type>(head);
    }
    private class ListIterator<Type3> implements Iterator<Type3> {
        private SListNode<Type3> current;

        public ListIterator(SListNode<Type3> current) {
            this.current = current;
        }

        public boolean hasNext() {
            return current != null;
        }

        public Type3 next() {
            if (!hasNext()) throw new NoSuchElementException("No next element!");
            Type3 val = current.val;
            current = current.next;
            return val;
        }
    }
	
	public String toString() {
		String str = "";
		SListNode<Type> current = head;
		while(current!=null) {
			str += current.val + "-->";
			current = current.next;
		}
		str += "null";
		return str;
	}
    
	public static void main(String[] args) {
		
		Stack<Character> stack = new Stack<>();

		System.out.println("stack size: " + stack.size() + "\n");
		
		stack.push('i');
		stack.push('h');
		stack.push('g');
		stack.push('f');
		System.out.println("stack: " + stack.toString());
		System.out.println("stack size: " + stack.size() + "\n");
		
		stack.push('e');
		stack.push('d');
		stack.pop();
		stack.push('c');
		stack.push('b');
		System.out.println("stack: " + stack.toString());
		System.out.println("stack peek: " + stack.peek());
		System.out.println("stack size: " + stack.size() + "\n");
		
		stack.pop();
		System.out.println("stack: " + stack.toString());
		System.out.println("stack peek: " + stack.peek() + "\n");
		
		stack.push('a');
		System.out.println("stack: " + stack.toString());
		System.out.println("stack size: " + stack.size() + "\n");
		
		Iterator<Character> it = stack.iterator();
		System.out.print("iterator: ");
		while(it.hasNext()) {
			System.out.print(it.next() + "-->");
		}
		System.out.print("null\n\n");
		
		stack.pop();
		stack.pop();
		stack.pop();
		stack.pop();
		stack.pop();
		stack.pop();
		System.out.println("stack peek: " + stack.peek());
		System.out.println("stack: " + stack.toString());
		System.out.println("stack size: " + stack.size() + "\n");
		

	}
}
