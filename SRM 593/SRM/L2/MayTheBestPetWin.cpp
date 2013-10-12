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
const int MAX = 2 * 50 * 10000;
int curr[MAX];
int last[MAX];
class MayTheBestPetWin {
public:
    int calc(vector <int> A, vector <int> B) {
        int res = 0;
	int N = A.size();
	for (int i = 0; i < N; i++) {
		
	}

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int AARRAY[] = {3,4,4,7};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {3,4,4,7};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        MayTheBestPetWin theObject;
        eq(0, theObject.calc(A, B),2);
    }
    {
        int AARRAY[] = {1,3,5,4,5};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,5,6,8,7};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        MayTheBestPetWin theObject;
        eq(1, theObject.calc(A, B),5);
    }
    {
        int AARRAY[] = {2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        MayTheBestPetWin theObject;
        eq(2, theObject.calc(A, B),52873);
    }
}
// END CUT HERE
