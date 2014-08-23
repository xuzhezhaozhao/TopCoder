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
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
class BishopMove {
public:
    int howManyMoves(int r1, int c1, int r2, int c2) {
	if (r1 == r2 && c1 == c2) {
		return 0;
	}
	if (abs(r1 - r2) == abs(c1 - c2)) {
		return 1;
	}

	for (int k = 1; k <= 7; k++) {
		for (int i = 0; i < 4; i++) {
			int tr = r1 + dx[i] * k;
			int tc = c1 + dy[i] * k;
			if (tr >= 0 && tr <= 7 && tc >= 0 && tc <= 7) {
				if (abs(tr - r2) == abs(tc - c2)) {
					return 2;
				}
			}
		}
	}

        return -1;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        BishopMove theObject;
        eq(0, theObject.howManyMoves(4, 6, 7, 3),1);
    }
    {
        BishopMove theObject;
        eq(1, theObject.howManyMoves(2, 5, 2, 5),0);
    }
    {
        BishopMove theObject;
        eq(2, theObject.howManyMoves(1, 3, 5, 5),2);
    }
    {
        BishopMove theObject;
        eq(3, theObject.howManyMoves(4, 6, 7, 4),-1);
    }
}
// END CUT HERE
