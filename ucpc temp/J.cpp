#include <stdio.h>
#include <vector>

using namespace std;

vector<int> meet[100001];
int dp[100001];

int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= m; i++) {
		int a;
		scanf("%d", &a);

		for (int j = 0; j < a; j++) {
			int b;
			scanf("%d", &b);

			meet[i].push_back(b);
		}
	}

	for (int i = 1; i <= n; i++)
		scanf("%d", dp + i);

	bool visited[100001] = { 0 };

	for (int i = m; i > 0; i--) {
		int flag = 0;

		for (int cur : meet[i]) {
			flag += dp[cur];
			visited[cur] = true;
		}

		if (flag > 0 && flag < meet[i].size()) {
			printf("NO\n");
			return 0;
		}

		bool zero = false;
		for (int next : meet[i - 1])
			if (dp[next] == 0)
				zero = true;

		if (!zero)
			continue;

		for (int next : meet[i - 1]) {
			if (visited[next] == false && dp[next] == 1) {
				printf("NO\n");
				return 0;
			}

			dp[next] = 0;
		}

	}

	printf("YES\n");

	for (int i = 1; i <= n; i++)
		printf("%d ", dp[i]);

	return 0;
}