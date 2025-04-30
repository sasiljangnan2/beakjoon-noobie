#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	char A[5];
	char B[5];
	int C;
	scanf("%s", &A);
	scanf("%s", &B);
	scanf("%d", &C);
	printf("%d\n", atoi(A) + atoi(B) - C);
	printf("%d\n", atoi(strcat(A , B)) - C);
	return 0;
}