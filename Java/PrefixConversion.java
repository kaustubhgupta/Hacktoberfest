//Code contributed by Aditya Prakash (@PrakashAditya17 --Github)
import java.io.*;
import java.util.*;

class PrefixConversion
{
        public static void preorder(Node root)
        {
            if(root!=null){
                System.out.print(root.value+" ");
                preorder(root.left);
                preorder(root.right);
            }
        }
        public static void inorder(Node root)
        {
            if(root!=null){
                inorder(root.left);
                System.out.print(root.value+" ");
                inorder(root.right);
            }
        }
        public static void postorder(Node root)
        {
            if(root!=null){
                postorder(root.left);
                postorder(root.right);
                System.out.print(root.value+" ");
            }
        }
        public static boolean checkOperator(char ele)
        {
                if(ele=='+' || ele=='-' || ele=='*' || ele=='/' || ele=='^' || ele=='%')
                        return true;
                return false;
        }
        public static void main(String args[])throws IOException
        {
                Scanner sc=new Scanner(System.in);
                
                //Taking Prefix Expression as input
                System.out.println("Enter a valid prefix expression");
                String s=sc.nextLine();
                int size=s.length();
                
                Stack<Node> stk=new Stack<Node>();  //Stack is created to store the nodes.
                Node nn,Left,Right;
                for(int i=size-1;i>=0;i--)
                {
                        char ch=s.charAt(i);
                        if(checkOperator(ch))  // ch -> operator.
                        {
                                nn=new Node(ch); //Operator is current_root node
                                
                                Left=stk.pop();     //Topmost element in stack is the left node
                                Right=stk.pop();  //2nd topmost will be the right node.
                                
                                nn.left=Left;    // Assigned to this root.
                                nn.right=Right;
                                
                                stk.push(nn);   //This new node is the topmost stack element now.
                        }
                        else//ch -> operand.
                        {
                                nn=new Node(ch);
                                stk.push(nn);
                        }
                }
                
                Node ROOT=stk.peek();  //peek() returns the first element of the stack which is the root node. 
                
                //Now to find the infix and postfix expression, we will simply traverse the binary tree using inorder and postorder 
                //respectively.
                
                System.out.println("Infix Expression:");
                inorder(ROOT);
                
                System.out.println();
                
                System.out.println("Postfix Expression:");
                postorder(ROOT);
                        
                //For prefix, just call the preorder function.
        }
}
public class Node
{
        char value;
        Node left;
        Node(char c)
        {
                value=c;
                left=right=null;
        }
}
          
