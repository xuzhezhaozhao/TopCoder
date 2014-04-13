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

class LISNumberDivTwo {
public:
    int calculate(vector <int> seq) {
	int res = 1;

	for (int i = 1; i < seq.size(); i++) {
		if (seq[i] <= seq[i - 1]) {
			++res;
		}
	}
	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int seqARRAY[] = {1, 4, 4, 2, 6, 3};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	LISNumberDivTwo theObject;
	eq(0, theObject.calculate(seq),4);
    }
    {
	int seqARRAY[] = {5, 8, 9, 12, 16, 32, 50};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	LISNumberDivTwo theObject;
	eq(1, theObject.calculate(seq),1);
    }
    {
	int seqARRAY[] = {1, 1, 9, 9, 2, 2, 3, 3};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	LISNumberDivTwo theObject;
	eq(2, theObject.calculate(seq),6);
    }
    {
	int seqARRAY[] = {50, 40, 30, 20, 10};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	LISNumberDivTwo theObject;
	eq(3, theObject.calculate(seq),5);
    }
    {
	int seqARRAY[] = {42};
	vector <int> seq( seqARRAY, seqARRAY+ARRSIZE(seqARRAY) );
	LISNumberDivTwo theObject;
	eq(4, theObject.calculate(seq),1);
    }
}
// END CUT HERE
