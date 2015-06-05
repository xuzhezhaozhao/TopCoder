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
class SuccessiveSubtraction2 {
public:
	int dp1[2001], dp2[2001];
    vector <int> calc(vector <int> a, vector <int> p, vector <int> v) {
        vector <int> res;

		for (int i = 0; i < (int)p.size(); i++) {
			a[ p[i] ] = v[i];
			res.push_back( calc(a) );
		}

        return res;
    }

	int calc(const vector <int> &a) {
		int ans = 0;
		int sz = a.size();
		if (sz <= 2) {
			ans = accumulate(a.begin(), a.end(), 0);
			return ans;
		}

		vector <int> sum1(sz + 1, 0);
		vector <int> sum2(sz + 1, 0);

		sum1[0] = a[0];
		for (int i = 1; i < sz; i++) {
			sum1[i] = sum1[i - 1] - a[i];
		}

		for (int i = sz - 1; i >= 1; i--) {
			sum2[i] = sum2[i + 1] - a[i];
		}
		sum2[0] = sum2[1] + a[0];

		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));

		for (int i = 2; i < sz; i++) {
			dp1[i] = std::max(dp1[i - 1] + a[i], 0);
		}

		for (int i = sz - 1; i >= 2; i--) {
			dp2[i] = std::max(dp2[i + 1] + a[i], 0);
		}

		int max1 = 0, max2 = 0;
		vector <int> f1(sz + 1, 0);
		vector <int> f2(sz + 1, 0);
		for (int i = 2; i < sz; i++) {
			if (dp1[i] > max1) {
				max1 = dp1[i];
			}
			f1[i] = sum1[i] + 2 * max1;
		}

		for (int i = sz - 1; i >= 2; i--) {
			if (dp2[i] > max2) {
				max2 = dp2[i];
			}
			f2[i] = sum2[i] + 2 * max2;
		}

		ans = sum1[sz - 1];
		for (int i = 2; i < sz - 1; i++) {
			ans = max(ans, f1[i] - a[i + 1] + f2[i + 2]);
		}
		ans = max(ans, f1[sz - 1]);

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
        int aARRAY[] = {1, 2, 3, 4, 5};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int pARRAY[] = {1, 2, 0, 4, 3};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        int vARRAY[] = {3, 9, -10, 5, 1};
        vector <int> v( vARRAY, vARRAY+ARRSIZE(vARRAY) );
        int retrunValueARRAY[] = {10, 16, 5, 5, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SuccessiveSubtraction2 theObject;
		eq(0, theObject.calc(a, p, v),retrunValue);
    }
    {
        int aARRAY[] = {-100, -100, -100, -100, -100};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int pARRAY[] = {0, 1, 2, 3, 4};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        int vARRAY[] = {0, 0, 0, 0, 0};
        vector <int> v( vARRAY, vARRAY+ARRSIZE(vARRAY) );
        int retrunValueARRAY[] = {400, 300, 200, 100, 0 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SuccessiveSubtraction2 theObject;
		eq(1, theObject.calc(a, p, v),retrunValue);
    }
    {
        int aARRAY[] = {83, 0, 25, 21};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int pARRAY[] = {0, 3, 2, 1, 3, 1, 2};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        int vARRAY[] = {10, -90, 33, 52, -100, 0, 45};
        vector <int> v( vARRAY, vARRAY+ARRSIZE(vARRAY) );
        int retrunValueARRAY[] = {56, 125, 133, 81, 91, 143, 155 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SuccessiveSubtraction2 theObject;
        eq(2, theObject.calc(a, p, v),retrunValue);
    }
    {
        int aARRAY[] = {1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int pARRAY[] = {0, 0, 0, 0};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        int vARRAY[] = {10, -10, 100, -100};
        vector <int> v( vARRAY, vARRAY+ARRSIZE(vARRAY) );
        int retrunValueARRAY[] = {10, -10, 100, -100 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SuccessiveSubtraction2 theObject;
        eq(3, theObject.calc(a, p, v),retrunValue);
    }
    {
        int aARRAY[] = {-11, -4, 28, 38, 21, -29, -45, 11, -58, -39, 92, 35, -56, -6, 29, -2, 61, 10, -29, -63};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int pARRAY[] = {19, 5, 3, 10, 4, 18, 5, 2, 0, 15};
        vector <int> p( pARRAY, pARRAY+ARRSIZE(pARRAY) );
        int vARRAY[] = {-19, 21, 7, -66, 38, -39, -22, 24, -32, 13};
        vector <int> v( vARRAY, vARRAY+ARRSIZE(vARRAY) );
        int retrunValueARRAY[] = {451, 443, 412, 440, 457, 467, 468, 464, 443, 458 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SuccessiveSubtraction2 theObject;
        eq(4, theObject.calc(a, p, v),retrunValue);
    }
	return 0;
}
// END CUT HERE
