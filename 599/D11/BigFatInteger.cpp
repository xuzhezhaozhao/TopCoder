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

/*************** Program Begin **********************/

class BigFatInteger {
public:
	map < long long, long long > extractPrimeFactors(int x)
	{
		map <long long, long long> ap;
		for (int p = 2; p * p <= x; p++) {
			int ex = 0;
			bool flag = false;
			while (x % p == 0) {
				flag = true;
				++ex;
				x /= p;
			}
			if (flag) {
				ap[p] = ex;
			}
		}
		if (x != 1) {
			ap[x] = 1;
		}
		return ap;
	}
	int minOperations(int A, int B) {
		int res = 0;
		auto ap = extractPrimeFactors(A);
		res = ap.size();
		int mxex = 0;
		for (auto it = ap.begin(); it != ap.end(); it++) {
			if (mxex < (*it).second) {
				mxex = (*it).second;
			}
		}
		for (int i = 1; i < mxex * B; i *= 2) {
			++res;
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		BigFatInteger theObject;
		eq(0, theObject.minOperations(6, 1),2);
	}
	{
		BigFatInteger theObject;
		eq(1, theObject.minOperations(162, 1),4);
	}
	{
		BigFatInteger theObject;
		eq(2, theObject.minOperations(999983, 9),5);
	}
	{
		BigFatInteger theObject;
		eq(3, theObject.minOperations(360, 8),8);
	}
}
// END CUT HERE
