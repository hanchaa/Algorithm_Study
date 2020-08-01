#include <stdio.h>
#include <queue>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t-- > 0) {
		int m, n, k, map[50][50] = { 0 };
		bool visited[50][50] = { 0 };
		
		scanf("%d %d %d", &m, &n, &k);

		for (int i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);

			map[y][x] = 1;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !visited[i][j]) {
					cnt++;
					queue<pair<int, int>> q;

					q.push({ i,j });

					while (!q.empty()) {
						int x = q.front().first, y = q.front().second;
						q.pop();

						if (visited[x][y])
							continue;

						visited[x][y] = 1;

						if (x - 1 >= 0 && map[x - 1][y])
							q.push({ x - 1, y });

						if (x + 1 < n && map[x + 1][y])
							q.push({ x + 1, y });

						if (y - 1 >= 0 && map[x][y - 1])
							q.push({ x, y - 1 });

						if (y + 1 < m && map[x][y + 1])
							q.push({ x, y + 1 });
					}
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}