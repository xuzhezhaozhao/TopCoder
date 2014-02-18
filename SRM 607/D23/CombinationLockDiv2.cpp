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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)

/*************** Program Begin **********************/

static const int INF = 1000000000;
static const int MAX_N = 50;
static const int MAX_OP = 450;
int dp[MAX_N + 1][MAX_OP + 1][2];

class CombinationLockDiv2 {
public:
	int N;
	vector<int> d;

	int rec(int p, int x, int up )
	{
		int & res = dp[p][x][up];
		if (p == N) {		// base case
			res = 0;
			return res;
		}
		if (res != -1) {
			return res;
		}
		res = INF;
		for (int i = 0; i <= 1; i++) {
			for (int y = 0; y <= MAX_OP; y++) {
				if (0 == i) {	// down
					if (d[p] - y % 10 != 0) {
						// invalid
						continue;
					}
				} else {	// up
					if ( (d[p] + y) % 10 != 0 ) {
						// invalid
						continue;
					}
				}

				if (i == up) {	// not necessary open new intervals
					res = min(res, max(y - x, 0) + rec(p + 1, y, i) );
				} else {	// must open y new intervals
					res = min(res, y + rec(p + 1, y, i) );
				}
			}
		}
		return res;
	}

	int minimumMoves(string s, string t)
	{
		this->N = s.size();
		d.resize(this->N);
		for (int i = 0; i < this->N; i++) {
			if (s[i] >= t[i]) {
				d[i] = s[i] - t[i];
			} else {
				d[i] = s[i] + 10 - t[i];
			}
		}
		memset(dp, -1, sizeof(dp));
		return rec(0,0,0);
	}
};


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		CombinationLockDiv2 theObject;
		eq(0, theObject.minimumMoves("123", "112"),1);
	}
	{
		CombinationLockDiv2 theObject;
		eq(1, theObject.minimumMoves("1", "7"),4);
	}
	{
		CombinationLockDiv2 theObject;
		eq(2, theObject.minimumMoves("607", "607"),0);
	}
	{
		CombinationLockDiv2 theObject;
		eq(3, theObject.minimumMoves("1234", "4567"),3);
	}
	{
		CombinationLockDiv2 theObject;
		eq(4, theObject.minimumMoves("020", "909"),2);
	}
	{
		CombinationLockDiv2 theObject;
		eq(5, theObject.minimumMoves("4423232218340", "6290421476245"),18);
	}
}
// END CUT HERE
