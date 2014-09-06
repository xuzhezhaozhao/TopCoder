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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

class RunningAroundPark {
public:
    int numberOfLap(int N, vector <int> d) {
        int res = 1;
	for (int i = 1; i < d.size(); i++) {
		if (d[i] <= d[i-1]) {
			++res;
		}
	}
        return res;
    }

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
    {
        int dARRAY[] = {1,2,3};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        RunningAroundPark theObject;
        eq(0, theObject.numberOfLap(3, d),1);
    }
    {
        int dARRAY[] = {6,6};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        RunningAroundPark theObject;
        eq(1, theObject.numberOfLap(24, d),2);
    }
    {
        int dARRAY[] = {3,2,1};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        RunningAroundPark theObject;
        eq(2, theObject.numberOfLap(3, d),3);
    }
    {
        int dARRAY[] = {1,3,5,7,9,2,4,6,8,10};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        RunningAroundPark theObject;
        eq(3, theObject.numberOfLap(50, d),2);
    }
	return 0;
}
// END CUT HERE
