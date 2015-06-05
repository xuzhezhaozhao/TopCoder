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
bool visited_vertex[5001];
bool visited_clique[5001];


class CliqueGraph {
public:
	long long calcSum(int N, vector <int> V, vector <int> sizes) {
		long long res = 0;
		vector <int> S(sizes.size() + 1);
		S[0] = 0;
		for (int i = 0; i < sizes.size(); i++) {
			S[i + 1] += S[i] + sizes[i];
		}
		vector <vector<int>> cliques(sizes.size());	// clique i 包含的点
		vector <vector<int>> vcliques(N);  // 包含点v的cliques
		for (int i = 0; i < sizes.size(); i++) {
			for (int j = S[i]; j < S[i + 1]; j++) {
				cliques[i].push_back(V[j]);
				vcliques[ V[j] ].push_back(i);
			}
		}

		for (int src = 0; src < N; src++) {
			vector <int> D(N, 123456789);
			D[src] = 0;
			memset(visited_vertex, 0, sizeof(visited_vertex));
			memset(visited_clique, 0, sizeof(visited_clique));
			queue <int> Q;
			Q.push(src);
			visited_vertex[src] = true;
			while (!Q.empty()) {
				int v = Q.front();
				Q.pop();
				// 更新所有包含v的cliques中的所有点
				for (int i = 0; i < vcliques[v].size(); i++) {
					int c = vcliques[v][i];	// 包含v的cliques
					if (visited_clique[c]) {
						continue;
					}
					visited_clique[c] = true;
					for (int j = 0; j < cliques[c].size(); j++) {
						int u = cliques[c][j];	// clique c z中的的点
						if (visited_vertex[u]) {
							continue;
						}
						visited_vertex[u] = true;
						D[u] = D[v] + 1;
						Q.push(u);
					}
				}
			}
			for (int i = 0; i < N; i++) {
				res += D[i];
			}
		}
		return res / 2;
	};
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int VARRAY[] = {0,1,2,0,3};
		vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
		int sizesARRAY[] = {3,2};
		vector <int> sizes( sizesARRAY, sizesARRAY+ARRSIZE(sizesARRAY) );
		CliqueGraph theObject;
		eq(0, theObject.calcSum(4, V, sizes),8LL);
	}
	{
		int VARRAY[] = {0,1,2,3,1,2,4};
		vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
		int sizesARRAY[] = {4,3};
		vector <int> sizes( sizesARRAY, sizesARRAY+ARRSIZE(sizesARRAY) );
		CliqueGraph theObject;
		eq(1, theObject.calcSum(5, V, sizes),12LL);
	}
	{
		int VARRAY[] = {1,3,5,7,9,11,13,0
			,2,3,6,7,10,11,14,0
			,4,5,6,7,12,13,14,0
			,8,9,10,11,12,13,14,0};
		vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
		int sizesARRAY[] = {8,8,8,8};
		vector <int> sizes( sizesARRAY, sizesARRAY+ARRSIZE(sizesARRAY) );
		CliqueGraph theObject;
		eq(2, theObject.calcSum(15, V, sizes),130LL);
	}
}
// END CUT HERE
