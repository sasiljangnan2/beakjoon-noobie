#include <stdio.h>
#include <stdlib.h>

int main() {
	int i = 2;
	int T, N;
	int fibo[41][2] = { {1, 0}, {0 , 1} };
	scanf("%d", &T);
	i = 2;
	while (i < 41)
	{
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
		i++;
	}
	i = 0;
	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);
		printf("%d %d\n", fibo[N][0], fibo[N][1]);
	}
}