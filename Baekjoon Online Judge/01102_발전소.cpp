#include <stdio.h>

#define INF 2000000000
#define MIN(a,b)(a<b?a:b)

using namespace std;

int map[16][16], dp[1 << 16], n, p;

int recovery(int working, int cnt) {
	if (dp[working] != INF)
		return dp[working];

	if (cnt >= p)
		return dp[working] = 0;

	for (int i = 0; i < n; i++) {
		if (working & (1 << i)) {
			for (int j = 0; j < n; j++) {
				if (!(working & (1 << j))) {
					dp[working] = MIN(dp[working], recovery(working | (1 << j), cnt + 1) + map[i][j]);
				}
			}
		}
	}

	return dp[working];
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < (1 << n); i++)
		dp[i] = INF;

	int working = 0, cnt = 0;

	scanf("\n");

	for (int i = 0; i < n; i++) {
		char tmp;
		tmp = getchar();

		if (tmp == 'Y') {
			cnt++;
			working = working | 1 << i;
		}
	}

	scanf("%d", &p);

	int res = recovery(working, cnt);
	if (res == INF)
		res = -1;

	printf("%d", res);

	return 0;
}