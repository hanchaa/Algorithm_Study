#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, l, data[1000] = { 0 }, cnt = 1, start = 0;

	scanf("%d %d", &n, &l);

	for (int i = 0; i < n; i++)
		scanf("%d", data + i);

	sort(data, data + n);

	start = data[0];

	for (int i = 1; i < n; i++) {
		if (data[i] > start + l - 1) {
			cnt++;
			start = data[i];
		}
	}

	printf("%d\n", cnt);

	return 0;
}