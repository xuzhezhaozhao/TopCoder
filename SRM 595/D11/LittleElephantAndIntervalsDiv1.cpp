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
int v[1005];
class LittleElephantAndIntervalsDiv1 {
public:
    long long getNumber(int M, vector <int> L, vector <int> R) {
        long long res = 1;
	int n = L.size();
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n; i++) {
		for (int j = L[i]; j <= R[i]; j++) {
			v[j] = i + 1;
		}
	}
	set <int> s;
	for (int i = 1; i <= M; i++) {
		if (v[i] != 0) {
			s.insert(v[i]);
		}
	}
	res = 1;
	for (int i = 0; i < s.size(); i++) {
		res *= 2;
	}

	return res;
    }

};


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int LARRAY[] = {1, 2, 3};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {1, 2, 3};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        LittleElephantAndIntervalsDiv1 theObject;
        eq(0, theObject.getNumber(4, L, R),8LL);
    }
    {
        int LARRAY[] = {1, 1, 2};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {3, 1, 3};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        LittleElephantAndIntervalsDiv1 theObject;
        eq(1, theObject.getNumber(3, L, R),4LL);
    }
    {
        int LARRAY[] = {47};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {747};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        LittleElephantAndIntervalsDiv1 theObject;
        eq(2, theObject.getNumber(1000, L, R),2LL);
    }
    {
        int LARRAY[] = {5, 23, 4, 1, 15, 2, 22, 26, 13, 16, 28, 13, 27, 9, 18, 4, 10, 3, 4, 4, 3, 4, 1, 18, 18, 2, 38, 4, 10, 12, 3, 30, 11, 38, 2, 13, 1, 13, 18, 16, 13, 2, 14, 27, 13, 3, 26, 19, 5, 10};
        vector <int> L( LARRAY, LARRAY+ARRSIZE(LARRAY) );
        int RARRAY[] = {30, 41, 17, 1, 21, 6, 28, 30, 15, 19, 31, 28, 35, 27, 30, 13, 31, 5, 8, 25, 40, 10, 3, 26, 23, 9, 40, 8, 40, 23, 12, 37, 35, 39, 11, 34, 10, 21, 22, 21, 24, 5, 39, 27, 17, 16, 26, 35, 25, 36};
        vector <int> R( RARRAY, RARRAY+ARRSIZE(RARRAY) );
        LittleElephantAndIntervalsDiv1 theObject;
        eq(3, theObject.getNumber(42, L, R),256LL);
    }
}
// END CUT HERE
