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

const int mod = 1000000009;
int dp[1001];
class StringWeightDiv2 {
public:
    int countMinimums(int L) {
	long long res = 1;
	if (L <= 26) {
		int t = 26;
		for (int i = L; i > 0; i--) {
			res *= t;
			res %= mod;
			--t;
		}
	} else {
		res = 26;
		for (int i = L - 1; i > L - 26; i--) {
			res *= i;
			res %= mod;
		}
	}

	return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	StringWeightDiv2 theObject;
	eq(0, theObject.countMinimums(1),26);
    }
    {
	StringWeightDiv2 theObject;
	eq(1, theObject.countMinimums(2),650);
    }
    {
	StringWeightDiv2 theObject;
	eq(2, theObject.countMinimums(50),488801539);
    }
}
// END CUT HERE
