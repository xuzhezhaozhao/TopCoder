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

int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

class AnArray {
public:
	vector <int> A;
	map<int, int> dp[2001][4];
	int f(int n, int t, int d) {
		// base case
		if (n == 0) {
			if (t == 0 && d == 1) {
				return 1;
			}
			return 0;
		}
		if (t == 0) {
			if (d == 1) {
				return 1;
			} else {
				return 0;
			}
		}

		if (dp[n][t].find(d) != dp[n][t].end()) {
			return dp[n][t][d];
		}
		// include A[n-1]
		dp[n][t][d] = f(n-1, t-1, d / gcd(A[n-1], d));
		// not include A[n-1]
		dp[n][t][d] += f(n-1, t, d);
		return dp[n][t][d];
	}

    int solveProblem(vector <int> A, int K) {
		this->A = A;
        int res = 0;
		int n = A.size();
		res = f(n, 3, K);
        return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int AARRAY[] = {31, 1, 3, 7, 2, 5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        AnArray theObject;
        eq(0, theObject.solveProblem(A, 30),1);
    }
    {
        int AARRAY[] = {4, 5, 2, 25};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        AnArray theObject;
        eq(1, theObject.solveProblem(A, 100),2);
    }
    {
        int AARRAY[] = {100000000, 100000000, 100000000};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        AnArray theObject;
        eq(2, theObject.solveProblem(A, 1000000),1);
    }
    {
        int AARRAY[] = {269, 154, 94, 221, 171, 154, 50, 210, 258, 358, 121, 159, 8, 47, 290, 125, 291, 293, 338, 248, 295, 160, 268, 227, 99, 4, 273};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        AnArray theObject;
        eq(3, theObject.solveProblem(A, 360),114);
    }
    {
        int AARRAY[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        AnArray theObject;
        eq(4, theObject.solveProblem(A, 1),220);
    }
  return 0;
}
// END CUT HERE
