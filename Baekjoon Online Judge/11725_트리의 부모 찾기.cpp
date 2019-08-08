#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <stack>

#define N 100005

using namespace std;

vector <int> list[N];
stack <int> s;
int parent[N];
bool chk[N];

int main() {
	int n, m, i, j, k;

	scanf("%d", &n);

	for (i = 1; i < n; i++) {
		scanf("%d %d", &j, &k);
		list[j].push_back(k);
		list[k].push_back(j);
	}

	s.push(1);

	while (!s.empty()) {
		int a = s.top();
		s.pop();
		chk[a] = true;

		for (i = 0; i < list[a].size(); i++) {
			if (chk[list[a][i]]) parent[a] = list[a][i];
			else s.push(list[a][i]);
		}

	}
	
	for (i = 2; i <= n; i++) printf("%d\n", parent[i]);
	return 0;
}