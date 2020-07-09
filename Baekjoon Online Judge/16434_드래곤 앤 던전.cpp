#include <stdio.h>

#define MIN(a,b)(a<b?a:b)

typedef struct {
	int type;
	int atk;
	int health;
} room;

room data[123456];

int main() {
	int n, atk;
	long long lo = 0, hi = 1e18;

	scanf("%d %d", &n, &atk);

	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &data[i].type, &data[i].atk, &data[i].health);

	while (lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		long long curAtk = atk, curHealth = mid;

		int i = 0;

		for (i = 0; i < n; i++) {
			if (data[i].type == 1)
				curHealth -= (data[i].health - 1) / curAtk * data[i].atk;

			else {
				curHealth = MIN(mid, curHealth + data[i].health);
				curAtk += data[i].atk;
			}

			if (curHealth <= 0)
				break;
		}

		if (i >= n)
			hi = mid;

		else
			lo = mid;
	}

	printf("%lld\n", hi);

	return 0;
}