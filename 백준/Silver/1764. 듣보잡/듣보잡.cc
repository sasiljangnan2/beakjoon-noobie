#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* arg1, const void* arg2)
{
	return strcmp((char*)arg1, (char*)arg2);
}

int main(void)
{
	int i, M, N, n = 0;
	char str[1000001][21], a[1000001][21];
	scanf("%d %d", &N, &M);
	

	for (i = 0; i < N + M; i++)
	{
		scanf("%s", &str[i]);
	}
	qsort(str, N + M, sizeof(str[0]), compare);
	for (i = 0; i < N + M; i++)
	{
		if (strcmp(str[i], str[i + 1]) == 0)
		{
			strcpy(a[n++], str[i]);
		}
	}
	
	printf("%d\n", n);
	for (i = 0; i < n; i++)
	{
		printf("%s\n", a[i]);
	}
	return 0;
}