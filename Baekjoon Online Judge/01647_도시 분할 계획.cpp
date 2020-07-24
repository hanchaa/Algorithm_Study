#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct {
	int cost, start, end;
} Edge;

int parent[100001];
Edge edge[1000000];

int UF_find(int cur) {
	if (parent[cur] == cur)
		return cur;

	return parent[cur] = UF_find(parent[cur]);
}

void UF_union(int aParent, int bParent) {
	parent[bParent] = aParent;
}

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &edge[i].start, &edge[i].end, &edge[i].cost);

	sort(edge, edge + m, [](Edge A, Edge B) {return A.cost < B.cost; });

	int sum = 0, cnt = 0;

	for (int i = 0; i < m; i++) {
		int aParent = UF_find(edge[i].start), bParent = UF_find(edge[i].end);

		if (aParent == bParent)
			continue;

		UF_union(aParent, bParent);

		sum += edge[i].cost;
		cnt++;

		if (cnt == n - 2)
			break;
	}

	printf("%d", sum);

	return 0;
}