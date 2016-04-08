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

long long dp[11][100001];
// sum[p] 为 dp[p][1...k] k 项和
long long sum[11];
const int MOD = 1000000007;
class DivFreed2 {
public:
    int count(int n, int k) {
        int res = 0;

		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		for (int m = 1; m <= k; m++) {
			dp[1][m] = 1;
		}
		sum[1] = k;
		for (int p = 2; p <= n; p++) {
			for (int m = 1; m <= k; m++) {
				// case 1: a <= m
				// case 2: a > m && a <= k && a % m != 0
				dp[p][m] += sum[p-1];
				dp[p][m] %= MOD;
				for (int d = 2; d * m <= k; d++) {
					dp[p][m] -= dp[p-1][d*m];
					if (dp[p][m] < 0) {
						dp[p][m] += MOD;
					}
				}

				sum[p] += dp[p][m];
				sum[p] %= MOD;
			}
		}

		for (int i = 1; i <= k; i++) {
			res += dp[n][i];
			res %= MOD;
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
        DivFreed2 theObject;
        eq(0, theObject.count(2, 2),3);
    }
    {
        DivFreed2 theObject;
        eq(1, theObject.count(9, 1),1);
    }
    {
        DivFreed2 theObject;
        eq(2, theObject.count(3, 3),15);
    }
    {
        DivFreed2 theObject;
        eq(3, theObject.count(1, 107),107);
    }
    {
        DivFreed2 theObject;
        eq(4, theObject.count(2, 10),83);
    }
    {
        DivFreed2 theObject;
        eq(5, theObject.count(2, 1234),1515011);
    }
    {
        DivFreed2 theObject;
        eq(6, theObject.count(3, 8),326);
    }
    {
        DivFreed2 theObject;
        eq(7, theObject.count(10, 100000),526882214);
    }
	return 0;
}
// END CUT HERE
