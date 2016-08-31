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

class XorOrderDiv2 {
public:
    vector<long long> getExpectation(int m, vector <int> a) {
        vector<long long> res;
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
        int aARRAY[] = {0,1,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        long retrunValueARRAY[] = {6L, 6L, 8L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        XorOrderDiv2 theObject;
        eq(0, theObject.getExpectation(2, a),retrunValue);
    }
    {
        int aARRAY[] = {1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        long retrunValueARRAY[] = {0L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        XorOrderDiv2 theObject;
        eq(1, theObject.getExpectation(1, a),retrunValue);
    }
    {
        int aARRAY[] = {13,17};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        long retrunValueARRAY[] = {16L, 16L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        XorOrderDiv2 theObject;
        eq(2, theObject.getExpectation(5, a),retrunValue);
    }
    {
        int aARRAY[] = {1,2,3,4,5,6,7,8,9,10};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        long retrunValueARRAY[] = {29527900160L, 28991029248L, 28991029248L, 27917287424L, 27917287424L, 27917287424L, 27917287424L, 35433480192L, 35433480192L, 35970351104L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        XorOrderDiv2 theObject;
        eq(3, theObject.getExpectation(30, a),retrunValue);
    }
	return 0;
}
// END CUT HERE
