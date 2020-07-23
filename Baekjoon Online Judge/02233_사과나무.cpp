#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define N 2005
#define MAXH 20

using namespace std;

stack <int> s;
vector <int> list[N];

int parent[MAXH][N], level[N], num[N][2];
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
		if (d & 1 << i) {
			x = parent[i][x];
		}
	}

	return x;
}

int query(int x, int y) {
	if (level[x] > level[y]) swap(x, y);
	y = lv_up(y, level[y] - level[x]);
	
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
	int n, m, i, k, cnt = 1, x, y;

	scanf("%d", &n);

	for (i = 1; i <= 2 * n; i++) {
		scanf("%1d", &k);
		if (k == 0) { 
			s.push(cnt);
			num[cnt][0] = i;
			cnt++;
		}
		if (k == 1) {

			int a = s.top();
			s.pop();
			if (!s.empty()) {
				int b = s.top();

				list[a].push_back(b);
				list[b].push_back(a);
			}
			num[a][1] = i;
		}
	}

	dfs(1, 0, 1);
	fill(n);
	
	scanf("%d %d", &x, &y);

	for (i = 1; i <= n; i++) {
		if (num[i][0] == x || num[i][1] == x) m = i;
		if (num[i][0] == y || num[i][1] == y) k = i;
	}

	k = query(m, k);

	printf("%d %d\n", num[k][0], num[k][1]);

	return 0;
}