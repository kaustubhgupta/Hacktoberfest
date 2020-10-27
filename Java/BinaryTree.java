import java.util.Scanner;

public class BinaryTree {
	
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		Node root = createBinaryTree();
		System.out.println("\nInorder traversal :- ");
		inOrder(root);
		System.out.println("\nPreorder traversal :- ");
		preOrder(root);
		System.out.println("\nPostorder traversal :- ");
		postOrder(root);
	}
	
	static Node createBinaryTree() {
		Node root = null;
		System.out.println("Enter data: -");
		int value = sc.nextInt();
		if(value == -1) {
			return root;
		}
		root = new Node(value);
		System.out.println("Enter left data for :- "+value);
		root.left = createBinaryTree();
		System.out.println("Enter right data for :- "+value);
		root.right = createBinaryTree();
		return root;
	}
	
	static void inOrder(Node root) {
		if(root == null) {
			return;
		}
		inOrder(root.left);
		System.out.print(root.value+" ");
		inOrder(root.right);
	}
	
	static void preOrder(Node root) {
		if(root == null) {
			return;
		}
		System.out.print(root.value+" ");
		preOrder(root.left);
		preOrder(root.right);
	}
	
	static void postOrder(Node root) {
		if(root == null) {
			return;
		}
		postOrder(root.left);
		postOrder(root.right);
		System.out.print(root.value+" ");
	}

}

class Node{
	Node left, right;
	int value;
	
	public Node(int value){
		this.value = value;
	}
}
