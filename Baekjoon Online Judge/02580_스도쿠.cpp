#include <stdio.h>
#include <vector>

using namespace std;

int sudoku[9][9];
bool found = false;
vector<pair<int, int>> hole;

void fill(int idx) {
	if (idx >= hole.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", sudoku[i][j]);

			printf("\n");
		}

		found = true;
		return;
	}

	for (int i = 1; !found && i <= 9; i++) {
		bool used = false;

		for (int j = 0; !used && j < 9; j++) {
			if (sudoku[hole[idx].first][j] == i || sudoku[j][hole[idx].second] == i)
				used = true;
		}

		for (int j = (hole[idx].first / 3) * 3; !used && j < (hole[idx].first / 3) * 3 + 3; j++)
			for (int k = (hole[idx].second / 3) * 3; !used && k < (hole[idx].second / 3) * 3 + 3; k++)
				if (sudoku[j][k] == i)
					used = true;

		if (!used) {
			sudoku[hole[idx].first][hole[idx].second] = i;
			fill(idx + 1);
			sudoku[hole[idx].first][hole[idx].second] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &sudoku[i][j]);

			if (sudoku[i][j] == 0)
				hole.push_back({ i,j });
		}
	}

	fill(0);

	return 0;
}