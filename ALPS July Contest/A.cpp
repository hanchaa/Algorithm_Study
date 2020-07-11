#include <stdio.h>
#include <string.h>

int main() {
	int n, sum = 0;
	char data[10000];

	scanf("%d", &n);
	scanf("%s", data);

	for (int i = 0; i < n; i++) {
		if (strncmp(data + i, "SSH", 3) == 0)
			sum += 3;

		else if (strncmp(data + i, "SHS", 3) == 0)
			sum += 2;

		else if (strncmp(data + i, "HSS", 3) == 0)
			sum += 1;
	}

	printf("%d", sum);

	return 0;
}