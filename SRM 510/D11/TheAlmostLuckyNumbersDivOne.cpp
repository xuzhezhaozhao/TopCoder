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

class TheAlmostLuckyNumbersDivOne {
public:
	long long res, a, b;
	void backtrack(long long cur, int almost)
	{	
		if (cur <= b) {
			if (cur >= a) {
				++res;
			}
		} else {
			return;
		}
		for (int i = 0; i <= 9; i++) {
			long long next = cur * 10 + i;
			if (0 == next) {
				continue;
			}
			if (almost && !(i != 4 && i != 7) ) {
				backtrack(next, almost);
			} else if (!almost) {
				if (i != 4 && i != 7) {
					backtrack(next, 1);	
				} else {
					backtrack(next, 0);
				}
			}
		}
	}
	long long find(long long a, long long b) {
		res = 0;
		this->a = a;
		this->b = b;
		backtrack(0, 0);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		TheAlmostLuckyNumbersDivOne theObject;
		eq(0, theObject.find(4L, 7L),4LL);
	}
	{
		TheAlmostLuckyNumbersDivOne theObject;
		eq(1, theObject.find(8L, 19L),4LL);
	}
	{
		TheAlmostLuckyNumbersDivOne theObject;
		eq(2, theObject.find(28L, 33L),0LL);
	}
	{
		TheAlmostLuckyNumbersDivOne theObject;
		eq(3, theObject.find(9876543210012345L, 9876543210012345L),0LL);
	}
}
// END CUT HERE
