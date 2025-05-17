#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int x;
	int y;
	int rank;
}Rank;


int main(void) 
{
	int i, j, N;
	scanf("%d", &N);
	Rank* rank = (Rank*)malloc(sizeof(Rank) * N);

	
	for (i = 0; i < N; i++)
	{
		scanf("%d %d",&rank[i].x, &rank[i].y);
		rank[i].rank = 1;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j) continue;
			if (rank[i].x < rank[j].x && rank[i].y < rank[j].y) rank[i].rank++;
		}
	}
	for (i = 0; i < N; i++)
	{
		printf("%d ", rank[i].rank);
	}
	return 0;
}



