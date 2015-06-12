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
const int MAX_N = 1000005;
bool composite[MAX_N];
class MissingLCM {
public:
    int getMin(int N) {
		if (1 == N) {
			return 2;
		}

        int res = 0;
		vector <int> primes;
		memset(composite, 0, sizeof composite);
		for (long long i = 2; i <= N; i++) {
			if (composite[i]) { continue; }
			primes.push_back(i);
			for (long long j = i * i;  j <= N; j += i) {
				composite[j] = true;
			}
		}

		for (auto x : primes) {
			int p = x;
			while ((long long)p * x <= N) {
				p *= x;
			}
			res = max(res, p * 2);
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
        MissingLCM theObject;
        eq(0, theObject.getMin(1),2);
    }
    {
        MissingLCM theObject;
        eq(1, theObject.getMin(2),4);
    }
    {
        MissingLCM theObject;
		eq(2, theObject.getMin(3),6);
    }
    {
        MissingLCM theObject;
		eq(3, theObject.getMin(4),8);
    }
    {
        MissingLCM theObject;
		eq(4, theObject.getMin(5),10);
    }
    {
        MissingLCM theObject;
		eq(5, theObject.getMin(42),82);
    }
    {
        MissingLCM theObject;
		eq(6, theObject.getMin(999999),1999966);
    }
	return 0;
}
// END CUT HERE
