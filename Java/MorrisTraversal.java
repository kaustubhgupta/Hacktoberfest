class BinaryTree { 
    class tNode { 
    int data; 
    tNode left, right; 
  
    tNode(int item) 
    { 
        data = item; 
        left = right = null; 
    } 
} 
  
    tNode root; 
  
    /* Function to traverse a binary tree without recursion and  
       without stack */
    void MorrisTraversal(tNode root) 
    { 
        tNode current, pre; 
  
        if (root == null) 
            return; 
  
        current = root; 
        while (current != null) { 
            if (current.left == null) { 
                System.out.print(current.data + " "); 
                current = current.right; 
            } 
            else { 
                /* Find the inorder predecessor of current */
                pre = current.left; 
                while (pre.right != null && pre.right != current) 
                    pre = pre.right; 
  
                /* Make current as right child of its inorder predecessor */
                if (pre.right == null) { 
                    pre.right = current; 
                    current = current.left; 
                } 
  
                /* Revert the changes made in the 'if' part to restore the  
                    original tree i.e., fix the right child of predecessor*/
                else { 
                    pre.right = null; 
                    System.out.print(current.data + " "); 
                    current = current.right; 
                } 
  
            } 
  
        } 
    } 
  
    public static void main(String args[]) 
    { 
       
        BinaryTree tree = new BinaryTree(); 
        tree.root = new tNode(1); 
        tree.root.left = new tNode(2); 
        tree.root.right = new tNode(3); 
        tree.root.left.left = new tNode(4); 
        tree.root.left.right = new tNode(5); 
  
        tree.MorrisTraversal(tree.root); 
    } 
} 
