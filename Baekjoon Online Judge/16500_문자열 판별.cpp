#include <stdio.h>
#include <string.h>

int main() {
	char str[100] = { 0 }, data[100][100] = { 0 };
	int n;
	bool possible[100] = { 0 };

	scanf("%s", str);
	scanf("%d", &n);

	int sLen = strlen(str);

	for (int i = 0; i < n; i++)
		scanf("%s", data[i]);

	for (int i = 0; i < sLen; i++) {
		for (int j = 0; j < n; j++) {
			int dLen = strlen(data[j]);

			if (i + dLen <= sLen) {
				if (strncmp(str + i, data[j], dLen) == 0 && (i == 0 || possible[i - 1]))
					possible[i + dLen - 1] = true;
			}
		}
	}

	printf("%d\n", possible[sLen - 1]);

	return 0;
}