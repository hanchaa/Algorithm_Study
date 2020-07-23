#pragma warning(disable : 4996)
#include <stdio.h>
#include <vector>
#include <queue>

#define M 1005
#define mk make_pair
#define MAX 100000000

using namespace std;

vector <pair <int, int> > edge[M];
vector <pair <int, int> > edge2[M];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq2;

int main() {
	int D[M] = { 0 }, D2[M] = { 0 };
	int n, m, i, j, k, a, b, v, u, d, x, max = 0;
	bool chk[M] = { 0 }, chk2[M] = { 0 };
	
	scanf("%d %d %d", &n, &m, &x);

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &d);
		edge[b].push_back(mk(a, d));
		edge2[a].push_back(mk(b, d));
	}

	for (i = 1; i <= n; i++) D[i] = MAX;
	D[x] = 0;

	pq.push(mk(0, x));
	
	while (!pq.empty()) {
		v = pq.top().second;
		pq.pop();

		if (chk[v]) continue;
		chk[v] = true;

		for (j = 0; j < edge[v].size(); j++) {
			u = edge[v][j].first;
			d = edge[v][j].second;

			if (D[u] > D[v] + d) {
				D[u] = D[v] + d;
				pq.push(mk(D[u], u));
			}
		}
	}
	
	for (i = 1; i <= n; i++) D2[i] = MAX;
	D2[x] = 0;

	pq2.push(mk(0, x));

	while (!pq2.empty()) {
		v = pq2.top().second;
		pq2.pop();

		if (chk2[v]) continue;
		chk2[v] = true;

		for (j = 0; j < edge2[v].size(); j++) {
			u = edge2[v][j].first;
			d = edge2[v][j].second;

			if (D2[u] > D2[v] + d) {
				D2[u] = D2[v] + d;
				pq2.push(mk(D2[u], u));
			}
		}
	}

	for (i = 1; i <= n; i++) {
		D[i] += D2[i];
		if (D[i] > max)	max = D[i];
	}

	printf("%d\n", max);

	return 0;
}