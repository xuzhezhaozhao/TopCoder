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

class PairGameEasy {
public:
    string able(int a, int b, int c, int d) {
	while ( !( (c < a || d < b) || (a == c && b == d) ) ) {
		if (c > d) {
			c -= d;
		} else {
			d -= c;
		}
	}
	if (a == c && b == d) {
		return "Able to generate";
	} else {
		return "Not able to generate";
	}
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        PairGameEasy theObject;
        eq(0, theObject.able(3, 3, 4, 4),"Not able to generate");
    }
    {
        PairGameEasy theObject;
        eq(1, theObject.able(1, 2, 2, 1),"Not able to generate");
    }
    {
        PairGameEasy theObject;
        eq(2, theObject.able(2, 2, 2, 999),"Not able to generate");
    }
    {
        PairGameEasy theObject;
        eq(3, theObject.able(2, 2, 2, 1000),"Able to generate");
    }
    {
        PairGameEasy theObject;
        eq(4, theObject.able(47, 58, 384, 221),"Able to generate");
    }
    {
        PairGameEasy theObject;
        eq(5, theObject.able(1000, 1000, 1000, 1000),"Able to generate");
    }
}
// END CUT HERE
