#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define pii pair<ll,ll>
#define pb push_back
#define INF 0x3f3f3f3f
#define ll long long
vector<pii> g[(int)1e4+5];
vector<bool> visited((int)1e4+5,false);
vector<ll> key((int)1e4+5,INF);
int n;

ll MST(ll start)
{
	ll u,c,v,w;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	key[start]=0;
	q.push(pii(0,start));
	while(!q.empty())
	{
		u=q.top().second;
		c=q.top().first;
		q.pop();
		visited[u]=true;
		for(auto it: g[u])
		{
			v=it.first;
			w=it.second;
			if(visited[v]==false && key[v]>w)
			{
				key[v]=w;
				q.push(pii(key[v],v));
			}
		}
	}
	ll sum=0;	
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
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[u].pb(pii(v,w));
		g[v].pb(pii(u,w));
	}
	cout<<MST(1);
	return 0;
}
