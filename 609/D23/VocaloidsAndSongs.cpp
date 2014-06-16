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
int dp[51][51][51][51];
int d1[] = {1, 0, 1, 0, 1, 0, 1};
int d2[] = {0, 1, 1, 0, 0, 1, 1};
int d3[] = {0, 0, 0, 1, 1, 1, 1};
const int MOD = 1e9 + 7;
class VocaloidsAndSongs {
public:
	int S, gumi, ia, mayu;
	int rec(int cur, int v1, int v2, int v3)
	{
		if (cur == S) { 
			if (v1 == gumi && v2 == ia && v3 == mayu) {
				return 1;
			} else {
				return 0;
			}
		}
		int & res = dp[cur][v1][v2][v3];
		if (res != -1) {
			return res;
		}
		res = 0;
		for (int i = 0; i < 7; i++) {
			int t1 = v1 + d1[i];
			int t2 = v2 + d2[i];
			int t3 = v3 + d3[i];
			if (t1 > gumi || t2 > ia || t3 > mayu) {
				continue;
			} else {
				res += rec(cur + 1, t1, t2, t3);
				res %= MOD;
			}
		}
		return res;
	}
	int count(int S, int gumi, int ia, int mayu) {
		this->S = S;
		this->gumi = gumi;
		this->ia = ia;
		this->mayu = mayu;
		memset(dp, -1, sizeof(dp));
		return rec(0, 0, 0, 0);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		VocaloidsAndSongs theObject;
		eq(0, theObject.count(3, 1, 1, 1),6);
	}
	{
		VocaloidsAndSongs theObject;
		eq(1, theObject.count(3, 3, 1, 1),9);
	}
	{
		VocaloidsAndSongs theObject;
		eq(2, theObject.count(50, 10, 10, 10),0);
	}
	{
		VocaloidsAndSongs theObject;
		eq(3, theObject.count(18, 12, 8, 9),81451692);
	}
	{
		VocaloidsAndSongs theObject;
		eq(4, theObject.count(50,25,25,25), 198591037);
	}
}
// END CUT HERE
