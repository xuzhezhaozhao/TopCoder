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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

class BridgeBuilding {
public:
    int minDiameter(vector <int> a, vector <int> b, int K) {
        int res;
        return res;
    }

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
    {
        int aARRAY[] = {2,1,1,1,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1,9,1,9,1};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        BridgeBuilding theObject;
        eq(0, theObject.minDiameter(a, b, 4),6);
    }
    {
        int aARRAY[] = {1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        BridgeBuilding theObject;
        eq(1, theObject.minDiameter(a, b, 43),42);
    }
    {
        int aARRAY[] = {50,10,15,31,20,23,7,48,5,50};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,5,1,8,3,2,16,11,9,1};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        BridgeBuilding theObject;
        eq(2, theObject.minDiameter(a, b, 3),124);
    }
    {
        int aARRAY[] = {50,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,50};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        BridgeBuilding theObject;
        eq(3, theObject.minDiameter(a, b, 4),17);
    }
    {
        int aARRAY[] = {2,4,10,2,2,22,30,7,28,14,17,6,32,41,1,3,16,20,40,39,6,4,18,3,3,7,
            3,2,2,14,10,6,38,6,13,3,6,1,23,26,9,17,1,38,1,21,2,12,3,13,28,6,4,
           10,3,1,1,43,15,11,18,6,41,1,2,5,6,26,43,9,5,13,1,27,1,33,12,16,1,12,
           1,37,34,6,20,3,21,3,1,17,3,10,2,1,8,25,2,6,7,1,7,22,11,8,49,9,1,7,1,
           13,17,20,27,31,43,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {5,26,1,2,6,2,16,3,15,1,1,38,2,4,6,1,2,3,11,2,2,2,25,16,2,15,45,3,10,
           4,17,5,6,1,16,13,29,3,1,2,4,47,4,10,1,2,23,3,29,20,4,21,1,28,7,25,6,6,
           10,1,2,1,17,6,1,28,2,2,12,2,3,42,39,11,18,3,15,4,1,15,3,9,4,26,4,13,41,
           1,27,1,14,1,2,14,5,33,1,34,5,17,23,3,33,14,23,2,29,18,3,41,1,45,5,4,6,2};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        BridgeBuilding theObject;
        eq(4, theObject.minDiameter(a, b, 5),1184);
    }
	return 0;
}
// END CUT HERE
