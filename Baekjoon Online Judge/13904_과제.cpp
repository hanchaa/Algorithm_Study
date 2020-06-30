#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>

using namespace std;

pair<int, int> p[1000];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.second;
	
	else
		return a.second > b.second;
}

int main() {
	int n, schedule[1005] = { 0 }, sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].first, &p[i].second);

	sort(p, p + n, cmp);

	for (int i = 0; i < n; i++) {
		for (int j = p[i].first; j > 0; j--) {
			if (schedule[j] == 0) {
				schedule[j] = p[i].second;
				break;
			}
		}
	}

	for (int i = 1; i < 1005; i++)
		sum += schedule[i];

	printf("%d\n", sum);
	
	return 0;
}