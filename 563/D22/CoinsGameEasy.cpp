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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

/*************** Program Begin **********************/
struct Point {
	char x1, y1, x2, y2, moves;
	Point (char  x1, char  y1, char  x2, char  y2, char  moves) {
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->moves = moves;
	}
	Point () {}
};
int dx[] = {-1, +1, 0, 0};
int dy[] = { 0, 0, -1, +1};
class CoinsGameEasy {
public:
	int minimalSteps(vector <string> board) {
		queue < Point > q;
		Point P;
		int cnt = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'o') {
					board[i][j] = '.';
					if (cnt == 0) {
						P.x1 = i; P.y1 = j;
					} else {
						P.x2 = i; P.y2 = j;
					}
					++cnt;
				}
			}
		}
		int W = board.size();
		int L = board[0].size();
		P.moves = 0;
		q.push(P);
		Point cur;
		int moves = 0;
		bool over = false;
		while (!q.empty() && !over) {
			cur = q.front();
			moves = cur.moves + 1;
			q.pop();
			if (moves > 10) {
				break;
			}
			int n_x1, n_x2, n_y1, n_y2;
			for (int i = 0; i < 4; i++) {
				n_x1 = cur.x1 + dx[i];
				n_y1 = cur.y1 + dy[i];
				n_x2 = cur.x2 + dx[i];
				n_y2 = cur.y2 + dy[i];
				if ( (n_x1 < 0 || n_x1 >= W || n_y1 < 0 || n_y1 >= L) && 
					(n_x2 >= 0 && n_x2 < W && n_y2 >= 0 && n_y2 < L) ) {
					over = true;
					break;
				}

				if ( (n_x2 < 0 || n_x2 >= W || n_y2 < 0 || n_y2 >= L) && 
					(n_x1 >= 0 && n_x1 < W && n_y1 >= 0 && n_y1 < L) ) {
					over = true;
					break;
				}

				if (n_x1 < 0 || n_x1 >= W || n_y1 < 0 || n_y1 >= L || 
					n_x2 < 0 || n_x2 >= W || n_y2 < 0 || n_y2 >= L) {
					continue;
				}

				if (board[n_x1][n_y1] == '#') {
					n_x1 = cur.x1;
					n_y1 = cur.y1;
				}
				if (board[n_x2][n_y2] == '#') {
					n_x2 = cur.x2;
					n_y2 = cur.y2;
				}
				q.push(Point(n_x1, n_y1, n_x2, n_y2, moves));
			}
		}	
		return ( moves > 10 ? -1 : moves );
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string boardARRAY[] = {"############", ".........#o#", "############", "..........o#", "############"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		CoinsGameEasy theObject;
		eq(0, theObject.minimalSteps(board),-1);
	}
	{
		string boardARRAY[] = {".#", 
			".#", 
			".#",
			"o#",
			"o#",
			"##"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		CoinsGameEasy theObject;
		eq(1, theObject.minimalSteps(board),4);
	}
	{
		string boardARRAY[] = {"..",
			"..",
			"..",
			"o#",
			"o#",
			"##"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		CoinsGameEasy theObject;
		eq(2, theObject.minimalSteps(board),3);
	}
	{
		string boardARRAY[] = {"###",
			".o.",
			"###",
			".o.",
			"###"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		CoinsGameEasy theObject;
		eq(3, theObject.minimalSteps(board),-1);
	}
	{
		string boardARRAY[] = {"###",
			".o.",
			"#.#",
			".o.",
			"###"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		CoinsGameEasy theObject;
		eq(4, theObject.minimalSteps(board),3);
	}
	{
		string boardARRAY[] = {"###########",
			"........#o#",
			"###########",
			".........o#",
			"###########"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		CoinsGameEasy theObject;
		eq(5, theObject.minimalSteps(board),10);
	}
	{
		string boardARRAY[] = {"############",
			".........#o#",
			"############",
			"..........o#",
			"############"};
		vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
		CoinsGameEasy theObject;
		eq(6, theObject.minimalSteps(board),-1);
		CHECKTIME();
	}
}
// END CUT HERE
