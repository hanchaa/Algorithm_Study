#pragma warning (disable : 4996)
#include <stdio.h>

#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)

int h[100000];

int area(int l, int r) {
	if (l == r)
		return 0;

	if (r - l == 1)
		return h[l];

	int mid = (l + r) / 2;
	int result = MAX(area(l, mid), area(mid, r));

	int ll = mid, rr = mid, height = h[mid];

	while (ll > l || rr < r) {
		int leftHeight = -1, rightHeight = -1;

		if (ll > l)
			leftHeight = MIN(height, h[ll - 1]);

		if (rr < r)
			rightHeight = MIN(height, h[rr]);
	
		if (leftHeight > rightHeight) {
			height = leftHeight;
			ll--;
		}

		else {
			height = rightHeight;
			rr++;
		}

		result = MAX(result, (rr - ll) * height);
	}

	return result;
}

int main() {
	int n;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", h + i);

	printf("%d\n", area(0, n));

	return 0;
}