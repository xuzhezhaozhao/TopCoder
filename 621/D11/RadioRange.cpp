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
const double eps = 0.000000001;
class RadioRange {
public:
		double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
			double res = 0;
			int N = X.size();
			vector <double> d1, d2;
			for (int i = 0; i < N; i++) {
				long long temp = (long long)X[i] * (long long)X[i] + (long long)Y[i] * (long long)Y[i];
				double d = sqrt(temp * 1.0);
				d1.push_back(d - R[i]);
				d2.push_back(d + R[i]);
			}

			double good = 0.0;
			vector <double> t2;
			for (int i = 0; i < N; i++) {
				if (d1[i] <= Z && d1[i] > 0) {
					t2.push_back(d1[i]);
				}
				if (d2[i] <= Z && d2[i] > 0) {
					t2.push_back(d2[i]);
				}
			}
			t2.push_back(0);
			t2.push_back(Z);
			int n = t2.size();
			sort(t2.begin(), t2.end());
			for (int i = 0; i < n - 1; i++) {
				bool ok = true;	
				double s1 = t2[i];
				double s2 = t2[i + 1];

				for (int j = 0; j < N; j++) {
					if ( (d2[j] > s2  && d1[j] < s2) ||
						(d2[j] > s1 && d1[j] < s1) ) {
							ok = false;
					} else if (abs(d1[j] - s1) < eps && abs(s2 - d2[j]) < eps) {
						ok = false;
					}
				}
				if (ok) {
					good += s2 - s1;
				}
			}
			res = good / (double)Z;
			return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int XARRAY[] = {0};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {0};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int RARRAY[] = {5};
		vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
		RadioRange theObject;
		eq(0, theObject.RadiusProbability(X, Y, R, 10),0.5);
	}
	{
		int XARRAY[] = {0};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {0};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int RARRAY[] = {10};
		vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
		RadioRange theObject;
		eq(1, theObject.RadiusProbability(X, Y, R, 10),0.0);
	}
	{
		int XARRAY[] = {10};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {10};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int RARRAY[] = {10};
		vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
		RadioRange theObject;
		eq(2, theObject.RadiusProbability(X, Y, R, 10),0.4142135623730951);
	}
	{
		int XARRAY[] = {11, -11, 0, 0};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {0, 0, 11, -11};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int RARRAY[] = {10, 10, 10, 10};
		vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
		RadioRange theObject;
		eq(3, theObject.RadiusProbability(X, Y, R, 31),0.3548387096774194);
	}
	{
		int XARRAY[] = {100};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {100};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int RARRAY[] = {1};
		vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
		RadioRange theObject;
		eq(4, theObject.RadiusProbability(X, Y, R, 10),1.0);
	}
	{
		int XARRAY[] = {1000000000};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {1000000000};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int RARRAY[] = {1000000000};
		vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
		RadioRange theObject;
		eq(5, theObject.RadiusProbability(X, Y, R, 1000000000),0.41421356237309503);
	}
	{
		int XARRAY[] = {20, -20, 0, 0};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {0, 0, 20, -20};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int RARRAY[] = {50, 50, 50, 50};
		vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
		RadioRange theObject;
		eq(6, theObject.RadiusProbability(X, Y, R, 100),0.3);
	}
	{
		int XARRAY[] = {0, -60, -62, -60, 63, -97};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {-72, 67, 61, -8, -32, 89};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		int RARRAY[] = {6, 7, 8, 7, 5, 6};
		vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
		RadioRange theObject;
		eq(7, theObject.RadiusProbability(X, Y, R, 918),0.9407071068962471);
	}
}
// END CUT HERE
