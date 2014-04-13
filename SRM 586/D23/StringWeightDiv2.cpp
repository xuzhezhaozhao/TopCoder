#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
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

/************** Program  Begin *********************/

static const int MOD = 1000000009;
long long dp[27][1001];
class StringWeightDiv2 {
public:
	// Math
	int countMinimums(int L) {
		long long res = 1;

		if (L <= 26) {
			int t = 26;
			for (int i = L; i > 0; i--) {
				res *= t;
				res %= MOD;
				--t;
			}
		} else {
			// 计算 26! * C(L-1, 25)
			res = 26;
			for (int i = L - 1; i > L - 26; i--) {
				res *= i;
				res %= MOD;
			}
		}

		return static_cast<int>(res);
	}

	// Dynamic Programming
	// a代表可以使用的字符的种类，L表示需要生成的字符串的长度
	long long onceConsecutive(int a, int L)
	{
		long long & res = dp[a][L];
		if (res == -1) {
			if (L == 0) {      // base case，L＝0时，a=0, 1, a>1, 0
				res = (a == 0);
			} else if (a == 1) {
				res = 1;
			} 
			else {
				// calculate the sum. (We need to use modular arithmetic)
				res = 0;
				// 做了一点改动，改为了i <= L-a+1而不是原来的i <= L，保证了a>=L
				for (int i = 1; i <= L-a+1; i++) {
					res += (a * onceConsecutive(a-1, L-i) ) % MOD;
				}
				res %= MOD;
			}
		} 
		return res;
	}

	int countMinimums2(int L)
	{
		memset(dp, -1, sizeof(dp));
		long long res = 1;
		if ( L <= 26 ) {
			// The simple case:
			//26 * 25 * 24 * ...
			for (int i=0; i < L; i++) {
				res = (res * (26 - i)) % MOD;
			}
		} else {
			// each letter must appear at least once, all instances
			// of each letter must be consecutive.
			res = onceConsecutive(26, L); //Use the recurrence relation
		}

		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		StringWeightDiv2 theObject;
		//eq(0, theObject.countMinimums(1),26);
	}
	{
		StringWeightDiv2 theObject;
		//eq(1, theObject.countMinimums(2),650);
	}
	{
		StringWeightDiv2 theObject;
		eq(2, theObject.countMinimums(50),488801539);
	}
}
// END CUT HERE
