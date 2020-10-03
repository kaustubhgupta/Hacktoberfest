#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph {
    map<T, list<T> > adjList;

public:
    Graph() {
    }

    void addEdge(T u, T v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }
    void print() {

        for (auto p : adjList) {
            auto key = p.first;
            auto neigbours = p.second; //list of neigbours

            cout << key << "->";
            for (auto n : neigbours) {
                cout << n << ",";
            }
            cout << endl;
        }
    }


    void dfshelper(T node, map<T, bool> &visited) {
        // comes to the node, mark it as visited
        visited[node] = true;
        cout << node << " ";

        for (T neighbour : adjList[node]) {
            if (!visited[neighbour]) {
                dfshelper(neighbour, visited);
            }
        }




    }

    void dfs(T src) {
        map<T, bool>visited;
        dfshelper(src, visited);


    }
};


int main() {

    Graph<string>g;
    // g.addEdge(0, 1);
    // g.addEdge(1, 2);
    // g.addEdge(0, 4);
    // g.addEdge(2, 4);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(3, 5);
    g.addEdge("a", "b", false);
    g.addEdge("b", "d", false);
    g.addEdge("d", "a", false);
    g.addEdge("d", "c", false);
    g.addEdge("e", "d", false);
    g.addEdge("e", "f", false);


    cout << "Adjacency list:" << endl;
    g.print();
    cout << "Depth First Search Traversal Applied:" << endl;
    g.dfs("a");
    cout << endl;


    return 0;
}





















