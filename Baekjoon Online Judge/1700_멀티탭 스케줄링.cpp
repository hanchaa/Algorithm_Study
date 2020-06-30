#pragma warning (disable : 4996)
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> tab;

int main() {
	int n, k, data[100] = { 0 }, cnt = 0;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++)
		scanf("%d", data + i);

	for (int i = 0; i < k; i++) {
		bool alreadyPlugged = false;
		for (int j = 0; j < tab.size(); j++) {
			if (tab[j] == data[i]) {
				alreadyPlugged = true;
				break;
			}
		}

		if (alreadyPlugged)
			continue;

		if (tab.size() < n) {
			tab.push_back(data[i]);
			continue;
		}

		int maxDuration = 0, maxIdx = 0;
		for (int j = 0; j < tab.size(); j++) {
			int duration = 2e9;

			for (int m = i + 1; m < k; m++) {
				if (tab[j] == data[m]) {
					duration = m;
					break;
				}
			}

			if (maxDuration < duration) {
				maxIdx = j;
				maxDuration = duration;
			}
		}

		tab[maxIdx] = data[i];

		cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}