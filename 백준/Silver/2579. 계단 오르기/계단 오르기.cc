#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main()
{
    int stair[301] = { 0 };
    int dp[301] = { 0 };
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &stair[i]);
    }

    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    for (int i = 4; i <= n; i++)
    {
        dp[i] = max(dp[i - 2], dp[i - 3] + stair[i - 1]) + stair[i];
    }

    printf("%d\n", dp[n]);
    return 0;
}