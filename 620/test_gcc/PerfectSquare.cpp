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

const int MOD = 1e9 + 7;

class PerfectSquare {
public:
    int ways(vector <int> x) {
        int res = 0;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int xARRAY[] = {1, 1,
            1, 2}
           ;
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        PerfectSquare theObject;
        eq(0, theObject.ways(x),1);
    }
    {
        int xARRAY[] = {620, 620,
            620, 620}
           ;
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        PerfectSquare theObject;
        eq(1, theObject.ways(x),2);
    }
    {
        int xARRAY[] = {1, 2, 3,
            4, 5, 6,
            7, 8, 9};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        PerfectSquare theObject;
        eq(2, theObject.ways(x),1);
    }
    {
        int xARRAY[] = {2, 2, 2, 2, 2,
            2, 2, 2, 2, 2,
            2, 2, 2, 2, 2,
            2, 2, 2, 2, 2,
            2, 2, 2, 2, 2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        PerfectSquare theObject;
        eq(3, theObject.ways(x),0);
    }
    {
        int xARRAY[] = {2, 3, 4, 5,
            6, 7, 8, 9,
            10,11,12,13,
            14,15,16,17};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        PerfectSquare theObject;
        eq(4, theObject.ways(x),4);
    }
    {
        int xARRAY[] = {9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
            9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        PerfectSquare theObject;
        eq(5, theObject.ways(x),993282280);
    }
	return 0;
}
// END CUT HERE
