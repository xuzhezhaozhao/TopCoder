#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

#define MAX_SIZE 40
#define INFINITY 100000
#define Positive(exp) ((exp) >= 0 ? exp : -(exp))

int D[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
class GameOnABoard_Floyd
{
public:
	int optimalChoice(vector <string> cost);
};

int GameOnABoard_Floyd::optimalChoice(vector<string> cost)
{
	int i, j, k, m, q, p;
	int tempMax, minL;
	int dis;
	
	int board_rows, board_cols;
	board_rows = cost.size();
	board_cols = cost[0].size();

	for (i = 0; i < board_rows; i++) {
		for (j = 0; j < board_cols; j++) {
			for (k = 0; k < board_rows; k++) {
				for (m = 0; m < board_cols; m++) {
					D[i][j][k][m] = INFINITY;
				}
			}
		}
	}

	for (i = 0; i < board_rows; i++) {
		for (j = 0; j < board_cols; j++) {
			D[i][j][i][j] = 0;

			/* up */
			if (i - 1 >= 0) {
				D[i][j][i-1][j] = cost[i-1][j] - '0';			
			}

			/* down */
			if (i + 1 <= board_rows - 1) {
				D[i][j][i+1][j] = cost[i+1][j] - '0';
			}

			/* left */
			if (j - 1 >= 0) {
				D[i][j][i][j-1] = cost[i][j-1] - '0';
			}
			
			/* right */
			if (j + 1 <= board_cols - 1) {
				D[i][j][i][j+1] = cost[i][j+1] - '0';
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
						}
					}
				}
		}			}

	}

	tempMax = -1;
	minL = INFINITY;
	for (i = 0; i < board_rows; i++) {
		for (j = 0; j < board_cols; j++) {
			tempMax = -1;
			for (k = 0; k < board_rows; k++) {
				for (m = 0; m < board_cols; m++) {
					dis = D[i][j][k][m] + cost[i][j] - '0';
					if (dis > tempMax) {
						tempMax = dis;
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

#define entry(x, y) make_pair(dd[x][y], make_pair(x, y))

int dijkstra(int x, int y);
vector <string> bcost;

int dd[MAX_SIZE][MAX_SIZE];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int rows, cols;
class GameOnABoard
{
public:
	int optimalChoice(vector <string> cost);
};

int GameOnABoard::optimalChoice(vector<string> cost)
{
	int rows, cols, minL;
	rows = cost.size();
	cols = cost[0].size();
	minL = INFINITY;
	bcost = cost;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			minL = min(minL, dijkstra(i, j));
		}
	}

	return minL;
}

int dijkstra(int x, int y)
{
	int i, j, dir, maxC;
	int cus_x, cus_y, next_x, next_y;
	set < pair<int, pair<int, int>> > s;
	rows = bcost.size();
	cols = bcost[0].size();

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			dd[i][j] = INFINITY;
		}
	}
	dd[x][y] = bcost[x][y] - '0';
	s.insert(entry(x, y));

	while (!s.empty()) {
		cus_x = s.begin()->second.first;
		cus_y = s.begin()->second.second;
		s.erase(s.begin());

		for (dir = 0; dir < 4; dir++) {
			next_x = cus_x + dx[dir];
			next_y = cus_y + dy[dir];
			if (next_x < 0 || next_x >= rows || next_y < 0 || next_y >= cols) {
				continue;
			}

			if (dd[next_x][next_y] <= dd[cus_x][cus_y] + bcost[next_x][next_y] - '0') {
				continue;
			}
			s.erase( entry(next_x, next_y) );
			dd[next_x][next_y] = dd[cus_x][cus_y] + bcost[next_x][next_y] - '0';
			s.insert( entry(next_x, next_y) );
		}
	}
	maxC = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			maxC = max(maxC, dd[i][j]);
		}
	}
	return maxC;
}

int main()
{
	GameOnABoard game;
	vector <string> cost;

	string str[] =
	{"110010100101010110100010001100111011",
		"001000000110100011010100000001001000",
		"011000110111101001011101110111000100",
		"111001011000100101111010100110110011",
		"111000011101001010000100001010000010",
		"111001110010100101000001001100011011",
		"111110100111010101100000100111000111",
		"011111111100100111111110000001110111",
		"110000010101001111100011110000001000",
		"010010110111111100011101100000011010",
		"110001100001111001101000101110110001",
		"110010000111011110000010110111010101",
		"100100110101001001101000001101101101",
		"001011101101001100111110101111001110",
		"111010111111111100110100000011111100",
		"110101101000001001000100101011100000",
		"011011001011010001001000100000110101",
		"011111111100000011010111010011010100",
		"111001111110001110001110010100111010",
		"000001111000001100101010000001101110",
		"010000110000010010111110111000010101",
		"100010010100110011000111101001101011",
		"111010110001101011010001111101111100",
		"000111110000110000000101100101000110",
		"110000010111001001110001101010111100",
		"011111101101001011011010011111100010",
		"110101111101010100110010000011001101",
		"101101111001010100101111100001110001",
		"000110010100101111011011110010010010",
		"110101010011101000111011100000010011",
		"110001010001110011010100110000010001",
		"111010101100111100100011001101010100",
		"011000000000100001011010000100010001",
		"100000110110000001010001001111010000",
		"100011111110010011011011001110011111",
		"101100001111100101001101100000100001",
		"010000111011010110011001110011111000",
		"100010100111110111001010100101111010",
		"000110011110111011111000101000001000"}
	;

	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
		cost.push_back(str[i]);
	}

	cout << game.optimalChoice(cost) << endl;
	return 0;
}