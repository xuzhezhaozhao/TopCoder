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
long long dp[3501][3501];

class PatternLock {
public:
	int N, MOD;
	long long rec(int m, int n)
	{
		// base case
		if (1 == m && 0 == n) {
			return 1;
		}
		if (0 == m) {
			return 0;
		}

		long long & res = dp[m][n];
		if (res != -1) {
			return res;
		}
		res = 0;
		res = m * rec(n, m - 1) + 2 * rec(m - 1, n);
		res %= MOD;

		return res;
	}

	int solve(int N, int MOD) {
		this->N = N;
		this->MOD = MOD;
		memset(dp, -1, sizeof(dp));
		long long res = 2 * rec(N, N);
		res %= MOD;
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
		PatternLock theObject;
		eq(0, theObject.solve(1, 12345667),2);
	}
	{
		PatternLock theObject;
		eq(1, theObject.solve(2, 324124124),24);
	}
	{
		PatternLock theObject;
		eq(2, theObject.solve(3, 5325352),504);
	}
	{
		PatternLock theObject;
		eq(3, theObject.solve(500, 1000000007),286169049);
	}
	return 0;
}
// END CUT HERE
