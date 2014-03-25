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

/*************** Program Begin **********************/

class CentaurCompanyDiv2 {
public:
    long long count(vector <int> a, vector <int> b) {
        long long res = 0;

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int aARRAY[] = {1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        CentaurCompanyDiv2 theObject;
        eq(0, theObject.count(a, b),4L);
    }
    {
        int aARRAY[] = {2,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1,3};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        CentaurCompanyDiv2 theObject;
        eq(1, theObject.count(a, b),7L);
    }
    {
        int aARRAY[] = {1,2,3,4,5,6,7,8,9};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,3,4,5,6,7,8,9,10};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        CentaurCompanyDiv2 theObject;
        eq(2, theObject.count(a, b),56L);
    }
    {
        int aARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        CentaurCompanyDiv2 theObject;
        eq(3, theObject.count(a, b),1125899906842675L);
    }
    {
        int aARRAY[] = {10, 7, 2, 5, 6, 2, 4, 9, 7};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {8, 10, 10, 4, 1, 6, 2, 2, 3};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        CentaurCompanyDiv2 theObject;
        eq(4, theObject.count(a, b),144L);
    }
}
// END CUT HERE
