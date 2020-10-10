package Hacktoberfest2020_.Java.Graphs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KruskalsAlgorithm {
    // Class to create edge
    static class Edge{
        int u, v, weight;
        
        public Edge(int u, int v, int weight){
            this.u = u;
            this.v = v;
            this.weight = weight;
        }
        
        @Override
        public String toString(){
            return this.u + " - " + this.v + " : " + this.weight;
        }
    }
    
    static class UnionFind{
        private int parents[];
        private int rank[];
        
        // Class constructor
        public UnionFind(int x){
            parents = new int[x];
            rank = new int[x];
            
            for(int i = 0; i < x; i++){
                parents[i] = i;
                rank[i] = 0;
            }
        }
        
        // A utility function to find set of an element i 
        // (uses path compression technique)
        public int find(int node){
            if(parents[node] != node){
                parents[node] = find(parents[node]);
            }
            
            return parents[node];
        }
        
        // A function that does union of two sets of x and y 
        // (uses union by rank) 
        public void union(int x, int y){
            x = find(x);
            y = find(y);
            
            if(rank[x] < rank[y]){
                parents[x] = y;
            }else if(rank[x] > rank[y]){
                parents[y] = x;
            }else{
                parents[x] = y;
                rank[y]++;
            }
        }
    }
    
    // Function to find the MST using Kruskal's Algorithm
    static void spanningTree(int V, int E, ArrayList<ArrayList<Integer>> graph) {
        // Creating list of edges
        List<Edge> edges = new ArrayList<>();
        
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(graph.get(i).get(j) != Integer.MAX_VALUE){
                    edges.add(new Edge(i, j, graph.get(i).get(j)));
                }
            }
        }
        
        // Sorting edges according to weights
        Collections.sort(edges, (x, y) -> x.weight - y.weight);
        
        // Index used to pick next edge
        int e = 0;
        UnionFind uf = new UnionFind(V);
        
        // Resulted graph
        Edge result[] = new Edge[V];
        
        for(Edge next: edges){
            // Number of edges to be taken is equal to V-1
            if(e == V-1) break;
            
            int x = uf.find(next.u);
            int y = uf.find(next.v);
            
            // If including this edge does't cause cycle, 
            // include it in result and increment the index  
            // of result for next edge
            if(x != y){
                uf.union(next.u, next.v);
                result[e++] = next;
            }
        }
        
        // print for edge and weight
        System.out.println("Minimum Spanning Tree formed.");
        System.out.println("Edge : Weight");

        for(int i = 0; i < e; i++){
            System.out.println(result[i].toString());
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter no. of Vertices: ");
        int verticeNo = Integer.parseInt(br.readLine());

        System.out.println("Enter no. of Edges: ");
        int edgeNo = Integer.parseInt(br.readLine());

        // Constructing graph in the form of adjacency matrix
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < verticeNo; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int j = 0; j < verticeNo; j++) temp.add(Integer.MAX_VALUE);
            graph.add(temp);
        }
        
        // initialize edges as per (u, v, w) space seperated
		// triplet representing undirected edge from
		// vertex u to vertex v having weight w
        System.out.println("Enter the edges as follows.");

        for(int i = 0; i < edgeNo; i++){
            System.out.println("Enter edge " + i + " :");
			
			String e[] = br.readLine().split(" ");
			int u = Integer.parseInt(e[0]);
			int v = Integer.parseInt(e[1]);
            int w = Integer.parseInt(e[2]);
            
            graph.get(u).set(v, w);
            graph.get(v).set(u, w);
        }

        spanningTree(verticeNo, edgeNo, graph);;
    }
}
