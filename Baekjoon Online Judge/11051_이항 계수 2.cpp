#include <stdio.h>

int dp[1005][1005];

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	dp[1][0] = dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				dp[i][j] = 1;

			else
				dp[i][j] = ((dp[i - 1][j - 1] % 10007) + (dp[i - 1][j] % 10007)) % 10007;
		}
	}

	printf("%d\n", dp[n][k]);

	return 0;
}