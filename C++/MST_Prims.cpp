#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define piii pair<ll,pair<ll,ll>> 
#define pii pair<ll,ll>
#define pb push_back
#define INF 0x3f3f3f3f
int n;

vector<piii> edges;
vector<pii> parent ((int)1e4+5); 
vector<pii> g[(int)1e4+5];

// findind the parent of element x
ll find(ll x)
{
	if(parent[x].first==x)
		return x;
	return parent[x].first=find(parent[x].first);
}

// Union find using path compression
void merge(ll x, ll y)
{
	ll set_x=find(x);									//Union based on the fact that both x and y are present in different sets.
	ll set_y=find(y);
	if(parent[set_x].second<parent[set_y].second)
		parent[set_x].first=set_y;
	else if(parent[set_x].second>parent[set_y].second)
		parent[set_y].first=set_x;
	else
	{
		parent[set_y].first=set_x;
		parent[set_x].second++;
	}
}

// Finds the cost of the minimum spanning tree
ll MST(ll start)
{
	ll cnt=0,sum=0,u,v,w,x,y;
	for(auto it: edges)
	{
		w=it.first;
		u=it.second.first;
		v=it.second.second;
		x=find(u);
		y=find(v);
		if(x!=y)
		{
			sum+=w;
			merge(u,v);
			cnt++;
		}
		if(cnt==n-1)
			break;
	}
	return sum;
}

int main()
{
	fast;
	ll m,u,v,w;
	// n represents node count and m represents edge count
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		edges.pb({w,{u,v}});
		g[u].pb(pii(v,w));
		g[v].pb(pii(u,w));
	}
	sort(edges.begin(),edges.end());
	for(int i=0;i<n;i++)
	{
		parent[i].first=i;
		parent[i].second=0;
	}
	cout<<MST(1);
	return 0;
}
