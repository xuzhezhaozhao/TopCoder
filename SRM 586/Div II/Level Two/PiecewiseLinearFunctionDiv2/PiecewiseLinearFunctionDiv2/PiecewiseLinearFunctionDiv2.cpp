#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>

using namespace std;

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
	if ( i != 0 ) cerr << ", ";
	print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
	cerr << "Case " << n << " passed." << endl;
    } else {
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
	print( have );
	print( need );
	return;
    }
    for( int i= 0; i < have.size(); i++ ) {
	if( have[i] != need[i] ) {
	    cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
	    print( have );
	    print( need );
	    return;
	}
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
	cerr << "Case " << n << " passed." << endl;
    } else {
	cerr << "Case " << n << " failed: expected ";
	print( need );
	cerr << " received ";
	print( have );
	cerr << "." << endl;
    }
}
// END CUT HERE

/************** Program  Begin *********************/

class PiecewiseLinearFunctionDiv2 {
public:
    vector <int> countSolutions(vector <int> Y, vector <int> query) {
	vector <int> res(query.size(), 0);

	for (int i = 0; i < query.size(); i++) {
		for (int j = 0; j < Y.size() - 1; j++) {
			if ( 
				(query[i] > Y[j] && query[i] < Y[j+1]) ||
				(query[i] < Y[j] && query[i] > Y[j+1]) ) {
				if (Y[j] == Y[j+1]) {
					res[i] = -1;
				} else if (res[i] != -1) {
					++res[i];
				}
			}
		}
		for (int j = 0; j < Y.size(); j++) {
			if (query[i] == Y[j] && res[i] != -1) {
				++res[i];
			}
		}
		for (int j = 0; j < Y.size()-1; j++) {
			if (query[i] == Y[j] && Y[j] == Y[j+1]) {
				res[i] = -1;
			}
		}
	}

	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int YARRAY[] = {1, 4, -1, 2};
	vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
	int queryARRAY[] = {-2, -1, 0, 1};
	vector <int> query( queryARRAY, queryARRAY+ARRSIZE(queryARRAY) );
	int retrunValueARRAY[] = {0, 1, 2, 3 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	PiecewiseLinearFunctionDiv2 theObject;
	eq(0, theObject.countSolutions(Y, query),retrunValue);
    }
    {
	int YARRAY[] = {0, 0};
	vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
	int queryARRAY[] = {-1, 0, 1};
	vector <int> query( queryARRAY, queryARRAY+ARRSIZE(queryARRAY) );
	int retrunValueARRAY[] = {0, -1, 0 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	PiecewiseLinearFunctionDiv2 theObject;
	eq(1, theObject.countSolutions(Y, query),retrunValue);
    }
    {
	int YARRAY[] = {2, 4, 8, 0, 3, -6, 10};
	vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
	int queryARRAY[] = {0, 1, 2, 3, 4, 0, 65536};
	vector <int> query( queryARRAY, queryARRAY+ARRSIZE(queryARRAY) );
	int retrunValueARRAY[] = {3, 4, 5, 4, 3, 3, 0 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	PiecewiseLinearFunctionDiv2 theObject;
	eq(2, theObject.countSolutions(Y, query),retrunValue);
    }
    {
	int YARRAY[] = {-178080289, -771314989, -237251715, -949949900, -437883156, -835236871, -316363230, -929746634, -671700962}
	   ;
	vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
	int queryARRAY[] = {-673197622, -437883156, -251072978, 221380900, -771314989, -949949900, -910604034, -671700962, -929746634, -316363230};
	vector <int> query( queryARRAY, queryARRAY+ARRSIZE(queryARRAY) );
	int retrunValueARRAY[] = {8, 6, 3, 0, 7, 1, 4, 8, 3, 4 };
	vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
	PiecewiseLinearFunctionDiv2 theObject;
	eq(3, theObject.countSolutions(Y, query),retrunValue);
    }
}
// END CUT HERE
