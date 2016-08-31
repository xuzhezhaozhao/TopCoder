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

class DivisibleSetDiv2 {
public:
    string isPossible(vector <int> b) {
        string res = "Impossible";
		double s = 0.0;
		for (auto x : b) {
			s += 1.0 / x;
		}
		if (s <= 1.0 + 1e-9) {
			res = "Possible";
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
        int bARRAY[] = {3,2};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DivisibleSetDiv2 theObject;
        eq(0, theObject.isPossible(b),"Possible");
    }
    {
        int bARRAY[] = {3,3,3};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DivisibleSetDiv2 theObject;
        eq(1, theObject.isPossible(b),"Possible");
    }
    {
        int bARRAY[] = {1,10};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DivisibleSetDiv2 theObject;
        eq(2, theObject.isPossible(b),"Impossible");
    }
    {
        int bARRAY[] = {2, 3, 10};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DivisibleSetDiv2 theObject;
        eq(3, theObject.isPossible(b),"Possible");
    }
    {
        int bARRAY[] = {7,10,4,6,3};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DivisibleSetDiv2 theObject;
        eq(4, theObject.isPossible(b),"Possible");
    }
    {
        int bARRAY[] = {9,9,9,9,9,9,9,9,9};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DivisibleSetDiv2 theObject;
        eq(5, theObject.isPossible(b),"Possible");
    }
    {
        int bARRAY[] = {3,4,5,6,7};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        DivisibleSetDiv2 theObject;
        eq(6, theObject.isPossible(b),"Impossible");
    }
	return 0;
}
// END CUT HERE
