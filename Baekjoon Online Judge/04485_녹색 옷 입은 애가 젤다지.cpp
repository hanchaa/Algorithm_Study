#pragma warning (disable : 4996)
#include <stdio.h>
#include <queue>

#define M 130
#define mk make_pair
#define INF 100000000

using namespace std;

typedef pair <int, int> p;
typedef pair <int, p> pp;

priority_queue <pp, vector <pp>, greater <pp> > pq;

int main() {
	int cnt = 0;
	while (1) {
		cnt++;

		int n, m, i, j, k, map[M][M] = { 0 }, wallet[M][M] = { 0 };
		bool chk[M][M] = { 0 };

		scanf("%d", &n);
		if (n == 0) break;

		for (i = 0; i <= n + 1; i++) {
			for (j = 0; j <= n + 1; j++) {
				map[i][j] = -1;
				wallet[i][j] = INF;
			}
		}

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		wallet[1][1] = map[1][1];
		pq.push(mk(map[1][1], mk(1, 1)));

		while (!pq.empty()) {
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			int d = pq.top().first;

			pq.pop();

			if (chk[x][y]) continue;
			chk[x][y] = true;

			if (y - 1 > 0 && wallet[x][y - 1] > d + map[x][y - 1]) {
				wallet[x][y - 1] = d + map[x][y - 1];
				pq.push(mk(wallet[x][y - 1], mk(x, y - 1)));
			}

			if (x - 1 > 0 && wallet[x - 1][y] > d + map[x - 1][y]) {
				wallet[x - 1][y] = d + map[x - 1][y];
				pq.push(mk(wallet[x - 1][y], mk(x - 1, y)));
			}

			if (y + 1 < n + 1 && wallet[x][y + 1] > d + map[x][y + 1]) {
				wallet[x][y + 1] = d + map[x][y + 1];
				pq.push(mk(wallet[x][y + 1], mk(x, y + 1)));
			}

			if (x + 1 < n + 1 && wallet[x + 1][y] > d + map[x + 1][y]) {
				wallet[x + 1][y] = d + map[x + 1][y];
				pq.push(mk(wallet[x + 1][y], mk(x + 1, y)));
			}

		}

		printf("Problem %d: %d\n", cnt, wallet[n][n]);

	}
	return 0;
}