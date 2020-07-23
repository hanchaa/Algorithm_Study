#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1000000000

using namespace std;

vector<int> list[101], group[100];
priority_queue<int, vector<int>, greater<int>> pq;

int map[101][101], n, cnt = 0;

void bfs() {
	queue<int> q;
	bool visited[101] = { 0 };

	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;

		q.push(i);

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (visited[cur])
				continue;

			visited[cur] = true;
			group[cnt].push_back(cur);

			for (int next : list[cur])
				q.push(next);
		}

		cnt++;
	}
}

int main() {
	int m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		map[a][b] = map[b][a] = 1;
		list[a].push_back(b);
		list[b].push_back(a);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
	
	bfs();

	for (int i = 0; i < cnt; i++) {
		pair<int, int> minVal(INF, 0);

		for (int person : group[i]) {
			int maxStep = 0;

			for (int j = 1; j <= n; j++)
				if (map[person][j] != INF)
					maxStep = max(maxStep, map[person][j]);

			if (maxStep < minVal.first)
				minVal = make_pair(maxStep, person);
		}

		pq.push(minVal.second);
	}

	printf("%d\n", cnt);
	while (!pq.empty()) {
		printf("%d\n", pq.top());
		pq.pop();
	}

	return 0;
}