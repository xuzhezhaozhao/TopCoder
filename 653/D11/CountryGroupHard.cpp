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
int dp[102];

class CountryGroupHard {
public:
    string solve(vector <int> a) {
		string sufficient = "Sufficient";
		string insufficient = "Insufficient";

		memset(dp, -1, sizeof(dp));
		return rec(a, 0) > 1 ? insufficient : sufficient;
    }

	int rec(vector <int> &a, int p) {
		int sz = a.size();
		if (p == sz) {
			return 1;
		}

		int & ans = dp[p];
		if (ans != -1) {
			return ans;
		}
		ans = 0;

		for (int len = 1; len <= sz - p; len++) {
			bool ok = true;
			for (int i = p; i < p + len; i++) {
				if (a[i] != len && a[i] != 0) {
					ok = false;
					break;
				}
			}
			if (ok) {
				ans += rec(a, p + len);
				ans = min(ans, 2);
			}
		}

		return ans;
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
        //int aARRAY[] = {0,2,3,0,0};
        int aARRAY[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ;
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(0, theObject.solve(a),"Sufficient");
    }
    {
        int aARRAY[] = {0, 0, 0, 0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(1, theObject.solve(a),"Insufficient");
    }
    {
        int aARRAY[] = {0,3,0,0,3,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(2, theObject.solve(a),"Sufficient");
    }
    {
        int aARRAY[] = {0,0,3,3,0,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(3, theObject.solve(a),"Insufficient");
    }
    {
        int aARRAY[] = {2,2,0,2,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroupHard theObject;
        eq(4, theObject.solve(a),"Sufficient");
    }
	return 0;
}
// END CUT HERE
