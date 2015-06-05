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
const int MOD = 1000000007;
const int MAX_N = 50;
const int MAX_K = 10;
int dp[2 * MAX_N + 2][1 << MAX_K];

class AlienAndSetDiv2 {
public:
	int N, K;
	int calc(int n, int unmatched)
	{
		int res = 0;
		if (-1 != dp[n][unmatched]) {
			return dp[n][unmatched];
		}

		if (n == 2 * N + 1) {
			if (0 == unmatched) {	// 匹配成功
				res = 1;
			}
		} else {
			if (0 == unmatched) {
				res += ( 2 * calc(n + 1, 1) ) % MOD;
			} else {
				int newset = unmatched;
				int i = 0;
				for (i = 0; (newset & 0x80000000 ) == 0; newset = ( newset << 1 ), ++i) {
					// 注意位操作的优先级，要加括号
				}
				int mx = 31 - i;	// mx 为unmatched不为0的最高位
				// match with largest:
				res += calc(n + 1,  (unmatched - (1 << mx)) << 1 );	// 注意操作符优先级，要加括号
				res %= MOD;

				if (mx != K - 1) {
					newset = unmatched;
					newset = ( (newset << 1) | 1 );
					res += calc(n + 1, newset);
					res %= MOD;
				}
			}	
		}
		dp[n][unmatched] = res;
		return res;
	}

	int getNumber(int N, int K) {
		this->N = N;
		this->K = K;
		int res = 0;
		memset(dp, -1, sizeof(dp));
		res = calc(1, 0);
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		AlienAndSetDiv2 theObject;
		eq(0, theObject.getNumber(2, 1),4);
	}
	{
		AlienAndSetDiv2 theObject;
		eq(1, theObject.getNumber(3, 1),8);
	}
	{
		AlienAndSetDiv2 theObject;
		eq(2, theObject.getNumber(4, 2),44);
	}
	{
		AlienAndSetDiv2 theObject;
		eq(3, theObject.getNumber(10, 10),184756);
	}
}
// END CUT HERE
