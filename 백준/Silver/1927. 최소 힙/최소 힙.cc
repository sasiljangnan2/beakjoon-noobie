#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100001
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; 
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		
		if ((child < h->heap_size) &&
			(h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key) break;
		h->heap[parent] = h->heap[child]; 
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void init(HeapType* h) {
	h->heap_size = 0;
}
int main(void) {
	int N;
	element t, temp;
	HeapType* heap;
	heap = create();
	init(heap); 
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp.key);
		if (temp.key == 0)
		{
			if (heap->heap_size == 0) printf("0\n");
			else
			{
				t = delete_max_heap(heap);
				printf("%d\n", t.key);
			}
		}
		else
		{
			insert_max_heap(heap, temp);
		}
	}
	free(heap);
	return 0;
}