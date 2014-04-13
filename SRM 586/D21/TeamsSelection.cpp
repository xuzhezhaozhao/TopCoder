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

class TeamsSelection {
public:
    string simulate(vector <int> preference1, vector <int> preference2) {
	char res[100];

	set <int> s;
	for (int i = 0; i < preference1.size(); i++) {
		for (int j = 0; j < preference1.size(); j++) {
			if (s.insert(preference1[j]).second) {
				res[preference1[j]-1] = '1';
				break;
			}
		}
		for (int j = 0; j < preference2.size(); j++) {
			if (s.insert(preference2[j]).second) {
				res[preference2[j]-1] = '2';
				break;
			}
		}
	}
	res[preference1.size()] = '\0';

	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	int preference1ARRAY[] = {1, 2, 3, 4};
	vector <int> preference1( preference1ARRAY, preference1ARRAY+ARRSIZE(preference1ARRAY) );
	int preference2ARRAY[] = {1, 2, 3, 4};
	vector <int> preference2( preference2ARRAY, preference2ARRAY+ARRSIZE(preference2ARRAY) );
	TeamsSelection theObject;
	eq(0, theObject.simulate(preference1, preference2),"1212");
    }
    {
	int preference1ARRAY[] = {3, 2, 1};
	vector <int> preference1( preference1ARRAY, preference1ARRAY+ARRSIZE(preference1ARRAY) );
	int preference2ARRAY[] = {1, 3, 2};
	vector <int> preference2( preference2ARRAY, preference2ARRAY+ARRSIZE(preference2ARRAY) );
	TeamsSelection theObject;
	eq(1, theObject.simulate(preference1, preference2),"211");
    }
    {
	int preference1ARRAY[] = {6, 1, 5, 2, 3, 4};
	vector <int> preference1( preference1ARRAY, preference1ARRAY+ARRSIZE(preference1ARRAY) );
	int preference2ARRAY[] = {1, 6, 3, 4, 5, 2};
	vector <int> preference2( preference2ARRAY, preference2ARRAY+ARRSIZE(preference2ARRAY) );
	TeamsSelection theObject;
	eq(2, theObject.simulate(preference1, preference2),"212211");
    }
    {
	int preference1ARRAY[] = {8, 7, 1, 2, 4, 5, 6, 3, 9};
	vector <int> preference1( preference1ARRAY, preference1ARRAY+ARRSIZE(preference1ARRAY) );
	int preference2ARRAY[] = {7, 2, 4, 8, 1, 5, 9, 6, 3};
	vector <int> preference2( preference2ARRAY, preference2ARRAY+ARRSIZE(preference2ARRAY) );
	TeamsSelection theObject;
	eq(3, theObject.simulate(preference1, preference2),"121121212");
    }
}
// END CUT HERE
