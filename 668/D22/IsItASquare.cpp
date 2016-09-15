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

class IsItASquare {
public:
    string isSquare(vector <int> x, vector <int> y) {
        string res;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int xARRAY[] = {0, 0, 2, 2};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 2, 0, 2};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        IsItASquare theObject;
        eq(0, theObject.isSquare(x, y),"It's a square");
    }
    {
        int xARRAY[] = {0, 1, 5, 6};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1, 6, 0, 5};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        IsItASquare theObject;
        eq(1, theObject.isSquare(x, y),"It's a square");
    }
    {
        int xARRAY[] = {0, 0, 7, 7};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 3, 0, 3};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        IsItASquare theObject;
        eq(2, theObject.isSquare(x, y),"Not a square");
    }
    {
        int xARRAY[] = {0, 5000, 5000, 10000};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {5000, 0, 10000, 5000};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        IsItASquare theObject;
        eq(3, theObject.isSquare(x, y),"It's a square");
    }
    {
        int xARRAY[] = {1, 2, 3, 4};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {4, 3, 2, 1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        IsItASquare theObject;
        eq(4, theObject.isSquare(x, y),"Not a square");
    }
    {
        int xARRAY[] = {0, 5, 3, 8};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0, 0, 4, 4};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        IsItASquare theObject;
        eq(5, theObject.isSquare(x, y),"Not a square");
    }
  return 0;
}
// END CUT HERE
