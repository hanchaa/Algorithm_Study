#include <stdio.h>
#include <queue>
#include <vector>

#define MIN(a,b)(a<b?a:b)
#define INF 500000000

using namespace std;
typedef pair<int, int> p;

vector<p> list[801];

void dijkstra(int start, int *dist) {
	bool visited[801] = { 0 };
	
	dist[start] = 0;

	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();

		if (visited[cur])
			continue;

		visited[cur] = true;

		for (auto next : list[cur]) {
			int d = dist[cur] + next.second;

			if (d < dist[next.first]) {
				dist[next.first] = d;
				pq.push(make_pair(d, next.first));
			}
		}
	}
}

int main() {
	int distFrom1[801], distFromV1[801], distFromV2[801];
	int n, e, a, b;

	scanf("%d %d", &n, &e);

	for (int i = 0; i < e; i++) {
		int c;
		scanf("%d %d %d", &a, &b, &c);
		
		list[a].push_back(make_pair(b, c));
		list[b].push_back(make_pair(a, c));
	}

	scanf("%d %d", &a, &b);

	for (int i = 1; i <= n; i++)
		distFrom1[i] = distFromV1[i] = distFromV2[i] = INF;

	dijkstra(1, distFrom1);
	dijkstra(a, distFromV1);
	dijkstra(b, distFromV2);

	int res = MIN(distFrom1[a] + distFromV1[b] + distFromV2[n], distFrom1[b] + distFromV2[a] + distFromV1[n]);

	if (res >= INF)
		res = -1;

	printf("%d", res);

	return 0;
}