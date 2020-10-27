class SetNode:
    def __init__(self,keyget): #defalut constructor
        self.leftroot = None
        self.rightroot = None
        self.value = keyget 
   
def showInorder(root):
    if root:
        showInorder(root.leftroot)  # left node recursion
        print(root.value)  # print node
        showInorder(root.rightroot)  # right node recursion
  
def showPostorder(root):
    if root:
        showPostorder(root.leftroot)  # left node recursion   
        showPostorder(root.rightroot)  # right node recursion
        print(root.value)  # print node
  
def showPreorder(root):
    if root:  
        print(root.value)  # print node
        showPreorder(root.leftroot)  # left node recursion  
        showPreorder(root.rightroot)  # right node recursion
  

if __name__=="__main__":
    #  setting root node and the following child nodes
    rootnode = SetNode(3)  
    rootnode.leftroot = SetNode(6) 
    rootnode.rightroot = SetNode(8) 
    rootnode.leftroot.leftroot = SetNode(2) 
    rootnode.leftroot.rightroot = SetNode(7)
    rootnode.leftroot.leftroot.leftroot = SetNode (4)

    print("\n\nInorder traversal")
    showInorder(rootnode) 
    print("\nPreorder traversal")
    showPreorder(rootnode)
    print("\n\nPostorder traversal")
    showPostorder(rootnode) 
