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

class AliceGame {
public:
    long long findMinimumValue(long long x, long long y) {
		long long total = x + y;
		long long s = sqrt(total);
		if (s * s != total) {
			return -1;
		}
		for (long long k = 0; k <= s; k++) {
			if ((x + k) % 2) {
				continue;
			}
			long long min = k * k;
			long long max = (2 * s - k) * k;
			if (x >= min && x <= max) {
				return k;
			}
		}
		return -1;
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
        AliceGame theObject;
        eq(0, theObject.findMinimumValue(2L, 2LL),2LL);
    }
    {
        AliceGame theObject;
        eq(1, theObject.findMinimumValue(17L, 8LL),3LL);
    }
    {
        AliceGame theObject;
        eq(2, theObject.findMinimumValue(1000000000000LL, 0LL),1000000LL);
    }
    {
        AliceGame theObject;
        eq(3, theObject.findMinimumValue(11L, 14LL),3LL);
    }
    {
        AliceGame theObject;
        eq(4, theObject.findMinimumValue(500000L, 500000LL),294LL);
    }
	return 0;
}
// END CUT HERE
