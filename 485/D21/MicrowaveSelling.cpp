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

class MicrowaveSelling {
public:
	 int mostAttractivePrice(int minPrice, int maxPrice) {
		int res = maxPrice;
		int maxc = 0;
		for (int i = maxPrice; i >= minPrice; i--) {
			int temp = i;
			int count = 0;
			while (temp % 10 == 9) {
			 	++count;
				temp /= 10;
			}
			if (count > maxc) {
				maxc = count;
				res = i;
			}
		}
		return res;
	};
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	MicrowaveSelling theObject;
	eq(0, theObject.mostAttractivePrice(460, 680),599);
    }
    {
	MicrowaveSelling theObject;
	eq(1, theObject.mostAttractivePrice(10, 1000),999);
    }
    {
	MicrowaveSelling theObject;
	eq(2, theObject.mostAttractivePrice(1255, 2999),2999);
    }
    {
	MicrowaveSelling theObject;
	eq(3, theObject.mostAttractivePrice(20, 25),25);
    }
}
// END CUT HERE
