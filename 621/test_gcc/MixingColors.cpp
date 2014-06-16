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

class MixingColors {
public:
    int minColors(vector <int> colors) {
        int res;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int colorsARRAY[] = {1, 7, 3};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(0, theObject.minColors(colors),3);
    }
    {
        int colorsARRAY[] = {10};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(1, theObject.minColors(colors),1);
    }
    {
        int colorsARRAY[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(2, theObject.minColors(colors),4);
    }
    {
        int colorsARRAY[] = {534, 251, 76, 468, 909, 410, 264, 387, 102, 982, 199, 111, 659, 386, 151};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(3, theObject.minColors(colors),10);
    }
    {
        int colorsARRAY[] = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
        vector <int> colors( colorsARRAY, colorsARRAY+ARRSIZE(colorsARRAY) );
        MixingColors theObject;
        eq(4, theObject.minColors(colors),9);
    }
	return 0;
}
// END CUT HERE
