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

class ABBA {
public:
    string canObtain(string initial, string target) {
		if (initial.size() > target.size()) {
			return "Impossible";
		}
		bool reversed = false;
		int bpos = 0, epos = target.size() - 1;
		while (epos - bpos + 1 != initial.size()) {
			if (!reversed) {
				// from end
				if (target[epos] == 'B') {
					reversed = true;
				}
				--epos;
			} else {
				// from begin
				if (target[bpos] == 'B') {
					reversed = false;
				}
				++bpos;
			}
		}

		string s = target.substr(bpos, epos - bpos + 1);
		if (reversed) {
			reverse(s.begin(), s.end());
		}

		return s == initial ? "Possible" : "Impossible";
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
        ABBA theObject;
        eq(0, theObject.canObtain("B", "ABBA"),"Possible");
    }
    {
        ABBA theObject;
        eq(1, theObject.canObtain("AB", "ABB"),"Impossible");
    }
    {
        ABBA theObject;
        eq(2, theObject.canObtain("BBAB", "ABABABABB"),"Impossible");
    }
    {
        ABBA theObject;
        eq(3, theObject.canObtain("BBBBABABBBBBBA", "BBBBABABBABBBBBBABABBBBBBBBABAABBBAA"),"Possible");
    }
    {
        ABBA theObject;
        eq(4, theObject.canObtain("A", "BB"),"Impossible");
    }
	return 0;
}
// END CUT HERE
