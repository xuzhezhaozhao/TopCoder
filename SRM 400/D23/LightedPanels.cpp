#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
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
#include <ctime>
#include <climits>


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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

/*************** Program Begin **********************/

int g[10][10];
int g_temp[10][10];
int dr[] = {0, -1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {0, -1,  0,  1, -1, 1, -1, 0, 1};
class LightedPanels {
public:
	int rows, cols;
	inline int getBit(int mask, int p) { return (1 & (mask >> p)); }
	void flip(int i, int j) 
	{
		for (int x = 0; x < 9; x++) {
			int next_i = i + dr[x], next_j = j + dc[x];
			if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols) {
				continue;
			}
			g_temp[next_i][next_j] = 1 - g_temp[next_i][next_j];
		}
	}

	bool isAllOn()
	{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (!g_temp[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	int minTouch(vector <string> board) {
		int res = 65;
		rows = board.size();
		cols = board[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				g[i][j] = (board[i][j] == '*');
			}
		}
		int P = 1 << (rows + cols - 1);
		for (int mask = 0; mask < P; mask++) {
			int cnt = 0;
			memcpy(g_temp, g, sizeof(g));
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (i == 0) {
						if (getBit(mask, j)) {
							flip(0, j);
							++cnt;
						}
					}  else if (j == 0) {
						if (getBit(mask, cols + i - 1)) {
							flip(i, 0);
							++cnt;
						}
					} else {
						if (!g_temp[i - 1][j - 1]) {
							flip(i, j);
							++cnt;
						}
					}
				}
			}
			if (isAllOn()) {
				res = min(res, cnt);
			}
		}
		res = (res == 65 ? -1 : res);
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string boardARRAY[] = {"*****",
			"*...*",
			"*...*",
			"*...*",
			"*****"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		LightedPanels theObject;
		eq(0, theObject.minTouch(board),1);
	}
	{
		string boardARRAY[] = {".*.*.*", "******", "....**", ".*.*.*"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		LightedPanels theObject;
		eq(1, theObject.minTouch(board),10);
	}
	{
		string boardARRAY[] = {"**.",
			"**.",
			"..."};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		LightedPanels theObject;
		eq(2, theObject.minTouch(board),2);
	}
	{
		string boardARRAY[] = {"*...",
			"**..",
			"..**",
			"...*"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		LightedPanels theObject;
		eq(3, theObject.minTouch(board),10);
	}
}
// END CUT HERE
