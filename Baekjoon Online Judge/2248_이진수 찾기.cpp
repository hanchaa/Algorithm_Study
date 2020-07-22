#include <stdio.h>

int main() {
	int n, l;
	long long dp[32][32], i;

	scanf("%d %d %lld", &n, &l, &i);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= l; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 1;

			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	long long pivot = i;

	for (int i = n; i > 0; i--) {
		if (dp[i - 1][l] < pivot) {
			printf("1");
			pivot -= dp[i - 1][l];
			l--;
		}

		else
			printf("0");
	}

	return 0;
}