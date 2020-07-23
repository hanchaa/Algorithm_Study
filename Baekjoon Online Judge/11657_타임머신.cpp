#include <stdio.h>
#include <vector>

#define INF 2000000000

using namespace std;

int main() {
	int n, m;
	bool isCycle = false;
	pair<int, int> cost[501];
	vector<pair<int, int>> list[501];

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		cost[i] = make_pair(INF, 0);

	for (int i = 0; i < m; i++) {
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		list[a].push_back(make_pair(b, c));
	}

	cost[1] = make_pair(0, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[j].second != i)
				continue;

			for (auto next : list[j]) {
				int d = cost[j].first + next.second;

				if (d < cost[next.first].first) {
					cost[next.first].first = d;
					cost[next.first].second = i + 1;

					if (i == n)
						isCycle = true;
				}
			}
		}
	}

	if (isCycle)
		printf("-1");

	else {
		for (int i = 2; i <= n; i++) {
			if (cost[i].first != INF)
				printf("%d\n", cost[i].first);

			else
				printf("-1\n");
		}
	}

	return 0;
}