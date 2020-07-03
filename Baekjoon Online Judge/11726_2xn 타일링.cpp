#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int n, dp[1005];

	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] % 10007 + dp[i - 2] % 10007) % 10007;

	printf("%d\n", dp[n]);

	return 0;
}