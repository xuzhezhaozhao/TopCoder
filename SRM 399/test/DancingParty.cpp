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

/*************** Program Begin **********************/

class DancingParty {
public:
    int maxDances(vector <string> likes, int k) {
        int res = 0;
	int n = likes.size();
	res = n;
	for (int i = 0; i < n; i++) {
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < n; j++) {
			if (likes[i][j] == 'Y') {
				++cnt1;
			}
			if (likes[j][i] == 'Y') {
				++cnt2;
			}
		}
		res = min(res, cnt1);
		res = min(res, cnt2);
	}
        return min(n, res + k);
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string likesARRAY[] = {"YYY", "YYY", "YYY"};
        vector <string> likes( likesARRAY, likesARRAY+ARRSIZE(likesARRAY) );
        DancingParty theObject;
        eq(0, theObject.maxDances(likes, 0),3);
    }
    {
        string likesARRAY[] = {"YYY", "YYN", "YNY"};
        vector <string> likes( likesARRAY, likesARRAY+ARRSIZE(likesARRAY) );
        DancingParty theObject;
        eq(1, theObject.maxDances(likes, 0),2);
    }
    {
        string likesARRAY[] = {"YN", "YN"};
        vector <string> likes( likesARRAY, likesARRAY+ARRSIZE(likesARRAY) );
        DancingParty theObject;
        eq(2, theObject.maxDances(likes, 0),0);
    }
    {
        string likesARRAY[] = {"YN", "YN"};
        vector <string> likes( likesARRAY, likesARRAY+ARRSIZE(likesARRAY) );
        DancingParty theObject;
        eq(3, theObject.maxDances(likes, 1),1);
    }
}
// END CUT HERE
