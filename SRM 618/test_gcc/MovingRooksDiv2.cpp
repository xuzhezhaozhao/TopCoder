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

class MovingRooksDiv2 {
public:
	vector <int> Y1, Y2;
	int N;
	bool rec(int r)
	{
		if (r == N) {
			return true;
		}
		int p1 = -1;
		for (int i = r; i < N; i++) {
			if (Y1[i] == Y2[r] && Y1[r] >= Y1[i]) {
				p1 = i;
				break;
			}
		}
		if (p1 < 0) {
			return false;
		}
		for (int j = r + 1; j <= p1; j++) {
			if (Y1[j] < Y1[r] && Y1[j] > Y1[p1]) {
				int temp = Y1[j];
				Y1[j] = Y1[r];
				int temp2 = Y1[p1];
				Y1[p1] = Y1[j];
				if (rec(r + 1)) {
					return true;
				}
				Y1[j] = temp;
				Y1[p1] = temp2;
			}
		}
		if (p1 == r) {
			if (rec(r + 1))
				return true;
		}
		return false;
	}
    string move(vector <int> Y1, vector <int> Y2) {
	this->N = Y1.size();
	this->Y1 = Y1;
	this->Y2 = Y2;
	if (rec(0)) {
		return "Possible";
	}
	return "Impossible";
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int Y1ARRAY[] = {0};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {0};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(0, theObject.move(Y1, Y2),"Possible");
    }
    {
        int Y1ARRAY[] = {1,0};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {0,1};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(1, theObject.move(Y1, Y2),"Possible");
    }
    {
        int Y1ARRAY[] = {0,1};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {1,0};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(2, theObject.move(Y1, Y2),"Impossible");
    }
    {
        int Y1ARRAY[] = {3,1,2,0};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {0,2,1,3};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(3, theObject.move(Y1, Y2),"Possible");
    }
    {
        int Y1ARRAY[] = {3,1,2,0};
        vector <int> Y1( Y1ARRAY, Y1ARRAY+ARRSIZE(Y1ARRAY) );
        int Y2ARRAY[] = {3,2,0,1};
        vector <int> Y2( Y2ARRAY, Y2ARRAY+ARRSIZE(Y2ARRAY) );
        MovingRooksDiv2 theObject;
        eq(4, theObject.move(Y1, Y2),"Impossible");
    }
	return 0;
}
// END CUT HERE
