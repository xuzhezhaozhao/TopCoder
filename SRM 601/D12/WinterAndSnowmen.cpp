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
const int MAX_BITS = 11;
const int MAX_N = 2000;
int dp[MAX_N + 1][1 << MAX_BITS][2];

class WinterAndSnowmen {
public:
	int p, N, M;
	inline int getBit(int z, int p) { return ( (z >> p) & 1 ); }

	int rec(int t, int z, int b)
	{
		if (0 == t) {
			if ( 0 == b && 1 == z ) {
				return 1;
			} else {
				return 0;
			}
		}
		int & res = dp[t][z][b];
		if (res != -1) {
			return res;
		}
		res = 0;
		if (t <= N) {
			res += rec(t - 1, z ^ (t >> p), b ^ getBit(t, p));
			res %= MOD;
		}
		if (t <= M) {
			res += rec(t - 1, z ^ (t >> p), b);
			res %= MOD;
		}
		res += rec(t - 1, z, b);
		res %= MOD;
		return res;
	}
	int getNumber(int N, int M) {
		this->N = N;
		this->M = M;
		int res = 0;
		for (p = 0; p < 11; p++) {
			memset(dp, -1, sizeof(dp));
			res += rec( max(N, M), 0, 0 );
			res %= MOD;
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		WinterAndSnowmen theObject;
		//eq(0, theObject.getNumber(2, 2),4);
	}
	{
		WinterAndSnowmen theObject;
		//eq(1, theObject.getNumber(1, 1),1);
	}
	{
		WinterAndSnowmen theObject;
		//eq(2, theObject.getNumber(3, 5),74);
	}
	{
		WinterAndSnowmen theObject;
		////eq(3, theObject.getNumber(7, 4),216);
	}
	{
		WinterAndSnowmen theObject;
		eq(4, theObject.getNumber(497, 2000),962557390);
		CHECKTIME();
	}
}
// END CUT HERE
