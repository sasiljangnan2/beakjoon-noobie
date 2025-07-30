#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, N, M;
	int S[21] = { 0 };
	char a[10];
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%s", &a);
		if (strcmp(a, "add") == 0)
		{
			scanf("%d", &N);
			S[N - 1] = N;
		}

		else if (strcmp(a, "remove") == 0)
		{
			scanf("%d", &N);
			S[N - 1] = 0;
		}
		else if (strcmp(a, "check") == 0)
		{
			scanf("%d", &N);
			if (S[N - 1] == 0) printf("0\n");
			else printf("1\n");
		}
		else if (strcmp(a, "toggle") == 0)
		{
			scanf("%d", &N);
			if (S[N - 1] == 0) S[N - 1] = N;
			else S[N - 1] = 0;
		}
		else if (strcmp(a, "all") == 0)
		{
			for (int j = 0; j < 21; j++)
				S[j] = j + 1;
		}
		else if (strcmp(a, "empty") == 0)
		{
			for (int j = 0; j < 21; j++)
				S[j] = 0;
		}
	}
	return 0;
}