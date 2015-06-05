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

class Cyclemin {
public:
    string bestmod(string s, int k) {
        string res = "";
		int n = s.size();
		for (int i = 0; i < n; i++) {
			string newS = s.substr(i) + s.substr(0, i);
			int t = k;
			for (int j = 0; j < n && t > 0; j++) {
				if (newS[j] != 'a') {
					newS[j] = 'a';
					--t;
				}
			}
			if (res == "") {
				res = newS;
			} else {
				res = min(res, newS);
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
        Cyclemin theObject;
        eq(0, theObject.bestmod("aba", 1),"aaa");
    }
    {
        Cyclemin theObject;
        eq(1, theObject.bestmod("aba", 0),"aab");
    }
    {
        Cyclemin theObject;
        eq(2, theObject.bestmod("bbb", 2),"aab");
    }
    {
        Cyclemin theObject;
        eq(3, theObject.bestmod("sgsgaw", 1),"aasgsg");
    }
    {
        Cyclemin theObject;
        eq(4, theObject.bestmod("abacaba", 1),"aaaabac");
    }
    {
        Cyclemin theObject;
        eq(5, theObject.bestmod("isgbiao", 2),"aaaisgb");
    }
	return 0;
}
// END CUT HERE
