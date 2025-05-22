#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10000 
typedef int element; 
element stack[MAX_STACK_SIZE]; 
int top = -1;

int empty()
{
	if (top == -1) 
	{
		return 1; 
	}
	else return 0; 

}
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
void push(element item)
{
	if (is_full()) 
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}

int top_e()
{
	if (empty()) 
	{
		return -1;
	}
	else return stack[top];
}
int size()
{
	return top + 1;
}

element pop()
{
	if (empty()) return -1;
	else return stack[top--];
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
		else if (strcmp(str, "pop") == 0) printf("%d\n",pop());
		else if (strcmp(str, "top") == 0) printf("%d\n", top_e()); 
		else if (strcmp(str, "size") == 0) printf("%d\n", size()); 
		else if (strcmp(str, "empty") == 0) printf("%d\n", empty()); 
	}
	
}
