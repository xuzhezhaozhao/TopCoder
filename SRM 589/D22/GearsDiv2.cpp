#include <algorithm>
#include <iostream>
#include <sstream>

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

/*************** Program Begin **********************/

class GearsDiv2 {
public:
    int getmin(string Directions) {
	int res = 0;
	Directions = Directions + Directions[0];
	char pre;
	int N = Directions.size();
	pre = Directions[0];
	for (int i = 1; i < N; i++) {
		if (Directions[i] == pre) {
			++res;
			pre = '#';
		} else {
			pre = Directions[i];
		}
	}
	int temp = res;
	res = 1;
	pre = ' ';
	for (int i = 1; i < N-1; i++) {
		if (Directions[i] == pre) {
			++res;
			pre = '#';
		} else {
			pre = Directions[i];
		}
	}
	res = min(temp, res);
	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	GearsDiv2 theObject;
	eq(0, theObject.getmin("LRRR"),1);
    }
    {
	GearsDiv2 theObject;
	eq(1, theObject.getmin("RRR"),2);
    }
    {
	GearsDiv2 theObject;
	eq(2, theObject.getmin("LRLR"),0);
    }
    {
	GearsDiv2 theObject;
	eq(3, theObject.getmin("LRLLRRLLLRRRLLLL"),6);
    }
    {
	GearsDiv2 theObject;
	eq(4, theObject.getmin("RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"),14);
    }
}
// END CUT HERE
