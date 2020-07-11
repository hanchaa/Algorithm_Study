#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int query[100000];
long long dp[200005];

int main() {
	int n, max = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", query + i);
		max = MAX(max, query[i]);
	}

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;

	for (int i = 5; i <= max; i++) {
		dp[i] = (dp[i - 2] % 1000000007 + dp[i - 3] % 1000000007 + dp[i - 4] % 1000000007) % 1000000007;
	}

	for (int i = 0; i < n; i++)
		printf("%lld\n", dp[query[i]]);

	return 0;
}