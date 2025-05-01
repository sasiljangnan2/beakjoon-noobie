#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* arg1, const void* arg2)
{
	return (*(int*)arg1 - *(int*)arg2);
}

int main(void)
{
	int i, temp[3] = { 0 };

	while (1)
	{
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &temp[i]);
		}
		qsort(temp, 3, sizeof(int), compare);
		
		if (temp[0] == 0 && temp[1] == 0 && temp[2] == 0) break;

		else if (temp[0] * temp[0] + temp[1] * temp[1] == temp[2] * temp[2]) printf("right\n");

		else printf("wrong\n");
	}
	return 0;
}