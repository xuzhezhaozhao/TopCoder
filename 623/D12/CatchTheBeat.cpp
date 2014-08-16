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
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) {
	cerr << a;
}
static void print( long long a ) {
	cerr << a << "L";
}
static void print( string a ) {
	cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
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
		print( have );
		print( need );
		return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have );
			print( need );
			return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) {
		cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need );
		cerr << " received ";
		print( have );
		cerr << "." << endl;
	}
}
// END CUT HERE

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

/*************** Program Begin **********************/
int M[500001];
vector <int> x, y;

class CatchTheBeat {
public:
	int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) {
		x.resize(n); y.resize(n);
		x[0] = x0;
		for (int i = 1; i < n; i++) {
			x[i] = (x[i-1] * (long long)a + b) % mod1;
		}

		for (int i = 0; i < n; i++) {
			x[i] = x[i] - offset;
		}
		y[0] = y0;
		for (int i = 1; i < n; i++) {
			y[i] = (y[i-1] * (long long)c + d) % mod2;
		}
		vector <pii> v;
		for (int i = 0; i < n; i++) {
			if (abs(x[i]) > y[i]) {
				continue;
			}
			v.push_back(mkp(x[i] + y[i], y[i] - x[i]));
		}
		sort(v.begin(), v.end());
		n = v.size();
		memset(M, 0, sizeof(M));
		for (int i = 0; i < n; i++) {
			x[i] = v[i].second;
		}
		// LIS
		int L = 0;
		for (int i = 0; i < n; i++) {
			// binary search
			int lo = 1, hi = L;
			int mid;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (x[M[mid]] > x[i]) {
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			int newL = lo;
			if (newL > L) {		// sequence length increase 1
				M[newL] = i;
				L = newL;
			} else {
				if (x[M[newL]] >= x[i]) {
					M[newL] = i;
				}
			}
		}
	
		return L;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		CatchTheBeat theObject;
		eq(0, theObject.maxCatched(3, 0, 0, 1, 1, 1, 1, 100, 100, 1),2);
	}
	{
		CatchTheBeat theObject;
		eq(1, theObject.maxCatched(1, 0, 1234, 0, 0, 0, 0, 1000000000, 1000000000, 1000),1);
	}
	{
		CatchTheBeat theObject;
		eq(2, theObject.maxCatched(1, 0, 999, 0, 0, 0, 0, 1000000000, 1000000000, 1000),0);
	}
	{
		CatchTheBeat theObject;
		eq(3, theObject.maxCatched(100, 0, 0, 1, 1, 1, 1, 3, 58585858, 1),66);
	}
	{
		CatchTheBeat theObject;
		eq(4, theObject.maxCatched(500000, 123456, 0, 1, 0, 1, 1, 1000000000, 1000000000, 0),376544);
	}
	{
		CatchTheBeat theObject;
		eq(5, theObject.maxCatched(500000, 0, 0, 0, 0, 0, 0, 1, 1, 0),500000);
	}
	{
		CatchTheBeat theObject;
		eq(6, theObject.maxCatched(10, 999999957, 79, 993948167, 24597383, 212151897, 999940854, 999999986, 999940855, 3404),3);
	}
}
// END CUT HERE
