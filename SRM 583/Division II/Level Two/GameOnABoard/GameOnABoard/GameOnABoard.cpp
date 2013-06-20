#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE 40
#define INFINITY 100000
#define Positive(exp) ((exp) >= 0 ? exp : -(exp))

int D[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
int D2[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
int C[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];


class GameOnABoard
{
public:
	int optimalChoice(vector <string> cost);
};

int GameOnABoard::optimalChoice(vector<string> cost)
{
	int i, j, k, m, q, p;
	int tempMax, minL;
	int dis;
	int start_i, start_j;
	
	int board_rows, board_cols;
	board_rows = cost.size();
	board_cols = cost[0].size();

	for (i = 0; i < board_rows; i++) {
		for (j = 0; j < board_cols; j++) {
			for (k = 0; k < board_rows; k++) {
				for (m = 0; m < board_cols; m++) {
					D[i][j][k][m] = INFINITY;
					D2[i][j][k][m] = INFINITY;
				}
			}
		}
	}

	for (i = 0; i < board_rows; i++) {
		for (j = 0; j < board_cols; j++) {
			D[i][j][i][j] = 0;
			D2[i][j][i][j] = 0;

			/* down */
			if (i + 1 <= board_rows - 1) {
				D[i][j][i+1][j] = (cost[i+1][j] - '0') ? 0 : 1;
				D2[i][j][i+1][j] = (cost[i+1][j] - '0') ? 0 : 1;
			}

			/* right */
			if (j + 1 <= board_cols - 1) {
				D[i][j][i][j+1] = (cost[i][j+1] - '0') ? 0 : 1;
			}

			/* left */
			if (j - 1 >= 0) {
				D2[i][j][i][j-1] = (cost[i][j-1] - '0') ? 0 : 1;
			}
		}
	}

	for (k = 0; k < board_rows; k++) {
		for (m = 0; m < board_cols; m++) {
			for (i = 0; i < board_rows; i++) {
				for (j = 0; j < board_cols; j++) {
					for (p = 0; p < board_rows; p++) {
						for (q = 0; q < board_cols; q++) {
							if (D[i][j][k][m] + D[k][m][p][q] < D[i][j][p][q]) {
								D[i][j][p][q] = D[i][j][k][m] + D[k][m][p][q];
							}
							if (D2[i][j][k][m] + D2[k][m][p][q] < D2[i][j][p][q]) {
								D2[i][j][p][q] = D2[i][j][k][m] + D2[k][m][p][q];
							}
						}
					}
				}
			}
		}
	}

	for (i = 0; i < board_rows; i++) {
		for (j = 0; j < board_cols; j++) {
			for (k = 0; k < board_rows; k++) {
				for (m = 0; m < board_cols; m++) {
					if (k >= i && m >= j) {
						C[i][j][k][m] = (Positive(k-i) + Positive(m - j)) - D[i][j][k][m] + cost[i][j] - '0';
					}
					if (k >= i && m <= j) {
						C[i][j][k][m] = (Positive(k-i) + Positive(m - j)) - D2[i][j][k][m] + cost[i][j] - '0';
					}
					C[k][m][i][j] = C[i][j][k][m];
				}
			}
		}
	}

	tempMax = -1;
	minL = INFINITY;
	for (i = 0; i < board_rows; i++) {
		for (j = 0; j < board_cols; j++) {
			tempMax = -1;
			for (k = 0; k < board_rows; k++) {
				for (m = 0; m < board_cols; m++) {
					if (i != k || j != m) {
						dis = C[i][j][k][m];
						if (dis > tempMax) {
							tempMax = dis;
						}
					}
				}
			}
			if (tempMax < minL) {
				minL = tempMax;
			}
		}
	}

	return minL;
}


int main()
{
	GameOnABoard game;
	vector <string> cost;

	string str[] = {
		"111001",
		"001000",
		"111111",
		"001111",
		"001100",
		"001011",
		"111001",
		"010011"
	}
	;

	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
		cost.push_back(str[i]);
	}
	//cost.push_back("01");


	cout << game.optimalChoice(cost) << endl;

	return 0;
}