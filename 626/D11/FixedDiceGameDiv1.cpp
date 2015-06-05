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
const int MAX_SCORE = 50 * 50;
class FixedDiceGameDiv1 {
public:
	double dp1[MAX_SCORE + 1], dp2[MAX_SCORE + 1];

	// dp[i]: roll a b-sieded dice 最后总得分为i的概率
	void calc(int a, int b, double dp[])
	{
		for (int i = 0; i < MAX_SCORE + 1; i++) {
			dp[i] = 0.0;
		}
		dp[0] = 1.0;
		for (int i = 0; i < a; i++) {
			for (int j = a * b; j >= 0; j--) {
				if (dp[j] == 0) {
					continue;
				}
				for (int k = 1; k <= b; k++) {
					dp[j + k] += dp[j] / b;
				}
				dp[j] = 0;
			}
		}
	}
	double getExpectation(int a, int b, int c, int d) {
		double res = 0.0;

		calc(a, b, dp1);
		calc(c, d, dp2);

		// 贝叶斯公式
		double up = 0, down = 0;
		for (int i = a; i <= a * b; i++) {
			for (int j = 0; j < i; j++) {
				up += dp1[i] * dp2[j] * i;
				down += dp1[i] * dp2[j];
			}
		}

		if (down == 0) {
			return -1;
		}
		res = up / down;

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		FixedDiceGameDiv1 theObject;
		eq(0, theObject.getExpectation(1, 2, 1, 5),2.0);
	}
	{
		FixedDiceGameDiv1 theObject;
		eq(1, theObject.getExpectation(3, 1, 1, 3),3.0);
	}
	{
		FixedDiceGameDiv1 theObject;
		eq(2, theObject.getExpectation(1, 5, 1, 1),3.4999999999999996);
	}
	{
		FixedDiceGameDiv1 theObject;
		eq(3, theObject.getExpectation(2, 6, 50, 30),-1.0);
	}
	{
		FixedDiceGameDiv1 theObject;
		eq(4, theObject.getExpectation(50, 11, 50, 50),369.8865999182022);
	}
}
// END CUT HERE
