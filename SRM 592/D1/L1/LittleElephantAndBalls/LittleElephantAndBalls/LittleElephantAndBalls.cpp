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

class LittleElephantAndBalls {
public:
    int getNumber(string S) {
        int res = 0;

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        LittleElephantAndBalls theObject;
        eq(0, theObject.getNumber("RGB"),3);
    }
    {
        LittleElephantAndBalls theObject;
        eq(1, theObject.getNumber("RGGRBBB"),21);
    }
    {
        LittleElephantAndBalls theObject;
        eq(2, theObject.getNumber("RRRGBRR"),16);
    }
    {
        LittleElephantAndBalls theObject;
        eq(3, theObject.getNumber("RRRR"),5);
    }
    {
        LittleElephantAndBalls theObject;
        eq(4, theObject.getNumber("GGRRRGR"),18);
    }
    {
        LittleElephantAndBalls theObject;
        eq(5, theObject.getNumber("G"),0);
    }
}
// END CUT HERE
