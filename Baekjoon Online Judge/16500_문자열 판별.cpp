#include <stdio.h>

int main() {
	char str[100] = { 0 }, data[100][100] = { 0 };
	int n;
	bool possible[100] = { 0 }, flag = true;

	scanf("%s", str);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%s", data[i]);

	return 0;
}