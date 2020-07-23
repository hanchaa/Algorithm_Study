#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 1000005

using namespace std;
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
	int n, m, i, a, b, c;

	scanf("%d %d", &n, &m);

	for (i = 0; i <= n; i++) p[i] = -1;

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0) add(b, c);
		else if (a == 1) {
			if (find(b) == find(c)) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
};