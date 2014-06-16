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

class MinimumSquare {
public:
	long long minArea(vector <int> x, vector <int> y, int K) {
		long long res = 0;
		int n = x.size();

		long long side = LLONG_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sx = x[i], sy = y[j];
				vector <int> tmp;
				for (int k = 0; k < n; k++) {
					if (x[k] >= sx && y[k] >= sy) {
						tmp.push_back(max(x[k] - sx, y[k] - sy));
					}
				}
				if (tmp.size() >= K) {
					sort(tmp.begin(), tmp.end());
					side = min(side, (long long)tmp[K - 1]);
				}
			}
		}
		res = (2 + side) * (2 + side);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int xARRAY[] = {0, 3};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {0, 7};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		MinimumSquare theObject;
		eq(0, theObject.minArea(x, y, 2),81LL);
	}
	{
		int xARRAY[] = {-4, 3, 1};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {3 , -1, -2};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		MinimumSquare theObject;
		eq(1, theObject.minArea(x, y, 2),16LL);
	}
	{
		int xARRAY[] = {0, 0, 1, 1, 2, 2};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {0, 1, 0, 1, 0, 1};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		MinimumSquare theObject;
		eq(2, theObject.minArea(x, y, 4),9LL);
	}
	{
		int xARRAY[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		MinimumSquare theObject;
		eq(3, theObject.minArea(x, y, 3),4000000008000000004LL);
	}
	{
		int xARRAY[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		MinimumSquare theObject;
		eq(4, theObject.minArea(x, y, 8),1695545329LL);
	}
}
// END CUT HERE
