#pragma warning (disable : 4996)
#include <stdio.h>

#define INF 1000000000

int main() {
	int dp[105][15] = { 0 }, n, sum = 0;

	scanf("%d", &n);

	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][1];

			else
				dp[i][j] = ((dp[i - 1][j - 1] % INF) + (dp[i - 1][j + 1] % INF)) % INF;
		}
	}

	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= INF;
	}

	printf("%d\n", sum);

	return 0;
}