#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 128

typedef struct { 
	int color;
} Paper;
int blue = 0;
int white = 0;
Paper Paper_stack[MAX_SIZE][MAX_SIZE];
void init()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			Paper_stack[i][j].color = 0;
		}
	}
}
void cut(Paper(*list)[MAX_SIZE], int xleft, int xright, int yleft, int yright)
{
	int first = list[xleft][yleft].color;
	int flag = 1;
	for (int i = xleft; i <= xright && flag == 1; i++)
	{
		for(int j = yleft; j <= yright &&flag == 1; j++)
		{
			if (list[i][j].color != first)
			{
				flag = 0;
			}
		}
	}
	if (flag == 1)
	{
		if (first == 0) white++;
		else blue++;
		return;
	}
	else
	{
		int xmid = (xleft + xright) / 2;
		int ymid = (yleft + yright) / 2;
		cut(list, xleft, xmid, yleft, ymid);
		cut(list, xleft, xmid, ymid + 1, yright);
		cut(list, xmid + 1, xright, ymid + 1, yright);
		cut(list, xmid + 1, xright, yleft, ymid);
	}
}
int main() 
{
	int i, j;
	int T, color;
	scanf("%d", &T);
	init();
	for (int i = 0; i < T; i++)
	{
		for(int j = 0; j < T; j++)
		{
			scanf("%d", &color);
			Paper_stack[i][j].color = color;
		}
	}
	cut(Paper_stack, 0, T - 1, 0, T - 1);
	printf("%d\n%d\n", white, blue);
}