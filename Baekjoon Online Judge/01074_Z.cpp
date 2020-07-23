#pragma warning (disable : 4996)
#include <stdio.h>
#include <math.h>

int cnt = 0;
bool found = false;

void devide(int x, int y, int n, int r, int c) {
	if (found)
		return;

	if (r == x && c == y)
		found = true;

	if (r >= x && r < x + n && c >= y && c < y + n) {
		devide(x, y, n / 2, r, c);
		devide(x, y + n / 2, n / 2, r, c);
		devide(x + n / 2, y, n / 2, r, c);
		devide(x + n / 2, y + n / 2, n / 2, r, c);
	}

	else
		cnt += n * n;
}

int main() {
	int n, r, c;

	scanf("%d %d %d", &n, &r, &c);

	devide(0, 0, pow(2, n), r, c);

	printf("%d\n", cnt);

	return 0;
}