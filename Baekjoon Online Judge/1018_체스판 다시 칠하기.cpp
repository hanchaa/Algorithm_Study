#pragma warning (disable : 4996)
#include <stdio.h>

#define MIN(a,b)(a<b?a:b)

int countRepaint(char map[][55], int n, int m) {
	int cnt = 0;
	char presentColor = map[n][m];
	
	for (int i = n; i < n + 8; i++) {
		for (int j = m; j < m + 8; j++) {
			if (map[i][j] != presentColor)
				cnt++;

			if (presentColor == 'B')
				presentColor = 'W';
			
			else
				presentColor = 'B';
		}

		if (presentColor == 'B')
			presentColor = 'W';

		else
			presentColor = 'B';
	}

	return cnt;
}

int main() {
	int n, m, min = 2e9;
	char map[55][55] = { 0 };

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 7 < n && j + 7 < m) {
				int cnt = countRepaint(map, i, j);
				min = MIN(min, MIN(cnt, 64 - cnt));
			}
		}
	}

	printf("%d\n", min);

	return 0;
}