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
const int MAX_CUBES = 8;
const int MAX_LETTERS = 30;
int g[MAX_LETTERS][MAX_CUBES];
bool v[MAX_CUBES];
int cubes_match[MAX_CUBES];

class PlayingCubes {
public:
	bool DFS(int where)
	{
		if (-1 == where) {
			return true;
		}
		for (int i = 0; i < MAX_CUBES; i++) {
			if (v[i] || !g[where][i]) {
				continue;
			}
			v[i] = true;
			if (DFS(cubes_match[i])) {
				cubes_match[i] = where;
				return true;
			}
		}
		return false;
	}
	vector <int> composeWords(vector <string> cubes, vector <string> words) {
		vector <int> res;
		memset(g, 0, sizeof(g));
		for (int i = 0; i < cubes.size(); i++) {
			for (int j = 0; j < cubes[i].size(); j++) {
				g[cubes[i][j] - 'A'][i] = 1;
			}
		}
		for (int i = 0; i < words.size(); i++) {
			memset(cubes_match, -1,sizeof(cubes_match));
			bool ok = true;
			for (int j = 0; j < words[i].size(); j++) {
				memset(v, 0, sizeof(v));
				if (!DFS(words[i][j] - 'A')) {
					ok = false;
					break;
				}
			}
			if (ok) {
				res.push_back(i);
			}
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string cubesARRAY[] = {"ABCDEF", "DEFGHI", "OPQRST", "ZZZZZZ", "YYYYYY"};
		vector <string> cubes( cubesARRAY, cubesARRAY+ARRSIZE(cubesARRAY) );
		string wordsARRAY[] = {"CAT", "DOG", "PIZZA"};
		vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
		int retrunValueARRAY[] = {1 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		PlayingCubes theObject;
		eq(0, theObject.composeWords(cubes, words),retrunValue);
	}
	{
		string cubesARRAY[] = {"ABCDEF", "DEFGHI", "OPQRST", "MNZLSA", "QEIOGH", "IARJGS"};
		vector <string> cubes( cubesARRAY, cubesARRAY+ARRSIZE(cubesARRAY) );
		string wordsARRAY[] = {"DOG", "CAT", "MOUSE", "BIRD", "CHICKEN", "PIG", "ANIMAL"};
		vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
		int retrunValueARRAY[] = {0, 1, 3, 5 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		PlayingCubes theObject;
		eq(1, theObject.composeWords(cubes, words),retrunValue);
	}
	{
		string cubesARRAY[] = {"AAAAAA", "AAAAAA", "AAAAAA", "AAAAAA"};
		vector <string> cubes( cubesARRAY, cubesARRAY+ARRSIZE(cubesARRAY) );
		string wordsARRAY[] = {"AA", "AAA", "AAAA", "AAAAA", "AAAAAA"};
		vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
		int retrunValueARRAY[] = {0, 1, 2 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		PlayingCubes theObject;
		eq(2, theObject.composeWords(cubes, words),retrunValue);
	}
	{
		string cubesARRAY[] = {"ABCDEF", "DEFGHI", "OPQRST", "ZZZZZZ", "ZZZZZZ"};
		vector <string> cubes( cubesARRAY, cubesARRAY+ARRSIZE(cubesARRAY) );
		string wordsARRAY[] = {"CAT", "DOG", "PIZZA"};
		vector <string> words( wordsARRAY, wordsARRAY+ARRSIZE(wordsARRAY) );
		int retrunValueARRAY[] = {1, 2 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		PlayingCubes theObject;
		eq(3, theObject.composeWords(cubes, words),retrunValue);
	}
}
// END CUT HERE
