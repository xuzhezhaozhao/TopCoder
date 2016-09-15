#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
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
int dp[31][31][31];
class ShopPositions {
public:
	int n, m;
	vector <int> c;
	int solve(int a, int b, int k) {
		if (k == n) {
			// end
			if (a+b == 0) {
				return 0;
			}
			return b*c[3*(n-1)*m + a+b-1];
		}
		int & ans = dp[a][b][k];
		if (ans != -1) {
			return ans;
		}
		ans = 0;
		for (int ck = 0; ck <= m; ck++) {
			ans = max(ans, b*c[3*(k-1)*m + a+b+ck-1] + solve(b, ck, k+1));
		}
		return ans;
	}

    int maxProfit(int n, int m, vector <int> c) {
		this->n = n;
		this->m = m;
		this->c = c;
		memset(dp, -1, sizeof(dp));

		if (n == 1) {
			int p = 0;
			for (int i = 1; i <= m; i++) {
				p = max(p, i * c[i-1]);
			}
			return p;
		}

		int res = 0;
		for (int a = 0; a <= m; a++) {
			for (int b = 0; b <= m; b++) {
				if (a + b == 0) {
					continue;
				}
				int p = a*c[a+b-1];
				res = max(res, p + solve(a, b, 2));
			}
		}

		return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int cARRAY[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 1, 1, 1, 1, 1};
        vector <int> c( cARRAY, cARRAY+ARRSIZE(cARRAY) );
        ShopPositions theObject;
        eq(0, theObject.maxProfit(1, 5, c),300);
    }
    {
        int cARRAY[] = {1000, 5, 4, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        vector <int> c( cARRAY, cARRAY+ARRSIZE(cARRAY) );
        ShopPositions theObject;
        eq(1, theObject.maxProfit(1, 5, c),1000);
    }
    {
        int cARRAY[] = {
             7,6,1,
             10,4,1,
             7,6,3
           };
        vector <int> c( cARRAY, cARRAY+ARRSIZE(cARRAY) );
        ShopPositions theObject;
        eq(2, theObject.maxProfit(3, 1, c),14);
    }
    {
        int cARRAY[] = {
            12,11,10,9,8,7,
            6,5,4,3,2,1
           };
        vector <int> c( cARRAY, cARRAY+ARRSIZE(cARRAY) );
        ShopPositions theObject;
        eq(3, theObject.maxProfit(2, 2, c),24);
    }
    {
        int cARRAY[] = {
             30,28,25,15,14,10,5,4,2,
             50,40,30,28,17,13,8,6,3,
             45,26,14,14,13,13,2,1,1
           };
        vector <int> c( cARRAY, cARRAY+ARRSIZE(cARRAY) );
        ShopPositions theObject;
        eq(4, theObject.maxProfit(3, 3, c),127);
    }
  return 0;
}
// END CUT HERE
