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
int dp[1005];
class EmoticonsDiv1 {
public:
	int rec(int smiles)
	{
		int & res = dp[smiles];
		if (res != -1) {
			return res;
		}
		if (1 == smiles) {
			res = 0;
			return res;
		}
		res = 10000000;
		for (int i = 1; i < smiles; i++) {
			res = min( res, rec(i) + (smiles + i - 1) / i + (smiles % i == 0 ? 0 : i - smiles % i) );
		}
		return res;
	}
	int printSmiles(int smiles) {
		memset(dp, -1, sizeof(dp));
		int res = rec(smiles);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		EmoticonsDiv1 theObject;
		eq(0, theObject.printSmiles(2),2);
	}
	{
		EmoticonsDiv1 theObject;
		eq(1, theObject.printSmiles(4),4);
	}
	{
		EmoticonsDiv1 theObject;
		eq(2, theObject.printSmiles(6),5);
	}
	{
		EmoticonsDiv1 theObject;
		eq(3, theObject.printSmiles(18),8);
	}
	{
		EmoticonsDiv1 theObject;
		eq(4, theObject.printSmiles(11),8);
	}
}
// END CUT HERE
