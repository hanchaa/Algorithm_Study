#pragma warning (disable : 4996)
#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int dp[1005][1005] = { 0 }, cost[1005] = { 0 };

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", cost + i);

	for (int i = 1; i <= n; i++)
		dp[1][i] = cost[1] * i;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j];

			if (j - i >= 0)
				dp[i][j] = MAX(dp[i][j], MAX(dp[i - 1][j - i] + cost[i], dp[i][j - i] + cost[i]));
		}
	}

	printf("%d\n", dp[n][n]);

	return 0;
}