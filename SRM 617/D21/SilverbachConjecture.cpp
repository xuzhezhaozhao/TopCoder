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

class SilverbachConjecture {
public:
        bool iscom(int x)
        {
                for (int i = 2; i < x; i++) {
                        if (x % i == 0) {
                                return true;
                        }
                }        
                return false;
        }
    vector <int> solve(int n) {
        vector <int> res;
        for (int i = 4; i <= n - 4; i++) {
                if (iscom(i) && iscom(n - i)) {
                        res.push_back(i);
                        res.push_back(n - i);
                        break;
                }
        }
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int retrunValueARRAY[] = {8, 12 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SilverbachConjecture theObject;
        eq(0, theObject.solve(20),retrunValue);
    }
    {
        int retrunValueARRAY[] = {15, 15 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SilverbachConjecture theObject;
        eq(1, theObject.solve(30),retrunValue);
    }
    {
        int retrunValueARRAY[] = {699, 300 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SilverbachConjecture theObject;
        eq(2, theObject.solve(999),retrunValue);
    }
    {
        int retrunValueARRAY[] = {15, 30 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        SilverbachConjecture theObject;
        eq(3, theObject.solve(45),retrunValue);
    }
	return 0;
}
// END CUT HERE
