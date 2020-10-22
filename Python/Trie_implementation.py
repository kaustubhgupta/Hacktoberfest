class TrieNode: 

	# Trie node class 
	def __init__(self): 
		self.children = [None]*26
		self.isWordEnd = False

class Trie: 

	# Trie data structure class 
	def __init__(self): 
		self.root = self.getNode() 

	def getNode(self): 
		return TrieNode() 
		
	def insert(self,key): 
	   # If not present, inserts key into trie, if prefix of node
	   #marks it as leaf

		node = self.root 
		length = len(key) 
		for level in range(length): 
			index = ord(key[level])-ord('a')
			if not node.children[index]: 
				node.children[index] = self.getNode() 
			node = node.children[index] 

		# mark last node as leaf 
		node.isWordEnd = True

	def search(self, key): 
		node = self.root 
		length = len(key) 
		for level in range(length): 
			index = ord(key[level])-ord('a')
			if not node.children[index]: 
				return False
			node = node.children[index] 

		return node is not None and node.isWordEnd 

def main(): 
    
    #tree object
    t = Trie() 
    c="y"
    while c == "y":
        val = input("Enter 1: Insert, 2: Search")
        if val == "1":
            key = input("Enter Word to insert : ")
            t.insert(key) 
        elif val == "2":
            searchKey = input("Enter Word to be searched : ")
            if t.search(searchKey):
                print("Present")
            else:
                print("Not Present")
        c=input("Do you want to continue(y/n): ")
        

if __name__ == '__main__': 
	main() 
