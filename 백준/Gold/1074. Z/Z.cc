#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void z(int s, int r, int c, int n)
{
	int size = s / 2;
	if (s == 1) 
	{
		printf("%d\n", n);
		return;
	}
	if (r < size && c < size) 
	{
		z(size, r, c, n);
	} 
	else if (r < size && c >= size) 
	{
		z(size, r, c - size, n + size * size);
	} 
	else if (r >= size && c < size) 
	{
		z(size, r - size, c, n + 2 * size * size);
	} 
	else 
	{
		z(size, r - size, c - size, n + 3 * size * size);
	}
}
int main() 
{
	int N, r, c;
	scanf("%d %d %d", &N, &r, &c);
	z(pow(2, N), r, c, 0);
}