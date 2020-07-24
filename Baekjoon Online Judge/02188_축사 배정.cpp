#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int to, capacity, flow;
	Edge* reverse;

	Edge() : Edge(-1, 0){}
	Edge(int t, int c) : to(t), capacity(c), flow(0), reverse(nullptr) {}

	int leftCapacity() {
		return capacity - flow;
	}

	void addFlow(int f) {
		flow += f;
		reverse->flow -= f;
	}
};

int main() {
	int n, m, sum = 0;
	vector<Edge*> adj[402];

	scanf("%d %d", &n, &m);

	int s = 0, e = 401;

	for (int i = 1; i <= n; i++) {
		Edge* e1 = new Edge(i * 2 - 1, 1), * e2 = new Edge(0, 0);
		
		e1->reverse = e2;
		e2->reverse = e1;

		adj[0].push_back(e1);
		adj[i * 2 - 1].push_back(e2);
	}

	for (int i = 1; i <= m; i++) {
		Edge* e1 = new Edge(e, 1), * e2 = new Edge(i * 2, 0);

		e1->reverse = e2;
		e2->reverse = e1;

		adj[i * 2].push_back(e1);
		adj[e].push_back(e2);
	}

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			int b;
			scanf("%d", &b);

			Edge* e1 = new Edge(b * 2, 1), * e2 = new Edge(i * 2 - 1, 0);

			e1->reverse = e2;
			e2->reverse = e1;

			adj[i * 2 - 1].push_back(e1);
			adj[b * 2].push_back(e2);
		}
	}

	int total = 0;

	while (1) {
		int from[402] = { 0 };
		Edge* edge[402] = { 0 };
		queue<int> q;

		fill(from, from + 402, -1);
		q.push(s);

		while (!q.empty() && from[e] == -1) {
			int cur = q.front();
			q.pop();

			for (Edge* next : adj[cur]) {
				int nextVertex = next->to;

				if (from[nextVertex] == -1 && next->leftCapacity() > 0) {
					q.push(nextVertex);
					from[nextVertex] = cur;
					edge[nextVertex] = next;

					if (nextVertex == e)
						break;
				}
			}
		}

		if (from[e] == -1)
			break;

		int minFlow = 2e9;

		for (int i = e; i != s; i = from[i])
			minFlow = min(minFlow, edge[i]->leftCapacity());

		for (int i = e; i != s; i = from[i])
			edge[i]->addFlow(minFlow);

		sum += minFlow;
	}

	printf("%d\n", sum);

	return 0;
}