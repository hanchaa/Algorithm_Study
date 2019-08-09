#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 100005
#define MAXH 20
#define max(a, b)(a > b ? a : b)
#define mk make_pair

using namespace std;

vector <pair<int, int> > list[N];

int parent[MAXH][N], level[N];
long long dist[N];
bool chk[N];

void dfs(int n, int par, int lv, int d) {
	chk[n] = 1;
	parent[0][n] = par;
	level[n] = lv;

	dist[n] = dist[par] + d;
	for (int i = 0; i < list[n].size(); i++) {
		if (!chk[list[n][i].first]) dfs(list[n][i].first, n, lv + 1, list[n][i].second);
	}
}

void fill(int n) {
	for (int i = 1; i < MAXH; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}

int lv_up(int x, int d) {
	for (int i = MAXH - 1; i >= 0; i--) {
		if (d & (1 << i)) x = parent[i][x];
	}

	return x;
}

int query(int x, int y) {
	x = lv_up(x, max(0, level[x] - level[y]));
	y = lv_up(y, max(0, level[y] - level[x]));

	if (x == y) return x;

	for (int i = MAXH - 1; i >= 0; i--) {
		if (parent[i][x] != parent[i][y]) {
			x = parent[i][x];
			y = parent[i][y];
		}
	}
	x = parent[0][x];
	return x;
}

int query2(int x, int y, int k) {
	int lca = query(x, y);
	if (level[x] - level[lca] >= k) return lv_up(x, k);
	else {
		k = level[y] - level[lca] - k - (level[lca] - level[x]);
		return lv_up(y, k);
	}
}

int main() {
	int n, m, i, j, k, d, l, u, v;

	scanf("%d", &n);

	for (i = 1; i < n; i++) {
		scanf("%d %d %d", &j, &k, &d);
		list[j].push_back(mk(k, d));
		list[k].push_back(mk(j, d));
	}

	dfs(1, 0, 1, 0);
	fill(n);

	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d", &l);
		if (l == 1) {
			scanf("%d %d", &u, &v);
			printf("%lld\n", dist[u] + dist[v] - 2 * dist[query(u, v)]);
		}
		if (l == 2) {
			scanf("%d %d %d", &u, &v, &k);
			printf("%d\n", query2(u, v, k - 1));
		}
	}

	return 0;
}