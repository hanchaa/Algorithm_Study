#pragma warning (disable : 4996)
#include <stdio.h>

int dp[1000000];

int main() {
	int n;
	
	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; i++)
		dp[i] = (dp[i - 2] % 15746 + dp[i - 1] % 15746) % 15746;

	printf("%d\n", dp[n - 1]);

	return 0;
}