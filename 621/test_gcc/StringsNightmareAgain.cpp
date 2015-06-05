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
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/

class StringsNightmareAgain {
public:
	long long UniqueSubstrings(int a, int b, int c, int d, int n) {
		long long res = 0;
		string S = "";
		for (int i = 0; i < n; ++i)
		{
			S.append(1, 'a');
		}
		for (int i = 0; i < a; ++i)
		{
			b = ((long long)b*c+d)%n;
			S[b] = 'b';
		}

		
			return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		StringsNightmareAgain theObject;
		eq(0, theObject.UniqueSubstrings(0, 0, 0, 0, 4),2LL);
	}
	{
		StringsNightmareAgain theObject;
		eq(1, theObject.UniqueSubstrings(2, 3, 1, 1, 6),3LL);
	}
	{
		StringsNightmareAgain theObject;
		eq(2, theObject.UniqueSubstrings(4, 3, 1, 1, 6),3LL);
	}
	{
		StringsNightmareAgain theObject;
		eq(3, theObject.UniqueSubstrings(4, 3, 3, 3, 10),5LL);
	}
	{
		StringsNightmareAgain theObject;
		eq(4, theObject.UniqueSubstrings(5, 3, 2, 3, 11),9LL);
	}
	{
		StringsNightmareAgain theObject;
		eq(5, theObject.UniqueSubstrings(10, 1000000, 1000000, 1, 51),63LL);
	}
	return 0;
}
// END CUT HERE
