#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct {
	int cost, start, end;
} Edge;

int parent[200000];
Edge edge[200000];

bool cmp(Edge A, Edge B) {
	return A.cost < B.cost;
}

int UF_find(int cur) {
	if (parent[cur] == cur)
		return cur;

	return parent[cur] = UF_find(parent[cur]);
}

void UF_union(int aParent, int bParent) {
	if (aParent == bParent)
		return;

	parent[bParent] = aParent;
}

int main() {
	int m, n;

	scanf("%d %d", &m, &n);

	while (m != 0 && n != 0) {
		int sum = 0;

		for (int i = 0; i < m; i++)
			parent[i] = i;

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &edge[i].start, &edge[i].end, &edge[i].cost);
			sum += edge[i].cost;
		}

		sort(edge, edge + n, [](Edge A, Edge B) {return A.cost < B.cost; });

		for (int i = 0; i < n; i++) {
			int aParent = UF_find(edge[i].start), bParent = UF_find(edge[i].end);

			if (aParent == bParent)
				continue;

			UF_union(aParent, bParent);
			sum -= edge[i].cost;
		}

		printf("%d\n", sum);

		scanf("%d %d", &m, &n);
	}

	return 0;
}