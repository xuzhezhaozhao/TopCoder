#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class WalkingHome
{
public:
	int fewestCrossings(string map[]);
};

#define BUFFER_SIZE 100
#define ELEMENT_SIZE 50

typedef struct CurrentPos {
	int row;
	int col;
	int crossings;
};

bool visited[ELEMENT_SIZE][ELEMENT_SIZE];	/* 访问标志数组 */
int map_rows;		/* 地图行数 */
int map_cols;		/* 地图列数 */

void init(string map[], CurrentPos &curpos);

int main()
{
	WalkingHome walkinghome;
	fstream fin;
	string map[ELEMENT_SIZE];
	char buffer[BUFFER_SIZE];
	string str;
	int line;
	
	fin.open("../map.txt", fstream::in);

	line = 0;
	while (!fin.eof()) {
		fin.getline(buffer, 255);
		str = buffer;
		while ("" == str) {
			map[line] = "";
			cout << walkinghome.fewestCrossings(map) << endl;
			fin.getline(buffer, 255);
			str = buffer;
			line = 0;
		}
		map[line] = buffer;
		++line;
	}

	map[line] = "";
	cout << walkinghome.fewestCrossings(map) << endl;

	fin.close();

	return 0;
}

int WalkingHome::fewestCrossings(string map[])
{
	queue <CurrentPos> QC, QS;
	CurrentPos curpos, nextpos;
	int row, col;

	init(map, curpos);

	/* 初始化visited数组 */
	for (int i = 0; i < ELEMENT_SIZE; i++) {
		for (int j = 0; j < ELEMENT_SIZE; j++) {
			visited[i][j] = false;
		}
	}

	QS.push(curpos);

	while (!QS.empty()) {
		curpos = QS.front();
		QS.pop();

		QC.push(curpos);
		while (!QC.empty()) {
			curpos = QC.front();
			QC.pop();

			row = curpos.row;
			col = curpos.col;

			if ('H' == map[row][col]) {
				return curpos.crossings;
			}

			/* 上下左右四个方向 */
			/* 向上走 */
			nextpos = curpos;
			if (row - 1 >= 0 && ('.' == map[row-1][col] || 'H' == map[row-1][col])) {
				if (!visited[row-1][col]) {
					nextpos.row = row - 1;
					visited[row-1][col] = true;
					QC.push(nextpos);
				}
			} else if (row - 1 >= 0 && '-' == map[row-1][col]) {
				int street_adj = 1; 
				while (row-1-street_adj >= 0 && '-' == map[row-1-street_adj][col]) {
					++street_adj;
				}
				if (row - 1 - street_adj >= 0 && ('.' == map[row-1-street_adj][col] || 'H' == map[row-1-street_adj][col])) {
					if (!visited[row-1-street_adj][col]) {
						nextpos.row = row - 1 - street_adj;
						++nextpos.crossings;
						QS.push(nextpos);
					}
				}
			}
			/* 向下走 */
			nextpos = curpos;
			if (row + 1 <= map_rows-1 && ('.' == map[row+1][col] || 'H' == map[row+1][col])) {
				if (!visited[row+1][col]) {
					nextpos.row = row + 1;
					visited[row+1][col] = true;
					QC.push(nextpos);
				}
			} else if (row + 1 <= map_rows-1 && '-' == map[row+1][col]) {
				int street_adj = 1; 
				while (row+1+street_adj <= map_rows-1 && '-' == map[row+1+street_adj][col]) {
					++street_adj;
				}
				if (row + 1 + street_adj <= map_rows-1 && ('.' == map[row+1+street_adj][col] || 'H' == map[row+1+street_adj][col])) {
					if (!visited[row+1+street_adj][col]) {
						nextpos.row = row + 1 + street_adj;
						++nextpos.crossings;
						QS.push(nextpos);
					}
				}
			}
			/* 向左走 */
			nextpos = curpos;
			if (col - 1 >= 0 && ('.' == map[row][col-1] || 'H' == map[row][col-1])) {
				if (!visited[row][col-1]) {
					nextpos.col = col - 1;
					visited[row][col-1] = true;
					QC.push(nextpos);
				}
			} else if (col - 1 >= 0 && '|' == map[row][col-1]) {
				int street_adj = 1; 
				while (col-1-street_adj >= 0 && '|' == map[row][col-1-street_adj]) {
					++street_adj;
				}
				if (col - 1 - street_adj >= 0 && ('.' == map[row][col-1-street_adj] || 'H' == map[row][col-1-street_adj])) {
					if (!visited[row][col-1-street_adj]) {
						nextpos.col = col - 1 - street_adj;
						++nextpos.crossings;
						QS.push(nextpos);
					}
				}
			}
			/* 向右走 */
			nextpos = curpos;
			if (col + 1 <= map_cols-1 && ('.' == map[row][col+1] || 'H' == map[row][col+1])) {
				if (!visited[row][col+1]) {
					nextpos.col = col + 1;
					visited[row][col+1] = true;
					QC.push(nextpos);
				}
			} else if (col + 1 <= map_cols-1 && '|' == map[row][col+1]) {
				int street_adj = 1; 
				while (col+1+street_adj <= map_cols-1 && '|' == map[row][col+1+street_adj]) {
					++street_adj;
				}
				if (col + 1 + street_adj <= map_cols-1 && ('.' == map[row][col+1+street_adj] || 'H' == map[row][col+1+street_adj])) {
					if (!visited[row][col+1+street_adj]) {
						nextpos.col = col + 1 + street_adj;
						++nextpos.crossings;
						QS.push(nextpos);
					}
				}
			}
		}
	}

	return -1;
}

/**
 * 初始化操作，得到地图的基本信息
 */
void init(string map[], CurrentPos &curpos)
{
	map_rows = 0;
	map_cols = 0;
	while ("" != map[map_rows]) {
		++map_rows;
	}
	map_cols = map[0].length();
	curpos.crossings = 0;
	for (int i = 0; i < map_rows; i++) {
		for (int j = 0; j < map_cols; j++) {
			if ('S' == map[i][j]) {
				curpos.row = i;
				curpos.col = j;
			}
		}
	}
}