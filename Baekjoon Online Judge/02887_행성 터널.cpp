#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct {
	int x, y, z, idx;
} Position;

typedef struct {
	int cost, start, end;
} Edge;

Position position[100000];
Edge edge[300000];
int parent[100000];

int UF_find(int cur) {
	if (parent[cur] == cur)
		return cur;

	return parent[cur] = UF_find(parent[cur]);
}

void UF_merge(int aParent, int bParent) {
	parent[bParent] = aParent;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &position[i].x, &position[i].y, &position[i].z);
		position[i].idx = parent[i] = i;
	}

	int cnt = 0;

	sort(position, position + n, [](Position A, Position B) {return A.x < B.x; });
	for (int i = 0; i < n - 1; i++) {
		edge[cnt].cost = abs(position[i].x - position[i + 1].x);
		edge[cnt].start = position[i].idx;
		edge[cnt++].end = position[i+1].idx;
	}

	sort(position, position + n, [](Position A, Position B) {return A.y < B.y; });
	for (int i = 0; i < n - 1; i++) {
		edge[cnt].cost = abs(position[i].y - position[i + 1].y);
		edge[cnt].start = position[i].idx;
		edge[cnt++].end = position[i + 1].idx;
	}

	sort(position, position + n, [](Position A, Position B) {return A.z < B.z; });
	for (int i = 0; i < n - 1; i++) {
		edge[cnt].cost = abs(position[i].z - position[i + 1].z);
		edge[cnt].start = position[i].idx;
		edge[cnt++].end = position[i + 1].idx;
	}

	sort(edge, edge + cnt, [](Edge A, Edge B) {return A.cost < B.cost; });

	long long ans = 0;

	for (int i = 0; i < cnt; i++) {
		int aParent = UF_find(edge[i].start), bParent = UF_find(edge[i].end);

		if (aParent == bParent)
			continue;

		ans += edge[i].cost;
		UF_merge(aParent, bParent);
	}

	printf("%lld", ans);

	return 0;
}