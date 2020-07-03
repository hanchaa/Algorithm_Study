#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int n, dp[1000];

	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 3;

	for (int i = 2; i < n; i++)
		dp[i] = ((dp[i - 2] * 2) % 10007 + dp[i - 1] % 10007) % 10007;

	printf("%d\n", dp[n - 1]);

	return 0;
}