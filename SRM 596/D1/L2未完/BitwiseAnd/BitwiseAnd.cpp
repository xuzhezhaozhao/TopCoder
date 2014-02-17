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

/*************** Program Begin **********************/

class BitwiseAnd {
public:
    vector<long long> lexSmallest(vector<long long> subset, int N) {
        vector<long long> res;

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        long subsetARRAY[] = {14L, 20L};
        vector<long long> subset( subsetARRAY, subsetARRAY+ARRSIZE(subsetARRAY) );
        long retrunValueARRAY[] = {14L, 18L, 20L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BitwiseAnd theObject;
        eq(0, theObject.lexSmallest(subset, 3),retrunValue);
    }
    {
        long subsetARRAY[] = {11L, 17L, 20L};
        vector<long long> subset( subsetARRAY, subsetARRAY+ARRSIZE(subsetARRAY) );
        BitwiseAnd theObject;
        eq(1, theObject.lexSmallest(subset, 4),vector<long long>());
    }
    {
        long subsetARRAY[] = {99L, 157L};
        vector<long long> subset( subsetARRAY, subsetARRAY+ARRSIZE(subsetARRAY) );
        long retrunValueARRAY[] = {99L, 157L, 262L, 296L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BitwiseAnd theObject;
        eq(2, theObject.lexSmallest(subset, 4),retrunValue);
    }
    {
        long subsetARRAY[] = {1152921504606846975L};
        vector<long long> subset( subsetARRAY, subsetARRAY+ARRSIZE(subsetARRAY) );
        BitwiseAnd theObject;
        eq(3, theObject.lexSmallest(subset, 3),vector<long long>());
    }
    {
        long retrunValueARRAY[] = {15L, 113L, 402L, 676L, 840L };
        vector<long long> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        BitwiseAnd theObject;
        eq(4, theObject.lexSmallest(vector<long long>(), 5),retrunValue);
    }
    {
        long subsetARRAY[] = {1L, 3L, 5L, 7L, 9L, 11L};
        vector<long long> subset( subsetARRAY, subsetARRAY+ARRSIZE(subsetARRAY) );
        BitwiseAnd theObject;
        eq(5, theObject.lexSmallest(subset, 6),vector<long long>());
    }
}
// END CUT HERE
