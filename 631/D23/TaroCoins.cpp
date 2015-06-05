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
long long dp[64][3];

class TaroCoins {
public:
	vector <int> bits;
	long long rec(int x, int req)
	{
		// base case
		if (x == -1) {
			if (req != 0) {
				return 0;
			}
			return 1;
		}
		
		long long & res = dp[x][req];
		if (res != -1) {
			return res;
		}

		res = 0;
		if (bits[x]) {
			if (req == 2) {
				res = rec(x - 1, 2);
			} else {
				res = rec(x - 1, 0) + rec(x - 1, 2);
			}
		} else {
			if (req == 2) {
				res = rec(x - 1, 0) + rec(x - 1, 2);
			} else {
				res = rec(x - 1, 0);
			}
		}

		return res;
	}
	long long getNumber(long long N) {
		long long res = 0;
	
		for (int i = 0; i < 63; i++) {
			bits.push_back( (N >> i) & 0x1 );
		}

		memset(dp, -1, sizeof(dp));

		res = rec( bits.size() - 1, 0 );

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
		TaroCoins theObject;
		eq(0, theObject.getNumber(4LL),3LL);
	}
	{
		TaroCoins theObject;
		eq(1, theObject.getNumber(6L),3LL);
	}
	{
		TaroCoins theObject;
		eq(2, theObject.getNumber(47L),2LL);
	}
	{
		TaroCoins theObject;
		eq(3, theObject.getNumber(256L),9LL);
	}
	{
		TaroCoins theObject;
		eq(4, theObject.getNumber(8489289L),6853LL);
	}
	{
		TaroCoins theObject;
		eq(5, theObject.getNumber(1000000000L),73411LL);
	}
	return 0;
}
// END CUT HERE
