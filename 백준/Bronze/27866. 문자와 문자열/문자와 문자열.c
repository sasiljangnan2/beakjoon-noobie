#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char S[1000];
	scanf("%s", &S);
	scanf("%d", &i);
	printf("%c", S[i - 1]);
}