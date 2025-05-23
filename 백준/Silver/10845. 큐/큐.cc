#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10000
int data[MAX_QUEUE_SIZE];
int front =0, rear = 0;
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
int size()
{
	if (front <= rear) return rear - front;
	else return MAX_QUEUE_SIZE - front + rear;
}
int front_e()
{
	if (empty()) return -1;
	else return data[(front + 1) % MAX_QUEUE_SIZE];
}
int rear_e()
{
	if (empty()) return -1;
	else return data[rear];
}
int main(void)
{
	int i, N, t;
	char str[100];
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%s", &str);
		if (strcmp(str, "push") == 0)
		{
			scanf("%d\n", &t);
			push(t);
		}
		else if (strcmp(str, "pop") == 0) printf("%d\n", pop());
		else if (strcmp(str, "front") == 0) printf("%d\n", front_e());
		else if (strcmp(str, "back") == 0) printf("%d\n", rear_e());
		else if (strcmp(str, "size") == 0) printf("%d\n", size());
		else if (strcmp(str, "empty") == 0) printf("%d\n", empty());
	}

}