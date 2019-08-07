#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 205

int p[N];

int find(int a) {
	if (p[a] == -1) return a;
	return p[a] = find(p[a]);
}

void add(int a, int b) {
	int ap = find(a), bp = find(b);
	
	if (ap != bp) p[bp] = ap;
}

int main() {
	int n, m, i, j, k;
	bool res = true;

	scanf("%d %d", &n, &m);

	for (i = 0; i <= n; i++) p[i] = -1;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &k);
			if (k == 1) {
				add(i, j);
			}
		}
	}
	scanf("%d", &j);
	for (i = 2; i <= m; i++) {
		scanf("%d", &k);
		if (find(j) != find(k)) res = false;
		j = k;
	}

	if (res) printf("YES\n");
	else printf("NO\n");

	return 0;
};