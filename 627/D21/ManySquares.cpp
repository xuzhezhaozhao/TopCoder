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

class ManySquares {
public:
    int howManySquares(vector <int> sticks) {
        int res = 0;
	multiset <int> s(sticks.begin(), sticks.end());
	for (int k = 1; k <= 1000; k++) {
		res += (s.count(k) / 4);
	}
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int sticksARRAY[] = {1,1,2,2,1,1,2};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(0, theObject.howManySquares(sticks),1);
    }
    {
        int sticksARRAY[] = {3, 1, 4, 4, 4, 10, 10, 10, 10}
           ;
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(1, theObject.howManySquares(sticks),1);
    }
    {
        int sticksARRAY[] = {1,2,3,4,1,2,3,4,1,2,3,1,2,3,4,1,2,3,3,3};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(2, theObject.howManySquares(sticks),3);
    }
    {
        int sticksARRAY[] = {1,1,1,2,2,2,3,3,3,4,4,4};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(3, theObject.howManySquares(sticks),0);
    }
    {
        int sticksARRAY[] = {1,1,1,2,1,1,1,3,1,1,1};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(4, theObject.howManySquares(sticks),2);
    }
    {
        int sticksARRAY[] = {2,2,4,4,8,8};
        vector <int> sticks( sticksARRAY, sticksARRAY+ARRSIZE(sticksARRAY) );
        ManySquares theObject;
        eq(5, theObject.howManySquares(sticks),0);
    }
	return 0;
}
// END CUT HERE
