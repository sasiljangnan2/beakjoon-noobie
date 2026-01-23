#include <stdio.h>
#include <stdlib.h>
#define MAX_Vertices 100000
#define TRUE 1
#define FALSE 0

typedef struct graphnode
{
	int vertex;
	struct graphnode* link;
} graphnode;

typedef struct graphtype
{
	int n;
	graphnode* adj_list[MAX_Vertices];
} graphtype;

void init(graphtype* g)
{
	g->n = 0;
	for (int i = 0; i < MAX_Vertices; i++) g->adj_list[i] = NULL;
}

void insertvertex(graphtype* g)
{
	if (((g->n) + 1) > MAX_Vertices)
	{
		return;
	}
	g->n++;
	return;
}
void insert_edge(graphtype* g, int u, int v)
{
	if (u >= g->n || v >= g->n)
	{
		return;
	}
	graphnode* node;
	node = (graphnode*)malloc(sizeof(graphnode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

}

int visited[MAX_Vertices];
int parent[MAX_Vertices];
void dfs_list(graphtype* g, int v)
{
	graphnode* w;
	visited[v] = TRUE;
	for (w = g->adj_list[v]; w; w = w->link)
	{
		if (!visited[w->vertex])
		{
			parent[w->vertex] = v;
			dfs_list(g, w->vertex);
		}
	}
}
int main(void)
{
	int N, i, u, v;
	graphtype* g;
	g = (graphtype*)malloc(sizeof(graphtype));
	init(g);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) insertvertex(g);
	for (i = 0; i < N-1; i++)
	{
		scanf("%d %d", &u, &v);
		insert_edge(g, u - 1, v - 1);
		insert_edge(g, v - 1, u - 1);
	}
	dfs_list(g, 0);
	for (i = 1; i < N; i++) printf("%d\n",parent[i] + 1);
	return 0;
}