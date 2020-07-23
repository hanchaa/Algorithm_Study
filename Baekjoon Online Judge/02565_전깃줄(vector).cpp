#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#define N 1005
#define mk make_pair

using namespace std;

vector<pair<int, int> > d;

int t[N];

int main() {
	int n, m, i, j, k = 0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		d.push_back(mk(a, b));
		t[i] = 1;
	}

	sort(d.begin(), d.end());
	
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (d[j].second < d[i].second) {
				t[i] = max(t[i], t[j] + 1);
			}
		}
		k = max(k, t[i]);
	}

	printf("%d\n", n - k);

	return 0;
} 