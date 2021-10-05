import java.util.*;

public class UnionFind {
    
    /* parent array to store parent of each element
     * parent[i] : parent of element i
     * */
    private int[] parent;
    
    /* Constructor: takes number of elements as input and initialize parent array
     * Initailly, all elements are roots
     * For root, parent[idx] is equal to idx
     * */
    public UnionFind(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
 
    /* Find the root(topmost parent) of x
     * Assumption: x is 0-index based
     * */
    public int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
 
    /* Merge groups of x and y
     * Find respective roots and update parent of first as second
     * Assumption: x and y are 0-index based
     * */
    public void union(int x, int y)  {
        var px = find(x);
        var py = find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
 
    /* Fetch the number of disjoint groups
     * Return number of roots in parent array
     * */
    public int size() {
        int ans = 0;
        for (int i = 0; i < parent.length; ++ i) {
            if (i == parent[i]) ans ++;
        }
        return ans;
    }


    public static void main(String[] args){
        UnionFind dsu = new UnionFind(5);
        System.out.println(dsu.size());
        dsu.union(0,1);
        dsu.union(3,4);
        System.out.println(dsu.size());
        dsu.union(1,4);
        System.out.println(dsu.size());
    }
}

