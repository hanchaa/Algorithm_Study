#include <stdio.h>
#include <vector>

#define INF -2000000000

using namespace std;

vector<pair<int, int>> list[101];
bool cycleFlag = false;

typedef struct {
	int cost, count, from;
} Dist;

void dfs(int cur, bool *visited, int n) {
	if (cur == n) {
		cycleFlag = true;
		return;
	}

	for (auto next : list[cur]) {
		if (!visited[next.first] && !cycleFlag) {
			visited[next.first] = true;
			dfs(next.first, visited, n);
		}
	}
}

int main() {
	int n, m;
	vector<int> cycle;
	Dist dist[101];

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		dist[i].cost = INF;
		dist[i].count = 0;
		dist[i].from = 0;
	}

	dist[1].cost = 0;
	dist[1].count = 1;

	for (int i = 0; i < m; i++) {
		int u, v, w;

		scanf("%d %d %d", &u, &v, &w);
		list[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[j].count != i)
				continue;

			for (auto next : list[j]) {
				int d = dist[j].cost + next.second;

				if (d > dist[next.first].cost) {
					dist[next.first].cost = d;
					dist[next.first].count = i + 1;
					dist[next.first].from = j;

					if (i == n)
						cycle.push_back(next.first);
				}
			}
		}
	}

	if (dist[n].cost == INF) {
		printf("-1");
		return 0;
	}

	for (int start : cycle) {
		bool visited[101] = { 0 };
		visited[start] = true;
		dfs(start, visited, n);

		if (cycleFlag) {
			printf("-1");
			return 0;
		}
	}

	int res[100] = { 0 }, cnt = 0, cur = n;

	while (cur != 0) {
		res[cnt++] = cur;
		cur = dist[cur].from;
	}

	for (int i = cnt - 1; i >= 0; i--)
		printf("%d ", res[i]);


	return 0;
}