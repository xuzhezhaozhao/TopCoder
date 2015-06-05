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

class EllysScrabble {
public:
    string getMin(string letters, int maxDistance) {
        string res;
	int N = letters.size();
	bool used[55];
	memset(used, 0, sizeof(used));	
	for (int i = 0; i < letters.size(); i++) {
		int best = 'Z' + 1;
		int index = -1;
		for (int j = max(0, i - maxDistance); j <= min(N - 1, i + maxDistance); j++) {
			if (used[j] || letters[j] >= best) {
				continue;	
			}		
			best = letters[j];
			index = j;
		}
		if (i - maxDistance >= 0 && !used[i - maxDistance]) {
			index = i - maxDistance;	
			best = letters[index];
		}

		used[index] = true;
		res.push_back(best);
	}
	
        return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        EllysScrabble theObject;
        eq(0, theObject.getMin("TOPCODER", 3),"CODTEPOR");
    }
    {
        EllysScrabble theObject;
        eq(1, theObject.getMin("ESPRIT", 3),"EIPRST");
    }
    {
        EllysScrabble theObject;
        eq(2, theObject.getMin("BAZINGA", 8),"AABGINZ");
    }
    {
        EllysScrabble theObject;
        eq(3, theObject.getMin("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 9),"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    }
    {
        EllysScrabble theObject;
        eq(4, theObject.getMin("GOODLUCKANDHAVEFUN", 7),"CADDGAHEOOFLUKNNUV");
    }
    {
        EllysScrabble theObject;
        eq(5, theObject.getMin("AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD", 6),"AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW");
    }
    {
        EllysScrabble theObject;
        eq(6, theObject.getMin("ABRACADABRA", 2),"AABARACBDAR");
    }
	return 0;
}
// END CUT HERE
