#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int i, A, B, C;
	int temp;
	char  buf[10];
	int res[10] = { 0 };
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	temp = A * B * C;
	sprintf(buf, "%d", temp);
	for (i = 0; i < 10; i++)
	{
		res[buf[i] - '0']++;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", res[i]);
	}
	return 0;
}