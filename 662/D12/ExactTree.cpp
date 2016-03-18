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

const int MAX_N = 51;
const int MAX_M = 101;
long long dp[MAX_N][MAX_M];
class ExactTree {
public:
    int getTree(int n, int m, int r) {
        int res = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = -1;
			}
		}
		dp[1][0] = 0;

		for (int i = 2; i <= n; i++) {
			for (int k = 1; k < i; k++) {
				for (int p = 0; p < m; p++) {
					for (int q = 0; q < m; q++) {
						if (dp[k][p] == -1 || dp[i-k][q] == -1) {
							continue;
						}
						int v = dp[k][p] + dp[i-k][q] + k * (n-k);
						if (dp[i][v%m] == -1 || dp[i][v%m] > v) {
							dp[i][v%m] = v;
						}
					}
				}
			}
		}

		res = dp[n][r];
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
        ExactTree theObject;
        eq(0, theObject.getTree(4, 100, 9),9);
    }
    {
        ExactTree theObject;
        eq(1, theObject.getTree(4, 100, 10),10);
    }
    {
        ExactTree theObject;
        eq(2, theObject.getTree(4, 100, 0),-1);
    }
    {
        ExactTree theObject;
        eq(3, theObject.getTree(6, 2, 0),28);
    }
    {
        ExactTree theObject;
        eq(4, theObject.getTree(6, 2, 1),25);
    }
    {
        ExactTree theObject;
        eq(5, theObject.getTree(25, 100, 0),700);
    }
    {
        ExactTree theObject;
        eq(6, theObject.getTree(50, 97, 89),2708);
    }
	return 0;
}
// END CUT HERE
