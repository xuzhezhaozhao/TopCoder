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

const int MOD = 1e9 + 7;
int dp[55];
class PilingRectsDiv2
{
public:
	int getmax(vector <int> X, vector <int> Y, int limit)
	{
		int res = 0;
		int n = X.size();
		for (int i = 1; i <= 200; i++) {
			for (int j = 1; j <= 200; j++) {
				if (i * j < limit) {
					continue;
				}
				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if ( (i <= X[k] && j <= Y[k]) ||
						(i <= Y[k] && j <= X[k]) ) {
							++cnt;
					}
				}
				res = max(res, cnt);
				break;
			}
		}
		res = (res ? res : -1);
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int XARRAY[] = {1,2,3,1};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {3,2,4,4};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		PilingRectsDiv2 theObject;
		eq(0, theObject.getmax(X, Y, 3),3);
	}
	{
		int XARRAY[] = {4,7};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {7,4};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		PilingRectsDiv2 theObject;
		eq(1, theObject.getmax(X, Y, 25),2);
	}
	{
		int XARRAY[] = {10};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {10};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		PilingRectsDiv2 theObject;
		eq(2, theObject.getmax(X, Y, 9999),-1);
	}
	{
		int XARRAY[] = {10};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {3};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		PilingRectsDiv2 theObject;
		eq(3, theObject.getmax(X, Y, 30),1);
	}
	{
		int XARRAY[] = {3,6,5,8,2,9,14};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {14,6,13,8,15,6,3};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		PilingRectsDiv2 theObject;
		eq(4, theObject.getmax(X, Y, 27),4);
	}
	{
		int XARRAY[] = {121,168,86,106,36,10,125,97,53,26,148,129,41,18,173,55,13,73,91,174,177,190,28,164,122,92,5,26,58,188,14,67,48,196,41,94,24,89,54,117,12,6,155,103,200,128,184,29,92,149};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {199,182,43,191,2,145,15,53,38,37,61,45,157,129,119,123,177,178,183,188,132,108,112,137,92,59,75,196,102,152,114,121,181,93,32,3,24,116,4,163,96,159,196,43,59,150,79,113,20,146};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		PilingRectsDiv2 theObject;
		eq(5, theObject.getmax(X, Y, 5345),24);
	}
}
// END CUT HERE
