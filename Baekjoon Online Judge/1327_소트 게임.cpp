#include <stdio.h>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n, k, cnt = 0;
	string str;
	set<string> visited;
	queue<string> bfs;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);

		str += tmp + '0';
	}
	
	bfs.push(str);

	string ans = str;
	sort(ans.begin(), ans.end());

	while (!bfs.empty()) {
		int size = bfs.size();

		for (int i = 0; i < size; i++) {
			string curStr = bfs.front();
			bfs.pop();

			if (curStr == ans) {
				printf("%d", cnt);
				return 0;
			}

			if (visited.find(curStr) != visited.end())
				continue;

			visited.insert(curStr);

			for (int j = 0; j <= n - k; j++) {
				string revStr = curStr.substr(j, k);
				reverse(revStr.begin(), revStr.end());
				bfs.push(curStr.substr(0, j) + revStr + curStr.substr(j + k, -1));
			}
		}
		cnt++;
	}

	printf("-1");

	return 0;
}