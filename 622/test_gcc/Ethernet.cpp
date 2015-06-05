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

class Ethernet {
public:
    int connect(vector <int> parent, vector <int> dist, int maxDist) {
        int res = 0;
	int n = parent.size() + 1;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int parentARRAY[] = {0,0,0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int distARRAY[] = {1,1,1};
        vector <int> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
        Ethernet theObject;
        eq(0, theObject.connect(parent, dist, 2),1);
    }
    {
        int parentARRAY[] = {0,0,0,0,0,0,0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int distARRAY[] = {1,2,3,4,5,6,7};
        vector <int> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
        Ethernet theObject;
        eq(1, theObject.connect(parent, dist, 8),4);
    }
    {
        int parentARRAY[] = {0,1,2,3,4,5};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int distARRAY[] = {1,2,3,4,5,6};
        vector <int> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
        Ethernet theObject;
        eq(2, theObject.connect(parent, dist, 6),3);
    }
    {
        int parentARRAY[] = {0,0,0,1,1};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int distARRAY[] = {1,1,1,1,1};
        vector <int> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
        Ethernet theObject;
        eq(3, theObject.connect(parent, dist, 2),2);
    }
    {
        int parentARRAY[] = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        int distARRAY[] = {93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4};
        vector <int> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
        Ethernet theObject;
        eq(4, theObject.connect(parent, dist, 162),11);
    }
	return 0;
}
// END CUT HERE
