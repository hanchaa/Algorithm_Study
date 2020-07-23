#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <vector>

#define N 55
#define MAX(a, b)(a > b ? a : b)
#define MIN(a, b)(a < b ? a : b)

using namespace std;

stack <int> s;
vector <int> v[N];

int p[N];

int main() {
	int n, m, i, j, k = 0, start;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &j);
		p[i] = j;
		if (j == -1) m = i;
	}

	scanf("%d", &start);

	for (i = 0; i < n; i++) {
		if (p[i] != -1 && i != start) v[p[i]].push_back(i);
	}

	if (start != m) s.push(m);

	while (!s.empty()) {
		int a = s.top();
		s.pop();
		if (v[a].size() == 0) k++;
		for (i = 0; i < v[a].size(); i++) {
			s.push(v[a][i]);
		}
	}
	printf("%d\n", k);

	return 0;
};