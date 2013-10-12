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

class FoxAndGomoku {
public:
    string win(vector <string> board) {
        string res = "";

	int n = board.size();
	// 行
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			if ('o' == board[i][j]) {
				++c;
			} else {
				c = 0;
			}
			if (5 == c) {
				return "found";
			}
		}
	}
	// 列
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			if ('o' == board[j][i]) {
				++c;
			} else {
				c = 0;
			}
			if (5 == c) {
				return "found";
			}
		}
	}

	// 右对角
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (i + j < n) {
				if ('o' == board[i+j][j]) {
					++c;
				} else {
					c = 0;
				}
			}
			if (5 == c) {
				return "found";
			}
		}
	}
	// 左对角
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (i - j >= 0) {
				if ('o' == board[i-j][j]) {
					++c;
				} else {
					c = 0;
				}
			}
			if (5 == c) {
				return "found";
			}
		}
	}
        return "not found";
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string boardARRAY[] = {"....o.",
            "...o..",
            "..o...",
            ".o....",
            "o.....",
            "......"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(0, theObject.win(board),"found");
    }
    {
        string boardARRAY[] = {"oooo.",
            ".oooo",
            "oooo.",
            ".oooo",
            "....."}
            ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(1, theObject.win(board),"not found");
    }
    {
        string boardARRAY[] = {"oooo.",
            ".oooo",
            "oooo.",
            ".oooo",
            "....o"}
            ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(2, theObject.win(board),"found");
    }
    {
        string boardARRAY[] = {"o.....",
            ".o....",
            "..o...",
            "...o..",
            "....o.",
            "......"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(3, theObject.win(board),"found");
    }
    {
        string boardARRAY[] = {"o....",
            "o.o..",
            "o.o.o",
            "o.o..",
            "o...."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(4, theObject.win(board),"found");
    }
    {
        string boardARRAY[] = {"..........",
            "..........",
            "..oooooo..",
            "..o.......",
            "..o.......",
            "..oooooo..",
            ".......o..",
            ".......o..",
            "..oooooo..",
            ".........."}
            
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(5, theObject.win(board),"found");
    }
    {
        string boardARRAY[] = {"..........",
            "..........",
            "..oooo.o..",
            "..o.......",
            "..o.......",
            "..o.oooo..",
            ".......o..",
            ".......o..",
            "..oooo.o..",
            ".........."}
           ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(6, theObject.win(board),"not found");
    }
    {
        string boardARRAY[] = {"ooooo",
            "ooooo",
            "ooooo",
            "ooooo",
            "ooooo"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(7, theObject.win(board),"found");
    }
    {
        string boardARRAY[] = {".....",
            ".....",
            ".....",
            ".....",
            "....."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        FoxAndGomoku theObject;
        eq(8, theObject.win(board),"not found");
    }
}
// END CUT HERE
