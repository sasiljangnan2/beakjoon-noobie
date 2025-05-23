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
	int i, N, K;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) push(i);
	printf("<");
	while (!empty()) {
		for (int i = 1; i < K; i++) {
			push(front_e());
			pop();
		}
		printf("%d", front_e());
		pop();
		if (!empty()) printf(", ");
	}
	printf(">\n");

}