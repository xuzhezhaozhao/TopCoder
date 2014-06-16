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
    
    cerr << "Case " << n << " passed." << endl;
	}
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
const int MOD = 1000000007;
const int MAX_N = 5001;
const int MAX_M = 51;
long long dp[MAX_N][MAX_M][MAX_M];

class AlternativePiles {
public:
	string C;
	int M;
	long long rec(int cur, int balance, int matches)
	{
		long long & res = dp[cur][balance][matches];
		if (-1 != res) {
			return res;
		}

		if (cur == C.size()) {  		// base case
			if (0 == balance && 0 == matches) {
				res = 1;
				return res;
			} else {
				res = 0;
				return res;
			}
		}
		res = 0;
		char x = C[cur];
		if ('R' == x || 'W' == x) {
			if (balance < M) {
				res += rec(cur + 1, balance + 1, matches);
			}
		} 
		if ('G' == x || 'W' == x) {
			if (balance > 0) {
				res += rec(cur + 1, balance - 1, (matches + 1) % M);
			}
		} 
		if ('B' == x || 'W' == x) {
			res += rec(cur + 1, balance, matches);
		}
		res %= MOD;

		return res;
	}
    int count(string C, int M) {
        int res = 0;
	this->C = C;
	this->M = M;	

	memset(dp, -1, sizeof(dp));
	res = rec(0, 0, 0);

	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        AlternativePiles theObject;
        eq(0, theObject.count("WRGWWRGW", 2),3);
        eq(0, theObject.count("WRBBGBWRWWWWBWWWBGBGWRRRWWRWWRWBBWRWBBRGGBWRBWBBWWBGWWWWWWGBWGBWWWWRWWGBRWBBRWGRWWWGWWWWWBWGWWWGGBBWWGBWRWGRWGRBWRBWGWWWBWGBBRGRWBWBRWBGWWWGGWGRRWRWBGBWBWGWWWRRWWWWRBWWBWWWGGWGGWWBBRRBRBRWWRWWBWRRBWWRGGRWRWBRWWRWWGGGWGWWRRGBRGGRWBWRWRRRWWWWGGWWWGGWWBWWWRWWWRWBWWGWWRGWWWBGWGWRRRBGRWWWBRWWRRGWWWWWWWWBWBWGGWBWWWRRWWWWWRWBWWGRWWWGWGWGBGBBWBWGBWWRRBBWBWBBGGWWWGWWRGBGRBGBGBWWBBGGRWWGGWRRWWWWGBGWRGRRWWWRWGWGWBRBWWWWRWWWWBGWWGBRGBGGRGWWGWWWWRRWWWWBBWWWWRGGRWBBRGWBWRWRBWWGGWWWWRWWWBBWRWGWBGWRWWWWBWRGWWRWWGBWWGGWWWRWBBWBWBGRWRGRRRRRWGGWWBWWGBGWWGRWWGRGGBWRWRGWWGWWRGGWGBWWWRWWWBWRWGGGWGWWBGBWWWRWWBWWGRWWB", 10),951122960);
    }
    {
        AlternativePiles theObject;
        eq(1, theObject.count("RRGG", 1),0);
    }
    {
        AlternativePiles theObject;
        eq(2, theObject.count("BBBB", 5),1);
    }
    {
        AlternativePiles theObject;
        eq(3, theObject.count("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", 50),265470435);
    }
    {
        AlternativePiles theObject;
        eq(4, theObject.count("WRWRGWWGWWWRWBWRWGWWRWBWWRGWBWGRGWWGWGRWGRWBRWBW", 7),7400348);
    }
	return 0;
}
// END CUT HERE
