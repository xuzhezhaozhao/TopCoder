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

class InsertZ {
public:
    string canTransform(string init, string goal) {
	string res = "";
	for (int i = 0; i < goal.size(); i++) {
		if (goal[i] != 'z') {
			res += goal[i];
		}
	}
	if (init == res) {
		return "Yes";
	}

	return "No";
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	InsertZ theObject;
	eq(0, theObject.canTransform("fox", "fozx"),"Yes");
    }
    {
	InsertZ theObject;
	eq(1, theObject.canTransform("fox", "zfzoxzz"),"Yes");
    }
    {
	InsertZ theObject;
	eq(2, theObject.canTransform("foon", "foon"),"Yes");
    }
    {
	InsertZ theObject;
	eq(3, theObject.canTransform("topcoder", "zopzoder"),"No");
    }
    {
	InsertZ theObject;
	eq(4, theObject.canTransform("aaaaaaaaaa", "a"),"No");
    }
    {
	InsertZ theObject;
	eq(5, theObject.canTransform("mvixrdnrpxowkasufnvxaq", "mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq"),"Yes");
    }
    {
	InsertZ theObject;
	eq(6, theObject.canTransform("opdlfmvuicjsierjowdvnx", "zzopzdlfmvzuicjzzsizzeijzowvznxzz"),"No");
    }
}
// END CUT HERE
