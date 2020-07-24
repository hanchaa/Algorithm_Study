#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int CtoI(char c) {
	if (c <= 'Z')
		return c - 'A';

	return c - 'a' + 26;
}

int main() {
	int n, sum = 0;
	int capacity[52][52] = { 0 }, flow[52][52] = { 0 };
	vector<int> edge[52];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char a, b;
		int c;
		scanf("\n%c %c %d", &a, &b, &c);

		a = CtoI(a);
		b = CtoI(b);

		capacity[a][b] = capacity[b][a] += c;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	int s = CtoI('A'), e = CtoI('Z');

	while (1) {
		int from[52];
		queue<int> bfsQ;

		fill(from, from + 52, -1);

		bfsQ.push(s);

		while (!bfsQ.empty() && from[e] == -1) {
			int cur = bfsQ.front();
			bfsQ.pop();

			for (int next : edge[cur]) {
				if (capacity[cur][next] - flow[cur][next] > 0 && from[next] == -1) {
					bfsQ.push(next);
					from[next] = cur;

					if (next == e)
						break;
				}
			}
		}

		if (from[e] == -1)
			break;

		int minFlow = 2e9, cur = e;

		while (cur != s) {
			minFlow = min(minFlow, capacity[from[cur]][cur] - flow[from[cur]][cur]);
			cur = from[cur];
		}

		cur = e;

		while (cur != s) {
			flow[from[cur]][cur] += minFlow;
			flow[cur][from[cur]] -= minFlow;
			cur = from[cur];
		}

		sum += minFlow;
	}

	printf("%d", sum);

	return 0;
}