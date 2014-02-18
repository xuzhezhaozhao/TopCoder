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
bool cell[60][60];

class GooseInZooDivTwo {
private:
	void dfs(vector <string> & field, int a, int b, int dist)
	{
		for (int i = 0; i < field.size(); i++) {
			for (int j = 0; j < field[0].size(); j++) {
				if (0 == cell[i][j] && abs(a-i) + abs(b-j) <= dist) {
					cell[i][j] = true;
					dfs(field, i, j, dist);
				}
			}
		}
	}
public:
    int count(vector <string> field, int dist) {
	int res = 1;

	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field[0].size(); j++) {
			if ('.' == field[i][j]) {
				cell[i][j] = true;
			} else {
				cell[i][j] = false;
			}	
		}
	}
	int kind = 0;
	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j <field[0].size(); j++) {
			if (0 == cell[i][j]) {
				dfs(field, i, j, dist);
				++kind;
			}
		}
	}

	/* (2 ^ kind - 1) % 1000000007 */
	while (kind) {
		res = (2 * res) % 1000000007;
		--kind;
	}
	return res - 1;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
	string fieldARRAY[] = {".vv..v.........v....", "....v.......vv...vvv", "...vv.v....v..vv....", "v......v....vv...v..", "..v..v..vv.v..vv....", "..v....v.v.....v...v", ".v......v..vv...v...", "vv..............v...", "..v..v.....vv.v.v..v", "v.........vv...v....", "......v..v.v.....v..", ".....v.....v....v..v", "..v.v....v.v.....v..", "..v.......vvv.....v.", "....v....v.vv.....v.", ".v...v.............v", "..vv.....v.........v", "..v.................", "v.........v.........", "v...........v....v..", "v.......v..........."};

	vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
	GooseInZooDivTwo theObject;
	eq(0, theObject.count(field, 0),560523803);
    }
    {
	string fieldARRAY[] = {"."};
	vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
	GooseInZooDivTwo theObject;
	eq(1, theObject.count(field, 100),0);
    }
    {
	string fieldARRAY[] = {"vvv"};
	vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
	GooseInZooDivTwo theObject;
	eq(2, theObject.count(field, 1),1);
    }
    {
	string fieldARRAY[] = {"v.v..................v............................"
	   ,".v......v..................v.....................v"
	   ,"..v.....v....v.........v...............v......v..."
	   ,".........vvv...vv.v.........v.v..................v"
	   ,".....v..........v......v..v...v.......v..........."
	   ,"...................vv...............v.v..v.v..v..."
	   ,".v.vv.................v..............v............"
	   ,"..vv.......v...vv.v............vv.....v.....v....."
	   ,"....v..........v....v........v.......v.v.v........"
	   ,".v.......v.............v.v..........vv......v....."
	   ,"....v.v.......v........v.....v.................v.."
	   ,"....v..v..v.v..............v.v.v....v..........v.."
	   ,"..........v...v...................v..............v"
	   ,"..v........v..........................v....v..v..."
	   ,"....................v..v.........vv........v......"
	   ,"..v......v...............................v.v......"
	   ,"..v.v..............v........v...............vv.vv."
	   ,"...vv......v...............v.v..............v....."
	   ,"............................v..v.................v"
	   ,".v.............v.......v.........................."
	   ,"......v...v........................v.............."
	   ,".........v.....v..............vv.................."
	   ,"................v..v..v.........v....v.......v...."
	   ,"........v.....v.............v......v.v............"
	   ,"...........v....................v.v....v.v.v...v.."
	   ,"...........v......................v...v..........."
	   ,"..........vv...........v.v.....................v.."
	   ,".....................v......v............v...v...."
	   ,".....vv..........................vv.v.....v.v....."
	   ,".vv.......v...............v.......v..v.....v......"
	   ,"............v................v..........v....v...."
	   ,"................vv...v............................"
	   ,"................v...........v........v...v....v..."
	   ,"..v...v...v.............v...v........v....v..v...."
	   ,"......v..v.......v........v..v....vv.............."
	   ,"...........v..........v........v.v................"
	   ,"v.v......v................v....................v.."
	   ,".v........v................................v......"
	   ,"............................v...v.......v........."
	   ,"........................vv.v..............v...vv.."
	   ,".......................vv........v.............v.."
	   ,"...v.............v.........................v......"
	   ,"....v......vv...........................v........."
	   ,"....vv....v................v...vv..............v.."
	   ,".................................................."
	   ,"vv........v...v..v.....v..v..................v...."
	   ,".........v..............v.vv.v.............v......"
	   ,".......v.....v......v...............v............."
	   ,"..v..................v................v....v......"
	   ,".....v.....v.....................v.v......v......."};
	vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
	GooseInZooDivTwo theObject;
	eq(3, theObject.count(field, 3),797922654);
    }
}
// END CUT HERE
