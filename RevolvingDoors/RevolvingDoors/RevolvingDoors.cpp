/**
 * TopCoder:RevolvingDoors
 * （http://community.topcoder.com/stat?c=problem_statement&pm=3064&rd=5869）
 * Author: xuzhezhao
 * E-mail: zhezhaoxu@gmail.com
 * Blog: http://blog.csdn.net/xuzhezhaozhao/
 * Date: 2013/6/4
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

#define MAX 50

class RevolvingDoors
{
public:
	int turns(string map[]);
};

enum Door {H, V, NONE};
typedef struct CurrentPos{
	int row;
	int col;
	Door door[MAX][MAX];
	int throuth_doors;
}CurrentPos;

static int map_rows = 0;
static int map_cols = 0;
static int end_row;
static int end_col;
static int visited[MAX][MAX];

void init(string map[], CurrentPos &curpos);
bool isEnd(CurrentPos curpos);

int main()
{
	RevolvingDoors revolvingdoors;
	
	string map[] = {
	" |  |  |     |  |  |  |  |  | ",
	" O  O EO -O- O  O  O  O  OS O ",
	" |  |  |     |  |  |  |  |  | ", 
	""};

	cout << revolvingdoors.turns(map) << endl;

	return 0;
}

int RevolvingDoors::turns(string map[])
{
	list <CurrentPos> LC, LD;
	CurrentPos curpos, nextpos;
	int row, col;

	init(map, curpos);
	LD.push_back(curpos);

	while (!LD.empty()) {
		curpos = LD.front();
		LD.pop_front();

		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				visited[i][j] = false;
			}
		}
		
		LC.push_back(curpos);
		while (!LC.empty()) {
			curpos = LC.front();
			LC.pop_front();
			row = curpos.row;
			col = curpos.col;
			visited[row][col] = true;
		

			/* 向上走 */
			nextpos = curpos;
			if (row - 1 >= 0 && !visited[row-1][col]) {
				nextpos.row = row - 1;
				if (isEnd(nextpos)) {
					/* 终点处也要和turn一次的情况 */
					return curpos.throuth_doors;
				}

				if (' ' == map[row-1][col]) {
					LC.push_back(nextpos);
				} else if ('*' == map[row-1][col]) {
					if (row - 2 >= 0 && 'O' == map[row-2][col] &&
						H == curpos.door[row-2][col] ) {
							LC.push_back(nextpos);
					} else if (col + 1 <= map_cols - 1 && 
						'O' == map[row-1][col+1]) {
						if (V == curpos.door[row-1][col+1]) {
							LC.push_back(nextpos);
						} else {	/* turn door */
							nextpos.door[row-1][col+1] = V;
							++nextpos.throuth_doors;
							visited[row-1][col] = true;
							LD.push_back(nextpos);
						}
					} else if (col - 1 >= 0 && 
						'O' == map[row-1][col-1]) {
						if (V == curpos.door[row-1][col-1]) {
							LC.push_back(nextpos);
						} else {
							nextpos.door[row-1][col-1] = V;
							++nextpos.throuth_doors;
							visited[row-1][col] = true;
							LD.push_back(nextpos);
						}
					}
				}
			}

			/* 向下走 */
			nextpos = curpos;
			if (row + 1 <= map_rows - 1 && !visited[row+1][col]) {
				nextpos.row = row + 1;
				if (isEnd(nextpos)) {
					return curpos.throuth_doors;
				}
				if (' ' == map[row+1][col]) {
					LC.push_back(nextpos);
				} else if ('*' == map[row+1][col]) {
					if (row + 2 <= map_rows - 1 && 'O' == map[row+2][col] &&
						H == curpos.door[row+2][col] ) {
							LC.push_back(nextpos);
					} else if (col + 1 <= map_cols - 1 && 
						'O' == map[row+1][col+1]) {
							if (V == curpos.door[row+1][col+1]) {
								LC.push_back(nextpos);
							} else {	/* turn door */
								nextpos.door[row+1][col+1] = V;
								++nextpos.throuth_doors;
								visited[row+1][col] = true;
								LD.push_back(nextpos);
							}
					} else if (col - 1 >= 0 &&
						'O' == map[row+1][col-1]) {
						if (V == curpos.door[row+1][col-1]) {
							LC.push_back(nextpos);
						} else {
							nextpos.door[row+1][col-1] = V;
							++nextpos.throuth_doors;
							visited[row+1][col] = true;
							LD.push_back(nextpos);
						}
					}
				}
			}

			/* 向左走 */
			nextpos = curpos;
			if (col - 1 >= 0 && !visited[row][col-1]) {
				nextpos.col = col - 1;
				if (isEnd(nextpos)) {
					return curpos.throuth_doors;
				}
				if (' ' == map[row][col-1]) {
					LC.push_back(nextpos);
				} else if ('*' == map[row][col-1]) {
					if (col - 2 >= 0 && 'O' == map[row][col-2] &&
						V == curpos.door[row][col-2] ) {
							LC.push_back(nextpos);
					} else if (row - 1 >= 0 && 
						'O' == map[row-1][col-1]) {
						if (H == curpos.door[row-1][col-1]) {
							LC.push_back(nextpos);
						} else {	/* turn door */
							nextpos.door[row-1][col-1] = H;
							++nextpos.throuth_doors;
							visited[row][col-1] = true;
							LD.push_back(nextpos);
						}
					} else if (row + 1 <= map_rows - 1 &&
						'O' == map[row+1][col-1]) {
							if (H == curpos.door[row+1][col-1]) {
								LC.push_back(nextpos);
							} else {
								nextpos.door[row+1][col-1] = H;
								++nextpos.throuth_doors;
								visited[row][col-1] = true;
								LD.push_back(nextpos);
							}
					}
				}
			}

			/* 向右走 */
			nextpos = curpos;
			if (col + 1 <= map_cols - 1 && !visited[row][col+1]) {
				nextpos.col = col + 1;
				if (isEnd(nextpos)) {
					return curpos.throuth_doors;
				}
				if (' ' == map[row][col+1]) {
					LC.push_back(nextpos);
				} else if ('*' == map[row][col+1]) {
					if (col + 2 <= map_cols - 1 && 'O' == map[row][col+2] &&
						V == curpos.door[row][col+2] ) {
							LC.push_back(nextpos);
					} else if (row + 1 <= map_rows - 1 && 
						'O' == map[row+1][col+1]) {
						if (H == curpos.door[row+1][col+1]) {
							LC.push_back(nextpos);
						} else {	/* turn door */
							nextpos.door[row+1][col+1] = H;
							++nextpos.throuth_doors;
							visited[row][col+1] = true;
							LD.push_back(nextpos);
						}
					} else if (row - 1 >= 0 &&
						'O' == map[row-1][col+1]) {
						if (H == curpos.door[row-1][col+1]) {
							LC.push_back(nextpos);
						} else {
							nextpos.door[row-1][col+1] = H;
							++nextpos.throuth_doors;
							visited[row][col+1] = true;
							LD.push_back(nextpos);
						}
					}
				}
			}
		}
	}
	return -1;
}


