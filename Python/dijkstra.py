# Here, a priority queue maintains a set of key-value pairs, where vertex v is a value and d(s, v) is its key.
# This implementation supports three operations: insert(val,key), extract_min

class PriorityQueue: # Hash Table Implementation
    def __init__(self): # stores keys with unique labels
        self.A = {}

    def insert(self, label, key): # insert labeled key
        self.A[label] = key

    def extract_min(self): # return a label with minimum key
        min_label = None
        for label in self.A:
            if (min_label is None) or (self.A[label] < self.A[min_label]):
                min_label = label
        del self.A[min_label]
        return min_label

    def decrease_key(self, label, key): # decrease key of a given label
        if (label in self.A) and (key < self.A[label]):
            self.A[label] = key
    
    def print_queue(self): # debug
        print(self.A)

## To relax a shortest path estimate d(s, v), we will relax an incoming edge to v, from another vertex u.
# If we maintain that d(s, u) always upper bounds the shortest path from s to u for all u ∈ V ,
# then the true shortest path weight δ(s, v) can’t be larger than d(s, u) + w(u, v) or else going to u
# along a shortest path and traversing the edge (u, v) would be a shorter path (by the triangle inequality)
def try_to_relax(w, d, parent, u, v):
    if d[v] > d[u] + w: # better path through vertex u
        d[v] = d[u] + w # relax edge with shorter path found
        parent[v] = u

# Dijkstra is possibly the most commonly used weighted shortest paths algorithm;
# it is asymptotically faster than Bellman-Ford, but only applies to graphs containing non-negative edge weights,
# which appear often in many applications

# Dijkstra’s algorithm discretizes this continuous process by repeatedly relaxing edges from
# a vertex whose minimum weight path estimate is smallest among vertices whose out-going edges
# have not yet been relaxed

def dijkstra(Adj, s):
    d = [float('inf') for _ in Adj] # shortest path estimates d(s, v)
    parent = [None for _ in Adj] # initialize parent pointers
    d[s], parent[s] = 0, s # initialize source

    Q = PriorityQueue() # initialize empty priority queue
    V = len(Adj) # number of vertices
    for v in range(V): # loop through vertices
        Q.insert(v, d[v]) # insert vertex-estimate pair
    for _ in range(V): # main loop
        u = Q.extract_min() # extract vertex with min estimate
        cur_vertex_path_weights = Adj[u]
        for index, weight in enumerate(cur_vertex_path_weights): # loop through out-going edges
            if weight != 0:
                try_to_relax(weight, d, parent, u, index)
                Q.decrease_key(index, d[index]) # update key of vertex   
                print(d)

    return d, parent


graph = [
            [0, 4, 0, 0, 0, 0, 0, 8, 0], 
            [4, 0, 8, 0, 0, 0, 0, 11, 0], 
            [0, 8, 0, 7, 0, 4, 0, 0, 2], 
            [0, 0, 7, 0, 9, 14, 0, 0, 0], 
            [0, 0, 0, 9, 0, 10, 0, 0, 0], 
            [0, 0, 4, 14, 10, 0, 2, 0, 0], 
            [0, 0, 0, 0, 0, 2, 0, 1, 6], 
            [8, 11, 0, 0, 0, 0, 1, 0, 7], 
            [0, 0, 2, 0, 0, 0, 6, 7, 0] 
        ]

shortest_paths = []
parents = []

shortest_paths, parents = dijkstra(graph,0)


print(shortest_paths)
print(parents)