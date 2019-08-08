#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 100005
#define MAXH 20
#define max(a, b)(a > b ? a : b)

using namespace std;

vector <int> list[N];

int parent[MAXH][N], level[N];
bool chk[N];

void dfs(int n, int par, int lv) {
	chk[n] = 1;
	parent[0][n] = par;
	level[n] = lv;

	for (int i = 0; i < list[n].size(); i++) {
		if (!chk[list[n][i]]) dfs(list[n][i], n, lv + 1);
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

int main() {
	int n, m, i, j, k;

	scanf("%d", &n);

	for (i = 1; i < n; i++) {
		scanf("%d %d", &j, &k);
		list[j].push_back(k);
		list[k].push_back(j);
	}

	dfs(1, 0, 1);
	fill(n);

	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &j, &k);
		printf("%d\n", query(j, k));
	}

	return 0;
}