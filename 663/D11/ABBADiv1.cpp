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

class ABBADiv1 {
public:
	string initial, target;
    string canObtain(string initial, string target) {
		this->initial = initial;
		this->target = target;

		bool f = solve(0, target.size() - 1, false);

        return f ? "Possible" : "Impossible";
    }

	bool solve(int b, int e, bool inv) {
		if (e - b + 1 == initial.size()) {
			string str = target.substr(b, e - b + 1);
			if (inv) {
				reverse(str.begin(), str.end());
			}
			return str == initial;
		}

		bool f1 = false;
		if (inv) {
			// 逆
			if (target[b] == 'A' && target[e] == 'A') {
				f1 = solve(b + 1, e, inv);
			} else if (target[b] == 'A' && target[e] == 'B') {
				f1 = solve(b + 1, e, inv) | solve(b, e - 1, !inv);
			} else if (target[b] == 'B' && target[e] == 'A') {
				f1 = false;
			} else {
				// target[b] == 'B' && target[e] == 'B'
				f1 = solve(b, e - 1, !inv);
			}
		} else {
			// 非逆
			if (target[b] == 'A' && target[e] == 'A') {
				f1 = solve(b, e - 1, inv);
			} else if (target[b] == 'A' && target[e] == 'B') {
				f1 = false;
			} else if (target[b] == 'B' && target[e] == 'A') {
				f1 = solve(b, e - 1, inv) | solve(b + 1, e, !inv);
			} else {
				// target[b] == 'B' && target[e] == 'B'
				f1 = solve(b + 1, e, !inv);
			}
		}
		return f1;
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
        ABBADiv1 theObject;
        eq(0, theObject.canObtain("A", "BABA"),"Possible");
    }
    {
        ABBADiv1 theObject;
        eq(1, theObject.canObtain("BAAAAABAA", "BAABAAAAAB"),"Possible");
    }
    {
        ABBADiv1 theObject;
        eq(2, theObject.canObtain("A", "ABBA"),"Impossible");
    }
    {
        ABBADiv1 theObject;
        eq(3, theObject.canObtain("AAABBAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"),"Possible");
    }
    {
        ABBADiv1 theObject;
        eq(4, theObject.canObtain("AAABAAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"),"Impossible");
    }
	return 0;
}
// END CUT HERE
