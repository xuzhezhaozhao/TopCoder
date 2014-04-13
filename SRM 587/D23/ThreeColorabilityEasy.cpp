#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>

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
#include <cstring>

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
class ThreeColorabilityEasy {
public:
    string isColorable(vector <string> cells) {
	for (int i = 0; i < cells.size() - 1; i++) {
		for (int j = 0; j < cells[0].size() - 1; j++) {
			int n = 0;
			
			n += cells[i][j] == 'N' ? 1 : 0;
			n += cells[i][j+1] == 'N' ? 1 : 0;
			n += cells[i+1][j] == 'N' ? 1 : 0;
			n += cells[i+1][j+1] == 'N' ? 1 : 0;
			if (n == 1 || n == 3) {
				return "No";
			}
		}
	}

	return "Yes";
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	string cellsARRAY[] = {"Z"};
	vector <string> cells( cellsARRAY, cellsARRAY+ARRSIZE(cellsARRAY) );
	ThreeColorabilityEasy theObject;
	eq(0, theObject.isColorable(cells),"Yes");
    }
    {
	string cellsARRAY[] = {"NZ"
	   ,"NZ"};
	vector <string> cells( cellsARRAY, cellsARRAY+ARRSIZE(cellsARRAY) );
	ThreeColorabilityEasy theObject;
	eq(1, theObject.isColorable(cells),"Yes");
    }
    {
	string cellsARRAY[] = {"ZZZ"
	   ,"ZNZ"};
	vector <string> cells( cellsARRAY, cellsARRAY+ARRSIZE(cellsARRAY) );
	ThreeColorabilityEasy theObject;
	eq(2, theObject.isColorable(cells),"No");
    }
    {
	string cellsARRAY[] = {"NZNZNNN"
	   ,"NNZNNNZ"
	   ,"NNNNZZZ"
	   ,"ZZZNZZN"
	   ,"ZZNZNNN"
	   ,"NZZZZNN"
	   ,"ZZZNZNN"};
	vector <string> cells( cellsARRAY, cellsARRAY+ARRSIZE(cellsARRAY) );
	ThreeColorabilityEasy theObject;
	eq(3, theObject.isColorable(cells),"No");
    }
    {
	string cellsARRAY[] = {"ZZZZ"
	   ,"ZZZZ"
	   ,"ZZZZ"};
	vector <string> cells( cellsARRAY, cellsARRAY+ARRSIZE(cellsARRAY) );
	ThreeColorabilityEasy theObject;
	eq(4, theObject.isColorable(cells),"Yes");
    }
}
// END CUT HERE
