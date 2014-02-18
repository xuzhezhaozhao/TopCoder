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

long long h[61];

class TrafficCongestionDivTwo {
public:
    long long theMinCars(int treeHeight) {
	for (int i = 0; i < 61; i++) {
		h[i] = 0;
	}

	h[0] = 1;
	h[1] = 1;

	for (int i = 2; i <= 60; i++) {
		h[i] = h[i - 1] + 2 * h[i - 2];
	}

	return h[treeHeight];
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	TrafficCongestionDivTwo theObject;
	eq(0, theObject.theMinCars(1),1LL);
    }
    {
	TrafficCongestionDivTwo theObject;
	eq(1, theObject.theMinCars(2),3LL);
    }
    {
	TrafficCongestionDivTwo theObject;
	eq(2, theObject.theMinCars(3),5LL);
    }
    {
	TrafficCongestionDivTwo theObject;
	eq(3, theObject.theMinCars(10),683LL);
    }
    {
	TrafficCongestionDivTwo theObject;
	eq(4, theObject.theMinCars(60),768614336404564651LL);
    }
}
// END CUT HERE
