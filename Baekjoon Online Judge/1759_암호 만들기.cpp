#include <stdio.h>
#include <algorithm>

using namespace std;

int l, c;
char alphabets[15], ans[15];

void backtracking(int idx, int alphabetCnt, int consonant, int vowel) {
	if (alphabetCnt == l) {
		if (vowel >= 1 && consonant >= 2) {
			for (int i = 0; i < l; i++)
				printf("%c", ans[i]);

			printf("\n");
		}

		return;
	}

	if (idx >= c)
		return;

	bool isVowel = 0;

	if (alphabets[idx] == 'a' || alphabets[idx] == 'e' || alphabets[idx] == 'i' || alphabets[idx] == 'o' || alphabets[idx] == 'u')
		isVowel = 1;

	ans[alphabetCnt] = alphabets[idx];
	backtracking(idx + 1, alphabetCnt + 1, consonant + (!isVowel * 1), vowel + (isVowel * 1));
	backtracking(idx + 1, alphabetCnt, consonant, vowel);
}

int main() {
	scanf("%d %d", &l, &c);

	for (int i = 0; i < c; i++)
		scanf(" %c", alphabets + i);

	sort(alphabets, alphabets + c);

	backtracking(0, 0, 0, 0);

	return 0;
}