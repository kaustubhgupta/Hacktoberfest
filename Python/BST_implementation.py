class Node:  
    def __init__(self,value):  
        self.leftkey = None
        self.rightkey = None
        self.value = value

#Function to print inorder traversal of tree
def printInorder(root): 
    if root: 
        printInorder(root.leftkey) 
        print(root.value),  
        printInorder(root.rightkey) 
  
  
  
#Function to print postorder traversal of tree 
def printPostorder(root): 
    if root: 
        printPostorder(root.leftkey) 
        printPostorder(root.rightkey) 
        print(root.value), 
  
  
#Function to print Preorder traversal of tree
def printPreorder(root): 
   if root: 
        print(root.value),  
        printPreorder(root.leftkey) 
        printPreorder(root.rightkey) 
  
 
 
#Function to Insert values in the Binary search tree        
def insert(root,value):  
    if root is None:  
        return Node(value)  
    else: 
        if root.value == value: 
            return root 
        elif root.value < value:  
            root.rightkey = insert(root.rightkey, value)  
        else: 
            root.leftkey = insert(root.leftkey, value) 
    return root 
  
  

def minValueNode( node): 
    current = node 
    while(current.leftkey is not None): 
        current = current.leftkey 
    return current  
  
#Function to Delete values from the Binary search tree       
def deleteNode(root, value): 
    if root is None: 
        return root  
    if value < root.value: 
        root.leftkey = deleteNode(root.leftkey, value) 
    elif(value > root.value): 
        root.rightkey = deleteNode(root.rightkey, value) 
    else: 
        if root.leftkey is None : 
            temp = root.rightkey  
            root = None 
            return temp        
        elif root.rightkey is None : 
            temp = root.leftkey  
            root = None
            return temp  
        temp = minValueNode(root.rightkey) 
        root.value = temp.value 
        root.rightkey = deleteNode(root.rightkey , temp.value) 
    return root  
    

if __name__ == '__main__': 
	r = Node(50)  
	r = insert(r, 30)  
	r = insert(r, 20)  
	r = insert(r, 40)  
	r = insert(r, 70)  
	r = insert(r, 60)  
	r = insert(r, 80)
	printInorder(r)



