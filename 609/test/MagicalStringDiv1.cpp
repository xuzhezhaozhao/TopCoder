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

/*************** Program Begin **********************/
int cnt1[55];
int cnt2[55];
class MagicalStringDiv1 {
public:
    int getLongest(string S) {
        int res = 0;
	memset(cnt1, 0, sizeof(cnt1));
	memset(cnt2, 0, sizeof(cnt2));
	int n = S.size();
	cnt1[0] = (S[0] == '>');
	for (int i = 1; i < n; i++) {
		if ('>' == S[i]) {
			cnt1[i] = cnt1[i-1] + 1;
		} else {
			cnt1[i] = cnt1[i-1];
		}
	}
	cnt2[n-1] = (S[n-1] == '<');
	for (int i = n - 2; i >= 0; i--) {
		if ('<' == S[i]) {
			cnt2[i] = cnt2[i + 1] + 1;
		} else {
			cnt2[i] = cnt2[i + 1];
		}
	}
	for (int h = n / 2; h >= 0; h--) {
		for (int i = 0; i < n; i++) {
			if (cnt1[i] >= h && cnt2[i+1] >= h) {
				return h * 2;
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
        MagicalStringDiv1 theObject;
        eq(0, theObject.getLongest("<><><<>"),4);
    }
    {
        MagicalStringDiv1 theObject;
        eq(1, theObject.getLongest(">>><<<"),6);
    }
    {
        MagicalStringDiv1 theObject;
        eq(2, theObject.getLongest("<<<>>>"),0);
    }
    {
        MagicalStringDiv1 theObject;
        eq(3, theObject.getLongest("<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"),24);
    }
}
// END CUT HERE
