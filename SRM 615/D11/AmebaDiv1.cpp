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

class AmebaDiv1 {
public:
	int count(vector <int> X) {
		int res = 0;
		set <int> have;
		for (int i = 0; i < X.size(); i++) {
			int cur = X[i];
			for (int j = 0; j < X.size(); j++) {
				if (cur == X[j]) {
					cur *= 2;
				}
			}
			have.insert(cur);
		}
		set <int> S;
		for (int i = 0; i < X.size(); i++) {
			if (have.find(X[i]) == have.end()) {
				S.insert(X[i]);
			}
		}
		res = S.size();
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int XARRAY[] = {3,2,1};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		AmebaDiv1 theObject;
		eq(0, theObject.count(X),2);
	}
	{
		int XARRAY[] = {2,2,2,2,2,2,4,2,2,2};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		AmebaDiv1 theObject;
		eq(1, theObject.count(X),2);
	}
	{
		int XARRAY[] = {1,2,4,8,16,32,64,128,256,1024,2048};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		AmebaDiv1 theObject;
		eq(2, theObject.count(X),11);
	}
	{
		int XARRAY[] = {854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		AmebaDiv1 theObject;
		eq(3, theObject.count(X),7);
	}
}
// END CUT HERE
