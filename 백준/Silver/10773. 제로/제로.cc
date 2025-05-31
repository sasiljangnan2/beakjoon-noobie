#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100000 

int stack[MAX_STACK_SIZE];
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
void push(char item)
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

int pop()
{
	if (empty()) return -1;
	else return stack[top--];
}
int main(void)
{
	int i, k, d, temp = 0;
	
	scanf("%d", &k);
	
	for (i = 0; i < k; i++)
	{
		scanf("%d", &d);
		if (d == 0) pop();
		else push(d);
	}
	while (!empty())
	{
		temp += pop();
	}
	printf("%d\n", temp);
}
