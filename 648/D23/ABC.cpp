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

class ABC {
public:
    string createString(int N, int K) {
        string res;
		int a, b, c;
		a = b = c = N / 3;
		if (N % 3 == 1) {
			++a;
		}
		if (N % 3 == 2) {
			++a;
			++b;
		}

		int max = a * (b + c) + b * c;
		if (K > max) {
			return "";
		}

		int diff = max - K;
		int ra, ma, rb, mb;
		if (b * c >= diff) {	// only move B
			ra = 0;
			ma = 0;
			rb = diff / c;
			mb = diff % c;
		} else {				// move all B and move A
			ra = (diff - b * c) / (b + c);
			ma = (diff - b * c) % (b + c);
			rb = b;
			mb = 0;
		}

		string tmp = string( std::max(b - rb - 1, 0), 'B' ) + string(mb, 'C') + 
			string( std::min(b - rb, 1), 'B') +	string(c - mb, 'C') + string(rb, 'B');

		res = string( std::max(a - ra - 1, 0), 'A' ) + tmp.substr(0, ma) + 
			string(std::min(a - ra, 1), 'A') + tmp.substr(ma) +	string(ra, 'A');

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
        ABC theObject;
        eq(0, theObject.createString(3, 3),"ABC");
    }
    {
        ABC theObject;
        eq(1, theObject.createString(3, 0),"CBA");
    }
    {
        ABC theObject;
        eq(2, theObject.createString(5, 10),"");
    }
    {
        ABC theObject;
        eq(3, theObject.createString(15, 36),"CABBACCBAABCBBB");
    }
	return 0;
}
// END CUT HERE
