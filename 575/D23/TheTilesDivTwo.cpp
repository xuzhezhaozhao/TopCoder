#include <algorithm>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>

using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) {
	cerr << a;
}
static void print( long long a ) {
	cerr << a << "L";
}
static void print( string a ) {
	cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
	if( have.size() != need.size() ) {
		cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
		print( have );
		print( need );
		return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have );
			print( need );
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
// END CUT HERE

/*************** Program Begin **********************/
string tile[][2] = {
	{".X",
	"XB"},
	{"X.",
	"BX"},
	{"BX",
	"X."},
	{"XB",
	".X"}
};

class TheTilesDivTwo {
public:

	int f[47 + 10][(1 << 4) + 10];
	int board[4 + 10][47 + 10];
	int cell[4 + 10][47 + 10];
	int row, column;

	int check (char t, int r, int c) {	
		if (t == '.') return 1;

		if (cell[r][c] + board[r][c] != 0) return 0;
		if (t == 'B') return (((c + r) % 2) == 0);

		return 1;
	}

	void try_(int c, int s, int r, int cnt) {
		//we are at cell(r, c)
		//number of new tiles is cnt

		if (r == row - 1) {
			//if r ==row - 1, we cannot pushed any tile more
			//we update f[c + 1][ns];
			//ns is called by the value of cell[][c + 1];
			int ns = 0;
			for (int i = 0; i < row; i++)
				ns |= cell[i][c + 1] << i;
			f[c + 1][ns] = max(f[c + 1][ns], f[c][s] + cnt);
			return;
		}

		//if we don't place tile at this position
		try_(c, s, r + 1, cnt);

		for (int t = 0; t < 4; t++) {
			//check wether we can place tile[t] here
			int ok = 1;
			for (int i = 0; i < 2; i++)
				for (int  j = 0; j < 2; j++)
					if (!check(tile[t][i][j], r + i, c + j)) ok = 0;

			if (ok == 0) continue;

			//place tile[t];
			for (int i = 0; i < 2; i++)
				for (int  j = 0; j < 2; j++)
					if (tile[t][i][j] != '.') cell[r + i][c + j] = 1;

			try_(c, s, r + 1, cnt + 1);

			//recover the cell value to the time before the tile is placed
			for (int i = 0; i < 2; i++)
				for (int  j = 0; j < 2; j++)
					if (tile[t][i][j] != '.') cell[r + i][c + j] = 0;
		}
	}

	void update(int c, int s) {
		//we are at the column c
		//the state of cells in this column is stored in s

		//used cell[][] to manage the states of cells in column c and c + 1
		//cell[i][j] = 0 means cell (i, j) is free
		memset (cell, 0, sizeof(cell));
		for (int i = 0; i < row; i++)
			cell[i][c] = ( (s & (1 << i)) > 0 ); 

		//try all the ways of tiling to update f[c + 1][]
		//store the value s in State
		try_(c, s, 0, 0);
	}

	int find(vector <string> board_) {
		row = board_.size();
		column = board_[0].size();

		//board[i][j] = 0 mean it is free cell
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				board[i][j] = (board_[i][j] == 'X');

		memset(f, -1, sizeof(f));
		f[0][0] = 0;
		for (int i = 0; i + 1 < column; i++) {
			for (int j = 0; j <= (1 << row) - 1; j++) {
				if (f[i][j] != -1) {
					//if f[i][j] is calculated, we use it to update for f[i + 1][]
					update(i, j);
				}
			}
		}

		int res = 0;
		//result is the maximum f[comlumn][i]
		for (int i = 0; i <= (1 << row) - 1; i++)
			res = max(res, f[column - 1][i]);

		return res;
	}
};
/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string boardARRAY[] = {"X.X",
			"...",
			"X.X"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		TheTilesDivTwo theObject;
		eq(0, theObject.find(board),1);
	}
	{
		string boardARRAY[] = {"...",
			"...",
			"..."};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		TheTilesDivTwo theObject;
		eq(1, theObject.find(board),2);
	}
	{
		string boardARRAY[] = {"......X.X.XXX.X.XX."};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		TheTilesDivTwo theObject;
		eq(2, theObject.find(board),0);
	}
	{
		string boardARRAY[] = {
			"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
			".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
			"....XX....X.XX..X.X...XX.X..XXXXXXX..X",
			"XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."
		};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		TheTilesDivTwo theObject;
		eq(3, theObject.find(board),13);
	}
}
// END CUT HERE
