#include <stdio.h>

int main() {
	int n, m;
	char str[100][100] = { 0 };

	scanf("%d %d\n", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);

	for (int j = m - 1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			switch (str[i][j])
			{

			case '.' :
				printf(".");
				break;

			case 'O' :
				printf("O");
				break;

			case '-' :
				printf("|");
				break;

			case '|' :
				printf("-");
				break;
				
			case '/' :
				printf("\\");
				break;
				
			case '\\' :
				printf("/");
				break;

			case '^' :
				printf("<");
				break;

			case '<' :
				printf("v");
				break;

			case 'v' :
				printf(">");
				break;

			case '>':
				printf("^");
				break;
			}
		}

		printf("\n");
	}

	return 0;
}