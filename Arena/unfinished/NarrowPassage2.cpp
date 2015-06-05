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

class NarrowPassage2 {
public:
    int count(vector <int> size, int maxSizeSum) {
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
        int sizeARRAY[] = {1, 2, 3};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2 theObject;
        eq(0, theObject.count(size, 3),2);
    }
    {
        int sizeARRAY[] = {1, 2, 3};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2 theObject;
        eq(1, theObject.count(size, 1000),6);
    }
    {
        int sizeARRAY[] = {1, 2, 3};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2 theObject;
        eq(2, theObject.count(size, 4),3);
    }
    {
        int sizeARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2 theObject;
        eq(3, theObject.count(size, 2),227020758);
    }
    {
        int sizeARRAY[] = {2,4,6,1,3,5};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2 theObject;
        eq(4, theObject.count(size, 8),60);
    }
    {
        int sizeARRAY[] = {1000000000};
        vector <int> size( sizeARRAY, sizeARRAY+ARRSIZE(sizeARRAY) );
        NarrowPassage2 theObject;
        eq(5, theObject.count(size, 1000000000),1);
    }
	return 0;
}
// END CUT HERE
