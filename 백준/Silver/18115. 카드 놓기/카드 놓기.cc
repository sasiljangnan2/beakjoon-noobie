#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 2000002

typedef int element;
typedef struct { // 큐 타입
	element  queue[MAX_QUEUE_SIZE];
	int  front ,rear;
} QueueType;

void enqueue(QueueType* q, element item) {
	
	q->queue[q->rear++] = item;
}

void dequeue(QueueType* q, element item) {
	q->front = (q->front - 1);
	q->queue[q->front] = item;
}

element deletequeue(QueueType* q) 
{
	return q->queue[q->front++];
}

void printQueue(QueueType* q) {
	int i;
	for (i = q->front; i < q->rear; i++) 
	{
		printf("%d ", q->queue[i]);
	}
}
void initQueue(QueueType* q) {
	q->front = MAX_QUEUE_SIZE / 2;
	q->rear = MAX_QUEUE_SIZE / 2;
}

int main() {
	QueueType q;
	element temp;
	initQueue(&q);
	int i;
	int N, num[1000000] = { 0 };
	scanf("%d", &N);
	for (i = N -1; i >= 0; i--) {
		scanf("%d", &num[i]);
	}
	for (i = 0; i < N; i++)
	{
		switch (num[i])
		{
		case 1:
		{
			dequeue(&q, i + 1);
			break;
		}
		case 2:
		{
	
			temp = deletequeue(&q);
			dequeue(&q, i + 1);
			dequeue(&q, temp);
			break;
			
		}
		case 3:
		{
			enqueue(&q, i + 1);
			break;
		}
		default:
			break;
		}
	}
	printQueue(&q);
}