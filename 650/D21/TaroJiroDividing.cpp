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

class TaroJiroDividing {
public:
    int getNumber(int A, int B) {
        int res = 0;
		int mx = max(A, B);
		int mi = min(A, B);
		if (mx % mi != 0) {
			return 0;
		}
		int tmp = mx / mi;
		bool ok = false;
		for (int i = 0; i < 31; i++) {
			if (tmp == (1 << i)) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			return 0;
		}

		res = 1;
		while (mi > 0 && mi % 2 == 0) {
			mi /= 2;
			++res;
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
        TaroJiroDividing theObject;
        eq(0, theObject.getNumber(8, 4),3);
    }
    {
        TaroJiroDividing theObject;
        eq(1, theObject.getNumber(4, 7),0);
    }
    {
        TaroJiroDividing theObject;
        eq(2, theObject.getNumber(12, 12),3);
    }
    {
        TaroJiroDividing theObject;
        eq(3, theObject.getNumber(24, 96),4);
    }
    {
        TaroJiroDividing theObject;
        eq(4, theObject.getNumber(1000000000, 999999999),0);
    }
	return 0;
}
// END CUT HERE
