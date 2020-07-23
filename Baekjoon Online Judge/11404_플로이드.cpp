#include <stdio.h>

#define MIN(a,b)(a<b?a:b)
#define INF 1000000000

int main() {
	int n, m, dist[101][101] = { 0 };

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		dist[a][b] = MIN(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = MIN(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", dist[i][j] == INF ? 0 : dist[i][j]);

		printf("\n");
	}

	return 0;
}