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
int dx[] = {0, -1, -1, 0, 1, 1}, dy[] = {-1, 0, 1, 1, 0, -1};
class HexagonalBoard {
private:
	vector <string> board;
	int color[50][50];
	int result, N;
public:
	void DFS(int x, int y, int c)
	{
		int nx, ny;
		if ('X' == board[x][y] && -1 == color[x][y]) {
			color[x][y] = c;
			result = max(result, 1);
			for (int i = 0; i < 6; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || nx > N-1 || ny < 0 || ny > N-1) {
					continue;
				}
				if ('X' == board[nx][ny]) {
					result = max(result, 2);
					DFS(nx, ny, !c);
					if (c == color[nx][ny]) {
						result = 3;
					}
				}
			}
		}
	}

	int minColors(vector <string> board)
	{
		this->board = board;
		memset(color, -1, sizeof(color));
		result = 0;
		N = board.size();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				DFS(i, j, 0);
			}
		}
		return result;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        string boardARRAY[] = {"---",
            "---",
            "---"}
            ;
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        HexagonalBoard theObject;
        eq(0, theObject.minColors(board),0);
    }
    {
        string boardARRAY[] = {
		"-X--",
		"---X",
		"----",
		"-X--"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        HexagonalBoard theObject;
        eq(1, theObject.minColors(board),1);
    }
    {
        string boardARRAY[] = {"XXXX",
            "---X",
            "---X",
            "---X"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        HexagonalBoard theObject;
        eq(2, theObject.minColors(board),2);
    }
    {
        string boardARRAY[] = {"XX-XX--"
           ,"-XX-XXX"
           ,"X-XX--X"
           ,"X--X-X-"
           ,"XX-X-XX"
           ,"-X-XX-X"
           ,"-XX-XX-"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        HexagonalBoard theObject;
        eq(3, theObject.minColors(board),3);
    }
}
// END CUT HERE
