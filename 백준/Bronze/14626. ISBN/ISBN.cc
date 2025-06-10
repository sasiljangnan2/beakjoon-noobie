#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int i, temp = 0, t;
	char arr[14];
	scanf("%s", &arr);
	for (i = 0; i < 14; i += 2)
	{
		if (arr[i] == '*')
		{
			t = i;
			continue;
		}
		temp += arr[i] - '0';
	}
	for (i = 1; i < 13; i += 2)
	{
		if (arr[i] == '*')
		{
			t = i;
			continue;
		}
		temp += (arr[i] - '0') * 3;
	}

	if (temp % 10 == 0 && t % 2 == 0) printf("0");
	else if (t % 2 == 0) printf("%d", 10 - (temp % 10));
	else if (t % 2 == 1)
	{
		for (i = 0; i < 10; i++)
		{
			if ((temp + 3 * i) % 10 == 0)
			{
				printf("%d", i);
				break;
			}
		}
	}
}
	
