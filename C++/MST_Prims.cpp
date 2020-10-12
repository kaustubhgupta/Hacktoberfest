// C++ implementation of Prim's algorithm 
// Runtime complexity = O(ElogV)

// Template for C++ code
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define pii pair<ll,ll>
#define pb push_back
#define INF 0x3f3f3f3f
#define ll long long

// vector to store the adjacency list
vector<pii> g[(int)1e4+5];
// vector to denote whether the node has been visited or not
vector<bool> visited((int)1e4+5,false);

// Minimum edge weight to get to that node
// Consider, 30, 20, 10 to be the edge weights 
// associated with edge {1,2}, {1,3}, {1,4}
//         1
//  30 / 20|  \10
//    2    3   4
// key[1] = 10 from edge {1,4}

// Initially, all nodes are unvisited, so key[all nodes.....] = INF
vector<ll> key((int)1e4+5,INF);
int n;

ll MST(ll start)
{
	ll u,c,v,w;
	// Using min heap 
	priority_queue<pii,vector<pii>,greater<pii>> q;
	key[start] = 0;
	q.push(pii(0,start));
	while(!q.empty())
	{
		// u denotes the node
		u = q.top().second;
		// c denotes the edge weight to get to, 
		// used as key for sorting in min heap 
		c = q.top().first;
		q.pop();
		// Since, we are considering u, it is visited now
		visited[u] = true;
		// Iterating through the neighbours of node u
		for(auto it: g[u])
		{
			v = it.first;
			w = it.second;
			// Consider a node if has NOT been visited already
			// and the edge weight to get to it, is lesser than the previous one
			if(visited[v] == false && key[v]>w)
			{
				key[v] = w;
				// Push {edge weight, next node} to the min heap
				q.push(pii(key[v],v));
			}
		}
	}
	ll sum = 0;
	// Sum of the edge weights involved in MST 
	for(int i=1;i<=n;i++)
	    sum+=key[i];
	return sum;
}

int main()
{
	fast;
	ll m,u,v,w;
	// n is the number of nodes and m is the number of edges
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		g[u].pb(pii(v,w));
		g[v].pb(pii(u,w));
	}
	// Any valid node can be used as the starting point as 
	// each node has to be added in the MST
	cout<<MST(0);
	return 0;
}


