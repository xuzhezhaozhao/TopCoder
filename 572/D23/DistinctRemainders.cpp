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
long long dp[51][51][2501];
class DistinctRemainders {
public:
	long long N;
	int M;
	int rec(int cur, int K, int q)
	{
		long long & res = dp[cur][K][q];
		if (res != -1) {
			return res;
		}
		if (M == cur) {		// base cases
			if (q % M == N % M) {
				long long Q = (N - q) / M;
				res = K;
				// C(Q + K - 1, K - 1) * K!
				for (int i = 0; i < K - 1; i++) {
					res *= ( (Q + K - 1 - i) % MOD );
					res %= MOD;
				}
				return res;
			} else {
				res = 0;
				return res;
			}
		}
		res = 0;
		// add
		res += rec(cur + 1, K + 1, q + cur);
		res %= MOD;
		// ignore
		res += rec(cur + 1, K, q);
		res %= MOD;
		return (int)res;
	}
	int howMany(long long N, int M) {
		int res = 0;
		this->N = N;
		this->M = M;
		memset(dp, -1, sizeof(dp));
		res = rec(0, 0, 0);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		DistinctRemainders theObject;
		eq(0, theObject.howMany(3L, 2),5);
	}
	{
		DistinctRemainders theObject;
		eq(1, theObject.howMany(3L, 3),9);
	}
	{
		DistinctRemainders theObject;
		eq(2, theObject.howMany(58L, 1),1);
	}
	{
		DistinctRemainders theObject;
		eq(3, theObject.howMany(572L, 7),922572833);
	}
	{
		DistinctRemainders theObject;
		eq(4, theObject.howMany(1000000000000000000LL, 20),240297629);
	}
}
// END CUT HERE
