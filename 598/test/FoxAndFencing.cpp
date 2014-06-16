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

class FoxAndFencing {
public:
    string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d) {
        string res;
	if (mov1 + rng1 >= d) {
		return "Ciel";
	} else {
		if (mov1 > mov2 && mov1 + rng1 > mov2 + rng2 + mov2) {
			return "Ciel";
		} else if (mov2 + rng2 >= d + mov1 || (mov2 > mov1 && mov2 + rng2 > mov1 + rng1 + mov1) ) {
			return "Liss";
		} else {
			return "Draw";
		}
	}
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        FoxAndFencing theObject;
        eq(0, theObject.WhoCanWin(1212548, 4702178, 5032818, 1951676, 7426047),"Draw");
    }
    {
        FoxAndFencing theObject;
        eq(1, theObject.WhoCanWin(2, 1, 1, 100, 50),"Liss");
    }
    {
        FoxAndFencing theObject;
        eq(2, theObject.WhoCanWin(2, 1, 1, 100, 150),"Draw");
    }
    {
        FoxAndFencing theObject;
        eq(3, theObject.WhoCanWin(100, 100, 100, 100, 100000000),"Draw");
    }
    {
        FoxAndFencing theObject;
        eq(4, theObject.WhoCanWin(100, 1, 100, 1, 100000000),"Ciel");
    }
    {
        FoxAndFencing theObject;
        eq(5, theObject.WhoCanWin(100, 1, 100, 250, 100000000),"Draw");
    }
    {
        FoxAndFencing theObject;
        eq(6, theObject.WhoCanWin(100, 1, 100, 150, 100000000),"Ciel");
    }
    {
        FoxAndFencing theObject;
        eq(7, theObject.WhoCanWin(100, 50, 100, 1, 100000000),"Ciel");
    }
    {
        FoxAndFencing theObject;
        eq(8, theObject.WhoCanWin(100, 150, 100, 1, 100000000),"Draw");
    }
}
// END CUT HERE
