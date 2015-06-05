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

class TreePuzzle {
public:
	vector <int> degree;
	vector < vector <int> > dist;
	bool on_path(int x, int y, int z)
	{
		return (dist[x][y] + dist[y][z] == dist[x][z]);
	}
	vector <int> reachable(vector <int> parent, vector <int> token) {
		int N = parent.size();
		dist.clear();
		dist.resize(N, vector<int>(N, 987654321));
		for (int i = 0; i < N; i++) {
			dist[i][i] = 0;
		}
		for (int i = 1; i < N; i++) {
			dist[i][ parent[i] ] = dist[ parent[i] ][i] = 1;
		}

		degree.clear();
		degree.resize(N, 1);
		degree[0] = 0;
		for (int i = 1; i < N; i++) {
			++degree[parent[i]];
		}

		// Floyd-Warshall
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		vector <int> result(N, 0);
		result[0] = 1;
		vector<vector<int>> tokens(N);
		tokens[0] = token;
		for (int v = 1; v < N; v++) {
			// skip v if we can't even reach v's parent
			int w = parent[v];
			if (!result[w]) {
				continue;
			}
			// suppose that the red token is at w
			// and the black tokens are distributed according to tokens[w]
			// can we reach v? and what will the black tokens look like then?

			// case 1: empty node in v's subtree (possibly v)
			for (int z = 0; z < N; z++) {
				if (on_path(w, v, z) && !tokens[w][z]) {
					result[v] = 1;
					tokens[v] = tokens[w];
					tokens[v][z] = 1;
					tokens[v][w] = 0;
					break;
				}
			}
			if (result[v]) {
				continue;
			}

			// case 2: empty nodes in subtrees of two different neighbors of w
			int e = -1;
			for (int z = 0; z < N; z++) {
				if (1 == dist[w][z] && z != v) {
					// test whether z is w's neighbor with some empty nodes
					for (int zz = 0; zz < N; zz++) {
						if (on_path(zz, z, w) && !tokens[w][zz]) {
							if (-1 == e) {
								e = z;
							} else {
								// we found a second neighbor with empty nodes
								result[v] = 1;
								tokens[v] = tokens[w];
								tokens[v][zz] = 1;
								tokens[v][w] = 0;
							}
							break;
						}

					}
					if (result[v]) {
						break;
					}
				}
			}
			if (result[v]) {
				continue;
			}
			// case 3: all empty nodes are in e's subtree only
			if (-1 == e) {
				continue;	// no empty nodes at all
			}
			int b = -1;
			// find the first branching node (if none, no solution)
			for (int c = 0; c < N; c++) {
				if (on_path(c, e, w) && degree[c] >= 3) {
					if (b == -1) {
						b = c;
					}
					if (dist[w][c] < dist[w][b]) {
						b = c;
					}
				}
			}
			if (b == -1) {
				continue;	// no branching node at all
			}

			// check whether we have enough empty nodes to reach the branching node
			int empty_nodes = 0;
			for (int i = 0; i < N; i++) {
				if (tokens[w][i] == 0) {
					++empty_nodes;
				}
			}
			if (empty_nodes < dist[w][b] + 2) {
				continue;	// not enough
			}

			// use the branching node to construct a solution
			result[v] = 1;
			tokens[v] = tokens[w];
			tokens[v][w] = 0;
			for (int i = 0; i < N; i++) {
				if (on_path(w, e, i) && !tokens[v][i]) {
					tokens[v][i] = 1;
					break;
				}
			}
		}
		return result;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int parentARRAY[] = {-1, 0, 0, 0, 1};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		int tokenARRAY[] = {1, 1, 0, 0, 1};
		vector <int> token( tokenARRAY, tokenARRAY+ARRSIZE(tokenARRAY) );
		int retrunValueARRAY[] = {1, 1, 1, 1, 0 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		TreePuzzle theObject;
		eq(0, theObject.reachable(parent, token),retrunValue);
	}
	{
		int parentARRAY[] = {-1, 0, 1, 0, 3, 2, 5, 6, 7, 8};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		int tokenARRAY[] = {1, 1, 1, 1, 1, 1, 0, 0, 1, 0};
		vector <int> token( tokenARRAY, tokenARRAY+ARRSIZE(tokenARRAY) );
		int retrunValueARRAY[] = {1, 1, 1, 0, 0, 1, 0, 0, 0, 0 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		TreePuzzle theObject;
		eq(1, theObject.reachable(parent, token),retrunValue);
	}
	{
		int parentARRAY[] = {-1, 0, 0, 2, 1, 1, 5, 0, 0, 2};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		int tokenARRAY[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		vector <int> token( tokenARRAY, tokenARRAY+ARRSIZE(tokenARRAY) );
		int retrunValueARRAY[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		TreePuzzle theObject;
		eq(2, theObject.reachable(parent, token),retrunValue);
	}
	{
		int parentARRAY[] = {-1, 0, 1, 2, 3, 4, 5, 0, 7, 6, 8, 9, 11, 0, 11, 2, 15, 13, 15, 10};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		int tokenARRAY[] = {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
		vector <int> token( tokenARRAY, tokenARRAY+ARRSIZE(tokenARRAY) );
		int retrunValueARRAY[] = {1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		TreePuzzle theObject;
		eq(3, theObject.reachable(parent, token),retrunValue);
	}
	{
		int parentARRAY[] = {-1, 0, 1, 2, 3, 4, 0, 5, 7, 8, 6, 10, 11, 9, 13, 14, 12, 16, 16, 18,
			15, 10, 17, 2, 23, 22, 21, 20, 27, 24, 19, 30, 28, 29, 17, 21, 34, 35, 31, 30,
			36, 32, 31, 39, 26, 40, 3, 38, 45, 25, 49, 46, 41, 44, 51, 47, 18, 54, 48, 36,
			43, 57, 52, 56, 60, 59, 53, 61, 64, 68, 37, 55, 71, 32, 26, 73, 28, 50, 75, 72,
			70, 67, 74, 66, 79, 76, 78, 63, 69, 41, 83, 86, 80, 18, 82, 87, 58, 62, 42, 20};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		int tokenARRAY[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
			1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1};
		vector <int> token( tokenARRAY, tokenARRAY+ARRSIZE(tokenARRAY) );
		int retrunValueARRAY[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		TreePuzzle theObject;
		eq(4, theObject.reachable(parent, token),retrunValue);
	}
}
// END CUT HERE
