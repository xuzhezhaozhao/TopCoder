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

class CartInSupermarketEasy {
public:
    int calc(int N, int K) {
        int res = 0;

		int p = getExpo(N);
		if (K >= N - 1) {
			return p + 1;
		}

		if (K == 0) {
			return N;
		}

		p = getExpo(K + 1);

		int r = (1 << (p-1)) - (K - ((1 << (p-1)) - 1));
		N -= r;

		res = N / (K + 1) + p;
		if (N % (K + 1) != 0) {
			++res;
		}

        return res;
    }

	int getExpo(int n) {
		for (int i = 0; i < 31; i++) {
			if ( (1 << i) >= n ) {
				return i;
			}
		}
		return 0;
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
        CartInSupermarketEasy theObject;
        eq(0, theObject.calc(5, 0),5);
    }
    {
        CartInSupermarketEasy theObject;
        eq(1, theObject.calc(5, 2),4);
    }
    {
        CartInSupermarketEasy theObject;
        eq(2, theObject.calc(15, 4),6);
    }
    {
        CartInSupermarketEasy theObject;
        eq(3, theObject.calc(7, 100),4);
    }
    {
        CartInSupermarketEasy theObject;
        eq(4, theObject.calc(45, 5),11);
    }
    {
        CartInSupermarketEasy theObject;
        eq(5, theObject.calc(100, 100),8);
    }
	return 0;
}
// END CUT HERE
