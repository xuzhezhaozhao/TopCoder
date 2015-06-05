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

class FoxAndChess {
public:
	string ableToMove(string begin, string target) {
		string res = "Possible";
		int N = begin.size();
		int p = 0;
		for (int i = 0; i < N; i++) {
			bool ok = true;
			if ('L' == begin[i]) {
				ok = false;
				for (int j = p; j < N; j++) {
					if ('L' == target[j]) {
						if (j > i) {
							ok = false;
							break;
						} else {
							ok = true;
							p = j + 1;
							break;
						}
					} else if ('R' == target[j]) {
						ok = false;
						break;
					}
				}
			} else if ('R' == begin[i]) {
				ok = false;
				for (int j = p; j < N; j++) {
					if ('R' == target[j]) {
						if (j < i) {
							ok = false;
							break;
						} else {
							ok = true;
							p = j + 1;
							break;
						}
					} else if ('L' == target[j]) {
						ok = false;
						break;
					}
				}
			}
			if (!ok) {
				res = "Impossible";
				break;
			}
		}
		for (int i = p; i < N; i++) {
			if ('R' == target[i] || 'L' == target[i]) {
				res = "Impossible";
			}
		}
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		FoxAndChess theObject;
		eq(0, theObject.ableToMove("...", "..L"),"Impossible");
	}
	{
		FoxAndChess theObject;
		eq(1, theObject.ableToMove("..R.", "R..."),"Impossible");
	}
	{
		FoxAndChess theObject;
		eq(2, theObject.ableToMove(".L.R.R.", "L...R.R"),"Possible");
	}
	{
		FoxAndChess theObject;
		eq(3, theObject.ableToMove(".L.R.", ".R.L."),"Impossible");
	}
	{
		FoxAndChess theObject;
		eq(4, theObject.ableToMove("LRLLRLRLLRLLRLRLRL", "LRLLRLRLLRLLRLRLRL"),"Possible");
	}
	{
		FoxAndChess theObject;
		eq(5, theObject.ableToMove("L", "."),"Impossible");
	}
}
// END CUT HERE
