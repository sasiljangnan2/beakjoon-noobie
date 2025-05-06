#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
}DOT;

int compare(const void* arg1, const void* arg2)
{
	DOT* a = (DOT*)arg1;
	DOT* b = (DOT*)arg2;
	if (a->x < b->x) return -1;
	else if (a->x > b->x) return 1;
	else
	{
		if (a->y < b->y) return -1;
		else return 1;
	}
	return 0;
}

int main(void) 
{
    int i, n;  
	DOT *dot;
    scanf("%d", &n);
	dot = (DOT*)malloc(n * sizeof(DOT));
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &dot[i].x, &dot[i].y);
	}
	qsort(dot, n, sizeof(dot[0]), compare);
	for (i = 0; i < n; i++)
	{
		printf("%d %d\n", dot[i].x, dot[i].y);
	}
	free(dot);
	return 0;
}
