package Hacktoberfest2020_.Java.Graphs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class PrimsAlgorithm {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter no. of Vertices: ");
        int verticeNo = Integer.parseInt(br.readLine());

        System.out.println("Enter no. of Edges: ");
        int edgeNo = Integer.parseInt(br.readLine());

        // Constructing graph in the form of adjacency matrix
        int graph[][] = new int[verticeNo][verticeNo];
        
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
            
            graph[u][v] = w;
            graph[v][u] = w;
        }

        primsGraph(graph, verticeNo);
    }

    // Function to find the MST using Prims Algorithm
    public static void primsGraph(int[][] graph, int verticeNo){
        int inf = Integer.MAX_VALUE;

        // number of edge
        int edgeNo;

        // create a array to track selected vertex
        // selected will become true otherwise false
        boolean[] selected = new boolean[verticeNo];

        // set selected false initially
        Arrays.fill(selected, false);

        // set number of edge to 0
        edgeNo = 0;

        // the number of egde in minimum spanning tree will be always 
        // less than (V -1), where V is number of vertices in graph 

        // choose 0th vertex and make it true
        selected[0] = true;

        // print for edge and weight
        System.out.println("Minimum Spanning Tree formed.");
        System.out.println("Edge : Weight");

        while (edgeNo < verticeNo - 1) {
            // For every vertex in the set S, find the all adjacent vertices
            // , calculate the distance from the vertex selected at step 1.
            // if the vertex is already in the set S, discard it otherwise
            // choose another vertex nearest to selected vertex at step 1.
      
            int min = inf;
            int x = 0; // row number
            int y = 0; // col number
      
            for (int i = 0; i < verticeNo; i++) {
                if (selected[i] == true) {
                    for(int j = 0; j < verticeNo; j++) {
                        // not in selected and there is an edge
                        if (!selected[j] && graph[i][j] != 0) {
                            if (min > graph[i][j]) {
                                min = graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            System.out.println(x + " - " + y + " :  " + graph[x][y]);
            selected[y] = true;
            edgeNo++;
        }
    }
}
