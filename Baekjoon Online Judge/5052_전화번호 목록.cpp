#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool duplicated;

struct Trie {
	Trie* next[10];
	bool isEnd;
	bool hasNext;

	Trie() {
		for (int i = 0; i < 10; i++)
			next[i] = NULL;

		isEnd = false;
		hasNext = false;
	}

	~Trie() {
		for (int i = 0; i < 10 && next[i] != NULL; i++)
			delete next[i];
	}

	bool AddTrie(const char* input) {
		if (*input == '\0') {
			isEnd = true;
			return hasNext;
		}

		hasNext = true;
		int idx = *input - '0';

		if (next[idx] == NULL)
			next[idx] = new Trie;

		return (next[idx]->AddTrie(input + 1) | isEnd);
	}
};

int main() {
	int t, n;

	scanf("%d", &t);

	for (int T = 0; T < t; T++) {
		scanf("%d", &n);
		duplicated = false;
		Trie* trie = new Trie;

		for (int i = 0; i < n; i++) {
			char input[11];
			scanf("%s", input);

			duplicated |= trie->AddTrie(input);
		}

		printf("%s\n", duplicated ? "NO" : "YES");
		delete trie;
	}
}