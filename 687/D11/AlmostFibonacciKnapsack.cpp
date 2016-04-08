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


class AlmostFibonacciKnapsack {
public:
	vector <long long> seq;


	void solve(long long x, int p, vector <int> &res) {
		if (p < 0) {
			return;
		}

		if (x == seq[p]) {
			res.push_back(p+1);
			return;
		}

		if (x - seq[p] > 1) {
			res.push_back(p+1);
			solve(x - seq[p], p-1, res);
		} else {
			solve(x, p-1, res);
		}
	}

    vector <int> getIndices(long long x) {
		long long a = 2, b = 3;
		seq.push_back(2);
		seq.push_back(3);
		for (int i = 3; b <= x; i++) {
			long long t = b;
			b = a + b - 1;
			a = t;
			if (b <= x) {
				seq.push_back(b);
			}
		}

		vector <int> res;
		solve(x, seq.size()-1, res);
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
        int retrunValueARRAY[] = {6, 10, 8, 5 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AlmostFibonacciKnapsack theObject;
        eq(0, theObject.getIndices(148L),retrunValue);
    }
    {
        int retrunValueARRAY[] = {1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AlmostFibonacciKnapsack theObject;
        eq(1, theObject.getIndices(2L),retrunValue);
    }
    {
        int retrunValueARRAY[] = {2, 3, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AlmostFibonacciKnapsack theObject;
        eq(2, theObject.getIndices(13L),retrunValue);
    }
    {
        int retrunValueARRAY[] = {2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AlmostFibonacciKnapsack theObject;
        eq(3, theObject.getIndices(3L),retrunValue);
    }
    {
        int retrunValueARRAY[] = {3, 14, 15, 9, 26, 53, 5, 8 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        AlmostFibonacciKnapsack theObject;
        eq(4, theObject.getIndices(86267769395L),retrunValue);
    }
	return 0;
}
// END CUT HERE
