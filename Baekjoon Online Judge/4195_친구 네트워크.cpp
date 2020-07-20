#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int parent[200000];

int find(int n) {
	if (parent[n] < 0)
		return n;

	return parent[n] = find(parent[n]);
}

int merge(int a, int b) {
	int aParent = find(a), bParent = find(b);

	if (aParent == bParent)
		return -parent[aParent];

	parent[aParent] += parent[bParent];
	parent[bParent] = aParent;

	return -parent[aParent];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int f, idx = 0;
		cin >> f;

		map<string, int> nameIndex;

		memset(parent, -1, sizeof(parent));

		for (int j = 0; j < f; j++) {
			string a, b;

			cin >> a >> b;

			if (nameIndex.find(a) == nameIndex.end())
				nameIndex[a] = idx++;

			if (nameIndex.find(b) == nameIndex.end())
				nameIndex[b] = idx++;

			printf("%d\n", merge(nameIndex[a], nameIndex[b]));
		}
	}
}