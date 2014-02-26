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
const int MOD = 1e9 + 7;

long long dp[55][55];
long long C[55][55];

class BlackBoxDiv2 {
public:
	int w, h;
	void calc()
	{
		C[0][0] = 1;
		for (int i = 1; i <= 50; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++) {
				C[i][j] = C[i-1][j] + C[i-1][j-1];
				C[i][j] %= MOD;
			}
		}
	}
	long long rec(int x, int y)
	{
		if (0 == x) {		// base case
			if (0 == y) {
				return 1;
			} else {
				return 0;
			}
		}

		long long & res = dp[x][y];
		if (res != -1) {
			return res;
		}

		res = 0;
		for (int s = 0; s <= y; s++) {
			for (int r = 0; r <= h - y; r++) {
				if (s + r < 1) {
					continue;
				}
				long long t = C[y][s] * C[h - y][r] % MOD;
				res += ( t * rec(x - 1, y - s) ) % MOD;
				res %= MOD;
			}
		}
		return res;
	}
	int count(string front, string side) {
		this->w = 0; this->h = 0;
		for (int i = 0; i < front.size(); i++) {
			w += ( front[i] == 'B' ? 1 : 0 );
		}
		for (int i = 0; i < side.size(); i++) {
			h += ( side[i] == 'B' ? 1 : 0 );
		}
		calc();
		memset(dp, -1, sizeof(dp));
		return rec(w, h);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		BlackBoxDiv2 theObject;
		eq(0, theObject.count("BB", "BB"),7);
	}
	{
		BlackBoxDiv2 theObject;
		eq(1, theObject.count("...", "....."),1);
	}
	{
		BlackBoxDiv2 theObject;
		eq(2, theObject.count("...", "BBB"),0);
	}
	{
		BlackBoxDiv2 theObject;
		eq(3, theObject.count("...BB.B....", "B.B.B.B.B"),16081);
	}
	{
		BlackBoxDiv2 theObject;
		eq(4, theObject.count("BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB", ".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB"),771030153);
	}
}
// END CUT HERE
