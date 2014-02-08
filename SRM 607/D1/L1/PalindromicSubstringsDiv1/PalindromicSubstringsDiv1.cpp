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
double dp[5001][5001];

class PalindromicSubstringsDiv1 {
public:
    double expectedPalindromes(vector <string> S1, vector <string> S2) {
        double res = 0;
	memset(dp, 0, sizeof(dp));
	string S;
	for (int i = 0; i < S1.size(); i++) {
		S += S1[i];
	}
	for (int i = 0; i < S2.size(); i++) {
		S += S2[i];
	}
	int N = S.size();
	for (int i = 0; i < N; i++) {
		dp[i][i] = 1.0;
		res += 1.0;
	}
	for (int len = 2; len <= N; len++) {
		for (int i = 0; i <= N - len; i++) {
			int marks = 0;
			if (S[i] == '?') {
				++marks;
			}
			if (S[i + len - 1] == '?') {
				++marks;
			}
			if (2 == len) {
				if (0 == marks && S[i] == S[i + len - 1]) {
					dp[i][i + len - 1] = 1.0;
				} else if (0 != marks) {
					dp[i][i + len - 1] = 1.0 / 26.0;
				}
			} else {
				if (0 == marks && S[i] == S[i + len - 1]) {
					dp[i][i + len - 1] = dp[i+1][i + len - 2];					
				} else if (0 != marks) {
					dp[i][i + len - 1] = (1.0 / 26.0) * dp[i+1][i + len - 2];
				}
			}
			res += dp[i][i + len - 1];
		}
	}
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string S1ARRAY[] = {"abccb"};
        vector <string> S1( S1ARRAY, S1ARRAY+ARRSIZE(S1ARRAY) );
        string S2ARRAY[] = {"a"};
        vector <string> S2( S2ARRAY, S2ARRAY+ARRSIZE(S2ARRAY) );
        PalindromicSubstringsDiv1 theObject;
        eq(0, theObject.expectedPalindromes(S1, S2),9.0);
    }
    {
        string S1ARRAY[] = {"z??"};
        vector <string> S1( S1ARRAY, S1ARRAY+ARRSIZE(S1ARRAY) );
        PalindromicSubstringsDiv1 theObject;
        eq(1, theObject.expectedPalindromes(S1, vector <string>()),3.115384615384615);
    }
    {
        string S1ARRAY[] = {"ab","c"};
        vector <string> S1( S1ARRAY, S1ARRAY+ARRSIZE(S1ARRAY) );
        string S2ARRAY[] = {"??","a?"};
        vector <string> S2( S2ARRAY, S2ARRAY+ARRSIZE(S2ARRAY) );
        PalindromicSubstringsDiv1 theObject;
        eq(2, theObject.expectedPalindromes(S1, S2),7.315088757396449);
    }
    {
        string S2ARRAY[] = {"?"};
        vector <string> S2( S2ARRAY, S2ARRAY+ARRSIZE(S2ARRAY) );
        PalindromicSubstringsDiv1 theObject;
        eq(3, theObject.expectedPalindromes(vector <string>(), S2),1.0);
    }
    {
        string S1ARRAY[] = {"ab?def","?"};
        vector <string> S1( S1ARRAY, S1ARRAY+ARRSIZE(S1ARRAY) );
        string S2ARRAY[] = {"f??a"};
        vector <string> S2( S2ARRAY, S2ARRAY+ARRSIZE(S2ARRAY) );
        PalindromicSubstringsDiv1 theObject;
        eq(4, theObject.expectedPalindromes(S1, S2),12.545971779699588);
    }
}
// END CUT HERE
