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
const int MAX_N = 500;
double dp[MAX_N + 1][MAX_N / 2 + 1][MAX_N / 2 + 1];
class RedPaint {
public:
	int N;
	double rec(int k, int L, int R)
	{
		// 当前位置左边有L个cells已经painted, 右边R个，还可以走k步
		// 返回此种情况下还可以paint多少个新的cells

		if (k == 0) {
			return 0;
		}
		double & res = dp[k][L][R];
		if (res > -0.5) {
			return res;
		}
		res = 0;
		res += 1.0 / 2 * rec(k - 1, max(0, L - 1), min(MAX_N / 2, R + 1))
		     + 1.0 / 2 * rec(k - 1, min(MAX_N / 2, L + 1), max(0, R - 1));
		if (0 == L) {
			res += 0.5;
		}
		if (0 == R) {
			res += 0.5;
		}
		return res;
	}
	double expectedCells(int N) {
		this->N = N;
		for (int i = 0; i < MAX_N + 1; i++) {
			for (int j = 0; j < MAX_N / 2 + 1; j++) {
				for (int k = 0; k < MAX_N / 2 + 1; k++) {
					dp[i][j][k] = -1;
				}
			}
		}

		return 1 + rec(N, 0, 0);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		RedPaint theObject;
		eq(0, theObject.expectedCells(500),1.0);
	}
	{
		RedPaint theObject;
		eq(1, theObject.expectedCells(1),2.0);
	}
	{
		RedPaint theObject;
		eq(2, theObject.expectedCells(2),2.5);
	}
	{
		RedPaint theObject;
		eq(3, theObject.expectedCells(4),3.375);
	}
}
// END CUT HERE
