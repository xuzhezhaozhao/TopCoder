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

class Hexspeak {
public:
    string decode(long long ciphertext) {
        string res;
		while (ciphertext > 0) {
			long long d = ciphertext % 16;
			ciphertext /= 16;
			if ( d >= 2 && d <= 9 ) { return "Error!"; }
			else if (d == 0) {
				res.push_back('O');
			} else if (d == 1) {
				res.push_back('I');
			} else {
				res.push_back( 'A' + d - 10 );
			}
		}
		std::reverse(res.begin(), res.end());
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
        Hexspeak theObject;
        eq(0, theObject.decode(257L),"IOI");
    }
    {
        Hexspeak theObject;
        eq(1, theObject.decode(258L),"Error!");
    }
    {
        Hexspeak theObject;
        eq(2, theObject.decode(3405691582L),"CAFEBABE");
    }
    {
        Hexspeak theObject;
        eq(3, theObject.decode(2882400001L),"ABCDEFOI");
    }
    {
        Hexspeak theObject;
        eq(4, theObject.decode(999994830345994239L),"DEOBIFFFFFFFFFF");
    }
    {
        Hexspeak theObject;
        eq(5, theObject.decode(1000000000000000000L),"Error!");
    }
	return 0;
}
// END CUT HERE
