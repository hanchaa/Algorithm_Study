#include <stdio.h>
#include <algorithm>

using namespace std;

int segTree[2100000];
pair<int, int> nums[1000005];

bool cmp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first)
		return A.second > B.second;

	return A.first < B.first;
}

int LIS(int idx, int leftBound, int rightBound, int queryL, int queryR) {
	if (queryL > rightBound || queryR < leftBound)
		return 0;

	if (queryL <= leftBound && rightBound <= queryR)
		return segTree[idx];

	int mid = (leftBound + rightBound) / 2;

	return max(LIS(idx * 2, leftBound, mid, queryL, queryR), LIS(idx * 2 + 1, mid + 1, rightBound, queryL, queryR));
}

int main() {
	int n, size = 1;
	
	scanf("%d", &n);

	while (size < n)
		size *= 2;

	for (int i = size; i < size + n; i++) {
		int tmp;
		scanf("%d", &tmp);
		nums[i - size] = { tmp, i };
	}

	sort(nums, nums + n, cmp);

	for (int i = 0; i < n; i++) {
		segTree[nums[i].second] = LIS(1, 1, size, 1, nums[i].second - size + 1) + 1;

		nums[i].second /= 2;

		while (nums[i].second >= 1) {
			segTree[nums[i].second] = max(segTree[nums[i].second * 2], segTree[nums[i].second * 2 + 1]);
			nums[i].second /= 2;
		}
	}

	printf("%d", segTree[1]);

	return 0;
}