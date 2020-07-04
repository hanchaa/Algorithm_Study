#include <stdio.h>
#include <algorithm>

#define MAX(a,b)(a>b?a:b)

using namespace std;

pair<int, int> thing[1000];

int dp[100][100005];

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &thing[i].first, &thing[i].second);

	for (int i = thing[0].first; i <= k; i++)
		dp[0][i] = thing[0].second;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];

			if (j >= thing[i].first)
				dp[i][j] = MAX(dp[i][j], dp[i - 1][j - thing[i].first] + thing[i].second);
		}
	}

	printf("%d\n", dp[n - 1][k]);

	return 0;
}