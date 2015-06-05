#include <algorithm>
#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <bitset>
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
int dp[2500][2][2];
int c[2][2500];
int N, F;
class FlippingBitsDiv2 {
private:
	int flip(int t, int pre, int allFlipped)
	{
		if (t == F) {
			return allFlipped;
		}
		if (dp[t][pre][allFlipped] != -1) {
			return dp[t][pre][allFlipped];
		}

		int res = 10000000;
		for (int f = 0; f <= 1; f++) {
			int cost = 0;
			cost += c[f][t] + flip(t+1, f, allFlipped && f);
			if (t != 0 && f != pre) {
				++cost;
			}
			res = min(res, cost);
		}
		dp[t][pre][allFlipped] = res;
		return res;
	}
public:
    int getmin(vector <string> S, int M) {
	    string B;
	    for (int i = 0; i < S.size(); i++) {
	    	B += S[i];
	    }
	    N = B.size();
	    F = N / M;
	    memset(c[0], 0, sizeof(c[0]));
	    memset(c[1], 0, sizeof(c[1]));
	    for (int i = 0; i < F; i++) {
	    	for (int j = 0; j < M; j++) {
	    		if (B[i*M + j] == '1') {
	    			++c[1][i];
	    		} else {
				++c[0][i];
			}
	    	}
	    }
	    memset(dp, -1, sizeof(dp));
	    return flip(0, 0, 1);
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	string SARRAY[] = {"00111000"};
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(0, theObject.getmin(S, 1),2);
    }
    {
	string SARRAY[] = {"00111000"};
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(1, theObject.getmin(S, 2),3);
    }
    {
	string SARRAY[] = {"111111"};
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(2, theObject.getmin(S, 3),0);
    }
    {
	string SARRAY[] = {"00100"};
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(3, theObject.getmin(S, 5),2);
    }
    {
	string SARRAY[] = {"00010","11010110","1010111","110001010","0110001100"
	   ,"000110110","011010101","00","111","100"}
	   ;
	vector <string> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
	FlippingBitsDiv2 theObject;
	eq(4, theObject.getmin(S, 13),31);
    }
}
// END CUT HERE