void init(string map[], CurrentPos &curpos)
{
	int i, j;
	
	curpos.throuth_doors = 0;

	while (map[map_rows] != "") {
		++map_rows;
	}
	if (map_rows > 0) {
		map_cols = map[0].length();
	}

	for (i = 0; i < map_rows; i ++) {
		for (j = 0; j < map_cols; j++) {
			if ('S' == map[i][j]) {
				curpos.row = i;
				curpos.col = j;
				map[i][j] = ' ';
			}
			if ('E' == map[i][j]) {
				end_row = i;
				end_col = j;
				map[i][j] = ' ';
			}
		}
	}

	for (i = 0; i < map_rows; i ++) {
		for (j = 0; j < map_cols; j++) {
			if ('O' == map[i][j]) {
				if ('|' == map[i+1][j]) {
					curpos.door[i][j] = V;
				} else {
					curpos.door[i][j] = H;
				}
				map[i+1][j] = map[i-1][j] =
					map [i][j+1] = map[i][j-1] = '*';
			} else {
				curpos.door[i][j] = NONE;
			}
		}
	}
}

/**
 * 判断是否到达终点
 */
bool isEnd(CurrentPos curpos)
{
	if (curpos.row == end_row && curpos.col == end_col) {
		return true;
	} else {
		return false;
	}
}