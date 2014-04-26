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
int split[100005];
class MyLongCake {
public:
vector <int> getFactor(int n)
{
        vector <int> factor;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			factor.push_back(i);
			factor.push_back(n / i);
		}
	}
	factor.push_back(n);
        return factor;
}
        
    int cut(int n) {
        int res = 0;
        vector <int> factor = getFactor(n);
        if (factor.size() == 1) {
                return 1;
        }
	memset(split, 0, sizeof(split));

	for (int i = 0; i < factor.size(); i++) {
		int t = factor[i];
		while (t <= n) {
			split[t] = 1;
			t += factor[i];
		}
	}
	res = accumulate(split, split + n + 1, 0);

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        MyLongCake theObject;
        eq(0, theObject.cut(6),4);
    }
    {
        MyLongCake theObject;
        eq(1, theObject.cut(3),1);
    }
    {
        MyLongCake theObject;
        eq(2, theObject.cut(15),7);
    }
    {
        MyLongCake theObject;
        eq(3, theObject.cut(100000),60000);
    }
	return 0;
}
// END CUT HERE
