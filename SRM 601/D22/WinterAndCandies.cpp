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
int cnt[51];
class WinterAndCandies {
public:
    int getNumber(vector <int> type) {
        int res = 0;
	int n = type.size();
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		++cnt[ type[i] ];
	}
	int mul = 1;
	for (int i = 1; i <= 50; i++) {
		mul *= cnt[i];
		res += mul;
	}
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int typeARRAY[] = {1, 3, 2};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(0, theObject.getNumber(type),3);
    }
    {
        int typeARRAY[] = {1, 1, 2};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(1, theObject.getNumber(type),4);
    }
    {
        int typeARRAY[] = {1, 3, 2, 5, 7, 4, 5, 4};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(2, theObject.getNumber(type),9);
    }
    {
        int typeARRAY[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(3, theObject.getNumber(type),62);
    }
    {
        int typeARRAY[] = {2};
        vector <int> type( typeARRAY, typeARRAY+ARRSIZE(typeARRAY) );
        WinterAndCandies theObject;
        eq(4, theObject.getNumber(type),0);
    }
}
// END CUT HERE
