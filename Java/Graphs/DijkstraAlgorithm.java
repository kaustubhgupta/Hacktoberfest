/* Given a source vertex s from set of vertices V in a weighted graph 
 * where all its edge weights w(u, v) are non-negative, find the 
 * shortest-path weights d(s, v) from given source s for all vertices 
 * v present in the graph. 
 * Time Complexity: O(V * E)
 * Space Complexity: O(V)
 */

package Hacktoberfest2020_.Java.Graphs;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

class Edge {
    int source, dest, weight;

    public Edge(int source, int dest, int weight) {
        this.source = source;
        this.dest = dest;
        this.weight = weight;
    }
}

// Data structure to store heap nodes
class Node {
    int vertex, weight;

    public Node(int vertex, int weight) {
        this.vertex = vertex;
        this.weight = weight;
    }
}

// class to represent a graph object
class Graph {
	
    // A List of Lists to represent an adjacency list
    List<List<Edge>> adjList = null;

    // Constructor
    Graph(List<Edge> edges, int N)
    {
        adjList = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            adjList.add(new ArrayList<>());
        }

        // add edges to the undirected graph
        for (Edge edge: edges) {
            adjList.get(edge.source).add(edge);
        }
    }
}

public class DijkstraAlgorithm {
    private static void getRoute(int[] prev, int i, List<Integer> route)
	{
		if (i >= 0) {
			getRoute(prev, prev[i], route);
			route.add(i);
		}
	}

	// Run Dijkstra's algorithm on given graph
	public static void shortestPath(Graph graph, int source, int N)
	{
		// create min heap and push source node having distance 0
		PriorityQueue<Node> minHeap;
		minHeap = new PriorityQueue<>(Comparator.comparingInt(node -> node.weight));
		minHeap.add(new Node(source, 0));

		// set infinite distance from source to v initially
		List<Integer> dist = new ArrayList<>(Collections.nCopies(N, Integer.MAX_VALUE));

		// distance from source to itself is zero
		dist.set(source, 0);

		// boolean array to track vertices for which minimum
		// cost is already found
		boolean[] done = new boolean[N];
		done[source] = true;

		int[] prev = new int[N];
		prev[source] = -1;

		List<Integer> route = new ArrayList<>();

		while (!minHeap.isEmpty()) {
			// Remove and return best vertex
			Node node = minHeap.poll();

			// get vertex number
			int u = node.vertex;

			// do for each neighbor v of u
			for (Edge edge: graph.adjList.get(u))
			{
				int v = edge.dest;
				int weight = edge.weight;

				// Relaxation step
				if (!done[v] && (dist.get(u) + weight) < dist.get(v))
				{
					dist.set(v, dist.get(u) + weight);
					prev[v] = u;
					minHeap.add(new Node(v, dist.get(v)));
				}
			}

			done[u] = true;
		}

		for (int i = 1; i < N; ++i)
		{
			if (i != source && dist.get(i) != Integer.MAX_VALUE) {
				getRoute(prev, i, route);
				System.out.printf("Path (%d -> %d): Minimum Cost = %d and Route is %s", source, i, dist.get(i), route);
                System.out.println();
				route.clear();
			}
		}
	}

	public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter no. of Vertices: ");
        int verticeNo = Integer.parseInt(br.readLine());

        System.out.println("Enter no. of Edges: ");
        int edgeNo = Integer.parseInt(br.readLine());

        // initialize edges as per (u, v, w) space seperated
		// triplet representing undirected edge from
		// vertex u to vertex v having weight w
        System.out.println("Enter the edges as follows.");
        List<Edge> edges = new ArrayList<>();

        for(int i = 0; i < edgeNo; i++){
            System.out.println("Enter edge " + i + " :");
			
			String e[] = br.readLine().split(" ");
			int u = Integer.parseInt(e[0]);
			int v = Integer.parseInt(e[1]);
			int w = Integer.parseInt(e[2]);

            edges.add(new Edge(u, v, w));
        }

		// construct graph
		Graph graph = new Graph(edges, verticeNo);

		int source = 0;
		shortestPath(graph, source, verticeNo);
	}
}
