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

class CatchTheBeatEasy {
public:
    string ableToCatchAll(vector <int> x, vector <int> y) {
	int N = x.size();
	vector <pii> v;
	for (int i = 0; i < N; i++) {
		v.push_back(mkp(y[i], x[i]));
	}
	sort(v.begin(), v.end());
	int cur = 0;
	int time = 0;
	for (int i = 0; i < N; i++) {
		time += abs(cur - v[i].second);
		if (time > v[i].first) {
			return "Not able to catch";
		}
		cur = v[i].second;
		time = v[i].first;
	}
        return "Able to catch";
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int xARRAY[] = {-1, 1, 0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 3, 4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(0, theObject.ableToCatchAll(x, y),"Able to catch");
    }
    {
        int xARRAY[] = {-3};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {2};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(1, theObject.ableToCatchAll(x, y),"Not able to catch");
    }
    {
        int xARRAY[] = {-1, 1, 0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 2, 4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(2, theObject.ableToCatchAll(x, y),"Not able to catch");
    }
    {
        int xARRAY[] = {0, -1, 1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {9, 1, 3};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(3, theObject.ableToCatchAll(x, y),"Able to catch");
    }
    {
        int xARRAY[] = {70,-108,52,-70,84,-29,66,-33};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {141,299,402,280,28,363,427,232};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(4, theObject.ableToCatchAll(x, y),"Not able to catch");
    }
    {
        int xARRAY[] = {-175,-28,-207,-29,-43,-183,-175,-112,-183,-31,-25,-66,-114,-116,-66};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {320,107,379,72,126,445,318,255,445,62,52,184,247,245,185};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(5, theObject.ableToCatchAll(x, y),"Able to catch");
    }
    {
        int xARRAY[] = {0,0,0,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,0,0,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        CatchTheBeatEasy theObject;
        eq(6, theObject.ableToCatchAll(x, y),"Able to catch");
    }
}
// END CUT HERE
