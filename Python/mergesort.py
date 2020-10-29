
class Node:  # create Node using class Node. 
    def __init__(self, data): 
        self.data = data 
        self.next = None
  
class LinkedList: 
    def __init__(self): 
        self.head = None
      
    def append(self, new_value):  # push new value to linked list 
          
        new_node = Node(new_value)  # Allocate new node  
         
        if self.head is None:  # if head is None, initialize it to new node 
            self.head = new_node 
            return
        current_node = self.head 
        while current_node.next is not None: 
            current_node = current_node.next
        current_node.next = new_node  # Append the new node at the end of the linked list 
          
    def sortedMerge(self, a, b): 
        result = None
          
        if a == None:  # Base cases  
            return b 
        if b == None: 
            return a 
              
        if a.data <= b.data:  # pick either a or b  

            result = a 
            result.next = self.sortedMerge(a.next, b) 
        else: 
            result = b 
            result.next = self.sortedMerge(a, b.next) 
        return result 
      
    def mergeSort(self, h): 
          
        if h == None or h.next == None:  # Base case if head is None 
            return h 
        middle = self.getMiddle(h)  # get the pointer to the middle of the list 
        nexttomiddle = middle.next
        middle.next = None  # Now split the list into two halves but setting the middle node to NULL 
        
        left = self.mergeSort(h)  # Apply mergeSort on left list   
           
        right = self.mergeSort(nexttomiddle)  # Apply mergeSort on right list  
  
        sortedlist = self.sortedMerge(left, right)  # Merge the left and right lists  
        return sortedlist 
        
    def getMiddle(self, head):  # Function to get the middle node of the linked list
        if (head == None): 
            return head 
  
        slow = head 
        fast = head 
  
        while (fast.next != None and 
               fast.next.next != None): 
            slow = slow.next
            fast = fast.next.next
              
        return slow 
          

def printList(head):  # function to print the linked list   
    if head is None: 
        print(' ') 
        return
    curr_node = head 
    while curr_node: 
        print(curr_node.data, end = " ") 
        curr_node = curr_node.next
    print(' ') 
      

if __name__ == '__main__': 
    li = LinkedList() 
      
    li.append(15)  # Create an unsorted Linkedlist.
    li.append(10) 
    li.append(5) 
    li.append(20) 
    li.append(3) 
    li.append(2) 
    li.head = li.mergeSort(li.head)  # Apply merge Sort  
    print ("Sorted Linked List is:") 
    printList(li.head) 
  
