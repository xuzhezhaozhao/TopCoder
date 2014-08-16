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

class CostOfDancing {
public:
    int minimum(int K, vector <int> danceCost) {
        int res = 0;
	sort(danceCost.begin(), danceCost.end());
	res = accumulate(danceCost.begin(), danceCost.begin() + K, 0);
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int danceCostARRAY[] = {1, 5, 3, 4};
        vector <int> danceCost( danceCostARRAY, danceCostARRAY+ARRSIZE(danceCostARRAY) );
        CostOfDancing theObject;
        eq(0, theObject.minimum(2, danceCost),4);
    }
    {
        int danceCostARRAY[] = {1, 5, 4};
        vector <int> danceCost( danceCostARRAY, danceCostARRAY+ARRSIZE(danceCostARRAY) );
        CostOfDancing theObject;
        eq(1, theObject.minimum(3, danceCost),10);
    }
    {
        int danceCostARRAY[] = {2, 2, 4, 5, 3};
        vector <int> danceCost( danceCostARRAY, danceCostARRAY+ARRSIZE(danceCostARRAY) );
        CostOfDancing theObject;
        eq(2, theObject.minimum(1, danceCost),2);
    }
    {
        int danceCostARRAY[] = {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
            703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801};
        vector <int> danceCost( danceCostARRAY, danceCostARRAY+ARRSIZE(danceCostARRAY) );
        CostOfDancing theObject;
        eq(3, theObject.minimum(39, danceCost),20431);
    }
	return 0;
}
// END CUT HERE
