#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

#define N 100005
#define MAXH 20
#define mk make_pair

using namespace std;

vector <pair<int, int> > list[N];

int parent[MAXH][N], dismin[MAXH][N], dismax[MAXH][N], level[N], mi = 2e9, ma = 0;
bool chk[N];

void dfs(int n, int par, int lv, int d) {
	chk[n] = 1;
	parent[0][n] = par;
	level[n] = lv;
	dismin[0][n] = d;
	dismax[0][n] = d;

	for (int i = 0; i < list[n].size(); i++) {
		if (!chk[list[n][i].first]) dfs(list[n][i].first, n, lv + 1, list[n][i].second);
	}
}

void fill(int n) {
	for (int i = 1; i < MAXH; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			dismax[i][j] = max(dismax[i - 1][parent[i - 1][j]], dismax[i - 1][j]);
			dismin[i][j] = min(dismin[i - 1][parent[i - 1][j]], dismin[i - 1][j]);
		}
	}
}

int lv_up(int x, int d) {
	for (int i = MAXH - 1; i >= 0; i--) {
		if (d & 1 << i) {
			mi = min(mi, dismin[i][x]);
			ma = max(ma, dismax[i][x]);
			x = parent[i][x];
		}
	}

	return x;
}

void query(int x, int y) {
	if (level[x] > level[y]) swap(x, y);
	y = lv_up(y, level[y] - level[x]);
	
	if (x == y) {
		printf("%d %d\n", mi, ma);
		return;
	}

	for (int i = MAXH - 1; i >= 0; i--) {
		if (parent[i][x] != parent[i][y]) {
			mi = min(mi, min(dismin[i][x], dismin[i][y]));
			ma = max(ma, max(dismax[i][x], dismax[i][y]));
			x = parent[i][x];
			y = parent[i][y];
		}
	}

	mi = min(mi, min(dismin[0][x], dismin[0][y]));
	ma = max(ma, max(dismax[0][x], dismax[0][y]));


	printf("%d %d\n", mi, ma);
}

int main() {
	int n, m, i, j, k, d, e;

	scanf("%d", &n);

	for (i = 1; i < n; i++) {
		scanf("%d %d %d", &j, &k, &d);
		list[j].push_back(mk(k, d));
		list[k].push_back(mk(j, d));
	}

	dfs(1, 0, 1, 0);
	fill(n);
	
	scanf("%d\n", &m);

	for (i = 1; i <= m; i++) {
		mi = 2e9, ma = 0;
		scanf("%d %d", &d, &e);
		query(d, e);
	}

	return 0;
}