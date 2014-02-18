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

class KeyDungeonDiv2 {
public:
    int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
	int res = 0;
	for (int i = 0; i < doorG.size(); i++) {
		int wr = keys[0] - doorR[i];
		int wd = keys[1] - doorG[i];
		if (wr > 0) {
			wr = 0;
		}
		if (wd > 0) {
			wd = 0;
		}

		if ( keys[2] + wr + wd >= 0 ) {
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
	int doorRARRAY[] = {2, 0, 5, 3};
	vector <int> doorR( doorRARRAY, doorRARRAY+ARRSIZE(doorRARRAY) );
	int doorGARRAY[] = {1, 4, 0, 2};
	vector <int> doorG( doorGARRAY, doorGARRAY+ARRSIZE(doorGARRAY) );
	int keysARRAY[] = {2, 3, 1};
	vector <int> keys( keysARRAY, keysARRAY+ARRSIZE(keysARRAY) );
	KeyDungeonDiv2 theObject;
	eq(0, theObject.countDoors(doorR, doorG, keys),3);
    }
    {
	int doorRARRAY[] = {0, 1, 2, 0};
	vector <int> doorR( doorRARRAY, doorRARRAY+ARRSIZE(doorRARRAY) );
	int doorGARRAY[] = {0, 2, 3, 1};
	vector <int> doorG( doorGARRAY, doorGARRAY+ARRSIZE(doorGARRAY) );
	int keysARRAY[] = {0, 0, 0};
	vector <int> keys( keysARRAY, keysARRAY+ARRSIZE(keysARRAY) );
	KeyDungeonDiv2 theObject;
	eq(1, theObject.countDoors(doorR, doorG, keys),1);
    }
    {
	int doorRARRAY[] = {3, 5, 4, 2, 8};
	vector <int> doorR( doorRARRAY, doorRARRAY+ARRSIZE(doorRARRAY) );
	int doorGARRAY[] = {4, 2, 3, 8, 1};
	vector <int> doorG( doorGARRAY, doorGARRAY+ARRSIZE(doorGARRAY) );
	int keysARRAY[] = {0, 0, 10};
	vector <int> keys( keysARRAY, keysARRAY+ARRSIZE(keysARRAY) );
	KeyDungeonDiv2 theObject;
	eq(2, theObject.countDoors(doorR, doorG, keys),5);
    }
    {
	int doorRARRAY[] = {4, 5, 4, 6, 8};
	vector <int> doorR( doorRARRAY, doorRARRAY+ARRSIZE(doorRARRAY) );
	int doorGARRAY[] = {2, 1, 2, 3, 5};
	vector <int> doorG( doorGARRAY, doorGARRAY+ARRSIZE(doorGARRAY) );
	int keysARRAY[] = {1, 2, 1};
	vector <int> keys( keysARRAY, keysARRAY+ARRSIZE(keysARRAY) );
	KeyDungeonDiv2 theObject;
	eq(3, theObject.countDoors(doorR, doorG, keys),0);
    }
    {
	int doorRARRAY[] = {41,44,41,57,58,74,84,100,58,2,43,32,82,97,44,13,35,98,96,81,43,77,18,51,27,
	    27,39,39,45,82,59,20,28,93,6,39,64,78,28,85,17,56,3,68,4,0,36,80,41,77};
	vector <int> doorR( doorRARRAY, doorRARRAY+ARRSIZE(doorRARRAY) );
	int doorGARRAY[] = {67,15,53,36,88,29,26,57,68,99,97,27,51,70,3,49,65,75,35,92,66,0,23,96,38,86,
	    98,31,26,75,30,2,92,78,100,99,38,26,85,74,77,15,16,48,100,88,55,93,99,54};
	vector <int> doorG( doorGARRAY, doorGARRAY+ARRSIZE(doorGARRAY) );
	int keysARRAY[] = {39,31,34};
	vector <int> keys( keysARRAY, keysARRAY+ARRSIZE(keysARRAY) );
	KeyDungeonDiv2 theObject;
	eq(4, theObject.countDoors(doorR, doorG, keys),17);
    }
}
// END CUT HERE
