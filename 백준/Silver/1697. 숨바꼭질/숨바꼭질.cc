#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 200001
int data[MAX_QUEUE_SIZE];
int front = 0, rear = 0;
int empty()
{
	if (front == rear)
	{
		return 1;
	}
	else return 0;
}
void push(int item)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = item;
}
int pop()
{
	if (empty()) return -1;
	else
	{
		front = (front + 1) % MAX_QUEUE_SIZE;
		return data[front];
	}
}
int mark[200001] = { 0 };

void bfs(int n) 
{
	push(n);
	while (!empty())
	{
		int u = pop();
		if (u - 1 >= 0)
		{
			if (mark[u - 1] > mark[u] + 1 || mark[u - 1] == 0)
			{
				mark[u - 1] = mark[u] + 1;
				push(u - 1);
			}

		}
		if (u + 1 <= 200000)
		{
			if (mark[u + 1] > mark[u] + 1 || mark[u + 1] == 0)
			{
				mark[u + 1] = mark[u] + 1;
				push(u + 1);
			}
		}
		if (u * 2 <= 200000)
		{
			if (mark[u * 2] > mark[u] + 1 || mark[u * 2] == 0)
			{
				mark[u * 2] = mark[u] + 1;
				push(u * 2);
			}
		}
	}
}
int main() 
{
	int n, k;
	scanf("%d %d", &n, &k);
	if (n == k)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		bfs(n);
		printf("%d\n", mark[k]);
	}
	
}