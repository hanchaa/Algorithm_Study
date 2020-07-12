#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int map[1005][1005], length[10][1005][1005];
pair <int, int> position[10];
queue<pair<int, int>> q;

void bfs(int start) {
	q.push(position[start]);
	length[start][position[start].first][position[start].second] = 1;

	while (!q.empty()) {
		pair <int, int> curPos = q.front();
		q.pop();

		if (map[curPos.first + 1][curPos.second] != 0 && length[start][curPos.first + 1][curPos.second] == 0) {
			length[start][curPos.first + 1][curPos.second] = length[start][curPos.first][curPos.second] + 1;
			q.push({ curPos.first + 1, curPos.second });
		}

		if (map[curPos.first - 1][curPos.second] != 0 && length[start][curPos.first - 1][curPos.second] == 0) {
			length[start][curPos.first - 1][curPos.second] = length[start][curPos.first][curPos.second] + 1;
			q.push({ curPos.first - 1, curPos.second });
		}

		if (map[curPos.first][curPos.second + 1] != 0 && length[start][curPos.first][curPos.second + 1] == 0) {
			length[start][curPos.first][curPos.second + 1] = length[start][curPos.first][curPos.second] + 1;
			q.push({ curPos.first, curPos.second + 1 });
		}

		if (map[curPos.first][curPos.second - 1] != 0 && length[start][curPos.first][curPos.second - 1] == 0) {
			length[start][curPos.first][curPos.second - 1] = length[start][curPos.first][curPos.second] + 1;
			q.push({ curPos.first, curPos.second - 1 });
		}
	}
}

int main() {
	int n, min = 2e9, ans;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			position[map[i][j]] = { i, j };
		}
	}

	for (int i = 3; i < 10; i++) {
		if (i == 4)
			continue;
		
		bfs(i);

		if (i == 3)
			continue;

		int tmp = length[i][position[4].first][position[4].second] + length[3][position[i].first][position[i].second];

		if (tmp < min) {
			min = tmp;
			ans = i;
		}
	}

	printf("%d", ans);

	return 0;
}