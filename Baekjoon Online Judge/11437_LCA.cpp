#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

#define N 50005

using namespace std;

vector <int> list[N];

int level[N], parent[N];
bool chk[N];

void dfs(int n, int par, int lv) {
	chk[n] = true;
	level[n] = lv;
	parent[n] = par;

	for (int i = 0; i < list[n].size(); i++) {
		if (chk[list[n][i]] == false) dfs(list[n][i], n, lv + 1);
	}
}

int lca(int x, int y) {
	if (level[x] < level[y]) swap(x, y);
	while (level[x] > level[y]) {
		x = parent[x];
	}
	while (x != y) {
		x = parent[x];
		y = parent[y];
	}
	return x;
}

int main() {
	int n, m, i, j, k, q;

	scanf("%d", &n);

	for (i = 1; i < n; i++) {
		scanf("%d %d", &j, &k);
		list[j].push_back(k);
		list[k].push_back(j);
	}
	dfs(1, 0, 1);

	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &j, &k);
		printf("%d\n", lca(j, k));
	}
	return 0;
}