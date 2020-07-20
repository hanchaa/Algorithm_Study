#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, pair<string, int>> relation;

pair<string, int> find(string name) {
	if (relation[name].first == name)
		return relation[name];

	else
		return relation[name] = find(relation[name].first);
}

int merge(string a, string b) {
	string aParent = find(a).first, bParent = find(b).first;

	if (aParent == bParent)
		return relation[aParent].second;

	relation[aParent].second += relation[bParent].second;
	relation[bParent] = relation[aParent];

	return relation[aParent].second;
}

int main() {
	ios_base::sync_with_stdio(0);

	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		int f;
		scanf("%d", &f);

		for (int j = 0; j < f; j++) {
			string a, b;

			cin >> a >> b;

			if (relation.find(a) == relation.end())
				relation[a] = make_pair(a, 1);

			if (relation.find(b) == relation.end())
				relation[b] = make_pair(b, 1);

			printf("%d\n", merge(a, b));
		}

		relation.clear();
	}
}