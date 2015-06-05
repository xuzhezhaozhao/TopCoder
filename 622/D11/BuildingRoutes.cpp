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
int g[55][55];
int cost[55][55];
int cover[55][55];
class BuildingRoutes {
public:
	int build(vector <string> dist, int T) {
		int res = 0;
		int n = dist.size();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = dist[i][j] - '0';
				cost[i][j] = g[i][j];
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
				}
			}
		}
		memset(cover, 0, sizeof(cover));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int x = 0; x < n; x++) {
					for (int y = 0; y < n; y++) {
						if (cost[x][i] + g[i][j] + cost[j][y] == cost[x][y]) {
							++cover[i][j];
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cover[i][j] >= T) {
					res += g[i][j];
				}
			}
		}

		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		string distARRAY[] = {"011",
			"101",
			"110"};
		vector <string> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
		BuildingRoutes theObject;
		eq(0, theObject.build(dist, 1),6);
	}
	{
		string distARRAY[] = {"033",
			"309",
			"390"};
		vector <string> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
		BuildingRoutes theObject;
		eq(1, theObject.build(dist, 1),12);
	}
	{
		string distARRAY[] = {"0123",
			"1023",
			"1203",
			"1230"};
		vector <string> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
		BuildingRoutes theObject;
		eq(2, theObject.build(dist, 2),5);
	}
	{
		string distARRAY[] = {"05789654",
			"10347583",
			"65085479",
			"55602398",
			"76590934",
			"57939045",
			"12345608",
			"68647640"};
		vector <string> dist( distARRAY, distARRAY+ARRSIZE(distARRAY) );
		BuildingRoutes theObject;
		eq(3, theObject.build(dist, 3),40);
	}
	return 0;
}
// END CUT HERE
