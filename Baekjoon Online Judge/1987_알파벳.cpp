#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

char map[20][20];
bool used[26], visited[20][20];
int max = 0, r, c;

void backtracking(int i, int j, int dist) {
	if (used[map[i][j] - 'A'])
		return;

	max = MAX(max, dist);

	visited[i][j] = true;
	used[map[i][j] - 'A'] = true;

	if (i - 1 >= 0 && !visited[i - 1][j])
		backtracking(i - 1, j, dist + 1);

	if (i + 1 < r && !visited[i + 1][j])
		backtracking(i + 1, j, dist + 1);

	if (j - 1 >= 0 && !visited[i][j - 1])
		backtracking(i, j - 1, dist + 1);

	if (j + 1 < c && !visited[i][j + 1])
		backtracking(i, j + 1, dist + 1);

	visited[i][j] = false;
	used[map[i][j] - 'A'] = false;
}

int main() {
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)
		scanf("%s", map[i]);

	backtracking(0, 0, 1);

	printf("%d", max);
}