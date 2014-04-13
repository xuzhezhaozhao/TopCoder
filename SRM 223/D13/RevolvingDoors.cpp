/**
 * TopCoder:RevolvingDoors
 * （http://community.topcoder.com/stat?c=problem_statement&pm=3064&rd=5869）
 * Author: xuzhezhao
 * E-mail: zhezhaoxu@gmail.com
 * Blog: http://blog.csdn.net/xuzhezhaozhao/
 * Date: 2013/6/7
 */

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

#define MAX 50			/* 地图无数限制数 */
#define DOORS_MAX 10		/* 门数限制 */

class RevolvingDoors
{
public:
	int turns(vector <string> map);
};

enum Door_State {H, V};		/* 门的状态，H：水平 V：竖直 */
typedef struct {
	int row;
	int col;
}pos_t;
typedef struct CurrentPos{
	int row;			/* 当前所处行 */
	int col;			/* 当前所处列 */
	Door_State door[MAX][MAX];	/* 门状态数组 */
	pos_t door_pos[DOORS_MAX];	/* 门位置信息 */
	int doors_num;			/* 门数量 */
	int turn_doors;			/* trun的门数量 */
}CurrentPos;

static int map_rows = 0;	/* 地图行数 */
static int map_cols = 0;	/* 地图列数 */
static int end_row;		/* 终点所在行数 */
static int end_col;		/* 终点所在列数 */
static int visited[MAX][MAX];
int step = 0;

void init(vector <string> &map, CurrentPos &curpos);
bool isEnd(CurrentPos curpos);
bool isVisited(vector <CurrentPos> LV, CurrentPos curpos);

int main()
{
	RevolvingDoors revolvingdoors;
	
	vector <string> map;
	
	map.push_back(" |  |  |     |  |  |  |  |  | ");
	map.push_back(" O  O EO -O- O  O  O  O  OS O ");
	map.push_back(" |  |  |     |  |  |  |  |  | ");

	cout << revolvingdoors.turns(map) << endl;
	cout << step << endl;
	return 0;
}

