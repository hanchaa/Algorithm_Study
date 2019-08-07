#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

#define N 10005
#define MAX(a, b)(a > b ? a : b)
#define MIN(a, b)(a < b ? a : b)

int main() {
	int i, j, root = -1, edge = 0, minnode = 2e9, maxnode = 0, cnt = 0;
	int indegree[N] = { 0 }, outdegree[N] = { 0 };
	bool chk[N] = { false }, k = true;

	while (1) {
		scanf("%d %d", &i, &j);
		
		if (i == -1 && j == -1) break;

		if (i != 0 && j != 0) {
			chk[i] = chk[j] = 1;

			minnode = MIN(minnode, MIN(i, j));
			maxnode = MAX(maxnode, MAX(i, j));

			indegree[j]++;
			outdegree[i]++;
			edge++;
		}

		if (i == 0 && j == 0) {
			for (i = minnode; i <= maxnode; i++) {
				if (indegree[i] == 0 && outdegree[i] != 0) {
					if (root != -1) k = false;

					root = i;
				}
			}

			for (i = minnode; i <= maxnode; i++) {
				if (indegree[i] >= 2) k = false;
			}

			int node = 0;

			for (i = minnode; i <= maxnode; i++) {
				if (chk[i]) node++;
			}

			if (node != edge + 1) k = false;

			if (k == true || edge == 0) printf("Case %d is a tree.\n", ++cnt);
			else printf("Case %d is not a tree.\n", ++cnt);
		
			memset(indegree, 0, sizeof(indegree));
			memset(outdegree, 0, sizeof(outdegree));
			memset(chk, 0, sizeof(chk));

			k = true;
			root = -1;
			edge = 0;
			minnode = 2e9;
			maxnode = 0;
		}
	}


	return 0;
}