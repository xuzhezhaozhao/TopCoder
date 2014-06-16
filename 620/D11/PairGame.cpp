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

class PairGame {
public:
	void change(int & a, int & b)
	{
		if (a > b) {
			a -= b;
		} else {
			b -= a;
		}
	}
	int maxSum(int a, int b, int c, int d) {
		int res = 0;
		if (a == c && b == d) {
			return a + b;
		}

		while ( !(a == c && b == d) && (a > 0 && b > 0 && c > 0 && d > 0) ) {
			if (a > c && b > d) {
				change(a, b);
			} else if (a < c && b < d) {
				change(c, d);
			} else if (a != c && b != d ) {
				change(a, b);
				change(c, d);
			} else if (a == c) {
				if (b > d) {
					change(a, b);
				} else {
					change(c, d);
				}
			} else if (b == d) {
				if (a > c) {
					change(a, b);
				} else {
					change(c, d);
				}
			}
		}

		if (a == c && b == d && (a != 0 && b != 0)) {
			res = a + b;
		} else {
			res = -1;
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		PairGame theObject;
		eq(0, theObject.maxSum(1, 2, 2, 1),2);
	}
	{
		PairGame theObject;
		eq(1, theObject.maxSum(15, 4, 10, 7),7);
	}
	{
		PairGame theObject;
		eq(2, theObject.maxSum(1, 1, 10, 10),-1);
	}
	{
		PairGame theObject;
		eq(3, theObject.maxSum(1000, 1001, 2000, 2001),1001);
	}
	{
		PairGame theObject;
		eq(4, theObject.maxSum(10944, 17928, 7704, 21888),144);
	}
	{
		PairGame theObject;
		eq(5, theObject.maxSum(1, 1, 1, 1),2);
	}
}
// END CUT HERE
