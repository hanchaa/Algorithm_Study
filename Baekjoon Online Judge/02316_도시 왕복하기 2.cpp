#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int capacity[801][801], flow[801][801];
vector<int> adj[801];

int main() {
	int n, p, sum = 0;
	scanf("%d %d", &n, &p);
	
	int s = 1 + n, e = 2;

	for (int i = 3; i <= n; i++) {
		capacity[i][i + n] = 1;
		adj[i].push_back(i + n);
		adj[i + n].push_back(i);
	}

	for (int i = 0; i < p; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		capacity[a + n][b] = 1;
		capacity[b + n][a] = 1;

		adj[a + n].push_back(b);
		adj[b].push_back(a + n);
		adj[b + n].push_back(a);
		adj[a].push_back(b + n);
	}

	while (1) {
		int from[801];
		queue<int> q;

		fill(from, from + 2 * n + 1, -1);
		q.push(s);

		while (!q.empty() && from[e] == -1) {
			int cur = q.front();
			q.pop();

			for (int next : adj[cur]) {
				if (from[next] == -1 && capacity[cur][next] - flow[cur][next] > 0) {
					from[next] = cur;
					q.push(next);

					if (next == e)
						break;
				}
			}
		}

		if (from[e] == -1)
			break;

		int minFlow = 2e9;

		for (int i = e; i != s; i = from[i])
			minFlow = min(minFlow, capacity[from[i]][i] - flow[from[i]][i]);

		for (int i = e; i != s; i = from[i]) {
			flow[from[i]][i] += minFlow;
			flow[i][from[i]] -= minFlow;
		}

		sum += minFlow;
	}

	printf("%d", sum);

	return 0;
}