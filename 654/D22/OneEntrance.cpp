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

class OneEntrance {
public:
    int count(vector <int> a, vector <int> b, int s) {
        int res = 0;
		int N = a.size() + 1;
		vector<vector<int>> adj(N);
		for (int i = 0; i < N - 1; i++) {
			adj[ a[i] ].push_back( b[i] );
			adj[ b[i] ].push_back( a[i] );
		}

		vector <int> p;
		for (int i = 0; i < N; i++) {
			p.push_back(i);
		}

		do {
			if (p.back() == s) {
				res += (check(adj, p) ? 1 : 0);
			}
		} while (next_permutation(p.begin(), p.end()));

        return res;
    }

	bool check(vector <vector<int> > adj, vector <int> &p) {
		for (int i = 0; i < (int)p.size() - 1; i++) {
			if (adj[ p[i] ].size() != 1) {
				return false;
			} else {
				int parent = adj[ p[i] ][0];
				adj[parent].erase( find(adj[parent].begin(), adj[parent].end(), p[i]) );
				adj[ p[i] ].clear();
			}
		}
		return true;
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
        int aARRAY[] = {0, 1, 2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1, 2, 3};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        OneEntrance theObject;
        eq(0, theObject.count(a, b, 0),1);
    }
    {
        int aARRAY[] = {0, 1, 2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1, 2, 3};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        OneEntrance theObject;
		eq(1, theObject.count(a, b, 2),3);
    }
    {
        int aARRAY[] = {0, 0, 0, 0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {1, 2, 3, 4};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        OneEntrance theObject;
		eq(2, theObject.count(a, b, 0),24);
    }
    {
        int aARRAY[] = {7, 4, 1, 0, 1, 1, 6, 0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int bARRAY[] = {6, 6, 2, 5, 0, 3, 8, 4};
        vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
        OneEntrance theObject;
		eq(3, theObject.count(a, b, 4),896);
    }
    {
        OneEntrance theObject;
		eq(4, theObject.count(vector <int>(), vector <int>(), 0),1);
    }
	return 0;
}
// END CUT HERE
