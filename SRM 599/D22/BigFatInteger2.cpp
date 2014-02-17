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

class BigFatInteger2 {
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

	string isDivisible(int A, int B, int C, int D) {
		auto ap = extractPrimeFactors(A);
		auto cp = extractPrimeFactors(C);
		for (auto it = cp.begin(); it != cp.end(); it++) {
			if (ap[ (*it).first ] * B < (*it).second * D) {
				return "not divisible";
			}
		}
		return "divisible";
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		BigFatInteger2 theObject;
		eq(0, theObject.isDivisible(735134400, 1000000000, 64, 1000000000),"divisible");
	}
	{
		BigFatInteger2 theObject;
		eq(1, theObject.isDivisible(2, 1, 6, 1),"not divisible");
	}
	{
		BigFatInteger2 theObject;
		eq(2, theObject.isDivisible(1000000000, 1000000000, 1000000000, 200000000),"divisible");
	}
	{
		BigFatInteger2 theObject;
		eq(3, theObject.isDivisible(8, 100, 4, 200),"not divisible");
	}
	{
		BigFatInteger2 theObject;
		eq(4, theObject.isDivisible(999999937, 1000000000, 999999929, 1),"not divisible");
	}
	{
		BigFatInteger2 theObject;
		eq(5, theObject.isDivisible(2, 2, 4, 1),"divisible");
	}
}
// END CUT HERE