int RevolvingDoors::turns(vector <string> map)
{
	queue <CurrentPos> LC;		/* LC: 内层BFS状态 */
	queue <CurrentPos> LD;		/* LD: 外层BFS，turn 操作之后的状态 */
	vector <CurrentPos> LV;		/* LV：外层BFS访问状态标志，类似visited数组，保存turn操作之后的状态，以避免重复 */
	CurrentPos curpos, nextpos;
	int row, col;

	init(map, curpos);
	LD.push(curpos);

	/* 外层BFS */
	while (!LD.empty()) {
		curpos = LD.front();
		LD.pop();

		/* 初始化visited数组 */
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				visited[i][j] = false;
			}
		}

		LC.push(curpos);

		/* 内层BFS */
		while (!LC.empty()) {
			++step;
			curpos = LC.front();
			LC.pop();
			row = curpos.row;
			col = curpos.col;
			visited[row][col] = true;

			if (isEnd(curpos)) {
				return curpos.turn_doors;
			}

			/* 可以向上下左右四个方向推进状态 */

			/* 向上走 */
			nextpos = curpos;
			if (row - 1 >= 0 && !visited[row-1][col]) {
				nextpos.row = row - 1;

				if (' ' == map[row-1][col]) {
					LC.push(nextpos);
				} else if ('*' == map[row-1][col]) {	/* 进入门的四周区域 */
					/* 门的位置有三种情况 */
					if (row - 2 >= 0 && 'O' == map[row-2][col] && H == curpos.door[row-2][col] ) {
						LC.push(nextpos);
					} else if (col + 1 <= map_cols - 1 && 
						'O' == map[row-1][col+1]) {
						if (V == curpos.door[row-1][col+1]) {
							LC.push(nextpos);
						} else {	/* turn door */
							nextpos.door[row-1][col+1] = V;
							++nextpos.turn_doors;
							visited[row-1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					} else if (col - 1 >= 0 && 'O' == map[row-1][col-1]) {
						if (V == curpos.door[row-1][col-1]) {
							LC.push(nextpos);
						} else {
							nextpos.door[row-1][col-1] = V;
							++nextpos.turn_doors;
							visited[row-1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					}
				}
			}

			/* 向下走 */
			nextpos = curpos;
			if (row + 1 <= map_rows - 1 && !visited[row+1][col]) {
				nextpos.row = row + 1;
				if (' ' == map[row+1][col]) {
					LC.push(nextpos);
				} else if ('*' == map[row+1][col]) {
					if (row + 2 <= map_rows - 1 && 'O' == map[row+2][col] &&
						H == curpos.door[row+2][col] ) {
						LC.push(nextpos);
					} else if (col + 1 <= map_cols - 1 && 'O' == map[row+1][col+1]) {
						if (V == curpos.door[row+1][col+1]) {
							LC.push(nextpos);
						} else {	/* turn door */
							nextpos.door[row+1][col+1] = V;
							++nextpos.turn_doors;
							visited[row+1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					} else if (col - 1 >= 0 &&
						'O' == map[row+1][col-1]) {
						if (V == curpos.door[row+1][col-1]) {
							LC.push(nextpos);
						} else {
							nextpos.door[row+1][col-1] = V;
							++nextpos.turn_doors;
							visited[row+1][col] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					}
				}
			}

			/* 向左走 */
			nextpos = curpos;
			if (col - 1 >= 0 && !visited[row][col-1]) {
				nextpos.col = col - 1;
				if (' ' == map[row][col-1]) {
					LC.push(nextpos);
				} else if ('*' == map[row][col-1]) {
					if (col - 2 >= 0 && 'O' == map[row][col-2] &&
						V == curpos.door[row][col-2] ) {
						LC.push(nextpos);
					} else if (row - 1 >= 0 && 
						'O' == map[row-1][col-1]) {
						if (H == curpos.door[row-1][col-1]) {
							LC.push(nextpos);
						} else {	/* turn door */
							nextpos.door[row-1][col-1] = H;
							++nextpos.turn_doors;
							visited[row][col-1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					} else if (row + 1 <= map_rows - 1 && 'O' == map[row+1][col-1]) {
						if (H == curpos.door[row+1][col-1]) {
							LC.push(nextpos);
						} else {
							nextpos.door[row+1][col-1] = H;
							++nextpos.turn_doors;
							visited[row][col-1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					}
				}
			}

			/* 向右走 */
			nextpos = curpos;
			if (col + 1 <= map_cols - 1 && !visited[row][col+1]) {
				nextpos.col = col + 1;
				if (' ' == map[row][col+1]) {
					LC.push(nextpos);
				} else if ('*' == map[row][col+1]) {
					if (col + 2 <= map_cols - 1 && 'O' == map[row][col+2] &&
						V == curpos.door[row][col+2] ) {
							LC.push(nextpos);
					} else if (row + 1 <= map_rows - 1 && 
						'O' == map[row+1][col+1]) {
						if (H == curpos.door[row+1][col+1]) {
							LC.push(nextpos);
						} else {	/* turn door */
							nextpos.door[row+1][col+1] = H;
							++nextpos.turn_doors;
							visited[row][col+1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					} else if (row - 1 >= 0 &&
						'O' == map[row-1][col+1]) {
						if (H == curpos.door[row-1][col+1]) {
							LC.push(nextpos);
						} else {
							nextpos.door[row-1][col+1] = H;
							++nextpos.turn_doors;
							visited[row][col+1] = true;
							if (!isVisited(LV, nextpos)){
								LV.push_back(nextpos);
								LD.push(nextpos);
							}
						}
					}
				}
			}
		}
	}
	return -1;
}

/**
 * 初始操作，获得地图的基本信息，行，列，门状态。并将门四周的4个点置为 '*' 字符，将 S， E 置为' '(空格)。
 */
void init(vector <string> &map, CurrentPos &curpos)
{
	int i, j;
	
	curpos.turn_doors = 0;

	map_rows = map.size();

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
	curpos.doors_num = 0;
	for (i = 0; i < map_rows; i ++) {
		for (j = 0; j < map_cols; j++) {
			if ('O' == map[i][j]) {
				curpos.door_pos[curpos.doors_num].row = i;
				curpos.door_pos[curpos.doors_num].col = j;
				++curpos.doors_num;
				if ('|' == map[i+1][j]) {
					curpos.door[i][j] = V;
				} else {
					curpos.door[i][j] = H;
				}
				map[i+1][j] = map[i-1][j] =
					map [i][j+1] = map[i][j-1] = '*';
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

/**
 * 外层BFS访问标志，若LV中含有curpos状态，返回true，否则返回false
 */
bool isVisited(vector <CurrentPos> LV, CurrentPos curpos)
{

	int door_row, door_col;
	bool flag;
	if (LV.empty()) {
		return false;
	}
	for (int i = 0; i < LV.size(); i++) {
		if (LV[i].row == curpos.row && LV[i].col == curpos.col) {
			flag = true;
			for (int j = 0; j < curpos.doors_num; j++) {
				door_row = curpos.door_pos[j].row;
				door_col = curpos.door_pos[j].col;
				if (LV[i].door[door_row][door_col] != curpos.door[door_row][door_col]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
	}
	return false;
}