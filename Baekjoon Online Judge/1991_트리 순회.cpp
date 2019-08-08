#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 30

struct a {
	int left, right;
}tree[N];

void pre(int i) {
	printf("%c", i + 64);
	if (tree[i].left != 0) pre(tree[i].left);
	if (tree[i].right != 0) pre(tree[i].right);
}

void inorder(int i) {
	if (tree[i].left != 0) inorder(tree[i].left);
	printf("%c", i + 64);
	if (tree[i].right != 0) inorder(tree[i].right);
}

void post(int i) {
	if (tree[i].left != 0) post(tree[i].left);
	if (tree[i].right != 0) post(tree[i].right);
	printf("%c", i + 64);
}

int main() {
	int n, m, i, j, k;
	char a, b, c;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		while (getchar() != '\n');
		scanf("%c %c %c", &a, &b, &c);
		if (b != '.') tree[a - 64].left = b - 64;
		if (c != '.') tree[a - 64].right = c - 64;
	}

	pre(1);
	printf("\n");

	inorder(1);
	printf("\n");

	post(1);
	printf("\n");

	return 0;
}