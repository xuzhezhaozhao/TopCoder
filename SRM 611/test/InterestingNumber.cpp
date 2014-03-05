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

class InterestingNumber {
public:
    string isInteresting(string x) {
        string res;
	for (int i = '0'; i <= '9'; i++) {
		int cnt = count(x.begin(), x.end(), i);
		if (cnt != 0 && cnt != 2) {
			return "Not interesting";
		}
		if (cnt == 2) {
			int first = x.find(i);
			int second = x.find(i, first + 1);
			if (second - first - 1 != i - '0') {
				return "Not interesting";
			}
		}
	}
	res = "Interesting";
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        InterestingNumber theObject;
        eq(0, theObject.isInteresting("2002"),"Interesting");
    }
    {
        InterestingNumber theObject;
        eq(1, theObject.isInteresting("1001"),"Not interesting");
    }
    {
        InterestingNumber theObject;
        eq(2, theObject.isInteresting("41312432"),"Interesting");
    }
    {
        InterestingNumber theObject;
        eq(3, theObject.isInteresting("611"),"Not interesting");
    }
    {
        InterestingNumber theObject;
        eq(4, theObject.isInteresting("64200246"),"Interesting");
    }
    {
        InterestingNumber theObject;
        eq(5, theObject.isInteresting("631413164"),"Not interesting");
    }
}
// END CUT HERE
