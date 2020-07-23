#include <stdio.h>
#include <queue>
#include <vector>

#define MIN(a,b)(a<b?a:b)
#define INF 2000000000

using namespace std;

typedef pair<int, int> p;
priority_queue<p, vector<p>, greater<p>> pq;
vector<p> list[1000];

int main() {
	int n, m, start, end, dist[1000] = { 0 };
	bool visited[1000] = { 0 };

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int cost;
		scanf("%d %d %d", &start, &end, &cost);

		start--;
		end--;

		list[start].push_back(make_pair(end, cost));
	}

	scanf("%d %d", &start, &end);

	start--;
	end--;

	for (int i = 0; i < n; i++)
		dist[i] = INF;

	dist[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int current = pq.top().second;
		pq.pop();

		if (visited[current])
			continue;

		visited[current] = true;

		for (p next : list[current]) {
			int d = dist[current] + next.second;

			if (d < dist[next.first]) {
				dist[next.first] = d;
				pq.push(make_pair(d, next.first));
			}
		}
	}

	printf("%d", dist[end]);

	return 0;
}