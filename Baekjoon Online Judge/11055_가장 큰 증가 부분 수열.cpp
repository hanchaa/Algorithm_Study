#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int main() {
	int dp[1000], data[1000], n, ans = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", data + i);
		dp[i] = data[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (data[i] > data[j])
				dp[i] = MAX(dp[i], dp[j] + data[i]);
		}
	}

	for (int i = 0; i < n; i++)
		ans = MAX(ans, dp[i]);

	printf("%d\n", ans);

	return 0;
}