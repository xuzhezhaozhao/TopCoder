#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

typedef pair <int, pair<int, int> > entry;
#define make_entry(radius, row, col) ( make_pair( (radius), make_pair( (row), (col) ) ) )

class LargestCircle
{
public:
	int radius(vector <string> grid);
};

bool checkCircle(int cusRadius, int cus_row, int cus_col, vector<string> & grid);
int LargestCircle::radius(vector<string> grid)
{
	int i, j;
	int rows, cols, cus_row, cus_col;
	priority_queue <entry> PQ;
	int maxRadius, cusRadius;

	rows = grid.size();
	cols = grid[0].size();
	for (i = 0; i < rows - 1; i++) {
		for (j = 0; j < cols - 1; j++) {
			PQ.push(make_pair(min(min(i + 1, j + 1), min(rows - i - 1, cols - j - 1)), 
				make_pair(i, j)));
		}
	}

	maxRadius = 0;

	while ( !PQ.empty() ) {
		cusRadius = PQ.top().first;
		cus_row = PQ.top().second.first;
		cus_col = PQ.top().second.second;
		PQ.pop();

		if ( checkCircle(cusRadius, cus_row, cus_col, grid) ) {
			maxRadius = cusRadius;
			break;
		}
		--cusRadius;
		if (cusRadius > 0) {
			PQ.push(make_entry(cusRadius, cus_row, cus_col));
		}
	}

	return maxRadius;
}

/**
 * 检查该圆是否合法
 */
bool checkCircle(int cusRadius, int cus_row, int cus_col, vector<string> & grid)
{
	int i, j;
	double pre_bias, next_bias;
	int pre_cell, next_cell;
	int next_row, next_col;

	next_bias = 0;
	for (i = 0; i < cusRadius; i++) {
		pre_bias = next_bias;	/* pre_bias值与上一个循环中的 next_bias值相等 */
		next_bias = sqrt( pow( (double)cusRadius, 2 ) - pow( (double)(cusRadius-i - 1), 2 ) );

		pre_cell = (int)pre_bias;
		next_cell = (int)next_bias;
		if ( abs( next_bias - next_cell > 0.00001)) {
			++next_cell;
		}

		for (j = 0; j < next_cell - pre_cell; j++) {
			next_row = cus_row - (cusRadius - i) + 1;
			next_col = cus_col - pre_cell - j;
			if ('#' == grid[next_row][next_col] ||
			    '#' == grid[next_row][2 * cus_col + 1 - next_col] ||	// 右对称点
			    '#' == grid[2 * cus_row + 1 - next_row][next_col] ||	// 下对称点
			    '#' == grid[2 * cus_row + 1 - next_row][2 * cus_col + 1 - next_col]) {	//中心对称
				return false;
			}
		}
	}

	return true;
}


int main()
{
	LargestCircle La;
	vector <string> grid;
	string sgrid[] = {"###"}
		;
	int size = sizeof(sgrid) / sizeof(sgrid[0]);
	for (int i = 0; i < size; i++) {
		grid.push_back(sgrid[i]);
	}

	cout << La.radius(grid) << endl;

	return 0;
}