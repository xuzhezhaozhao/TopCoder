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

class XorCards {
public:
    long long numberOfWays(vector<long long> number, long long limit) {
        long long res;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        long numberARRAY[] = {1L,2L};
        vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        XorCards theObject;
        eq(0, theObject.numberOfWays(number, 2L),3L);
    }
    {
        long numberARRAY[] = {5L,5L};
        vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        XorCards theObject;
        eq(1, theObject.numberOfWays(number, 3L),2L);
    }
    {
        long numberARRAY[] = {1L,2L,3L,4L,5L,6L,7L};
        vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        XorCards theObject;
        eq(2, theObject.numberOfWays(number, 5L),96L);
    }
    {
        long numberARRAY[] = {123L, 456L, 789L, 147L, 258L, 369L, 159L, 357L};
        vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        XorCards theObject;
        eq(3, theObject.numberOfWays(number, 500L),125L);
    }
    {
        long numberARRAY[] = {0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L,0L};
        vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        XorCards theObject;
        eq(4, theObject.numberOfWays(number, 1000000000000000L),4294967296L);
    }
    {
        long numberARRAY[] = {1000000000000000L, 999999999999999L};
        vector<long long> number( numberARRAY, numberARRAY+ARRSIZE(numberARRAY) );
        XorCards theObject;
        eq(5, theObject.numberOfWays(number, 65535L),2L);
    }
}
// END CUT HERE
