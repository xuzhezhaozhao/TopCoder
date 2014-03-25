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

class RobotHerbDiv2 {
public:
    int getdist(int T, vector <int> a) {
        int res;
	int di = 0;
	long long x = 0, y = 0;
	int n = a.size();
	for (int k = 0; k < T; k++) {
		for (int i = 0; i < n; i++) {
			switch (di) {
			case 0:
				y += a[i];
				di = (di + a[i]) % 4;
				break;
			case 1:
				x += a[i];
				di = (di + a[i]) % 4;
				break;
			case 2:
				y -= a[i];
				di = (di + a[i]) % 4;
				break;
			case 3:
				x -= a[i];
				di = (di + a[i]) % 4;
				break;
			}
		}
	}
	res = abs(x) + abs(y);
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int aARRAY[] = {1,2,3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        RobotHerbDiv2 theObject;
        eq(0, theObject.getdist(1, a),2);
    }
    {
        int aARRAY[] = {1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        RobotHerbDiv2 theObject;
        eq(1, theObject.getdist(100, a),0);
    }
    {
        int aARRAY[] = {1,1,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        RobotHerbDiv2 theObject;
        eq(2, theObject.getdist(5, a),10);
    }
    {
        int aARRAY[] = {400000};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        RobotHerbDiv2 theObject;
        eq(3, theObject.getdist(100, a),40000000);
    }
}
// END CUT HERE
