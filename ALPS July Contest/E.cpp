#include <stdio.h>
#include <stack>

using namespace std;

char str[1000000];

stack <int> leftToRight, rightToLeft;

int main() {
	int n;

	scanf("%d", &n);

	scanf("\n");

	for (int i = 0; i < n; i++) {
		scanf("%c", str + i);

		if (str[i] == '@')
			rightToLeft.push(i);
	}

	int last = rightToLeft.top();
	bool flag = false;

	while (!rightToLeft.empty()) {
		int start = rightToLeft.top(), finish = -1;
		rightToLeft.pop();
		leftToRight.push(start);

		if (!rightToLeft.empty()) {
			finish = rightToLeft.top();
			rightToLeft.pop();
			leftToRight.push(finish);
		}

		else
			flag = true;

		for (int i = start - 1; i > finish; i--)
			printf("%c", str[i]);
	}

	if (!flag)
		leftToRight.push(-1);

	while (!leftToRight.empty()) {
		int start = leftToRight.top(), finish = n;
		leftToRight.pop();

		if (!leftToRight.empty()) {
			finish = leftToRight.top();
			leftToRight.pop();
		}

		for (int i = start + 1; i < finish; i++)
			printf("%c", str[i]);
	}

	return 0;
}