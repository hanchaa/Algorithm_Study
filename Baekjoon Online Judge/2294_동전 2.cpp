#pragma warning (disable : 4996)
#include <stdio.h>

#define MIN(a,b)(a<b?a:b)
#define impossible 2e9

int dp[105][10005], coin[105];

int main() {
	int n, k;
	
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", coin + i);

	for (int i = 1; i <= k; i++) {
		dp[0][i] = impossible;

		if (i - coin[0] >= 0)
			dp[0][i] = MIN(dp[0][i], dp[0][i - coin[0]] + 1);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = impossible;

			dp[i][j] = dp[i - 1][j];

			if (j - coin[i] >= 0) {
				dp[i][j] = MIN(dp[i][j], dp[i - 1][j - coin[i]] + 1);
				dp[i][j] = MIN(dp[i][j], dp[i][j - coin[i]] + 1);
			}
		}
	}

	if (dp[n - 1][k] == impossible)
		dp[n - 1][k] = -1;

	printf("%d\n", dp[n - 1][k]);

	return 0;
}