#include <stdio.h>
#include <string.h>

int main() {
	bool flag[25] = { 0 };
	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		char work[10];
		int x;

		scanf("\n%s", work);

		if (!strcmp(work, "add")) {
			scanf("%d", &x);
			flag[x] = true;
		}

		else if (!strcmp(work, "remove")) {
			scanf("%d", &x);
			flag[x] = false;
		}

		else if (!strcmp(work, "check")) {
			scanf("%d", &x);
			printf("%d\n", flag[x]);
		}

		else if (!strcmp(work, "toggle")) {
			scanf("%d", &x);
			flag[x] = !flag[x];
		}

		else if (!strcmp(work, "all"))
			memset(flag, 1, sizeof(flag));

		else if (!strcmp(work, "empty"))
			memset(flag, 0, sizeof(flag));
	}

	return 0;
}