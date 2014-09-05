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
vector<vector<int>> g;

class AlwaysDefined {
public:
	inline long long items(long long rem, long long upper, int W)
	{
		// rem + (cnt - 1) * W < upper
		long long numbers = upper - rem;
		return (numbers + W - 1) / W;
	}
	long long solve(int W, int rem, long long cnt)
	{
		if (cnt <= 0) {
			return 0;
		}
		if (1 == rem) {
			return cnt;
		}
		long long ans = 0;
		for (int i = 0; i < g[rem].size(); i++) {
			int x = g[rem][i];
			long long smallest = rem + x * W;
			long long newrem = smallest / rem;
			ans += solve(W, newrem, items(x, cnt, rem));	// rem 为一个周期
		}
		return ans;
	}

	long long countIntegers(long long L, long long R, int W) {
		long long res = 0;
		g.resize(W);
		for (int i = 0; i < g.size(); i++) {
			g[i].clear();
		}
		for (int rem = 1; rem < W; rem++) {
			for (int x = 0; x < rem; x++) {
				if ( (x * W) % rem == 0 ) {
					g[rem].push_back(x);
				}
			}
		}
		for (int rem = 1; rem < W; rem++) {
			res += solve(W, rem, items(rem, R + 1, W));
			res -= solve(W, rem, items(rem, L, W));
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		AlwaysDefined theObject;
		eq(0, theObject.countIntegers(10L, 10L, 4),1LL);
	}
	{
		AlwaysDefined theObject;
		eq(1, theObject.countIntegers(1L, 99L, 2),50LL);
	}
	{
		AlwaysDefined theObject;
		eq(2, theObject.countIntegers(1282L, 1410L, 10),42LL);
	}
	{
		AlwaysDefined theObject;
		eq(3, theObject.countIntegers(29195807L, 273209804877L, 42),31415926535LL);
	}
}
// END CUT HERE
