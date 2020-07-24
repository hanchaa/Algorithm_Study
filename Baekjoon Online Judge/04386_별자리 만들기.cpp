#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct {
	float cost;
	int start, end;
} Edge;

int parent[100];
Edge edge[10000];

int UF_find(int cur) {
	if (parent[cur] == cur)
		return cur;

	return parent[cur] = UF_find(parent[cur]);
}

void UF_union(int aParent, int bParent) {
	parent[bParent] = aParent;
}

int main() {
	int n;
	scanf("%d", &n);

	pair<float, float> vertex[100];
	for (int i = 0; i < n; i++) {
		float a, b;

		scanf("%f %f", &a, &b);
		vertex[i] = { a, b };

		parent[i] = i;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edge[cnt].cost = sqrtf((vertex[j].first - vertex[i].first) * (vertex[j].first - vertex[i].first) + (vertex[j].second - vertex[i].second) * (vertex[j].second - vertex[i].second));
			edge[cnt].start = i;
			edge[cnt++].end = j;
		}
	}

	sort(edge, edge + cnt, [](Edge A, Edge B) {return A.cost < B.cost; });

	float ans = 0;

	for (int i = 0; i < cnt; i++) {
		int aParent = UF_find(edge[i].start), bParent = UF_find(edge[i].end);

		if (aParent == bParent)
			continue;

		ans += edge[i].cost;
		UF_union(aParent, bParent);
	}

	printf("%.2f", ans);
	
	return 0;
}