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

class StrongPrimePower {
public:
	bool isPrime(int n)
	{
		int limit = sqrt(n * 1.0 + 0.5);
		for (int i = 2; i <= limit; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}
    vector <int> baseAndExponent(string _n) {
        vector <long long> res;
	vector <int> ans;

	long long n = 0;
	for (int i = 0; i < _n.size(); i++) {
		n = 10LL * n + _n[i] - '0';
	}
	int limit = sqrt(n * 1.0 + 0.5);
	if ( (long long) limit * limit == n) {
		if (isPrime(limit)) {
			ans.push_back(limit);
			ans.push_back(2);
			return ans;
		}
	}
	limit = min<int>(limit, 1e6 + 1);
	for (int i = 2; i <= limit; i++) {
		while (n % i == 0) {
			res.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		res.push_back(n);
	}
	if (res.size() > 1) {
		int d = res[0];
		for (int i = 1; i < res.size(); i++) {
			if (d != res[i]) {
				return ans;
			}
		}
		ans.push_back( (long long)res[0] );
		ans.push_back( (int)res.size() );
	}
	return ans;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int retrunValueARRAY[] = {3, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StrongPrimePower theObject;
        eq(0, theObject.baseAndExponent("435307306210734208"),vector <int>());
    }
    {
        StrongPrimePower theObject;
        eq(1, theObject.baseAndExponent("10"),vector <int>());
    }
    {
        StrongPrimePower theObject;
        eq(2, theObject.baseAndExponent("7"),vector <int>());
    }
    {
        StrongPrimePower theObject;
        eq(3, theObject.baseAndExponent("1296"),vector <int>());
    }
    {
        int retrunValueARRAY[] = {2, 59 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StrongPrimePower theObject;
        eq(4, theObject.baseAndExponent("576460752303423488"),retrunValue);
    }
    {
        int retrunValueARRAY[] = {999999937, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        StrongPrimePower theObject;
        eq(5, theObject.baseAndExponent("999999874000003969"),retrunValue);
    }
}
// END CUT HERE
