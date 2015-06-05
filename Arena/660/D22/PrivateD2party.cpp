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

class PrivateD2party {
public:
    int getsz(vector <int> a) {
		int n = a.size();
        int res = n;

		bool visited[55] = { false };
		for (int i = 0; i < n; i++) {
			set <int> s;
			int cur = i;
			int next = a[i];
			s.insert(cur);
			while (true) {
				if (visited[cur]) {
					break;
				}
				if (s.find(next) != s.end()) {
					if (cur != next) {
						--res;
					}
					break;
				}
				cur = next;
				s.insert(cur);
				next = a[next];
			}
			for (auto x : s) {
				visited[x] = true;
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
        int aARRAY[] = {0,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        PrivateD2party theObject;
        eq(0, theObject.getsz(a),2);
    }
    {
        int aARRAY[] = {1,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        PrivateD2party theObject;
        eq(1, theObject.getsz(a),1);
    }
    {
        int aARRAY[] = {1,0,3,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        PrivateD2party theObject;
        eq(2, theObject.getsz(a),2);
    }
    {
        int aARRAY[] = {5,2,2,4,5,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        PrivateD2party theObject;
        eq(3, theObject.getsz(a),5);
    }
    {
        int aARRAY[] = {3,2,1,0,5,4};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        PrivateD2party theObject;
        eq(4, theObject.getsz(a),3);
    }
	return 0;
}
// END CUT HERE
