#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, k, data[10000] = { 0 }, length[10000] = { 0 };

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", data + i);

	sort(data, data + n);

	for (int i = 0; i < n - 1; i++)
		length[i] = data[i + 1] - data[i];

	sort(length, length + n - 1, cmp);

	int ans = data[n - 1] - data[0];

	for (int i = 0; i < k - 1; i++)
		ans -= length[i];
	
	printf("%d", ans);

	return 0;
}