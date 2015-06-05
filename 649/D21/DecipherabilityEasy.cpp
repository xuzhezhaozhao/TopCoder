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

class DecipherabilityEasy {
public:
    string check(string s, string t) {
		string possible = "Possible";
		string impossible = "Impossible";
		bool pass = false;
		int i, j;
		for (i = 0, j = 0; i < (int)s.size() && j < (int)t.size(); i++, j++) {
			if (s[i] != t[j]) {
				if (pass) {
					return impossible;
				} else {
					--j;
					pass = true;
				}
			}
		}
		if (i == s.length() - 1 && j == t.length() && !pass) {
			return possible;
		}
		if (i == s.length() && j == t.length() && pass) {
			return possible;
		}
		return impossible;
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
        DecipherabilityEasy theObject;
        eq(0, theObject.check("sunuke", "snuke"),"Possible");
    }
    {
        DecipherabilityEasy theObject;
        eq(1, theObject.check("snuke", "skue"),"Impossible");
    }
    {
        DecipherabilityEasy theObject;
        eq(2, theObject.check("snuke", "snuke"),"Impossible");
    }
    {
        DecipherabilityEasy theObject;
        eq(3, theObject.check("snukent", "snuke"),"Impossible");
    }
    {
        DecipherabilityEasy theObject;
        eq(4, theObject.check("aaaaa", "aaaa"),"Possible");
    }
    {
        DecipherabilityEasy theObject;
        eq(5, theObject.check("aaaaa", "aaa"),"Impossible");
    }
    {
        DecipherabilityEasy theObject;
        eq(6, theObject.check("topcoder", "tpcoder"),"Possible");
    }
    {
        DecipherabilityEasy theObject;
        eq(7, theObject.check("singleroundmatch", "singeroundmatc"),"Impossible");
    }
	return 0;
}
// END CUT HERE
