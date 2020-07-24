#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int capacity[401][401], flow[401][401];
vector<int> adj[401];

int main() {
	int n, p, s = 1, e = 2, sum = 0;
	scanf("%d %d", &n, &p);

	for (int i = 0; i < p; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		capacity[a][b] = 1;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	while (1) {
		int from[401];
		queue<int> q;

		fill(from, from + n + 1, -1);
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