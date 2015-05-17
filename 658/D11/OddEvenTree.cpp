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

class OddEvenTree {
public:
    vector <int> getTree(vector <string> x) {
        vector <int> res;
		int N = x.size();
		for (int i = 0; i < N; i++) {
			if (x[i][i] != 'E') {
				return {-1};
			}
			for (int j = 0; j < N; j++) {
				if (x[i][j] != x[j][i]) {
					return {-1};
				}
				for (int k = 0; k < N; k++) {
					if ((x[i][j] == 'O') ^ (x[i][k] == 'O') ^ (x[j][k] == 'O')) {
						return {-1};
					}
				}
			}
		}

		int od = -1;
		for (int i = 1; i < N; i++) {
			if (x[0][i] == 'O') {
				od = i;
				break;
			}
		}
		if (-1 == od) {
			return {-1};
		}
		for (int i = 1; i < N; i++) {
			if (x[0][i] == 'O') {
				res.push_back(0);
				res.push_back(i);
			} else {
				res.push_back(od);
				res.push_back(i);
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
        string xARRAY[] = {"EOE",
            "OEO",
            "EOE"};
        vector <string> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {0, 1, 2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        OddEvenTree theObject;
        eq(0, theObject.getTree(x),retrunValue);
    }
    {
        string xARRAY[] = {"EO",
            "OE"};
        vector <string> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {0, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        OddEvenTree theObject;
        eq(1, theObject.getTree(x),retrunValue);
    }
    {
        string xARRAY[] = {"OO",
            "OE"};
        vector <string> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {-1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        OddEvenTree theObject;
        eq(2, theObject.getTree(x),retrunValue);
    }
    {
        string xARRAY[] = {"EO",
            "EE"};
        vector <string> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {-1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        OddEvenTree theObject;
        eq(3, theObject.getTree(x),retrunValue);
    }
    {
        string xARRAY[] = {"EOEO",
            "OEOE",
            "EOEO",
            "OEOE"};
        vector <string> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int retrunValueARRAY[] = {0, 1, 0, 3, 2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        OddEvenTree theObject;
        eq(4, theObject.getTree(x),retrunValue);
    }
	return 0;
}
// END CUT HERE
