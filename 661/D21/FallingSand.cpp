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

class FallingSand {
public:
    vector <string> simulate(vector <string> board) {
        vector <string> res = board;
		int R = board.size();
		int C = board[0].size();

		for (int col = 0; col < C; col++) {
			for (int row = R - 2; row >= 0; row--) {
				if (res[row][col] == 'o') {
					res[row][col] = '.';
					int pos = row;
					while (pos <= R - 1 && res[pos][col] == '.') {
						++pos;
					}
					--pos;
					res[pos][col] = 'o';
				}
			}
		}
        return res;
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
        string boardARRAY[] = {"ooooo",
            "..x..",
            "....x",
            ".....",
            "....o"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        string retrunValueARRAY[] = {"..o..", "..x.o", "....x", ".....", "oo.oo" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingSand theObject;
        eq(0, theObject.simulate(board),retrunValue);
    }
    {
        string boardARRAY[] = {"..o..", 
            "..x.o", 
            "....x", 
            ".....", 
            "oo.oo" };
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        string retrunValueARRAY[] = {"..o..", "..x.o", "....x", ".....", "oo.oo" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingSand theObject;
        eq(1, theObject.simulate(board),retrunValue);
    }
    {
        string boardARRAY[] = {"ooooxooo.ooxo.oxoxoooox.....x.oo"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        string retrunValueARRAY[] = {"ooooxooo.ooxo.oxoxoooox.....x.oo" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingSand theObject;
        eq(2, theObject.simulate(board),retrunValue);
    }
    {
        string boardARRAY[] = {"o",
            ".",
            "o",
            ".",
            "o",
            ".",
            "."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        string retrunValueARRAY[] = {".", ".", ".", ".", "o", "o", "o" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingSand theObject;
        eq(3, theObject.simulate(board),retrunValue);
    }
    {
        string boardARRAY[] = {"oxxxxooo",
            "xooooxxx",
            "..xx.ooo",
            "oooox.o.",
            "..x....."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        string retrunValueARRAY[] = {"oxxxxooo", "x.oo.xxx", "..xxo...", ".oo.x.o.", "ooxo.ooo" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingSand theObject;
        eq(4, theObject.simulate(board),retrunValue);
    }
    {
        string boardARRAY[] = {"..o..o..o..o..o..o..o..o..o..o..o",
            "o..o..o..o..o..o..o..o..o..o..o..",
            ".o..o..o..o..o..o..o..o..o..o..o.",
            "...xxx...xxx...xxxxxxxxx...xxx...",
            "...xxx...xxx...xxxxxxxxx...xxx...",
            "...xxx...xxx......xxx......xxx...",
            "...xxxxxxxxx......xxx......xxx...",
            "...xxxxxxxxx......xxx......xxx...",
            "...xxxxxxxxx......xxx......xxx...",
            "...xxx...xxx......xxx............",
            "...xxx...xxx...xxxxxxxxx...xxx...",
            "...xxx...xxx...xxxxxxxxx...xxx...",
            "..o..o..o..o..o..o..o..o..o..o..o",
            "o..o..o..o..o..o..o..o..o..o..o..",
            ".o..o..o..o..o..o..o..o..o..o..o."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        string retrunValueARRAY[] = {".................................", ".................................", "...ooo...ooo...ooooooooo...ooo...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxxoooxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxxxxxxxx......xxx......xxx...", "...xxx...xxx......xxx............", "...xxx...xxx...xxxxxxxxx...xxx...", "...xxx...xxx...xxxxxxxxx...xxx...", ".................................", "ooo.........ooo.........ooo...ooo", "ooooooooooooooooooooooooooooooooo" };
        vector <string> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FallingSand theObject;
        eq(5, theObject.simulate(board),retrunValue);
    }
	return 0;
}
// END CUT HERE
