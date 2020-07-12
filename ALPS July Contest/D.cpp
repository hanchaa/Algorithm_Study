#include <stdio.h>

#define MAX(a,b)(a>b?a:b)

int dp[100][100005];

typedef struct {
	int price, happiness;
} Beer;

Beer beer[100];

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &beer[i].price, &beer[i].happiness);


}