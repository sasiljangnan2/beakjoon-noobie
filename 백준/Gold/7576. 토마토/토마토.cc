#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 2000000
#define MAX_SIZE 1000
typedef struct {
	int x;
	int y;
}Node;
Node data[MAX_QUEUE_SIZE];
Node tempdata[MAX_QUEUE_SIZE];
int index = 0;
int front = 0, rear = 0;
int empty()
{
	if (front == rear)
	{
		return 1;
	}
	else return 0;
}
void push(int x, int y)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear].x = x;
	data[rear].y = y;
}
Node pop()
{
	Node r;
	r.x = -1;
	r.y = -1;
	if (empty()) return r;
	else
	{
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
}
int land[MAX_SIZE][MAX_SIZE];
void bfs(int n, int m)
{
	while (!empty())
	{
		Node u = pop();
		if (u.x - 1 >= 0 && land[u.x - 1][u.y] == 0 )
		{
			tempdata[index].x = u.x - 1;
			tempdata[index].y = u.y;
			land[u.x - 1][u.y] = 1;
			index++;
		}
		if (u.x + 1 < n && land[u.x + 1][u.y] == 0 )
		{
			tempdata[index].x = u.x + 1;
			tempdata[index].y = u.y;
			land[u.x + 1][u.y] = 1;
			index++;
		}
		if (u.y - 1 >= 0 && land[u.x][u.y - 1] == 0 )
		{
			tempdata[index].x = u.x;
			tempdata[index].y = u.y - 1;
			land[u.x][u.y - 1] = 1;
			index++;
		}
		if (u.y + 1 < m && land[u.x][u.y + 1] == 0 )
		{
			tempdata[index].x = u.x;
			tempdata[index].y = u.y + 1;
			land[u.x][u.y + 1] = 1;
			index++;
		}
	}
}
int main()
{
	int m, n, temp, count = -1;
	int i, j;
	int x, y;
	index = 0;
	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &temp);
			if (temp == 1)
			{
				tempdata[index].x = i;
				tempdata[index].y = j;
				index++;
			}
			land[i][j] = temp;
		}
	}
	while (index > 0)
	{
		temp = index;
		for (i = 0; i < temp; i++)
		{
			push(tempdata[i].x, tempdata[i].y);
		}
		index = 0;
		for (i = 0; i < temp; i++)
		{
			bfs(n, m);
		}
		count++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (land[i][j] == 0)
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", count);
}