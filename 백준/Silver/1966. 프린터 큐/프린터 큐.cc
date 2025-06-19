#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10000
int data[MAX_QUEUE_SIZE], dataa[MAX_QUEUE_SIZE];
int front = 0, rear = 0, fronta = 0, reara = 0;

int compare(const void* arg1, const void* arg2)
{
	return (*(int*)arg2 - *(int*)arg1);
}

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

void pusha(int item)
{
	reara = (reara + 1) % MAX_QUEUE_SIZE;
	dataa[reara] = item;
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
int popa()
{
	if (empty()) return -1;
	else
	{
		fronta = (fronta + 1) % MAX_QUEUE_SIZE;
		return dataa[fronta];
	}
}
int front_e()
{
	if (empty()) return -1;
	else return data[(front + 1) % MAX_QUEUE_SIZE];
}

int front_a()
{
	if (empty()) return -1;
	else return dataa[(fronta + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
	int i, j, cnt, M, N, t, arr[101] = { 0 };
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		front = 0;
		rear = 0;
		fronta = 0;
		reara = 0;
		scanf("%d %d", &N, &M);
		for (j = 0; j < N; j++)
		{
			scanf("%d", &t);
			push(t);
			if (j == M) pusha(1);
			else pusha(0);
			arr[j] = t;
		}
		qsort(arr, N, sizeof(int), compare);
		int c = 0;
		while (!empty())
		{
			
			if (front_e() == arr[c])
			{
				c++;
				if (front_a() == 1)
				{
					printf("%d\n", c);
					break;
				}
				pop();
				popa();
			}
			else
			{
				push(pop());
				pusha(popa());
			}
		}
	}
}