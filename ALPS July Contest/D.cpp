#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
bool bought[100] = { 0 };
pair<int, int> beer[100];

int fourCanTenDollar(int leftMoney, int happiness) {
	int cnt = 0, tmp = happiness;

	for (int i = n - 1; i >= 0; i--) {
		if (leftMoney >= 2500 && !bought[i]) {
			tmp += beer[i].second;
			cnt++;
			leftMoney -= 2500;

			if (cnt % 4 == 0)
				happiness = tmp;
		}
	}

	return happiness;
}

bool cmp(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second)
		return A.first < B.first;

	return A.second < B.second;
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &beer[i].first, &beer[i].second);

	sort(beer, beer + n, cmp);

	int leftMoney = m, happiness = 0;
	
	happiness = fourCanTenDollar(leftMoney, happiness);
	ans = max(ans, happiness);

	for (int i = 0; i < n; i++) {
		leftMoney = m - beer[i].first;

		if (leftMoney < 0)
			continue;

		happiness = beer[i].second;
		bought[i] = true;

		happiness = fourCanTenDollar(leftMoney, happiness);
		ans = max(ans, happiness);

		bought[i] = false;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			leftMoney = m - beer[i].first - beer[j].first;

			if (leftMoney < 0)
				continue;

			happiness = beer[i].second + beer[j].second;
			bought[i] = bought[j] = true;

			happiness = fourCanTenDollar(leftMoney, happiness);
			ans = max(ans, happiness);

			bought[i] = bought[j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				leftMoney = m - beer[i].first - beer[j].first - beer[k].first;

				if (leftMoney < 0)
					continue;

				happiness = beer[i].second + beer[j].second + beer[k].second;
				bought[i] = bought[j] = bought[k] = true;

				happiness = fourCanTenDollar(leftMoney, happiness);
				ans = max(ans, happiness);

				bought[i] = bought[j] = bought[k] = false;
			}
		}
	}

	printf("%d", ans);

	return 0;
}