#include <algorithm>
#include <iostream>
#include <sstream>

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

int dp[20][20];

class ColorfulRoad {
public:
	int getMin(string road) {
		int res = 0;
		int n = road.size();
		vector <int> v;
		for (int i = 0; i < n; i++) {
			if (road[i] == 'R') {
				v.push_back(0);
			} else if (road[i] == 'G') {
				v.push_back(1);
			} else {
				v.push_back(2);
			}
		}

		memset(dp, -1, sizeof(dp));
		for (int len = 1; len <= n - 1; len++) {
			for (int i = 0; i <= n - len - 1; i++) {
				int & ans = dp[i][i+len];
				if ( (v[i] + 1) % 3 == v[i+len] ) {
					ans = len * len;
				}
				for (int j = i + 1; j < i + len; j++) {
					if (dp[i][j] == -1 || dp[j][i+len] == -1) {
						continue;
					}
					if (ans == -1) {
						ans = dp[i][j] + dp[j][i+len];
					}
					ans = min(ans, dp[i][j] + dp[j][i+len]);
				}
			}
		}
		res = dp[0][n-1];
		return res;
	}
};


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		ColorfulRoad theObject;
		eq(0, theObject.getMin("RGGGB"),8);
	}
	{
		ColorfulRoad theObject;
		eq(1, theObject.getMin("RGBRGBRGB"),8);
	}
	{
		ColorfulRoad theObject;
		eq(2, theObject.getMin("RBBGGGRR"),-1);
	}
	{
		ColorfulRoad theObject;
		eq(3, theObject.getMin("RBRRBGGGBBBBR"),50);
	}
	{
		ColorfulRoad theObject;
		eq(4, theObject.getMin("RG"),1);
	}
	{
		ColorfulRoad theObject;
		eq(5, theObject.getMin("RBRGBGBGGBGRGGG"),52);
	}
}
// END CUT HERE
