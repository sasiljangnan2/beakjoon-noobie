#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 2000000
#define MAX_SIZE 100
typedef struct {
	int x;
	int y;
	int z;
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
void push(int x, int y, int z)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear].x = x;
	data[rear].y = y;
	data[rear].z = z;
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
int land[MAX_SIZE][MAX_SIZE][MAX_SIZE];
void bfs(int n, int m, int h)
{
	while (!empty())
	{
		Node u = pop();
		if (u.x - 1 >= 0 && land[u.z][u.x - 1][u.y] == 0)
		{
			tempdata[index].x = u.x - 1;
			tempdata[index].y = u.y;
			tempdata[index].z = u.z;
			land[u.z][u.x - 1][u.y] = 1;
			index++;
		}
		if (u.x + 1 < n && land[u.z][u.x + 1][u.y] == 0)
		{
			tempdata[index].x = u.x + 1;
			tempdata[index].y = u.y;
			tempdata[index].z = u.z;
			land[u.z][u.x + 1][u.y] = 1;
			index++;
		}
		if (u.y - 1 >= 0 && land[u.z][u.x][u.y - 1] == 0)
		{
			tempdata[index].x = u.x;
			tempdata[index].y = u.y - 1;
			tempdata[index].z = u.z;
			land[u.z][u.x][u.y - 1] = 1;
			index++;
		}
		if (u.y + 1 < m && land[u.z][u.x][u.y + 1] == 0)
		{
			tempdata[index].x = u.x;
			tempdata[index].y = u.y + 1;
			tempdata[index].z = u.z;
			land[u.z][u.x][u.y + 1] = 1;
			index++;
		}
		if (u.z - 1 >= 0 && land[u.z - 1][u.x][u.y] == 0)
		{
			tempdata[index].x = u.x;
			tempdata[index].y = u.y;
			tempdata[index].z = u.z - 1;
			land[u.z - 1][u.x][u.y] = 1;
			index++;
		}
		if (u.z + 1 < h && land[u.z + 1][u.x][u.y] == 0)
		{
			tempdata[index].x = u.x;
			tempdata[index].y = u.y;
			tempdata[index].z = u.z + 1;
			land[u.z + 1][u.x][u.y] = 1;
			index++;
		}
	}
}
int main()
{
	int m, n, h, temp, count = -1;
	int i, j, k;
	int x, y;
	index = 0;
	scanf("%d %d %d", &m, &n, &h);
	for (k = 0; k < h; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d", &temp);
				if (temp == 1)
				{
					tempdata[index].x = i;
					tempdata[index].y = j;
					tempdata[index].z = k;
					index++;
				}
				land[k][i][j] = temp;
			}
		}
	}
	
	while (index > 0)
	{
		temp = index;
		for (i = 0; i < temp; i++)
		{
			push(tempdata[i].x, tempdata[i].y, tempdata[i].z);
		}
		index = 0;
		for (i = 0; i < temp; i++)
		{
			bfs(n, m, k);
		}
		count++;
	}
	for (k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (land[k][i][j] == 0)
				{
					printf("-1");
					return 0;
				}
			}
		}
	}
	printf("%d", count);
}