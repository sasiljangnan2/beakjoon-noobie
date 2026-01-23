#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
#include <map>
using namespace std; 
queue<int> q;
map <string, int> mark;
void bfs(long long n , long long m)
{
	q.push(n);
	mark[to_string(n)] = 0;
	while (!q.empty())
	{
		long long u = q.front();
		q.pop();
		if (u * 10  + 1 <= m)
		{
			if (mark[to_string(u * 10 + 1)] > mark[to_string(u)] + 1 || mark[to_string(u * 10 + 1)] == 0)
			{
				mark[to_string(u * 10 + 1)] = mark[to_string(u)] + 1;
				q.push(u * 10 + 1);
			}
		}
		if (u * 2 <= m)
		{
			if (mark[to_string(u * 2)] > mark[to_string(u)] + 1 || mark[to_string(u * 2)] == 0)
			{
				mark[to_string(u * 2)] = mark[to_string(u)] + 1;
				q.push(u * 2);
			}

		}
		
	}
}
int main()
{
	long long A, B;
	cin >> A >> B;
	if (A == B)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		bfs(A, B);
		if (mark[to_string(B)] == 0)
		{
			printf("-1\n");
			return 0;
		}
		printf("%d\n", mark[to_string(B)] + 1);
	}

}