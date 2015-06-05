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
class ArcadeManao {
private:
	bool v[50][50];
	int M, N, L;
	vector <string> lev;
	void DFS(int x, int y) 
	{
		v[x][y] = true;
		// ◊Û
		if (y-1 >= 0 && 'X' == lev[x][y-1] && !v[x][y-1]) {
			DFS(x, y-1);
		}
		// ”“
		if (y+1 <= M-1 && 'X' == lev[x][y+1] && !v[x][y+1]) {
			DFS(x, y+1);
		}
		//  ˙÷±∑ΩœÚ
		for (int i = 0; i < N; i++) {
			if (abs(x-i) <= L && 'X' == lev[i][y] && !v[i][y]) {
				DFS(i, y);
			}
		}
	}
public:
    int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
	int res = 0;
	N = level.size();
	M = level[0].size();
	lev = level;

	for (int i = 0; i < N; i++) {
		memset(v, 0, sizeof(v));
		L = i;
		DFS(N-1, 0);
		if (v[coinRow-1][coinColumn-1]) {
			res = i;
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
	string levelARRAY[] = {
	    "XXXX....",
	    "...X.XXX",
	    "XXX..X..",
	    "......X.",
	    "XXXXXXXX"};
	vector <string> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
	ArcadeManao theObject;
	eq(0, theObject.shortestLadder(level, 2, 4),2);
    }
    {
	string levelARRAY[] = {
	    "XXXX",
	    "...X",
	    "XXXX"};
	vector <string> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
	ArcadeManao theObject;
	eq(1, theObject.shortestLadder(level, 1, 1),1);
    }
    {
	string levelARRAY[] = {
	    "..X..",
	    ".X.X.",
	    "X...X",
	    ".X.X.",
	    "..X..",
	    "XXXXX"};
	vector <string> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
	ArcadeManao theObject;
	eq(2, theObject.shortestLadder(level, 1, 3),4);
    }
    {
	string levelARRAY[] = {"X"};
	vector <string> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
	ArcadeManao theObject;
	eq(3, theObject.shortestLadder(level, 1, 1),0);
    }
    {
	string levelARRAY[] = {
	    "XXXXXXXXXX",
	    "...X......",
	    "XXX.......",
	    "X.....XXXX",
	    "..XXXXX..X",
	    ".........X",
	    ".........X",
	    "XXXXXXXXXX"};
	vector <string> level( levelARRAY, levelARRAY+ARRSIZE(levelARRAY) );
	ArcadeManao theObject;
	eq(4, theObject.shortestLadder(level, 1, 1),2);
    }
}
// END CUT HERE