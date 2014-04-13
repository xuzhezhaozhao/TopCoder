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

class LongLongTripDiv2 {
public:
    string isAble(long long D, int _T, int _B) {
	    long long T = _T, B = _B;
	    long long R = D % B;

	    T = T - R;
	    D = D - R;
	    long long K = D / B;
	    if (K > T || D < T) {
		return "Impossible";
	    }
	    if (B == 1) {
		if (D == T) {
			return "Possible";
		} else {
			return "Impossible";
		}
	    }
	    if ((D - T) % (B - 1) == 0) {
		return "Possible";
	    }

	    return "Impossible";
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        LongLongTripDiv2 theObject;
        eq(0, theObject.isAble(12L, 8, 3),"Possible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(1, theObject.isAble(10L, 5, 3),"Impossible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(2, theObject.isAble(50L, 100, 2),"Impossible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(3, theObject.isAble(120L, 10, 11),"Impossible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(4, theObject.isAble(10L, 10, 9999),"Possible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(5, theObject.isAble(1000L, 100, 10),"Possible");
    }
    {
        LongLongTripDiv2 theObject;
        eq(6, theObject.isAble(1000010000100001L, 1100011, 1000000000),"Possible");
    }
}
// END CUT HERE
