#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int data[9], sum = 0;

	for (int i = 0; i < 9; i++) {
		scanf("%d", data + i);
		sum += data[i];
	}

	for (int i = 0; i < 9; i++) {
		int j;
		for (j = 0; j < 9; j++) {
			if (i == j)
				continue;

			if (sum - data[i] - data[j] == 100) {
				data[i] = data[j] = 100;
				break;
			}
		}

		if (j < 9)
			break;
	}

	sort(data, data + 9);

	for (int i = 0; i < 7; i++)
		printf("%d\n", data[i]);

	return 0;
}