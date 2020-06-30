#pragma warning (disable : 4996)
#include <stdio.h>

void subset(int data[20], int* cnt, int n, int idx, int sum, int s) {
	if (idx >= n) {
		if (sum == s)
			(*cnt)++;

		return;
	}

	subset(data, cnt, n, idx + 1, sum + data[idx], s);
	subset(data, cnt, n, idx + 1, sum, s);
}

int main() {
	int n, s, data[20] = { 0 }, cnt = 0;

	scanf("%d%d", &n, &s);

	for (int i = 0; i < n; i++)
		scanf("%d", data + i);

	subset(data, &cnt, n, 0, 0, s);

	if (s == 0)
		cnt--;

	printf("%d\n", cnt);

	return 0;
}