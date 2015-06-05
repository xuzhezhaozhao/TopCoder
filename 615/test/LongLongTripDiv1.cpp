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

class LongLongTripDiv1 {
public:
    string isAble(int N, vector <int> A, vector <int> B, vector <int> D, long long T) {
        string res;



        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int AARRAY[] = {0,0,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,1,2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int DARRAY[] = {7,6,5};
        vector <int> D( DARRAY, DARRAY+ARRSIZE(DARRAY) );
        LongLongTripDiv1 theObject;
        eq(0, theObject.isAble(3, A, B, D, 11L),"Possible");
    }
    {
        int AARRAY[] = {0,0,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,1,2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int DARRAY[] = {7,6,5};
        vector <int> D( DARRAY, DARRAY+ARRSIZE(DARRAY) );
        LongLongTripDiv1 theObject;
        eq(1, theObject.isAble(3, A, B, D, 25L),"Possible");
    }
    {
        int AARRAY[] = {0};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {1};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int DARRAY[] = {1};
        vector <int> D( DARRAY, DARRAY+ARRSIZE(DARRAY) );
        LongLongTripDiv1 theObject;
        eq(2, theObject.isAble(2, A, B, D, 9L),"Possible");
    }
    {
        int AARRAY[] = {1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {0};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int DARRAY[] = {1};
        vector <int> D( DARRAY, DARRAY+ARRSIZE(DARRAY) );
        LongLongTripDiv1 theObject;
        eq(3, theObject.isAble(2, A, B, D, 1000000000000000000L),"Impossible");
    }
    {
        int AARRAY[] = {0,0,1};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,1,2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int DARRAY[] = {10,10,10};
        vector <int> D( DARRAY, DARRAY+ARRSIZE(DARRAY) );
        LongLongTripDiv1 theObject;
        eq(4, theObject.isAble(4, A, B, D, 1000L),"Impossible");
    }
    {
        int AARRAY[] = {4,8,5,8,3,6,2,6,7,6,6};
        vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
        int BARRAY[] = {2,7,1,5,1,3,1,1,5,4,2};
        vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
        int DARRAY[] = {6580,8822,1968,673,1394,9337,5486,1746,5229,4092,195};
        vector <int> D( DARRAY, DARRAY+ARRSIZE(DARRAY) );
        LongLongTripDiv1 theObject;
        eq(5, theObject.isAble(9, A, B, D, 937186357646035002L),"Impossible");
    }
}
// END CUT HERE
