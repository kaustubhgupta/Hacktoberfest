/* A C program for Prim's Minimum Spanning Tree (MST) algorithm. The program is for adjacency matrix representation of the graph*/
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 


int minKey(int key[], bool mstSet[])
{
	
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


int printMST(int parent[], int graph[V][V])
{
	printf("Edge \tWeight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[V][V])
{
	
	int parent[V];
	
	int key[V];

	bool mstSet[V];

	for (int i = 0; i < V; i++)
	{

		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	
	key[0] = 0;
	parent[0] = -1; 
	for (int count = 0; count < V - 1; count++) {
		
		int u = minKey(key, mstSet);

		
		mstSet[u] = true;

		
		for (int v = 0; v < V; v++)

			
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph);
}
int main()
{
	scanf(%d,&V);
	int graph[V][V];
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			scanf(%d,&graph[i][j]);
		}
	}

	
	primMST(graph);

	return 0;
}
/*