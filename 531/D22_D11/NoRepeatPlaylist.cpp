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
const int MOD = 1000000007;
long long dp[101][101];

class NoRepeatPlaylist {
public:
	int N, M, P;

	long long rec(int x, int kinds)
	{
		// base case
		if (x == P + 1) {
			if (N == kinds) {
				return 1;
			} else {
				return 0;
			}
		}

		long long & res = dp[x][kinds];
		if (res != -1LL) {
			return res;
		}

		res = 0;

		// have no possible to play all N songs
		if (kinds + P - x + 1 < N) {
			return res;
		}
		
		// repeat play a song
		if (kinds > M) {
			res += (kinds - M) * rec(x + 1, kinds);
			res %= MOD;
		}

		// play a new song
		if (N > kinds) {
 			res += (N - kinds) * rec(x + 1, kinds + 1);
			res %= MOD;
		}
		return res;
	}

	int numPlaylists(int N, int M, int P) {
		long long res = 0;
		this->N = N;
		this->M = M;
		this->P = P;
		
		memset(dp, -1LL, sizeof(dp));

		res = rec(1, 0);
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
		NoRepeatPlaylist theObject;
		eq(0, theObject.numPlaylists(1, 0, 2),1);
	}
	{
		NoRepeatPlaylist theObject;
		eq(1, theObject.numPlaylists(1, 1, 3),0);
	}
	{
		NoRepeatPlaylist theObject;
		eq(2, theObject.numPlaylists(2, 0, 3),6);
	}
	{
		NoRepeatPlaylist theObject;
		eq(3, theObject.numPlaylists(4, 0, 4),24);
	}
	{
		NoRepeatPlaylist theObject;
		eq(4, theObject.numPlaylists(2, 1, 4),2);
	}
	{
		NoRepeatPlaylist theObject;
		eq(5, theObject.numPlaylists(50, 5, 100),222288991);
	}
	return 0;
}
// END CUT HERE
