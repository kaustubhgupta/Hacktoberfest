"""
Given a graph, clone the graph and output the cloned version of the graph.

The key thing is to map each node to its cloned version.

Steps
1. Map the starting or given node to its cloned version in a hash table.
2. Traverse the graph using a BFS.
3. For each current node get and clone its edges if each edge has not been cloned or seen before.
4. Add each edge(uncloned version) to the queue.
5. Set the neighbours of the cloned version of the current node to the cloned version of its edges.
6. Once the queue is empty, iteration ends and we return the cloned version of the starting node.

Time complexity  is O(n) since we visit every node at least once.
Space complexity is O(n) since we are recreating another graph of size n.


Testcase Walkthrough

1.)   

1-2, starting node = 1

- map node 1(starting node) to its clone: {1: 1'}
- add the node to queue: [1] and pop first item to get 1: queue = []
- get edges of current node and clone them: {1: 1', 2:2'}
- link cloned version of current node(1') to cloned edge: 1' -> 2'
- add edge(2) to queue: [2]  and pop first item: queue = []
- 2 has no edge therefore queue becomes empty and iteration ends 
- return 1' 

i.e  1'-2'


2.)

1 - 2
|   |      
4 - 3     , starting node = 1
 
- map node 1(starting node) to its clone:  {1: 1'}
- add the node to queue: [1] and pop first item to get 1:  queue = []
- get edges and clone them:  {1: 1', 2:2', 4:4'}
- link cloned version of current node(1') to cloned edge: 1' -> [2', 4']
- add edges to queue: [2, 4]  and pop first item to get 2 -> queue = [4]
- 2 has edges [1,3] , repeat step 5:          2' -> [1',3']
- 1 has been cloned and seen so we only add 3 to queue: [4,3]
- pop first item to get 4: queue =  [3]
- repeat step 5:  4' -> [1', 3'] 
- pop first item to get 3: queue =  []
- 3 has no edges therefore queue becomes empty and iteration ends
- return 1' 

i.e

1' - 2'
|    |      
4' - 3' 


"""

# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


# Solution
def cloneGraph(node):
        
    if not node:
        return None
    
    import collections
    queue = collections.deque([node]) #Initialize the Queue
    
    cloned = {node: Node(node.val)} 
    
    while queue:
        
        curr_node = queue.popleft()    # Get current node
        
        edges = curr_node.neighbors
        
        for edge in edges:
            if edge not in cloned:
                cloned[edge] = Node(edge.val)  # Clone the current node's edges
                queue.append(edge)
                
            cloned[curr_node].neighbors.append(cloned[edge])
            
            
    return cloned[node]
        