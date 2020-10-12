class Node: 
	def __init__(self, data): 
		self.data = data  
		self.next = None   
class LinkedList: 
	def __init__(self): 
		self.head = None
	def insert_begin(self, new_data): 
		new_node = Node(new_data) 
		new_node.next = self.head 
		self.head = new_node 
	def insert_after(self, prev_node, new_data): 
		if prev_node is None: 
			print ("The given previous node must inLinkedList.")
			return
		new_node = Node(new_data) 
		new_node.next = prev_node.next
		prev_node.next = new_node 
	def insert_end(self, new_data): 
		new_node = Node(new_data) 
		if self.head is None: 
			self.head = new_node 
			return
		last = self.head 
		while (last.next): 
			last = last.next
		last.next = new_node 
	def printList(self): 
		temp = self.head 
		while (temp): 
			print(temp.data) 
			temp = temp.next
if __name__=='__main__': 
	new_list = LinkedList() 
	new_list.insert_end(1) 
	new_list.insert_begin(2)
	new_list.insert_begin(3)
	new_list.insert_after(new_list.head,4) 
	new_list.insert_after(new_list.head,8) 
	print ('Created linked list is:') 
	new_list.printList()