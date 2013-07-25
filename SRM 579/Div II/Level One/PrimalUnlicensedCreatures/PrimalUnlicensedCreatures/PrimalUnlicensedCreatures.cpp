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

class PrimalUnlicensedCreatures {
public:
    int maxWins(int initialLevel, vector <int> grezPower) {
	int res = 0;
	int pow = initialLevel;
	sort(grezPower.begin(), grezPower.end());
	for (int i = 0; i < grezPower.size(); i++) {
		if (pow > grezPower[i]) {
			++res;
			pow += grezPower[i] / 2;
		} else {
			break;
		}
	}
	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int grezPowerARRAY[] = {10, 20, 30};
	vector <int> grezPower( grezPowerARRAY, grezPowerARRAY+ARRSIZE(grezPowerARRAY) );
	PrimalUnlicensedCreatures theObject;
	eq(0, theObject.maxWins(31, grezPower),3);
    }
    {
	int grezPowerARRAY[] = {24, 5, 6, 38};
	vector <int> grezPower( grezPowerARRAY, grezPowerARRAY+ARRSIZE(grezPowerARRAY) );
	PrimalUnlicensedCreatures theObject;
	eq(1, theObject.maxWins(20, grezPower),3);
    }
    {
	int grezPowerARRAY[] = {3, 3, 3, 3, 3, 1, 25 };
	vector <int> grezPower( grezPowerARRAY, grezPowerARRAY+ARRSIZE(grezPowerARRAY) );
	PrimalUnlicensedCreatures theObject;
	eq(2, theObject.maxWins(20, grezPower),6);
    }
    {
	int grezPowerARRAY[] = {3, 13, 6, 4, 9};
	vector <int> grezPower( grezPowerARRAY, grezPowerARRAY+ARRSIZE(grezPowerARRAY) );
	PrimalUnlicensedCreatures theObject;
	eq(3, theObject.maxWins(4, grezPower),5);
    }
    {
	int grezPowerARRAY[] = {7, 8, 9, 10};
	vector <int> grezPower( grezPowerARRAY, grezPowerARRAY+ARRSIZE(grezPowerARRAY) );
	PrimalUnlicensedCreatures theObject;
	eq(4, theObject.maxWins(7, grezPower),0);
    }
}
// END CUT HERE
