#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int age;
	int idx;
	char name[101];
}USER;

int compare(const void* arg1, const void* arg2)
{
	USER* a = (USER*)arg1;
	USER* b = (USER*)arg2;
	if (a->age < b->age) return -1;
	else if (a->age > b->age) return 11;
	else
	{
		if (a->idx < b->idx) return -1;
		else return 1;
	}
	return 0;
}
int main(void)
{
	int i, n;
	USER *user;
	scanf("%d", &n);
	user = (USER*)malloc(n * sizeof(USER));
	for (i = 0; i < n; i++)
	{
		scanf("%d %s", &user[i].age, &user[i].name);
		user[i].idx = i;
	}
	qsort(user, n, sizeof(user[0]), compare);
	for (i = 0; i < n; i++)
	{
		printf("%d %s\n", user[i].age, user[i].name);
	}
	free(user);
	return 0;
}