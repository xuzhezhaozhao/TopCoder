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

/************** Program Begin *********************/

class UndoHistory {
public:
    int minPresses(vector <string> lines) {
	int res = 0;
	string buf = "";
	set <string> his;
	his.insert("");
	int buf_size, his_size;
	for (int i = 0; i < lines.size(); i++) {
		buf_size = buf.size();
		his_size = 0;
		for (int j = lines[i].size(); j >= 1; j--) {
			if ( !his.insert(lines[i].substr(0, j)).second ) {
				his_size = j;
				break;
			}
		}
		/* use buf */
		if (his_size < buf_size + 2 && buf == lines[i].substr(0, buf_size)) {
			res += lines[i].size() - buf_size + 1;
			for (int j = buf_size + 1; j <= lines[i].size(); j++) {
				his.insert(lines[i].substr(0, j));
			}
		}
		/* use history */
		else if (his_size > 0) {
			res += lines[i].size() - his_size + 3;
			for (int j = his_size + 1; j <= lines[i].size(); j++) {
				his.insert(lines[i].substr(0, j));
			}
		}
		/* from empty */
		else {
			res += lines[i].size() + 3;
			for (int j = 1; j <= lines[i].size(); j++) {
				his.insert(lines[i].substr(0, j));
			}
		}
		/* update buf */
		buf = lines[i];
	}

	return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	string linesARRAY[] = {"tomorrow", "topcoder"};
	vector <string> lines( linesARRAY, linesARRAY+ARRSIZE(linesARRAY) );
	UndoHistory theObject;
	eq(0, theObject.minPresses(lines),18);
    }
    {
	string linesARRAY[] = {"a","b"};
	vector <string> lines( linesARRAY, linesARRAY+ARRSIZE(linesARRAY) );
	UndoHistory theObject;
	eq(1, theObject.minPresses(lines),6);
    }
    {
	string linesARRAY[] = {"a", "ab", "abac", "abacus" };
	vector <string> lines( linesARRAY, linesARRAY+ARRSIZE(linesARRAY) );
	UndoHistory theObject;
	eq(2, theObject.minPresses(lines),10);
    }
    {
	string linesARRAY[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
	vector <string> lines( linesARRAY, linesARRAY+ARRSIZE(linesARRAY) );
	UndoHistory theObject;
	eq(3, theObject.minPresses(lines),39);
    }
    {
	string linesARRAY[] = {"ba","a","a","b","ba"}
	   ;
	vector <string> lines( linesARRAY, linesARRAY+ARRSIZE(linesARRAY) );
	UndoHistory theObject;
	eq(4, theObject.minPresses(lines),13);
    }
}
// END CUT HERE