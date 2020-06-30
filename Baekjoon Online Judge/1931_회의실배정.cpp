#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct schedule {
	int start;
	int finish;
} Schedule;

bool compare(Schedule a, Schedule b) {
	if (a.finish == b.finish)
		return a.start < b.start;

	else
		return a.finish < b.finish;
}

int main() {
	int n, finish = 0, cnt = 0;
	Schedule data[100000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &data[i].start, &data[i].finish);

	sort(data, data + n, compare);

	for (int i = 0; i < n; i++) {
		if (data[i].start >= finish) {
			finish = data[i].finish;
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}