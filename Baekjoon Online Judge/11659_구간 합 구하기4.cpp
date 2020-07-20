#include <stdio.h>

int prefixSum[100002];

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int data;
		scanf("%d", &data);
		prefixSum[i + 1] = prefixSum[i] + data;
	}

	for (int i = 0; i < m; i++) {
		int begin, end;

		scanf("%d %d", &begin, &end);

		printf("%d\n", prefixSum[end + 1] - prefixSum[begin]);
	}

	return 0;
}