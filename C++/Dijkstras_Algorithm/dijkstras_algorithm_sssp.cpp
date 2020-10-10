// Dijkstra's Algorithm (SSSP)
// Weighted Graph (Directed OR Undirected)
// Positive Weighted Edges. Fails For Negative Weights.
// O(ELogV)
#include <bits/stdc++.h>
using namespace std;

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

template <typename T>
class Graph {
	int V;
	unordered_map<T, list<pair<T, int>>> um; // (string->(string,weight))
public:
	
	Graph(int V) {
		this->V = V;
	}

	void addEdge(T x, T y, int wt, bool bidir = true) {
		um[x].push_back(make_pair(y, wt));
		if (bidir) {
			um[y].push_back(make_pair(x, wt));
		}
	}

	void printAdjList() {
		for (auto edge : um) {
			T node = edge.first;
			cout << node << "--->";
			for (auto s : edge.second) {
				cout << "(" << s.first << "," << s.second << ")";
			}
			cout << endl;
		}
	}

	void dijkstraSSSP(T src) {
		unordered_map<T, int> dist;
		// Initially all the nodes are at infinite(INT_MAX) distance.
		for (auto edge : um) {
			T node = edge.first;
			dist[node] = INT_MAX;
		}
		// Used to get minimum in O(1) time and ramove in O(logN) time.
		set<pair<int, T>> s; // (dist,vertex)
		dist[src] = 0;
		s.insert(make_pair(0, src));
		while (!s.empty()) {
			auto node = *(s.begin());
			T vertex = node.second;
			int vertexDist = node.first;
			s.erase(s.begin());
			// Iterate over all the neighbours of the current node and add it to set
			for (auto childPair : um[vertex]) {
				int nbrDist = childPair.second;
				T dest = childPair.first;
				// In set updation is not possible
				// So we need to remove the pair from the set and add the updated pair to the set
				if (vertexDist + nbrDist < dist[dest]) {
					auto f = s.find(make_pair(dist[dest], dest));
					if (f != s.end()) {
						s.erase(f);
					}
					dist[dest] = vertexDist + nbrDist;
					s.insert(make_pair(dist[dest], dest));
				}
			}
		}

		// Print dist from all other node to src
		for (auto d : dist) {
			T vertex = d.first;
			int vertexDist = d.second;
			cout << vertex << " Is Located At Distance Of " << vertexDist << " From src" << endl;
		}
	}
};

int main() {
	init();
	int V, E;
	cin >> V >> E;
	Graph<string> g(V);
	for (int i = 0; i < E; i++) {
		string x, y;
		int wt;
		cin >> x >> y >> wt;
		g.addEdge(x, y, wt);
	}
	g.dijkstraSSSP("Amritsar");
	return 0;
}
