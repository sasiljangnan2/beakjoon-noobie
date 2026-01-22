#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>
#include <vector>
#include <utility>

#define INF 1000000000 
#define MAX_Vertices 20000

typedef std::pair<int, int> pii;

typedef struct graphtype 
{
    int n; 
    std::vector<pii> adj_list[MAX_Vertices]; 
} graphtype;

void init(graphtype* g, int n) 
{
    g->n = n;
    for (int i = 0; i < n; i++) 
    {
        g->adj_list[i].clear();
    }
}

void insert_edge(graphtype* g, int u, int v, int w) 
{
    g->adj_list[u].push_back({ w, v }); 
}

void dijkstra(graphtype* g, int start)
{
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; 
    std::vector<int> distance(g->n, INF); 

    distance[start] = 0;
    pq.push({ 0, start }); 

    while (!pq.empty())
    {
        int dist = pq.top().first; 
        int u = pq.top().second;   
        pq.pop();

        if (dist > distance[u]) continue; 

        for (auto edge : g->adj_list[u]) 
        {
            int weight = edge.first; 
            int v = edge.second;     

            if (distance[v] > distance[u] + weight) 
            {
                distance[v] = distance[u] + weight;
                pq.push({ distance[v], v });
            }
        }
    }

    for (int i = 0; i < g->n; i++) 
    {
        if (distance[i] == INF) 
        {
            printf("INF\n");
        }
        else 
        {
            printf("%d\n", distance[i]);
        }
    }
}

int main(void) 
{
    int N, V, K;
    int u, v, w;
    graphtype g;

    scanf("%d %d", &N, &V); 
    scanf("%d", &K);        
    init(&g, N);

    for (int i = 0; i < V; i++) 
    {
        scanf("%d %d %d", &u, &v, &w);
        insert_edge(&g, u - 1, v - 1, w);
    }

    dijkstra(&g, K - 1);
    return 0;
}