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
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/

class MinimumSquareEasy {
public:
    long long minArea(vector <int> x, vector <int> y) {
        long long res = LLONG_MAX;
	int N = x.size();
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int min_x, min_y, max_x, max_y;
			min_x = min_y = INT_MAX;
			max_x = max_y = INT_MIN;
			for (int k = 0; k < N; ++k) {
				if (k == i || k == j) {
					continue;
				}
				min_x = min(min_x, x[k]);
				min_y = min(min_y, y[k]);
				max_x = max(max_x, x[k]);
				max_y = max(max_y, y[k]);
			}		
			long long side = max( abs(max_x - min_x), 
					abs(max_y - min_y) ) + 2;
			res = min(res, side * side);
		}
	}	

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int xARRAY[] = {0, 1, 2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 1, 5};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        MinimumSquareEasy theObject;
        eq(0, theObject.minArea(x, y),4LL);
    }
    {
        int xARRAY[] = {-1, -1, 0, 2, 0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-2, -1, 0, -1, -2};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        MinimumSquareEasy theObject;
        eq(1, theObject.minArea(x, y),9LL);
    }
    {
        int xARRAY[] = {1000000000, -1000000000, 1000000000, -1000000000};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1000000000, 1000000000, -1000000000, -1000000000};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        MinimumSquareEasy theObject;
        eq(2, theObject.minArea(x, y),4000000008000000004LL);
    }
    {
        int xARRAY[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        MinimumSquareEasy theObject;
        eq(3, theObject.minArea(x, y),22801LL);
    }
	return 0;
}
// END CUT HERE
