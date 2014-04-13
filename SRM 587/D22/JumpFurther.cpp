#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

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

class JumpFurther {
public:
    int furthest(int N, int badStep) {
	int res = 0;
	int badn = 0;
	for (int i = 1; i <= N; i++) {
		if ( (i+1) * i / 2 == badStep) {
			badn = i;
			break;
		}
	}
	if (0 == badn) {
		res = (N+1) * N / 2;
	} else {
		res = (N+1) * N / 2 - 1;
	}
	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	JumpFurther theObject;
	eq(0, theObject.furthest(2, 2),3);
    }
    {
	JumpFurther theObject;
	eq(1, theObject.furthest(2, 1),2);
    }
    {
	JumpFurther theObject;
	eq(2, theObject.furthest(3, 3),5);
    }
    {
	JumpFurther theObject;
	eq(3, theObject.furthest(1313, 5858),862641);
    }
    {
	JumpFurther theObject;
	eq(4, theObject.furthest(1, 757065),1);
    }
}
// END CUT HERE
