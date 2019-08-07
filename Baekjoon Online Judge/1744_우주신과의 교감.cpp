#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

#define N 1005
#define mk make_pair

using namespace std;

typedef pair<double, double> p;
typedef pair<double, p> pp;


vector<pp> v;

int parent[N], map[N][5];

int find(int a) {
	if (parent[a] == -1) return a;
	return parent[a] = find(parent[a]);
}

void add(int a, int b) {
	int ap = find(a), bp = find(b);
	
	if (ap != bp) parent[bp] = ap;
}

int main() {
	int n, m, i, j, k, a, b, c;
	double sum = 0;
	
	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++) parent[i] = -1;

	for (i = 1; i <= n; i++) {
		scanf("%d %d", &map[i][0], &map[i][1]);
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++) {
			v.push_back(mk(sqrt(pow(map[j][0] - map[i][0], 2) + pow(map[j][1] - map[i][1], 2)), mk(i, j)));
		}
	}

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		add(a, b);
	}

	sort(v.begin(), v.end());

	for (i = 0; i < v.size(); i++) {
		if (find(v[i].second.first) != find(v[i].second.second)) {
			sum += v[i].first;
			add(v[i].second.first, v[i].second.second);
		}
	}

	printf("%.2lf\n", sum);

	return 0;
};