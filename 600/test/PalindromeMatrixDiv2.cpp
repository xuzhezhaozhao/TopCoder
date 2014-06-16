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

class PalindromeMatrixDiv2 {
public:
    int minChange(vector <string> A, int rowCount, int columnCount) {
        int res;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string AARRAY[] = {"0000"
           ,"1000"
           ,"1100"
           ,"1110"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(0, theObject.minChange(A, 2, 2),1);
    }
    {
        string AARRAY[] = {"0000"
           ,"1000"
           ,"1100"
           ,"1110"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(1, theObject.minChange(A, 3, 2),3);
    }
    {
        string AARRAY[] = {"01"
           ,"10"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(2, theObject.minChange(A, 1, 1),1);
    }
    {
        string AARRAY[] = {"1110"
           ,"0001"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(3, theObject.minChange(A, 0, 0),0);
    }
    {
        string AARRAY[] = {"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"
           ,"01010101"};
        vector <string> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        PalindromeMatrixDiv2 theObject;
        eq(4, theObject.minChange(A, 2, 2),8);
    }
}
// END CUT HERE
