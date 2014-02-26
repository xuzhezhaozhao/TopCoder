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

class PowerOfThree {
public:
	string ableToGet(int x, int y) {
		x = (x > 0) ? x : -x;
		y = (y > 0) ? y : -y;
		while (x != 0 || y != 0) {
			if (x % 3 == 1 || y % 3 == 1) {
				if (x % 3 == 1) {
					if (y % 3 == 0) {
						x = (x - 1) / 3;
						y = y / 3;
					} else {
						return "Impossible";
					}
				} else {	// y % 3 == 1
					if (x % 3 == 0) {
						y = (y - 1) / 3;
						x = x / 3;
					} else {
						return "Impossible";
					}
				}
			} else if (x % 3 == 2 || y % 3 == 2) {
				if (x % 3 == 2) {
					if (y % 3 == 0) {
						x = (x + 1) / 3;
						y = y / 3;
					} else {
						return "Impossible";
					}
				} else {	// y % 3 == 2
					if (x % 3 == 0) {
						y = (y + 1) / 3;
						x = x / 3;
					} else {
						return "Impossible";
					}
				}
			} else {
				return "Impossible";
			}
		}
		return "Possible";
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		PowerOfThree theObject;
		eq(0, theObject.ableToGet(1, 3),"Possible");
	}
	{
		PowerOfThree theObject;
		eq(1, theObject.ableToGet(1, 1),"Impossible");
	}
	{
		PowerOfThree theObject;
		eq(2, theObject.ableToGet(0, 0),"Possible");
	}
	{
		PowerOfThree theObject;
		eq(3, theObject.ableToGet(1, 9),"Impossible");
	}
	{
		PowerOfThree theObject;
		eq(4, theObject.ableToGet(-6890, 18252),"Possible");
	}
	{
		PowerOfThree theObject;
		eq(5, theObject.ableToGet(1093, 2187),"Possible");
	}
	{
		PowerOfThree theObject;
		eq(6, theObject.ableToGet(1000000000,-1000000000),"Impossible");
	}
}
// END CUT HERE
