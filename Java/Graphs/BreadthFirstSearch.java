/*
 * Given a directed graph. The task is to do Breadth First Search of the graph starting from vertex 1.
 * Expected Time Complexity: O(V + E).
 * Expected Auxiliary Space: O(V).
 */

package Hacktoberfest2020_.Java.Graphs;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BreadthFirstSearch {
    static class Traversal {
        
        // Method to perform BFS traversal of the graph
        public ArrayList<Integer> bfsTraversalPath(ArrayList<ArrayList<Integer>> adjList, int vertices) {
            boolean visited[] = new boolean[vertices];
            Queue<Integer> queue = new LinkedList<>();

            ArrayList<Integer> res = new ArrayList<>();
            queue.add(0);
            visited[0] = true;

            while (!queue.isEmpty()) {
                int vertex = queue.remove();
                res.add(vertex);

                if (adjList.get(vertex).size() != 0) {
                    for (int x : adjList.get(vertex)) {
                        if (!visited[x]) {
                            queue.add(x);
                            visited[x] = true;
                        }
                    }
                }
            }

            return res;
        }
    }

    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Taking input for no of vertices
        System.out.println("Enter no. of vertices: ");
        int vertices = Integer.parseInt(br.readLine());

        // Taking input for no of edges
        System.out.println("Enter no. of Edges: ");
        int edges = Integer.parseInt(br.readLine());

        // Creating graph in the form of adjacency list
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();

        for (int i = 0; i < vertices; i++) {
            adjList.add(new ArrayList<>());
        }

        // Taking input for egdes
        System.out.println("Enter the vertices for edges as follows.");
        for (int i = 1; i <= edges; i++) {
            System.out.println("Enter edge " + i + " starting vertex: ");
            int u = Integer.parseInt(br.readLine());

            System.out.println("Enter edge " + i + " ending vertex: ");
            int v = Integer.parseInt(br.readLine());

            adjList.get(u).add(v);
        }

        // Final output path of the traversal
        ArrayList<Integer> res = new Traversal().bfsTraversalPath(adjList, vertices);

        System.out.print("BFS Traversal path for the above graph is: ");
        for(int i = 0; i < res.size(); i++){
            System.out.print(res.get(i) + 1 + " ");
        }
    }
}
