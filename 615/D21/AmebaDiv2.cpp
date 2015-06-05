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

class AmebaDiv2 {
public:
    int simulate(vector <int> X, int A) {
        int res = A;
	for (int i = 0; i < X.size(); i++) {
		if (X[i] == res) {
			res *= 2;
		}
	}
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int XARRAY[] = {2,1,3,1,2};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        AmebaDiv2 theObject;
        eq(0, theObject.simulate(X, 1),4);
    }
    {
        int XARRAY[] = {1,4,9,16,25,36,49};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        AmebaDiv2 theObject;
        eq(1, theObject.simulate(X, 10),10);
    }
    {
        int XARRAY[] = {1,2,4,8,16,32,64,128,256,1024,2048};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        AmebaDiv2 theObject;
        eq(2, theObject.simulate(X, 1),512);
    }
    {
        int XARRAY[] = {817,832,817,832,126,817,63,63,126,817,832,287,823,817,574};
        vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
        AmebaDiv2 theObject;
        eq(3, theObject.simulate(X, 63),252);
    }
}
// END CUT HERE
