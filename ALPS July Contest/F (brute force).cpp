#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, k, falling[5] = { 0 };
	pair<int, int> block[6];

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", falling + i);

	for (int i = 1; i <= k; i++)
		scanf("%d %d", &block[i].first, &block[i].second);

	for (int i = 0; i < n; i++) {
		int cnt = 0, min = 2e9;

		for (int a = 0; a <= k; a++) {
			for (int b = a; b <= k; b++) {
				for (int c = b; c <= k; c++) {
					if (block[a].first + block[b].first + block[c].first >= falling[i]) {
						if (block[a].second + block[b].second + block[c].second < min) {
							min = block[a].second + block[b].second + block[c].second;
							cnt = 1;
						}

						else if (block[a].second + block[b].second + block[c].second == min)
							cnt++;
					}
				}
			}
		}

		printf("%d %d\n", min, cnt);
	}

	return 0;
}