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

class PotentialGeometricSequence {
public:
	int numberOfSubsequences(vector <int> d) {
		int res = 0;
		int N = d.size();

		res = N + N - 1; 	// one and two numbers
		for (int i = 0; i < N; i++) {
			for (int j = i + 2; j < N; j++) {
				int dif = d[i + 1] - d[i];
				bool ok = true;
				for (int k = i + 1; k <= j; k++) {
					if (d[k] - d[k - 1] != dif) {
						ok = false;
					}
				}
				if (ok) {
					++res;
				}
			}
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
		int dARRAY[] = {0,1,2};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		PotentialGeometricSequence theObject;
		eq(0, theObject.numberOfSubsequences(d),6);
	}
	{
		int dARRAY[] = {1,2,4};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		PotentialGeometricSequence theObject;
		eq(1, theObject.numberOfSubsequences(d),5);
	}
	{
		int dARRAY[] = {3,2,1,0};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		PotentialGeometricSequence theObject;
		eq(2, theObject.numberOfSubsequences(d),10);
	}
	{
		int dARRAY[] = {1,2,4,8,16};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		PotentialGeometricSequence theObject;
		eq(3, theObject.numberOfSubsequences(d),9);
	}
	{
		int dARRAY[] = {1,3,5,5,5,5,64,4,23,2,3,4,5,4,3};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		PotentialGeometricSequence theObject;
		eq(4, theObject.numberOfSubsequences(d),37);
	}
	return 0;
}
// END CUT HERE
