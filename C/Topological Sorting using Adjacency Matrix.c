#include<stdio.h>
void DFS(int);
int G[10][10],visited[10],n,TS[10],DF[10];
int top1=-1, top2=-1;

void main()
{
	int i, j;
    	printf("Enter number of vertices:");
   	scanf("%d", &n);
 	printf("\nEnter adjecency matrix of the graph:");
   	for(i=0; i<n; i++)
       		for(j=0; j<n; j++)
			scanf("%d", &G[i][j]);
    	for(i=0; i<n; i++)
        		visited[i] = 0;
    	for(i=0; i<n; i++)
    		DFS(i);
    	printf("Topological Sorting of the given graph is:\n");
    	for(i=top2; i>=0; i--)
            		printf("%d\n",TS[i]);
}

void DFS(int i)
{
	int j;
	if(visited[i] == 0)
    	{
        		DF[++top1] = i;
    		visited[i] = 1;
		for(j=0; j<n; j++)
       			if(!visited[j] && G[i][j] == 1)
            				DFS(j);
    		TS[++top2] = DF[top1--];
    	}

}