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

class MyVeryLongCake {
public:
vector <long long> getPrimeFactor(int n)
{
        vector <long long> prime_factor;
	int lim = floor( sqrt(n * 1.0 + 0.5) );
	for (int i = 2; i <= lim; i++) {
		while (n % i == 0) {
			prime_factor.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		prime_factor.push_back(n);
	}
        return prime_factor;
}
        
    int cut(int _n) {
        int res = 0;
        long long n = _n;
        vector <long long> factor = getPrimeFactor(_n);
	sort(factor.begin(), factor.end());
	factor.erase(unique(factor.begin(), factor.end()), factor.end());
	long long t = n;
	long long p = 1;
	for (int i = 0; i < factor.size(); i++) {
		t *= (factor[i] - 1);
		p *= factor[i];
	}
	res = n - t / p;

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        MyVeryLongCake theObject;
        eq(0, theObject.cut(30),22);
    }
    {
        MyVeryLongCake theObject;
	eq(1, theObject.cut(4),2);
    }
    {
        MyVeryLongCake theObject;
       	eq(2, theObject.cut(15),7);
    }
    {
        MyVeryLongCake theObject;
        eq(3, theObject.cut(1000000000),600000000);
    }
    {
        MyVeryLongCake theObject;
        eq(4, theObject.cut(577007436),384671628);
    }
	return 0;
}
// END CUT HERE
