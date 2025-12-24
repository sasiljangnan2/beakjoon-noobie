#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int parent[MAX_VERTICES];

void set_init() 
{
	for (int i = 0; i < MAX_VERTICES; i++) {
		parent[i] = -1;
	}
}
int set_find(int v) {
	if (parent[v] == -1)
		return v;
	return set_find(parent[v]);
}
void set_union(int u, int v) {
	int root1 = set_find(u);
	int root2 = set_find(v);
	if (root1 != root2) {
		parent[root2] = root1;
	}
}
int main(void)
{
	int n, i, u, v, m;
	int sum = 0;
	set_init();
	scanf("%d", &m);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &u, &v);
		set_union(u - 1, v - 1);
	}
	for (i = 1; i < MAX_VERTICES; i++)
	{
		if (set_find(0) == set_find(i)) sum++;
	}
	printf("%d", sum);
}