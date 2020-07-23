#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define N 50005
#define MAXH 20
#define mk make_pair

using namespace std;

vector <pair<int, int> > list[N];
vector <pair<int, pair<int, int> > > d, nu;

int parent[MAXH][N], level[N], anc[N];
bool chk[N];

struct sgh {
	int x, y, z, chk;
}dis[MAXH][N], md;

void dfs(int n, int par, int lv, int d) {
	chk[n] = 1;
	parent[0][n] = par;
	dis[0][n].x = d;
	dis[0][n].y = par;
	dis[0][n].z = n;
	level[n] = lv;

	for (int i = 0; i < list[n].size(); i++) {
		if (!chk[list[n][i].first]) dfs(list[n][i].first, n, lv + 1, list[n][i].second);
	}
}

void fill(int n) {
	for (int i = 1; i < MAXH; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			//dis[i][j] = max(dis[i - 1][parent[i - 1][j]], dis[i - 1][j], cmp);
			if (dis[i-1][j].chk == 0) {
				if (dis[i - 1][parent[i - 1][j]].x != dis[i - 1][j].x) dis[i][j].chk = 1;
				if (dis[i - 1][parent[i - 1][j]].x < dis[i - 1][j].x) dis[i][j] = dis[i - 1][parent[i - 1][j]];
				else dis[i][j] = dis[i - 1][j];
			}
			else {
				dis[i][j].chk = 1;
				if (dis[i - 1][parent[i - 1][j]].x > dis[i - 1][j].x) dis[i][j] = dis[i - 1][parent[i - 1][j]];
				else dis[i][j] = dis[i - 1][j];
			}
		}
	}
}

int lv_up(int x, int d) {
	for (int i = MAXH - 1; i >= 0; i--) {
		if (d & 1 << i) {
			//md = max(md, dis[i][x], cmp);
			if (md.x < dis[i][x].x) md = dis[i][x];
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
			//md = max(md, max(dis[i][x], dis[i][y]), cmp);
			if (md.chk == 1) {
				if (dis[i][x].chk == 0 && dis[i][y].chk == 0) {
					if (dis[i][x].x < dis[i][y].x)
						if (md.x < dis[i][x].x) {
							md = dis[i][x];
							md.chk = 1;
						}
				}
			}
			
			if (md.x < dis[i][x].x) md = dis[i][x];
			if (md.x < dis[i][y].x)md = dis[i][y];
			x = parent[i][x];
			y = parent[i][y];
		}
	}
	//md = max(md, max(dis[0][x], dis[0][y]), cmp);
	if (md.x < dis[0][x].x) md = dis[0][x];
	if (md.x < dis[0][y].x) md = dis[0][y];
	x = parent[0][x];

	return x;
}

int find(int a) {
	if (anc[a] == -1) return a;
	return anc[a] = find(anc[a]);
}

void add(int a, int b) {
	anc[b] = a;
}

void update(int a, int b, int c, int d) {
	parent[0][a] = b;
	parent[0][b] = c;
	
	dis[0][a].x = dis[0][b].x;
	dis[0][a].y = b;
	dis[0][a].z = a;

	dis[0][b].x = d;
	dis[0][b].y = c;
	dis[0][b].z = b;

	for (int i = 1; i < MAXH; i++) {
		parent[i][b] = parent[i - 1][parent[i - 1][b]];
		parent[i][a] = parent[i - 1][parent[i - 1][a]];

		if (i == 1) {
			if (dis[i - 1][parent[i - 1][b]].x < dis[i - 1][b].x) dis[i][b] = dis[i - 1][parent[i - 1][b]];
			else dis[i][b] = dis[i - 1][b];

			if (dis[i - 1][parent[i - 1][a]].x < dis[i - 1][a].x) dis[i][a] = dis[i - 1][parent[i - 1][a]];
			else dis[i][a] = dis[i - 1][a];
		}
		else {
			//dis[i][b] = max(dis[i - 1][parent[i - 1][b]], dis[i - 1][b], cmp);
			if (dis[i - 1][parent[i - 1][b]].x > dis[i - 1][b].x) dis[i][b] = dis[i - 1][parent[i - 1][b]];
			//dis[i][a] = max(dis[i - 1][parent[i - 1][a]], dis[i - 1][a], cmp);
			else dis[i][b] = dis[i - 1][b];

			if (dis[i - 1][parent[i - 1][a]].x > dis[i - 1][a].x) dis[i][a] = dis[i - 1][parent[i - 1][a]];
			else dis[i][a] = dis[i - 1][a];
		}


	}
}

int main() {
	int n, m, i, j, k, a, b, c, sum = 0;

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) anc[i] = -1;

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);

		d.push_back(mk(c, mk(a, b)));
	}

	sort(d.begin(), d.end());

	for (i = 0; i < d.size(); i++) {
		if (find(d[i].second.first) != find(d[i].second.second)) { 
			list[d[i].second.first].push_back(mk(d[i].second.second, d[i].first));
			add(find(d[i].second.first), find(d[i].second.second)); 
			sum += d[i].first;
		}
		else {
			nu.push_back(mk(d[i].first, mk(d[i].second.first, d[i].second.second)));
		}
	}
	
	dfs(1, 0, 1, 0);
	fill(n);

	int mi = 2e9;

	for (i = 0; i < nu.size(); i++) {
		query(nu[i].second.first, nu[i].second.second);


		if (nu[i].first - md.x != 0 && nu[i].first - md.x < mi) {
			mi = nu[i].first - md.x;

			int b, c;
			if (level[nu[i].second.first] > level[nu[i].second.second]) b = nu[i].second.first;
			else b = nu[i].second.second;

			if (level[nu[i].second.first] < level[nu[i].second.second]) c = nu[i].second.first;
			else c = nu[i].second.second;

			update(md.z, b, c, nu[i].first);
		}
	}

	if (mi == 2e9) printf("-1\n");
	else printf("%d\n", sum + mi);

	return 0;
}