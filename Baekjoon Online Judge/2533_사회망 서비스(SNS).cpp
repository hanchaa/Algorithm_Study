#include <stdio.h>
#include <algorithm>
#include <vector>

#define INF 2000000000

using namespace std;

vector<int> edge[1000001], children[1000001];
bool visited[1000001];
int dp[1000001][2];

void findChildren(int cur) {
	visited[cur] = true;

	for (int next : edge[cur]) {
		if (!visited[next]) {
			children[cur].push_back(next);
			findChildren(next);
		}
	}
}

int DP(int current, bool isParentEarlyAdapter) {
	if (dp[current][isParentEarlyAdapter] != INF)
		return dp[current][isParentEarlyAdapter];

	int earlyAdopter = 1, notEarlyAdopter = INF;

	for (int next : children[current])
		earlyAdopter += DP(next, true);

	if (isParentEarlyAdapter) {
		notEarlyAdopter = 0;

		for (int next : children[current])
			notEarlyAdopter += DP(next, false);
	}

	return dp[current][isParentEarlyAdapter] = min(earlyAdopter, notEarlyAdopter);
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		dp[i][0] = dp[i][1] = INF;

	findChildren(1);

	printf("%d", DP(1, true));

	return 0;
}