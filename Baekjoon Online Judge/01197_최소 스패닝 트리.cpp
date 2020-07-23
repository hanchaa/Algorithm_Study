#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 10005
#define mk make_pair

using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

vector<pp> v;

int parent[N];

int find(int a) {
	if (parent[a] == -1) return a;
	return parent[a] = find(parent[a]);
}

void add(int a, int b) {
	int ap = find(a), bp = find(b);
	
	if (ap != bp) parent[bp] = ap;
}

int main() {
	int n, m, i, j, k, a, b, c, sum = 0;
	
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) parent[i] = -1;

	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(mk(c, mk(a, b)));
	}

	sort(v.begin(), v.end());

	for (i = 0; i < v.size(); i++) {
		if (find(v[i].second.first) != find(v[i].second.second)) {
			sum += v[i].first;
			add(v[i].second.first, v[i].second.second);
		}
	}

	printf("%d\n", sum);

	return 0;
};