#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX(a, b)(a > b ? a : b)
#define MIN(a, b)(a < b ? a : b)
#define N 1005

int t[N][N];
char s1[N], s2[N];

int main() {
	int n, m, i, j, k;

	scanf("%s %s", s1, s2);

	for (i = 1; i <= strlen(s2); i++) {
		for (j = 1; j <= strlen(s1); j++) {
			if (s2[i - 1] == s1[j - 1]) t[i][j] = MAX(t[i - 1][j - 1] + 1, MAX(t[i][j - 1], t[i - 1][j]));
			else t[i][j] = MAX(t[i - 1][j], t[i][j - 1]);
		}
	}

	printf("%d\n", t[strlen(s2)][strlen(s1)]);
	return 0;
}