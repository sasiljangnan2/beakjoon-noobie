#include <stdio.h>
#define MAX_STACK_SIZE 100001

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int item)
{
    stack[++top] = item;
}

void pop()
{
    top--;
}

int main(void)
{
    int n, i, j = 1, b = 0, istop = 0, num;
    scanf("%d", &n);
    int r[100001];
    char c[200002];
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &r[i]);
    }
    for (i = 0; i < n; i++) 
    {
        if (j <= r[i]) 
        {
            while (j <= r[i]) 
            {
                push(j++);
				c[b++] = '+';
            }
			c[b++] = '-';
            pop();
        }
        else {
            if (top == -1 || stack[top] != r[i])
            {
                printf("NO\n");
                return 0;
            }
			c[b++] = '-';
            pop();
        }
    }
    for (i = 0; i < b; i++) 
    {
        printf("%c\n", c[i]);
	}
    return 0;
}