#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

#define N 100005
#define MAXH 20
#define max(a, b)(a > b ? a : b)
#define mk make_pair

using namespace std;

vector <pair<int, int> > list[N];

int parent[MAXH][N], power[N], dis[MAXH][N];
bool chk[N];

void dfs(int n, int par, int lv, int d) {
	chk[n] = 1;
	parent[0][n] = par;
	dis[0][n] = d;

	for (int i = 0; i < list[n].size(); i++) {
		if (!chk[list[n][i].first]) dfs(list[n][i].first, n, lv + 1, list[n][i].second);
	}
}

void fill(int n) {
	for (int i = 1; i < MAXH; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			dis[i][j] = dis[i - 1][parent[i - 1][j]] + dis[i - 1][j];
		}
	}
}

int query(int x, int p) {
	for (int i = MAXH - 1; i >= 0; i--) {
		if (p >= dis[i][x]) {
			p -= dis[i][x];
			x = parent[i][x];
		}
	}

	if (x == 0) x = 1;

	return x; 
}

int main() {
	int n, i, j, k, d;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &power[i]);
	}

	for (i = 1; i < n; i++) {
		scanf("%d %d %d", &j, &k, &d);
		list[j].push_back(mk(k, d));
		list[k].push_back(mk(j, d));
	}

	dfs(1, 0, 1, 0);
	fill(n);

	for (i = 1; i <= n; i++) {
		printf("%d\n", query(i, power[i]));
	}

	return 0;
}