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

class LittleElephantAndBooks {
public:
    int getNumber(vector <int> pages, int number) {
        int res = 0;
	sort(pages.begin(), pages.end());
	for (int i = 0; i < number; i++) {
		res += pages[i];
	}
	res = res - pages[number-1] + pages[number];
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int pagesARRAY[] = {1, 2};
        vector <int> pages( pagesARRAY, pagesARRAY+ARRSIZE(pagesARRAY) );
        LittleElephantAndBooks theObject;
        eq(0, theObject.getNumber(pages, 1),2);
    }
    {
        int pagesARRAY[] = {74, 7, 4, 47, 44};
        vector <int> pages( pagesARRAY, pagesARRAY+ARRSIZE(pagesARRAY) );
        LittleElephantAndBooks theObject;
        eq(1, theObject.getNumber(pages, 3),58);
    }
    {
        int pagesARRAY[] = {3, 1, 9, 7, 2, 8, 6, 4, 5};
        vector <int> pages( pagesARRAY, pagesARRAY+ARRSIZE(pagesARRAY) );
        LittleElephantAndBooks theObject;
        eq(2, theObject.getNumber(pages, 7),29);
    }
    {
        int pagesARRAY[] = {74, 86, 32, 13, 100, 67, 77};
        vector <int> pages( pagesARRAY, pagesARRAY+ARRSIZE(pagesARRAY) );
        LittleElephantAndBooks theObject;
        eq(3, theObject.getNumber(pages, 2),80);
    }
}
// END CUT HERE
