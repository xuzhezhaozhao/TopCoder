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

int dp[2005][2005][2];

class SingingEasy {
public:
	vector <int> pitch;
	int N;
    int solve(vector <int> pitch) {
		this->pitch = pitch;
        int res = 0;
		N = pitch.size();
		memset(dp, -1, sizeof(dp));
		res = rec(1, 2002, 1);
        return res;
    }
	int rec(int p, int last, int first) {
		if (p == N) {
			return 0;
		}
		if (dp[p][last][first] != -1) {
			return dp[p][last][first];
		}
		int & ans = dp[p][last][first];
		ans = INT_MAX;

		// first man sing
		if (1 == first) {
			ans = min(ans, abs(pitch[p] - pitch[p-1]) + rec(p + 1, last, 1));
		} else {
			if (last == 2002) {
				ans = min(ans, rec(p + 1, p - 1, 1));
			} else {
				ans = min(ans, abs(pitch[p] - pitch[last]) + rec(p + 1, p - 1, 1));
			}
		}
		
		// second man sing
		if (1 == first) {
			if (last == 2002) {
				ans = min(ans, rec(p + 1, p - 1, 0));
			} else {
				ans = min(ans, abs(pitch[p] - pitch[last]) + rec(p + 1, p - 1, 0));
			}
		} else {
			ans = min(ans, abs(pitch[p] - pitch[p-1]) + rec(p + 1, last, 0));
		}
		return ans;
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
        int pitchARRAY[] = {1,3,8,12,13};
        vector <int> pitch( pitchARRAY, pitchARRAY+ARRSIZE(pitchARRAY) );
        SingingEasy theObject;
        eq(0, theObject.solve(pitch),7);
    }
    {
        int pitchARRAY[] = {1,5,6,2,1};
        vector <int> pitch( pitchARRAY, pitchARRAY+ARRSIZE(pitchARRAY) );
        SingingEasy theObject;
        eq(1, theObject.solve(pitch),3);
    }
    {
        int pitchARRAY[] = {5,5,5,5,4,4,4,4};
        vector <int> pitch( pitchARRAY, pitchARRAY+ARRSIZE(pitchARRAY) );
        SingingEasy theObject;
        eq(2, theObject.solve(pitch),0);
    }
    {
        int pitchARRAY[] = {1000000};
        vector <int> pitch( pitchARRAY, pitchARRAY+ARRSIZE(pitchARRAY) );
        SingingEasy theObject;
        eq(3, theObject.solve(pitch),0);
    }
    {
        int pitchARRAY[] = {24,13,2,4,54,23,12,53,12,23,42,13,53,12,24,12,11,24,42,52,12,32,42};
        vector <int> pitch( pitchARRAY, pitchARRAY+ARRSIZE(pitchARRAY) );
        SingingEasy theObject;
        eq(4, theObject.solve(pitch),188);
    }
	return 0;
}
// END CUT HERE
