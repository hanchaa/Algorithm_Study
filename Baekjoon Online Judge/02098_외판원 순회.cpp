#include <stdio.h>

#define MIN(a,b)(a<b?a:b)
#define INF 2000000000

int map[16][16], dp[16][1<<16], n;

int tsp(int current, int visited) {
	if (dp[current][visited] != INF)
		return dp[current][visited];

	if (visited == (1 << n) - 1) {
		if (map[current][0] == 0)
			return INF;

		return map[current][0];
	}

	for (int i = 0; i < n; i++) {
		if (map[current][i] == 0 || visited & 1 << i)
			continue;

		dp[current][visited] = MIN(dp[current][visited], tsp(i, visited | 1 << i) + map[current][i]);
	}

	return dp[current][visited];
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < (1 << n); j++)
			dp[i][j] = INF;

	printf("%d", tsp(0, 1));

	return 0;
}