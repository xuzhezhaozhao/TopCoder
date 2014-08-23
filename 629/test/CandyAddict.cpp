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

class CandyAddict {
public:
	vector<long long> solve(vector <int> X, vector <int> Y, vector <int> Z) {
		vector<long long> res;



		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int XARRAY[] = {5};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {3};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int ZARRAY[] = {3};
		vector <int> Z( ZARRAY, ZARRAY+ARRSIZE(ZARRAY) );
		long retrunValueARRAY[] = {6L };
		vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		CandyAddict theObject;
		eq(0, theObject.solve(X, Y, Z),retrunValue);
	}
	{
		int XARRAY[] = {5,5,5,5,5};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {3,3,3,3,3};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int ZARRAY[] = {1,2,3,4,5};
		vector <int> Z( ZARRAY, ZARRAY+ARRSIZE(ZARRAY) );
		long retrunValueARRAY[] = {2L, 1L, 6L, 2L, 7L };
		vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		CandyAddict theObject;
		eq(1, theObject.solve(X, Y, Z),retrunValue);
	}
	{
		int XARRAY[] = {1000000000,1000000000,1000000000,1000000000,1000000000};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {1,2,3,999999998,999999999};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int ZARRAY[] = {342568368,560496730,586947396,386937583,609483745};
		vector <int> Z( ZARRAY, ZARRAY+ARRSIZE(ZARRAY) );
		long retrunValueARRAY[] = {342568367000000000L, 60496729000000000L, 253614062000000001L, 773875166L, 609483745L };
		vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		CandyAddict theObject;
		eq(2, theObject.solve(X, Y, Z),retrunValue);
	}
}
// END CUT HERE
