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

#include<limits>

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

class SplitIntoPairs {
public:
    int makepairs(vector <int> A, int X) {
        int res = 0;
	sort(A.begin(), A.end());
	int N = A.size();
	int neg = 0;
	for (; A[neg] < 0; ++neg) {
	}
	if (neg % 2 == 0) {
		res = N / 2;
	} else {
		res = N / 2;
		long long t1, t2;
		t1 = A[neg - 1];
		t2 = A[neg];
		if ( t1 * t2 < X) {
			--res;
		}
	}

        return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int AARRAY[] = {1000000000,-1000000000};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(0, theObject.makepairs(A, -1000000000), 0);
    }
    {
        int AARRAY[] = {1,-1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(1, theObject.makepairs(A, -1),1);
    }
    {
        int AARRAY[] = {-5,-4,2,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(2, theObject.makepairs(A, -1),2);
    }
    {
        int AARRAY[] = {5,-7,8,-2,-5,3};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(3, theObject.makepairs(A, -7),3);
    }
    {
        int AARRAY[] = {3,4,5,6,6,-6,-4,-10,-1,-9};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(4, theObject.makepairs(A, -2),4);
    }
    {
        int AARRAY[] = {1000000,1000000};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        SplitIntoPairs theObject;
        eq(5, theObject.makepairs(A, -5),1);
    }
}
// END CUT HERE
