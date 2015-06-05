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

class DivisorsPower {
public:
	long long longPow(long long x, int p)
	{
		long long m = 1;
		for (int i = 0; i < p; i++) {
			m *= x;
		}
		return m;
	}
	int divisors(long long x)
	{
		int ans = 0;
		for (long long i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				++ans;
				if (i * i != x) {
					++ans;
				}
			}
		}
		return ans;
	}

	long long findArgument(long long n) {
		long long res = -1;
		for (int p = 63; p >= 2; p--) {
			long long x = pow(n + 0.5, 1.0 / p);
			bool ok = false;
			if (longPow(x, p) == n) {
				ok = true;
			} else if (longPow(x + 1, p) == n) {
				++x;
				ok = true;
			} else if (longPow(x - 1, p) == n) {
				--x;
				ok = true;
			}
			if (ok) {
				if (divisors(x) == p) {
					res = x;
					break;
				}
			}
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		DivisorsPower theObject;
		eq(0, theObject.findArgument(1000000000000000000L),100LL);
	}
	{
		DivisorsPower theObject;
		eq(1, theObject.findArgument(10L),-1LL);
	}
	{
		DivisorsPower theObject;
		eq(2, theObject.findArgument(64L),4LL);
	}
	{
		DivisorsPower theObject;
		eq(3, theObject.findArgument(10000L),10LL);
	}
	{
		DivisorsPower theObject;
		eq(4, theObject.findArgument(2498388559757689L),49983883LL);
	}
}
// END CUT HERE
