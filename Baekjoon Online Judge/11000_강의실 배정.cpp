#pragma warning (disable : 4996)
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct schedule {
	int start;
	int finish;
} Schedule;

bool cmp(Schedule a, Schedule b) {
	if (a.start == b.start)
		return a.finish < b.finish;

	else
		return a.start < b.start;
}

int main() {
	int n, classroom[200000] = { 0 }, cnt = 0;
	Schedule data[200000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &data[i].start, &data[i].finish);

	sort(data, data + n, cmp);

	for (int i = 0; i < )
}