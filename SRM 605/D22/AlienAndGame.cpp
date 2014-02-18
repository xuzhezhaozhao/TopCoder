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

class AlienAndGame {
public:
    int getNumber(vector <string> board) {
	int rows = board.size();
	int cols = board[0].size();
	int n = min(board.size(), board[0].size());
	
	for (; n >= 1; n--) {	// 从大到小枚举各个可能的 正方形边长
		for (int j = 0; j < rows - n + 1; j++) {
			for (int k = 0; k < cols - n + 1; k++) {
				// 判断以board[j][k]为正方形左上顶点时是否有边长为n的正方形
				bool flag_row;
				for (int s = 0; s < n; s++) {
					flag_row = true;
					for (int t = 0; t < n; t++) {
						if ( board[j+s][k] != board[j+s][k+t] ) {
							flag_row = false;
							break;
						}
					}
					if (!flag_row) {
						break;
					}
				}
				if (flag_row) {
					return n * n;
				}
			}
		}
	}
	return 1;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string boardARRAY[] = {"BB",
            "WW"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(0, theObject.getNumber(board),4);
    }
    {
        string boardARRAY[] = {"W"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(1, theObject.getNumber(board),1);
    }
    {
        string boardARRAY[] = {"WBBB",
            "WBBB",
            "WWWW"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(2, theObject.getNumber(board),9);
    }
    {
        string boardARRAY[] = {"W",
            "B",
            "W",
            "W",
            "W"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(3, theObject.getNumber(board),1);
    }
    {
        string boardARRAY[] = {"BWBBWBB",
            "WWBWWBW",
            "BBBBBBW",
            "WBBBBWB",
            "BBWWWWB",
            "WWWWWWW",
            "BBWWBBB"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        AlienAndGame theObject;
        eq(4, theObject.getNumber(board),9);
    }
}
// END CUT HERE
