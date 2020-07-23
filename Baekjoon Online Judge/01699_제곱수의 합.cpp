#pragma warning (disable : 4996)
#include <stdio.h>

#define MIN(a,b)(a<b?a:b)

int dp[100005];

int main() {
	int n, num = 1;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		dp[i] = 2e9;
		
		if (i == num * num) {
			dp[i] = 1;
			num++;
			continue;
		}

		for (int j = 1; j < num; j++)
			dp[i] = MIN(dp[i], dp[i - j * j] + 1);
	}

	printf("%d\n", dp[n]);

	return 0;
}