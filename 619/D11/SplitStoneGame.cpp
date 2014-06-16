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

class SplitStoneGame {
public:
    string winOrLose(vector <int> number) {
	int N = number.size();
	bool ok = false;
	for (int i = 0; i < N; i++) {
		if (number[i] > 1) {
			ok = true;
			break;
		}
	}
	if (!ok) {
		return "LOSE";	
	}
	if (N < 3) {
		return "LOSE";
	}
	return (N % 2 == 0 ? "LOSE" : "WIN");
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int numberARRAY[] = {1, 1, 1};
        vector <int> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        SplitStoneGame theObject;
        eq(0, theObject.winOrLose(number),"LOSE");
    }
    {
        int numberARRAY[] = {2, 2};
        vector <int> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        SplitStoneGame theObject;
        eq(1, theObject.winOrLose(number),"LOSE");
    }
    {
        int numberARRAY[] = {1, 1, 2};
        vector <int> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        SplitStoneGame theObject;
        eq(2, theObject.winOrLose(number),"WIN");
    }
    {
        int numberARRAY[] = {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1};
        vector <int> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        SplitStoneGame theObject;
        eq(3, theObject.winOrLose(number),"WIN");
    }
    {
        int numberARRAY[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1};
        vector <int> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        SplitStoneGame theObject;
        eq(4, theObject.winOrLose(number),"LOSE");
    }
	return 0;
}
// END CUT HERE
