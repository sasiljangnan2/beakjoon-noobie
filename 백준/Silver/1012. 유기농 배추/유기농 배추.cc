#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

typedef int element;
typedef struct { // 큐 타입
	int selected;
	int cabbage;
} Cabbage;
Cabbage cabbages[MAX_SIZE][MAX_SIZE];
void init()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cabbages[i][j].selected = 0;
			cabbages[i][j].cabbage = 0;
		}
	}
}
void adjacent(int x, int y, int M, int N)
{
	if (x - 1 >= 0 && cabbages[x - 1][y].cabbage == 1 && cabbages[x - 1][y].selected == 0) // 상
	{
		cabbages[x - 1][y].selected = 1;
		adjacent(x - 1, y, M, N);
	}
	if (x + 1 < M && cabbages[x + 1][y].cabbage == 1 && cabbages[x + 1][y].selected == 0) // 하
	{
		cabbages[x + 1][y].selected = 1;
		adjacent(x + 1, y, M, N);
	}
	if (y - 1 >= 0 && cabbages[x][y - 1].cabbage == 1 && cabbages[x][y - 1].selected == 0) // 좌
	{
		cabbages[x][y - 1].selected = 1;
		adjacent(x, y - 1, M, N);
	}
	if (y + 1 < N && cabbages[x][y + 1].cabbage == 1 && cabbages[x][y + 1].selected == 0) // 우
	{
		cabbages[x][y + 1].selected = 1;
		adjacent(x, y + 1, M, N);
	}
}
int main() 
{
	int T, M, N, K;
	int i, j, x, y;
	int lava;
	scanf("%d",&T);
	for (i = 0; i < T; i++)
	{
		init();
		lava = 0;
		scanf("%d %d %d", &M, &N, &K);
		for (j = 0; j < K; j++)
		{
			scanf("%d %d", &x, &y);
			cabbages[x][y].cabbage = 1;

		}
		for (x = 0; x < M; x++)
		{
			for (y = 0; y < N; y++)
			{
				if (cabbages[x][y].cabbage == 1 && cabbages[x][y].selected == 0)
				{
					cabbages[x][y].selected = 1;
					adjacent(x, y, M, N);
					lava++;
				}
			}
		}
		printf("%d\n", lava);
	}
}