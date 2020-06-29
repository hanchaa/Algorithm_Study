#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int n, x;

	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp < x)
			printf("%d ", tmp);
	}

	return 0;
}