#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> p[200000];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].first, &p[i].second);

	sort(p, p + n);

	for (int i = 0; i < n; i++) {
		if (!pq.empty() && pq.top() <= p[i].first) {
			pq.pop();
			pq.push(p[i].second);
		}

		else
			pq.push(p[i].second);
	}

	printf("%d\n", pq.size());

	return 0;
}