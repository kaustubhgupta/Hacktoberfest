import java.util.ArrayList;
import java.util.Map;
import java.util.LinkedHashMap;
import java.util.HashMap;
import java.util.Set;
import java.util.Queue;
import java.util.LinkedList;



/**
 * An algorithm that sorts a graph in toplogical order.
 */


/**
 * A class that represents the adjaceny list of a graph
 */
class AdjacencyListGraph<E extends Comparable<E>>{


    Map<E,ArrayList<E>> adj;

    AdjacencyListGraph(){
        adj = new LinkedHashMap<E,ArrayList<E>>();
    }

    /**
     * This function adds an Edge to the adjaceny list
     * @param from the vertex the edge is from
     * @param to the vertex the edge is going to
     */
    void addEdge(E from, E to){
        try{
            adj.get(from).add(to);
        }
        catch(Exception E){
            adj.put(from,new ArrayList<E>());
            adj.get(from).add(to);
        }
        if(!adj.containsKey(to)){
            adj.put(to, new ArrayList<E>());
        }
    }

    /**
     * @param v A vertex in a graph
     * @return returns an ArrayList of all the adjacents of vertex v
     */
    ArrayList<E> getAdjacents(E v){
        return adj.get(v);
    }

    /**
     * @return returns a set of all vertices in the graph
     */
    Set<E> getVertices(){
        return adj.keySet();
    }

    /**
     * Prints the adjacency list
     */
    void printGraph(){
        for(E vertex: adj.keySet()){
            System.out.print(vertex+" : ");
            for(E adjacent: adj.get(vertex)){
                System.out.print(adjacent+" ");
            }
            System.out.println();
        }
    }
}

class TopologicalSort<E extends Comparable<E>>{
    AdjacencyListGraph<E> graph;
    Map<E,Integer> inDegree;

    TopologicalSort(AdjacencyListGraph<E> graph){
        this.graph = graph;
    }


    /**
     * Calculates the in degree of all vertices
     */
    void calculateInDegree(){
        inDegree = new HashMap<>();
        for(E vertex: graph.getVertices()){
            if(!inDegree.containsKey(vertex)){
                inDegree.put(vertex,0);
            }
            for(E adjacent: graph.getAdjacents(vertex)){
                try{
                    inDegree.put(adjacent,inDegree.get(adjacent) + 1);
                }
                catch(Exception e){
                    inDegree.put(adjacent,1);
                }
            }
        }
    }

    /**
     * Returns an ArrayList with vertices arranged in topological order
     */
    ArrayList<E> topSortOrder(){
        calculateInDegree();
        int count = 0;
        Queue<E> q = new LinkedList<E>();

        //Push all the vertices with zero indegree in a queue
        for(E vertex: inDegree.keySet()){
            if(inDegree.get(vertex) == 0){
                q.add(vertex);
            }
        }

        ArrayList<E> answer = new ArrayList<>();

        while(!q.isEmpty()){

            //Get one element from the queue
            E current = q.poll();

            //Add that to the required order
            answer.add(current);

            //Visit all the adjacents of current and reduce their indegree by 1
            for(E adjacent: graph.getAdjacents(current)){
                inDegree.put(adjacent,inDegree.get(adjacent)-1);

                //If a vertex now has an indegree of zero push them into the queue
                if(inDegree.get(adjacent) == 0){
                    q.add(adjacent);
                }
            }
        }

        return answer;

    }
}

/**
 * This class contains the driver code
 */
public class KahnsAlgorithm{
    public static void main(String[] args){

        //Graph definition and initialization
        AdjacencyListGraph<String> graph = new AdjacencyListGraph<String>();
        graph.addEdge("a","b");
        graph.addEdge("c","a");
        graph.addEdge("a","d");
        graph.addEdge("b","d");
        graph.addEdge("c","u");
        graph.addEdge("u","b");

        TopologicalSort<String> topSort = new TopologicalSort<String>(graph);

        //Printing the order
        for(String s: topSort.topSortOrder()){
            System.out.print(s+" ");
        }
    }
}