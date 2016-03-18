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

class FoxesOfTheRoundTable {
public:
    vector <int> minimalDifference(vector <int> h) {
        vector <int> res;
		int N = h.size();
		int rank[51];
		for (int i = 0; i < N; i++) {
			rank[i] = i;
		}
		sort(rank, rank + N, [&h](int a, int b) {
			return h[a] > h[b];
		});
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				res.push_back(rank[i]);
			} else {
				res.insert(res.begin(), rank[i]);
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
        int hARRAY[] = {1,99,50,50};
        vector <int> h( hARRAY, hARRAY+ARRSIZE(hARRAY) );
        int retrunValueARRAY[] = {0, 3, 1, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxesOfTheRoundTable theObject;
        eq(0, theObject.minimalDifference(h),retrunValue);
    }
    {
        int hARRAY[] = {123,456,789};
        vector <int> h( hARRAY, hARRAY+ARRSIZE(hARRAY) );
        int retrunValueARRAY[] = {0, 1, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxesOfTheRoundTable theObject;
        eq(1, theObject.minimalDifference(h),retrunValue);
    }
    {
        int hARRAY[] = {10,30,40,50,60};
        vector <int> h( hARRAY, hARRAY+ARRSIZE(hARRAY) );
        int retrunValueARRAY[] = {0, 1, 4, 3, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxesOfTheRoundTable theObject;
        eq(2, theObject.minimalDifference(h),retrunValue);
    }
    {
        int hARRAY[] = {1,2,3,4,8,12,13,14 };
        vector <int> h( hARRAY, hARRAY+ARRSIZE(hARRAY) );
        int retrunValueARRAY[] = {0, 1, 2, 3, 5, 6, 7, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxesOfTheRoundTable theObject;
        eq(3, theObject.minimalDifference(h),retrunValue);
    }
    {
        int hARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
        vector <int> h( hARRAY, hARRAY+ARRSIZE(hARRAY) );
        int retrunValueARRAY[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FoxesOfTheRoundTable theObject;
        eq(4, theObject.minimalDifference(h),retrunValue);
    }
	return 0;
}
// END CUT HERE
