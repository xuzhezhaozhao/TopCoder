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

double dp[1001][1001];
class Queueing {
public:
	int p1, p2;
	double solve(int n1, int n2) {
		if (n1 == 0 || n2 == 0) {
			if (n1 < n2) {
				return 1;	
			} else {
				return 0;
			}
		}

		if (dp[n1][n2] != -1) {
			return dp[n1][n2];
		}

		dp[n1][n2] = 0;

		double res = 0;
		double t = 0;

		t += (1 - 1.0/p1) * 1.0/p2 * solve(n1, n2-1);
		t += 1.0/p1 * (1 - 1.0/p2) * solve(n1-1, n2);
		t += 1.0/p1 * 1.0/p2 * solve(n1-1, n2-1);

		res = t / ( 1 - (1-1.0/p1)*(1-1.0/p2) );

		dp[n1][n2] = res;
		return res;
	}

    double probFirst(int len1, int len2, int p1, int p2) {
		this->p1 = p1;
		this->p2 = p2;
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				dp[i][j] = -1;
			}
		}

        double res = solve(len1, len2);

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
        Queueing theObject;
        eq(0, theObject.probFirst(1, 2, 2, 1),0.5);
    }
    {
        Queueing theObject;
        eq(1, theObject.probFirst(1, 3, 3, 7),0.9835390946502058);
    }
    {
        Queueing theObject;
        eq(2, theObject.probFirst(3, 1, 7, 3),0.010973936899862834);
    }
    {
        Queueing theObject;
        eq(3, theObject.probFirst(12, 34, 56, 78),0.999996203228025);
    }
    {
        Queueing theObject;
        eq(4, theObject.probFirst(3, 6, 8, 4),0.5229465300297028);
    }
	return 0;
}
// END CUT HERE
