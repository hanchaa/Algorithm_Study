#include <stdio.h>

int parent[10000];

int find(int n) {
	if (parent[n] < 0)
		return n;

	return parent[n] = find(parent[n]);
}

void initRelation(int s, int e) {
	int sParent = find(s), eParent = find(e);

	if (sParent == eParent)
		return;

	if (parent[sParent] > parent[eParent])
		parent[eParent] = sParent;

	else
		parent[sParent] = eParent;
}

int main() {
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		parent[i] = -tmp;
	}

	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		initRelation(s - 1, e - 1);
	}

	int cost = 0;

	for (int i = 0; i < n; i++)
		if (parent[i] < 0)
			cost += -parent[i];

	if (cost > k)
		printf("Oh no");

	else
		printf("%d", cost);

	return 0;
}