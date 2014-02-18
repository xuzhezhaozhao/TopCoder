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

/*************** Program Begin **********************/
const int MOD = 1000000007;  
const int MAX_N = 50;
const int MAX_K = 10;
int dp[2 * MAX_N + 1][2 * MAX_N + 1][1 << MAX_K];

class AlienAndSetDiv1 {
public:
	int K;
	int calc(int s, int g, int n)
	{
		int res = 0;
		if (-1 != dp[n][g][s]) {
			return dp[n][g][s];
		}
		if (n == 0) {
			if (0 == s && 0 == g) {		// base case
				res = 1;
			}
		} else {
			if (0 == s && 0 == g) {
				if (1 == K) {
					res += 2 * calc(0, 1, n-1);	// add
				} else {
					res += 2 * calc(1, 0, n-1);	// add
				}
				res %= MOD;
			} else if (0 == s && g != 0) {
				res += calc(0, g-1, n-1);	// match
				if (1 == K) {
					res += calc(0, g+1, n-1);	// add
				} else {
					res += calc(1, g, n-1);	// add
				}
				res %= MOD;
			} else if (s != 0 && 0 == g) {		// K != 1，只能add
				int newset = s;
				int i = 0;  
				for (i = 0; (newset & 0x80000000 ) == 0; newset = ( newset << 1 ), ++i) {  
					// 注意位操作的优先级，要加括号
				}  
				int mx = 31 - i;    // mx 为s不为0的最高位
				if (n + mx + 1 - (n - 1) >= K) {	// g -> 1
					int t = (s - (1 << mx));	// 清除mx位
					res += calc( (t << 1) | 1, 1, n - 1 );	// add
					res %= MOD;
				} else {
					res += calc( (s << 1) | 1, 0, n - 1 );	// add
					res %= MOD;
				}
			} else {	// s != 0 && 0 != g	// K != 1
				int newset = s;
				int i = 0;  
				for (i = 0; (newset & 0x80000000 ) == 0; newset = ( newset << 1 ), ++i) {
				}  
				int mx = 31 - i;    // mx 为s不为0的最高位

				if ( n + mx + 1 - (n - 1) >= K) {	// 判断是否使g变化
					int t = (s - (1 << mx));
					res += calc(t << 1, g, n-1);	// match
					res += calc( (t << 1) | 1, g+1, n - 1 ); // add
				} else {
					res += calc(s << 1, g-1, n-1);	// match
					res += calc( (s << 1) | 1, g, n - 1 );	// add
				}
				res %= MOD;
			}
		}

		dp[n][g][s] = res;
		return res;
	}

	int getNumber(int N, int K) {
		int res = 0;
		this->K = K;
		memset(dp, -1, sizeof(dp));
		res = calc(0, 0, 2 * N);
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        AlienAndSetDiv1 theObject;
        eq(0, theObject.getNumber(2, 2),2);
    }
    {
        AlienAndSetDiv1 theObject;
        eq(1, theObject.getNumber(3, 1),20);
    }
    {
        AlienAndSetDiv1 theObject;
        eq(2, theObject.getNumber(4, 2),14);
    }
    {
        AlienAndSetDiv1 theObject;
        eq(3, theObject.getNumber(10, 7),40);
    }
}
// END CUT HERE
