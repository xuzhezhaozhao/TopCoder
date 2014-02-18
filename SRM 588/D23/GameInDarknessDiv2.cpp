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
vector <string> f;
string M;
bool v[2600][50][50];
bool BobWin = false;
void move(int Ax, int Ay, int Bx, int By, int steps)
{
	v[steps][Bx][By] = true;
	if (steps == M.size()) {
		BobWin = true;
		return;
	} else {
		int nAx = Ax;
		int nAy = Ay;
		switch (M[steps]) {
		case 'U':
			nAy = Ay - 1;
			break;
		case 'R':
			nAx = Ax + 1;
			break;
		case 'L':
			nAx = Ax - 1;
			break;
		case 'D':
			nAy = Ay + 1;
			break;
		}
		if (nAx == Bx && nAy == By) {
			return;
		}
		int nBx = Bx;
		int nBy = By;
		// ио
		nBx = Bx;
		nBy = By - 1;
		if ( nBy >= 0 && '.' == f[nBy][nBx] && !(nAx == nBx && nAy == nBy) && !v[steps+1][nBx][nBy] ) {
			move(nAx, nAy, nBx, nBy, steps+1);
		}
		// об
		nBx = Bx;
		nBy = By + 1;
		if ( nBy <= f.size() - 1 && '.' == f[nBy][nBx] && !(nAx == nBx && nAy == nBy) && !v[steps+1][nBx][nBy] ) {
			move(nAx, nAy, nBx, nBy, steps+1);
		}
		// вС
		nBx = Bx - 1;
		nBy = By;
		if ( nBx >= 0 && '.' == f[nBy][nBx] && !(nAx == nBx && nAy == nBy) && !v[steps+1][nBx][nBy] ) {
			move(nAx, nAy, nBx, nBy, steps+1);
		}
		// ср
		nBx = Bx + 1;
		nBy = By;
		if ( nBx <= f[0].size() - 1 && '.' == f[nBy][nBx] && !(nAx == nBx && nAy == nBy) && !v[steps+1][nBx][nBy] ) {
			move(nAx, nAy, nBx, nBy, steps+1);
		}
	}
}

class GameInDarknessDiv2 {
public:
	string check(vector <string> field, vector <string> moves) {
		string res = "";
		f = field;
		int Ax = 0, Ay = 0, Bx = 0, By = 0;
		for (int i = 0; i < f.size(); i++) {
			for (int j = 0; j < f[0].size(); j++) {
				if ('A' == f[i][j]) {
					Ay = i;
					Ax = j;
					f[i][j] = '.';
				} else if ('B' == f[i][j]) {
					By = i;
					Bx = j;
					f[i][j] = '.';
				}
			}
		}
		M = "";
		for (int i = 0; i < moves.size(); i++) {
			M += moves[i];
		}
		BobWin = false;
		memset(v, 0, sizeof(v));
		move(Ax, Ay, Bx, By, 0);
		if (BobWin) {
			return "Bob wins";
		} else {
			return "Alice wins";
		}
	}
};
/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string fieldARRAY[] = {
			"A.B..",
			"##.##",
			"##.##"};
			vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
			string movesARRAY[] = {"RRDUR"};
			vector <string> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
			GameInDarknessDiv2 theObject;
			eq(0, theObject.check(field, moves),"Alice wins");
	}
	{
		string fieldARRAY[] = {"A.B..",
			"##.##",
			"##..."};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		string movesARRAY[] = {"RRRLD"};
		vector <string> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
		GameInDarknessDiv2 theObject;
		eq(1, theObject.check(field, moves),"Bob wins");
	}
	{
		string fieldARRAY[] = {"###.#",
			"###..",
			"A..B#",
			"###..",
			"###.#"};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		string movesARRAY[] = {"RR", "R", "UDD"};
		vector <string> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
		GameInDarknessDiv2 theObject;
		eq(2, theObject.check(field, moves),"Alice wins");
	}
	{
		string fieldARRAY[] = {"A.###",
			".B..."};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		string movesARRAY[] = {"RDRRRLLLLUDUDRLURDLUD"};
		vector <string> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
		GameInDarknessDiv2 theObject;
		eq(3, theObject.check(field, moves),"Bob wins");
	}
	{
		string fieldARRAY[] = {".....",
			".#.#.",
			"##.#.",
			"A###.",
			"B...."};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		string movesARRAY[] = {"D"};
		vector <string> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
		GameInDarknessDiv2 theObject;
		eq(4, theObject.check(field, moves),"Alice wins");
	}
	{
		string fieldARRAY[] = {".#...#....#.......#....#......",
			"...###.#.#..#.#.#..###...#.#.#",
			".#.#...#...#..#..#.....##.#...",
			"#..#.##..##..#.#..###.#....#.#",
			"..#..#..#...#...#....#..##.#..",
			"#..##..#..##.#.#.####..#.#...#",
			".#....##.#.....#......##.#.#..",
			".###.#...#.#.#..#.#.##...##.#.",
			".....#.#.##..#.#..##...##...#.",
			"#.#.#...#...#.#.#...#.#.#.##.#",
			".#..##.#..##..#.###...........",
			"..##.....####.......##.#.#.##.",
			"#....##.#.#...####.#...#.#.#..",
			"#.#.#......##.#...#..#.#..#..#",
			"..#..#.#.##...#.#..#..#..#..#.",
			".#..#...#...#..#..#.#..#..#A#.",
			"..#..#.#.B##.##..#...#.#.##...",
			"#.#.##..#......#.#.#.#.#...#.#",
			"#.#...#.######...#.#.#.#.#.#..",
			"..#.##.#.....#.##..#...#.#.#.#",
			".#..#..#.#.#.#.#..#.#####..#.#",
			"..#.#.##.#.#.##.#......#..#...",
			"#..#.....#.#.....#.#.##..##.#.",
			"##..###.#..#.#.#.#..##..#...##",
			"##.#...#..##.#.#..#.#..#.#.#..",
			"#..#.#.####..#..#..#..#......#",
			"..#..#.....####..#.##.#.###.#.",
			".#..#.####.#.#..#.....#...#...",
			"..##.......#...#..####.##.#.#.",
			"#....#.#.#..#.###....#....#..#"};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		string movesARRAY[] = {"UURURUULLLLLLLLLLDLLLLUDLLUDDLRDDDULLDLLDDRRRRRDDU","RRUUURUULLD"};
		vector <string> moves( movesARRAY, movesARRAY+ARRSIZE(movesARRAY) );
		GameInDarknessDiv2 theObject;
		eq(5, theObject.check(field, moves),"Alice wins");
	}
}
// END CUT HERE