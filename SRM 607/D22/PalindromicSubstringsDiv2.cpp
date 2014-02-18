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

#include<ctime>

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

bool dp[5000][5001];

class PalindromicSubstringsDiv2 {
public:
    int count(vector <string> S1, vector <string> S2) {
        memset(dp, 0, sizeof(dp));
	int res = 0;
	string S;
	for (int i = 0; i < S1.size(); i++) {
		S += S1[i];
	}
	for (int i = 0; i < S2.size(); i++) {
		S += S2[i];
	}
	int N = S.size();

	for (int i = 0; i < N; i++) {
		dp[i][i] = true;
		++res;
	}
	for (int len = 2; len <= N; len++) {
		for (int i = 0; i <= N - len; i++) {
			if (S[i] == S[i + len - 1]) {
				if (len == 2 || dp[i+1][i + len - 2] == true) {
					dp[i][i+ len - 1] = true;
					++res;
				}

			}
		}
	}

        return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string S1ARRAY[] = {"a","a",""};
        vector <string> S1( S1ARRAY, S1ARRAY+ARRSIZE(S1ARRAY) );
        string S2ARRAY[] = {"a"};
        vector <string> S2( S2ARRAY, S2ARRAY+ARRSIZE(S2ARRAY) );
        PalindromicSubstringsDiv2 theObject;
        eq(0, theObject.count(S1, S2),6);
    }
    {
        string S1ARRAY[] = {"zaz"};
        vector <string> S1( S1ARRAY, S1ARRAY+ARRSIZE(S1ARRAY) );
        PalindromicSubstringsDiv2 theObject;
        eq(1, theObject.count(S1, vector <string>()),4);
    }
    {
        string S1ARRAY[] = {"top"};
        vector <string> S1( S1ARRAY, S1ARRAY+ARRSIZE(S1ARRAY) );
        string S2ARRAY[] = {"coder"};
        vector <string> S2( S2ARRAY, S2ARRAY+ARRSIZE(S2ARRAY) );
        PalindromicSubstringsDiv2 theObject;
        eq(2, theObject.count(S1, S2),8);
    }
    {
	    string S2ARRAY[] = {"daata"};
	    vector <string> S2( S2ARRAY, S2ARRAY+ARRSIZE(S2ARRAY) );
        PalindromicSubstringsDiv2 theObject;
        eq(3, theObject.count(vector <string>(), S2),7);
    }
}
// END CUT HERE
