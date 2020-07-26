#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

long long d = 0, g = 0;
vector<long long> adj[300001];

int main() {
	long long n;
	scanf("%lld", &n);

	for (long long i = 1; i < n; i++) {
		long long a, b;
		scanf("%lld %lld", &a, &b);

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool visited[300001] = { 0 };
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (visited[cur])
			continue;

		visited[cur] = true;

		if (adj[cur].size() >= 3) {
			long long mul = 1;
			for (long long i = adj[cur].size(); i > adj[cur].size() - 3; i--)
				mul *= i;

			g += mul / 6;
		}

		if (adj[cur].size() >= 2) {
			for (int next : adj[cur]) {
				d += (adj[next].size() - 1) * (adj[cur].size() - 1);
			}
		}

		for (int next : adj[cur])
			q.push(next);
	}

	d /= 2;

	if (d > g * 3)
		printf("D");

	else if (d < g * 3)
		printf("G");

	else if (d == g * 3)
		printf("DUDUDUNGA");

	return 0;
}