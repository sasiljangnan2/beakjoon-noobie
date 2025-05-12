#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int i, t, j, b;
	char vps[50];

	scanf("%d", &t);

	for (i = 0; i < t; i++) 
	{
		scanf("%s", vps);
		j = 0;
		b = 0;
		while (vps[j] != '\0')
		{
			if (vps[j] == '(') b++;
			else if (vps[j] == ')') b--;
			if (b < 0)
			{
				printf("NO\n");
				break;
			}
			j++;
		}
		if (b == 0) printf("YES\n");
		else if (b > 0) printf("NO\n");
	}
	return 0;
}


