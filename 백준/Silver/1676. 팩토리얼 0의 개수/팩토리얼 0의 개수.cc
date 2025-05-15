#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
	int i, N, t = 1, cnt = 0;
	scanf("%d", &N);
	
	for (i = 1; i <= N; i++)
	{
		t *= i;
		if (t > 10000)
		{
			t = t % 10000;
		}
		while (t % 10 == 0)
		{
			t = t / 10;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}



