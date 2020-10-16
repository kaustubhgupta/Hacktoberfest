/*
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
write a program to find Diameter of a given Binary Tree .
Note:Construction of a complete binary tree is based on level order fashion.
 

Sample Input :     
6
1 2 3 4 5 6

Sample Output : 
5

Explanation: 4-2-1-3-6 or 5-2-1-3-6
			  1
			/   \
		   2     3
      	  / \   / 
     	 4   5  6

 * 
 */

import java.util.Scanner;

//MyBinaryTreeNode Class containing left and right child of current node and data value

public class DiameterOfBinaryTree {
	static class MyBinaryTreeNode {
		public int data;
		public MyBinaryTreeNode left;
		public MyBinaryTreeNode right;
		public MyBinaryTreeNode(int data) {
			this.data = data;
			left = null;
			right = null;
		}
		public int getData() {
			return data;
		}
		public void setData(int data) {
			this.data = data;
		}
		public MyBinaryTreeNode getLeft() {
			return left;
		}
		public void setLeft(MyBinaryTreeNode left) {
			this.left = left;
		}
		public MyBinaryTreeNode getRight() {
			return right;
		}
		public void setRight(MyBinaryTreeNode right) {
			this.right = right;
		}
	}
	sttaic class BinaryTree {
		// Root of BinaryTree
		MyBinaryTreeNode root;
		// Function to insert nodes in level order
		public MyBinaryTreeNode insertLevelOrder(int[] arr, MyBinaryTreeNode root, int i) {
			// Base case for recursion
			if (i < arr.length) {
				MyBinaryTreeNode temp = new MyBinaryTreeNode(arr[i]);
				root = temp;

				// insert left child
				root.left = insertLevelOrder(arr, root.left, 2 * i + 1);

				// insert right child
				root.right = insertLevelOrder(arr, root.right, 2 * i + 2);
			}
			return root;
		}
		int diameter(MyBinaryTreeNode root) {
			/* write your code here */
			if(root==null)
			return 0;
			/* Another way
			MyBinaryTreeNode temp=root;
			int res=0;
			while(temp.left!=null) {
			    res++;
			    temp=temp.left;
			}
			temp=root.right;
			if(root.right!=null) {
			temp=root.right;
			res++;
			}
			while(temp!=null && temp.left!=null ) {
			    res++;
			    temp=temp.left;
			}
			return res+1;
			*/
			return Math.max(1+depth(root.left)+depth(root.right),Math.max(diameter(root.left),diameter(root.right)));
		}
		int depth(MyBinaryTreeNode root) {
		    if(root==null)return 0;
		    return 1+Math.max(depth(root.left),depth(root.right));
		}
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int numOfNodes = sc.nextInt();
		BinaryTree bt = new BinaryTree();
		int arr[] = new int[numOfNodes];
		for (int i = 0; i < numOfNodes; i++)
			arr[i] = sc.nextInt();
		bt.root = new MyBinaryTreeNode(arr[0]);
		bt.root = bt.insertLevelOrder(arr, bt.root, 0);
		int diameter = bt.diameter(bt.root);
		System.out.println(diameter);
	}
}
