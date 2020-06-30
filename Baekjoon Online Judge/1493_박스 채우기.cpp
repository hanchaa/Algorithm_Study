#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

pair<int, int> cube[20];

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

void fill(int l, int w, int h, int n, bool *possible, int *cnt) {
	if (*possible == false)
		return;

	if (l == 0 || w == 0 || h == 0)
		return;

	for (int i = 0; i < n; i++) {
		if (cube[i].second > 0 && l >= pow(2, cube[i].first) && w >= pow(2, cube[i].first) && h >= pow(2,cube[i].first)) {
			cube[i].second--;
			(*cnt)++;

			fill(l, w, h - pow(2, cube[i].first), n, possible, cnt);
			fill(l, w - pow(2, cube[i].first), pow(2, cube[i].first), n, possible, cnt);
			fill(l - pow(2, cube[i].first), pow(2, cube[i].first), pow(2, cube[i].first), n, possible, cnt);

			return;
		}
	}

	*possible = false;
}

int main() {
	int l, w, h, n, cnt = 0;
	bool possible = true;

	scanf("%d %d %d %d", &l, &w, &h, &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &cube[i].first, &cube[i].second);

	sort(cube, cube + n, cmp);

	fill(l, w, h, n, &possible, &cnt);

	cnt = possible ? cnt : -1;

	printf("%d\n", cnt);

	return 0;
}