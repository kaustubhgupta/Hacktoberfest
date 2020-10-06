/* Given a Directed Graph. Check whether it contains any cycle or not.
 * Expected Time Complexity: O(V + E).
 * Expected Auxiliary Space: O(V).
*/

package Hacktoberfest2020_.Java.Graphs;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class CycleDetection {
    static class DetectCycle{

        // Method to detect cycle
        public boolean isCyclic(ArrayList<ArrayList<Integer>> adjList, int vertices){
            boolean visited[] = new boolean[vertices];

            for(int i = 0; i < vertices; i++){
                if(hasCycle(adjList, i, visited)){
                    return true;
                }
            }
            
            return false;
        }

        // Method to traverse graph with DFS and detect cycle
        private boolean hasCycle(ArrayList<ArrayList<Integer>> adjList, int vertex, boolean[] visited) {
            if(visited[vertex]) return true;
            visited[vertex] = true;
            
            for(int x: adjList.get(vertex)){
                if(hasCycle(adjList, x, visited)){
                    return true;
                }
            }
            
            visited[vertex] = false;
            return false;
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

        // Calling the method for Cycle Detection
        DetectCycle cycle = new DetectCycle();

        if(cycle.isCyclic(adjList, vertices)){
            System.out.println("Graph contains cycle.");
        }else{
            System.out.println("Graph does not contains cycle.");
        }
    }
}
