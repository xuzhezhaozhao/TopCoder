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

/*************** Program Begin **********************/

class PackingBallsDiv2 {
public:
    int minPacks(int R, int G, int B) {
        int res = 0;
	res = min(R, G);
	res = min(res, B);
	R -= res;
	G -= res;
	B -= res;
	res += R / 3 + G / 3 + B / 3;
	R %= 3;
	G %= 3;
	B %= 3;
	int s = R + G + B;
	if (s == 1 || s == 2) {
		res += 1;
	} else if (s == 3 || s == 4) {
		res += 2;
	}

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        PackingBallsDiv2 theObject;
        eq(0, theObject.minPacks(4, 2, 4),4);
    }
    {
        PackingBallsDiv2 theObject;
        eq(1, theObject.minPacks(1, 7, 1),3);
    }
    {
        PackingBallsDiv2 theObject;
        eq(2, theObject.minPacks(2, 3, 5),4);
    }
    {
        PackingBallsDiv2 theObject;
        eq(3, theObject.minPacks(78, 53, 64),66);
    }
    {
        PackingBallsDiv2 theObject;
        eq(4, theObject.minPacks(100, 100, 100),100);
    }
}
// END CUT HERE
