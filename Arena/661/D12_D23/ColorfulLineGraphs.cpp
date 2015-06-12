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

class ColorfulLineGraphs {
public:
	long long fastPow(long long a, long long b, int M) {
		long long res = 1;
		while (b > 0) {
			if (b % 2 != 0) {
				res *= a;
				res %= M;
			}
			b /= 2;
			a *= a;
			a %= M;
		}
		return res;
	}

    int countWays(long long N, long long K, int M) {
        long long res = 1;

		long long times = N / M;
		long long rem = N % M;

		long long m1 = K % M;
		long long m2 = (K - 1) % M;
		for (long long i = 0; i <= M - 1 && i <= N; i++) {
			long long a = ( m1 + i * m2) % M;
			res *= fastPow(a, times, M);
			res %= M;
			if (i < rem) {
				res *= a;
				res %= M;
			}
		}
        return (int)res;
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
        ColorfulLineGraphs theObject;
        eq(0, theObject.countWays(3L, 2L, 100000),24);
    }
    {
        ColorfulLineGraphs theObject;
		eq(1, theObject.countWays(15L, 3L, 1000000),510625);
    }
    {
        ColorfulLineGraphs theObject;
		eq(2, theObject.countWays(100000L, 100000L, 999999),185185);
    }
    {
        ColorfulLineGraphs theObject;
		eq(3, theObject.countWays(1000000000000L, 6L, 1000000),109376);
    }
    {
        ColorfulLineGraphs theObject;
		eq(4, theObject.countWays(5000L, 1000000000000L, 314159),202996);
    }
	return 0;
}
// END CUT HERE
