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

class KitayutaMart {
public:
	const static int MOD = 1000000007;

    int lastPrice(int N, int K) {
        int res = 0;
		int normal = getTotalUpto(K);
		int ep = 0;
		if (N > normal) {
			ep = (N - normal + K - 1) / K;
			N -= ep * K;
		}
		int left = 1;
		int right = K;
		while (right > left) {
			int middle = (right - left) / 2 + left;
			int tmp = getTotalUpto(middle);
			if (tmp >= N) {
  				right = middle;
			} else {
				left = middle + 1;
			}
		}
		res = (long long)right * fastPow(2, ep) % MOD;
		return res;
    }

	int fastPow(int a, int p) {
		if (p == 0) {
			return 1;
		}
		if (p % 2 == 0) {
			return fastPow((long long)a * a % MOD, p / 2) % MOD;
		} else {
			return (long long)a * fastPow(a, p - 1) % MOD;
		}
	}

	int getTotalUpto(int n) {
		int total = 0;
		int tmp = n;
		while (tmp > 0) {
			total += tmp;
			tmp /= 2;
		}
		return total;
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
        KitayutaMart theObject;
        eq(0, theObject.lastPrice(3, 1),4);
    }
    {
        KitayutaMart theObject;
        eq(1, theObject.lastPrice(3, 2),2);
    }
    {
        KitayutaMart theObject;
        eq(2, theObject.lastPrice(5, 3),4);
    }
    {
        KitayutaMart theObject;
        eq(3, theObject.lastPrice(1000000000, 1),570312504);
    }
    {
        KitayutaMart theObject;
        eq(4, theObject.lastPrice(987654321, 876543210),493827168);
    }
	return 0;
}
// END CUT HERE
