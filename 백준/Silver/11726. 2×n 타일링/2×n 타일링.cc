#include <stdio.h>
#include <stdlib.h>

int main() {
	int i = 2;
	int N;
	int fibo[1002] = { 0 , 1 };
	i = 2;
	while (i < 1002)
	{
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 10007;
		i++;
	}
	scanf("%d", &N);
	printf("%d\n", fibo[N + 1]);
}