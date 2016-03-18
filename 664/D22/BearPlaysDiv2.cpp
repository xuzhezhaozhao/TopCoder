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

bool can[1501][1501];
class BearPlaysDiv2 {
public:
	void solve(int t[]) {
		if (can[ t[0] ][ t[1] ]) {
			return;
		}
		can[t[0]][t[1]] = true;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) { continue; }
				if (t[i] < t[j]) {
					int t2[] = {t[i] * 2, t[j] - t[i], t[3-i-j]};
					solve(t2);
				}
			}
		}
	}

    string equalPiles(int A, int B, int C) {
		if ((A + B + C) % 3 != 0) {
			return "impossible";
		}
		memset(can, 0, sizeof(can));
		int T = (A + B + C) / 3;
		int t[3] = {A, B, C};

		solve(t);

		return can[T][T] ? "possible" : "impossible";
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
        BearPlaysDiv2 theObject;
        eq(0, theObject.equalPiles(10, 15, 35),"possible");
    }
    {
        BearPlaysDiv2 theObject;
        eq(1, theObject.equalPiles(1, 1, 2),"impossible");
    }
    {
        BearPlaysDiv2 theObject;
        eq(2, theObject.equalPiles(4, 6, 8),"impossible");
    }
    {
        BearPlaysDiv2 theObject;
        eq(3, theObject.equalPiles(18, 18, 18),"possible");
    }
    {
        BearPlaysDiv2 theObject;
        eq(4, theObject.equalPiles(225, 500, 475),"possible");
    }
	return 0;
}
// END CUT HERE
