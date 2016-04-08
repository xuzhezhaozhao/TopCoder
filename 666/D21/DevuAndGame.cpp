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

class DevuAndGame {
public:
    string canWin(vector <int> nextLevel) {
		bool visited[51] = {false};
		int c = 0;
		while ( c != -1 && !visited[c] ) {
			visited[c] = true;
			c = nextLevel[c];
		}
		return c == -1 ? "Win" : "Lose";
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
        int nextLevelARRAY[] = {1, -1};
        vector <int> nextLevel( nextLevelARRAY, nextLevelARRAY+ARRSIZE(nextLevelARRAY) );
        DevuAndGame theObject;
        eq(0, theObject.canWin(nextLevel),"Win");
    }
    {
        int nextLevelARRAY[] = {1, 0, -1};
        vector <int> nextLevel( nextLevelARRAY, nextLevelARRAY+ARRSIZE(nextLevelARRAY) );
        DevuAndGame theObject;
        eq(1, theObject.canWin(nextLevel),"Lose");
    }
    {
        int nextLevelARRAY[] = {0, 1, 2};
        vector <int> nextLevel( nextLevelARRAY, nextLevelARRAY+ARRSIZE(nextLevelARRAY) );
        DevuAndGame theObject;
        eq(2, theObject.canWin(nextLevel),"Lose");
    }
    {
        int nextLevelARRAY[] = {29,33,28,16,-1,11,10,14,6,31,7,35,34,8,15,17,26,12,13,22,1,20,2,21,-1,5,19,9,18,4,25,32,3,30,23,10,27};
        vector <int> nextLevel( nextLevelARRAY, nextLevelARRAY+ARRSIZE(nextLevelARRAY) );
        DevuAndGame theObject;
        eq(3, theObject.canWin(nextLevel),"Win");
    }
    {
        int nextLevelARRAY[] = {17,43,20,41,42,15,18,35,-1,31,7,33,23,33,-1,-1,0,33,19,12,42,-1,-1,9,9,-1,39,-1,31,46,-1,20,44,41,-1,-1,12,-1,36,-1,-1,6,47,10,2,4,1,29};
        vector <int> nextLevel( nextLevelARRAY, nextLevelARRAY+ARRSIZE(nextLevelARRAY) );
        DevuAndGame theObject;
        eq(4, theObject.canWin(nextLevel),"Win");
    }
    {
        int nextLevelARRAY[] = {3, 1, 1, 2, -1, 4};
        vector <int> nextLevel( nextLevelARRAY, nextLevelARRAY+ARRSIZE(nextLevelARRAY) );
        DevuAndGame theObject;
        eq(5, theObject.canWin(nextLevel),"Lose");
    }
	return 0;
}
// END CUT HERE
