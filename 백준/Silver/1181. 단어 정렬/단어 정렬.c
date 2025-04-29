#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* arg1, const void* arg2)
{
	if (strlen((const char*)arg1) > strlen((const char*)arg2)) return 1;
	else if (strlen((const char*)arg1) < strlen((const char*)arg2)) return -1;
	else return strcmp((char*)arg1, (char*)arg2);
}

int main(void)
{
	int i, n, j;
	char str[20000][51];
	scanf("%d",&n);
	

	for (i = 0; i < n; i++)
	{
		scanf("%s", &str[i]);
	}
	qsort(str, n, sizeof(str[0]), compare);
	

	for (i = 0; i < n; i++)
	{
		if (strcmp(str[i], str[i+1]) != 0 || i == n - 1) printf("%s\n", str[i]);
	}
	return 0;
}