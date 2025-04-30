#include <stdio.h>

int main(void)
{
	int i, temp = 0;
	int str[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &str[i]);
	}

	for (i = 0; i < 5; i++)
	{
		temp += str[i] * str[i];
	}

	printf("%d", temp % 10);
	return 0;
}