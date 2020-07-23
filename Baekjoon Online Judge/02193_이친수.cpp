#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int n;
	long long dp[90];

	scanf("%d", &n);

	dp[0] = dp[1] = 1;

	for (int i = 2; i < n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	printf("%lld\n", dp[n - 1]);

	return 0;
}