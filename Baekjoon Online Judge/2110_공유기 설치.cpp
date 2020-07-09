#include <stdio.h>
#include <algorithm>

using namespace std;

int coord[200000];

int main() {
	int n, c, lo = 1, hi;

	scanf("%d %d", &n, &c);

	for (int i = 0; i < n; i++)
		scanf("%d", coord + i);

	sort(coord, coord + n);

	hi = coord[n - 1] - coord[0];

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2, prev = coord[0], cnt = 1, i = 1;

		while (i < n && cnt < c) {
			if (coord[i] - prev >= mid) {
				cnt++;
				prev = coord[i];
			}

			i++;
		}

		if (cnt < c)
			hi = mid;

		else
			lo = mid;
	}

	printf("%d\n", lo);

	return 0;
}