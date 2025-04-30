#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i, num[8];
	for (i = 0; i < 8; i++)
	{
		scanf("%d", &num[i]);
	}
	for (i = 0; i < 7; i++)
	{
		if (num[i] != num[i + 1] + 1 && num[i] != num[i + 1] - 1)
		{
			printf("mixed");
			return 0;
		}
	
	}
	if (num[0] == 1)
	{
		printf("ascending");
	}
	else if (num[0] == 8)
	{
		printf("descending");
	}
}