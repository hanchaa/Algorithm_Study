#include <stdio.h>
#include <math.h>

#define MIN(a,b)(a<b?a:b)

bool broken[10];

int buttonPressed(int n) {
	if (broken[n % 10])
		return -1;
	
	int cnt = 1;

	n /= 10;

	while (n > 0) {
		if (broken[n % 10])
			return -1;

		cnt++;

		n /= 10;
	}

	return cnt;
}

int main() {
	int n, m, ans = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		broken[a] = true;
	}

	ans = abs(n - 100);

	for (int i = 0; i <= 1000000; i++) {
		int cnt = buttonPressed(i);

		if (cnt == -1)
			continue;

		cnt += abs(n - i);

		ans = MIN(ans, cnt);
	}

	printf("%d", ans);
}