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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

class TaroJiroGrid {
public:
	bool solve(const vector <string> grid) {
		int res = 0;
		int N = grid.size();
		
		for (int c = 0; c < N; c++) {
			int wh = 0, bl = 0;
			for (int r = 0; r < N; r++) {
				if (grid[r][c] == 'W') {
					++wh;
					res = max(res, bl);
					bl = 0;
				} else {
					++bl;
					res = max(res, wh);
					wh = 0;
				}
			}
			res = max(res, bl);
			res = max(res, wh);
		}

		if (res > ( N / 2 )) {
			return true;
		} else {
			return false;
		}
	}
	
	int getNumber(vector <string> grid) {
		int res = 0;
		int N = grid.size();

		if ( !solve(grid) ) {
			return 0;
		}

		vector <string> temp;
		for (int i = 0; i < N; i++) {
			temp = grid;
			for (int j = 0; j < N; j++) {
				temp[i][j] = 'W';
			}
			if ( !solve(temp) ) {
				return 1;
			}
			temp = grid;
			for (int j = 0; j < N; j++) {
				temp[i][j] = 'B';
			}
			if ( !solve(temp) ) {
				return 1;
			}
		}

		temp = grid;
		for (int i = 0; i < N; i++) {
			temp[N / 2 - 1][i] = 'W';
			temp[N / 2][i] = 'B';
		}

		if ( !solve(temp) ) {
			return 2;
		}
		
		temp = grid;
		for (int i = 0; i < N; i++) {
			temp[N / 2 - 1][i] = 'B';
			temp[N / 2][i] = 'W';
		}

		if ( !solve(temp) ) {
			return 2;
		}

		return res;
	}

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
	{
		
		string gridARRAY[] = {"WB",
			"BB"};
		vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
		TaroJiroGrid theObject;
		eq(0, theObject.getNumber(grid),1);
	}
	{
		string gridARRAY[] = {"WB",
			"WW"};
		vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
		TaroJiroGrid theObject;
		eq(1, theObject.getNumber(grid),1);
	}
	{
		string gridARRAY[] = {"WB",
			"WB"};
		vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
		TaroJiroGrid theObject;
		eq(2, theObject.getNumber(grid),2);
	}
	{
		string gridARRAY[] = {"WBBW",
			"WBWB",
			"WWBB",
			"BWWW"};
		vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
		TaroJiroGrid theObject;
		eq(3, theObject.getNumber(grid),2);
	}
	{
		string gridARRAY[] = {"WBBWBB",
			"BBWBBW",
			"WWBWBW",
			"BWWBBB",
			"WBWBBW",
			"WWWBWB"};
		vector <string> grid( gridARRAY, gridARRAY+ARRSIZE(gridARRAY) );
		TaroJiroGrid theObject;
		eq(4, theObject.getNumber(grid),1);
	}
	return 0;
}
// END CUT HERE
