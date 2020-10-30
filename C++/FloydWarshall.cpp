#include<bits/stdc++.h>
using namespace std;

#define MAX 1000

int adj[MAX][MAX];

void floydWarshall(int vertices, int edges){

	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			for(int k = 0; k < vertices; k++){
				adj[i][k] = min(adj[i][k], adj[i][j] + adj[j][k]);
			}
		}
	}
	
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			if(adj[i][j] == MAX)	printf("distance from %d to %d = INF\n",i,j);
			else					printf("distance from %d to %d = %d\n",i,j,adj[i][j]);
		}
	}
}

int main(){

	int vertices=4, edges=4;

    // initialize the array with infinity
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			adj[i][j] = MAX;
			if(i == j)
				adj[i][j] = 0;
		}
	}

	adj[0][1] = 5;
	adj[0][3] = 10;
	adj[1][2] = 3;
	adj[2][3] = 1;

	

	floydWarshall(vertices, edges);

	return 0;
}
