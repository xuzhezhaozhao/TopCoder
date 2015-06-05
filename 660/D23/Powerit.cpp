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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

const int MAX_N = 1000001;
long long results[MAX_N];
long long primefactor[MAX_N];
class Powerit {
public:
    int calc(int n, int k, int m) {
        long long res = 0;

		memset(results, -1, sizeof results);
		memset(primefactor, 0, sizeof primefactor);

		int limit = (int) (sqrt(n) + 0.5);
		for (int i = 2; i <= limit; i++) {
			if (primefactor[i] != 0) { continue; }
			for (int j = i * i;  j <= n; j += i) {
				primefactor[j] = i;
			}
		}


		for (int i = 1; i <= n; i++) {
			long long sum = 1;
			if (primefactor[i] == 0) {
				// i is primefactor
				long long cur = i % m;
				sum *= cur; sum %= m;
				for (int j = 1; j < k; j++) {
					cur *= cur; cur %= m;
					sum *= cur; sum %= m;
				}
				results[i] = sum;
				res += sum; res %= m;
			} else {
				int f1 = primefactor[i];
				int f2 = i / f1;
				sum = results[f1] * results[f2]; sum %= m;
				results[i] = sum;
				res += sum; res %= m;
			}
		}

        return res;
    }
};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
    {
        Powerit theObject;
        eq(0, theObject.calc(4, 1, 107),10);
    }
    {
        Powerit theObject;
        eq(1, theObject.calc(4, 2, 107),100);
    }
    {
        Powerit theObject;
        eq(2, theObject.calc(3, 3, 107),69);
    }
    {
        Powerit theObject;
        eq(3, theObject.calc(1, 400, 107),1);
    }
    {
        Powerit theObject;
        eq(4, theObject.calc(10, 2, 10),5);
    }
	return 0;
}
// END CUT HERE
