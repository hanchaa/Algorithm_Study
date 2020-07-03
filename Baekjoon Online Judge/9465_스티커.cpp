#pragma warning (disable : 4996)
#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int t1[100000], t2[100000], data[2][100000];

int main() {
	int n, t;

	scanf("%d", &t);

	for (int k = 0; k < t; k++) {
		scanf("%d", &n);

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &data[i][j]);

		t1[0] = data[0][0];
		t2[0] = data[1][0];

		for (int i = 1; i < n; i++) {
			t1[i] = MAX(t1[i - 1], t2[i - 1] + data[0][i]);
			t2[i] = MAX(t2[i - 1], t1[i - 1] + data[1][i]);
		}

		printf("%d\n", MAX(t1[n - 1], t2[n - 1]));
	}

	return 0;
}