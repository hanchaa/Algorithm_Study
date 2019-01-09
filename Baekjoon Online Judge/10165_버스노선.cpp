#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>

#define N 500005

using namespace std;

struct koi
{
	int in, out, x;
}bus[N];

bool cmp(const koi &A, const koi &B)
{
	if (A.in == B.in) return A.out > B.out;
 	return A.in < B.in;
}

int res[N];

int main(void)
{
	int n, m, i, max = 0;
	scanf("%d %d", &n, &m);
	for (i = 1;i <= m;i++)
	{
		scanf("%d %d", &bus[i].in, &bus[i].out); bus[i].x = i;
		if (bus[i].in > bus[i].out) { if( bus[i].out > max) max = bus[i].out; bus[i].out += n; }
	}
	sort(bus + 1, bus + m + 1, cmp);
	for (i = 1;i <= m;i++)
	{
		if (bus[i].out <= max) res[bus[i].x] = 1;
		else if (bus[i].out > max) max = bus[i].out;
	}
	for(i=1;i<=m;i++)
	{
		if (res[i] == 0) printf("%d ", i);
	}
}