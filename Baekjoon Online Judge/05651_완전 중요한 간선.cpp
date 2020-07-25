#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int k;
	scanf("%d", &k);

	while (k-- > 0) {
		int n, m, cnt = 0;
		int flow[301][301] = { 0 };
		pair<int, int> capacity[301][301];
		vector<int> adj[301];

		scanf("%d %d", &n, &m);

		int s = 1, e = n;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				capacity[i][j] = { 0, 0 };

		for (int i = 0; i < m; i++) {
			int f, t, b;
			scanf("%d %d %d", &f, &t, &b);

			capacity[f][t].first += b;
			capacity[f][t].second++;
			adj[f].push_back(t);
			adj[t].push_back(f);
		}

		while (1) {
			int from[301];
			queue<int> q;

			fill(from, from + n + 1, -1);
			q.push(s);

			while (!q.empty() && from[e] == -1) {
				int cur = q.front();
				q.pop();

				for (int next : adj[cur]) {
					if (from[next] == -1 && capacity[cur][next].first - flow[cur][next] > 0) {
						q.push(next);
						from[next] = cur;

						if (next == e)
							break;
					}
				}
			}

			if (from[e] == -1)
				break;

			int minFlow = 2e9;

			for (int i = e; i != s; i = from[i])
				minFlow = min(minFlow, capacity[from[i]][i].first - flow[from[i]][i]);

			for (int i = e; i != s; i = from[i]) {
				flow[from[i]][i] += minFlow;
				flow[i][from[i]] -= minFlow;
			}
		}

		vector<pair<int, int>> full;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (capacity[i][j].first == flow[i][j] && capacity[i][j].first) {
					full.push_back({ i,j });
					cnt += capacity[i][j].second;
				}
			}
		}

		for (auto cur : full) {
			bool visited[301] = { 0 };
			queue<int> q;
			q.push(cur.first);

			while (!q.empty()) {
				int idx = q.front();
				q.pop();

				if (visited[idx])
					continue;

				visited[idx] = true;

				if (visited[cur.second]) {
					cnt -= capacity[cur.first][cur.second].second;
					break;
				}

				for (int next : adj[idx])
					if (capacity[idx][next].first - flow[idx][next] > 0)
						q.push(next);
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}