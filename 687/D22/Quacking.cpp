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

class Quacking {
public:
    int quack(string s) {
        int res = 0;
		vector <int> v;
		for (auto c : s) {
			if (c == 'q') {
				v.push_back(0);
			} else if (c == 'u') {
				v.push_back(1);
			} else if (c == 'a') {
				v.push_back(2);
			} else if (c == 'c') {
				v.push_back(3);
			} else if (c == 'k') {
				v.push_back(4);
			}
		}

		vector <int> cnt(1, -1);

		bool ok = true;
		for (auto n : v) {
			bool added = false;
			for (int &x : cnt) {
				if (x + 1 == n) {
					x += 1;
					added = true;
					if (x == 4) {
						x = -1;
					}
					break;
				}
			}

			if (!added) {
				if (n == 0) {
					cnt.push_back(0);
				} else {
					ok = false;
					break;
				}
			}
		}

		for (auto x : cnt) {
			if (x != -1) {
				ok = false;
				break;
			}
		}

		res = ok ? cnt.size() : -1;

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
        Quacking theObject;
        eq(0, theObject.quack("quqacukqauackck"),2);
    }
    {
        Quacking theObject;
        eq(1, theObject.quack("kcauq"),-1);
    }
    {
        Quacking theObject;
        eq(2, theObject.quack("quackquackquackquackquackquackquackquackquackquack"),1);
    }
    {
        Quacking theObject;
        eq(3, theObject.quack("qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk"),10);
    }
    {
        Quacking theObject;
        eq(4, theObject.quack("quqaquuacakcqckkuaquckqauckack"),3);
    }
    {
        Quacking theObject;
        eq(5, theObject.quack("quackqauckquack"),-1);
    }
	return 0;
}
// END CUT HERE
