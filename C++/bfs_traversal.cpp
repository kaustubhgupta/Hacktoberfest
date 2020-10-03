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

    void bfs(T src) {
        queue<T>q;
        map<T, bool>visited;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T node = q.front();
            cout << node << " ";
            q.pop();


            for (int neighbour : adjList[node]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }


    }
};


int main() {

    Graph<int>g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);

    cout << "Adjacency list:" << endl;
    g.print();
    cout << "Breadth First Search Traversal Applied:" << endl;
    g.bfs(0);


    return 0;
}





















