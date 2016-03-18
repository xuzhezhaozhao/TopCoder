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

class LuckyCycle {
public:
    vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
		int N = edge1.size() + 1;
		vector < vector<int> > adj(N+1);
		vector < vector<int> > wgt(N+1);
		for (int i = 0; i < N-1; i++) {
			adj[ edge1[i] ].push_back( edge2[i] );
			adj[ edge2[i] ].push_back( edge1[i] );
			wgt[ edge1[i] ].push_back( weight[i] );
			wgt[ edge2[i] ].push_back( weight[i] );
		}

		bool visited[101];
		for (int e1 = 1; e1 <= N; e1++) {
			for (int e2 = 1; e2 <= N; e2++) {
				if (e1 == e2) {
					continue;
				}
				// connect e1, e2
				// BFS
				memset(visited, 0, sizeof(visited));
				queue < pair<int, int> > Q;
				Q.push( make_pair(e1, 0) );
				int layer = 0;
				int cnt = 1;
				while (!Q.empty()) {
					auto h = Q.front();
					Q.pop();
					--cnt;

					if (h.first == e2) {
						// found
						// layer 条边, 权重和为 h.second
						if (layer == 1 || layer % 2 == 0) {
							break;
						} else if ( (layer+1)/2 * 11 == h.second + 4 ) {
							return vector<int>{e1, e2, 4};
						} else if ( (layer+1)/2 * 11 == h.second + 7 ) {
							return vector<int>{e1, e2, 7};
						} else {
							break;
						}
					}

					for (int i = 0; i < adj[ h.first ].size(); i++) {
						int x = adj[ h.first ][i];
						if (!visited[x]) {
							visited[x] = true;
							Q.push( make_pair(x, h.second + wgt[h.first][i]) );
						}
					}

					if (cnt == 0) {
						++layer;
						cnt = Q.size();
					}
				}
			}
		}
        return vector<int>();
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
        int edge1ARRAY[] = {1};
        vector <int> edge1( edge1ARRAY, edge1ARRAY+ARRSIZE(edge1ARRAY) );
        int edge2ARRAY[] = {2};
        vector <int> edge2( edge2ARRAY, edge2ARRAY+ARRSIZE(edge2ARRAY) );
        int weightARRAY[] = {4};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        LuckyCycle theObject;
        eq(0, theObject.getEdge(edge1, edge2, weight),vector <int>());
    }
    {
        int edge1ARRAY[] = {1, 3, 2, 4};
        vector <int> edge1( edge1ARRAY, edge1ARRAY+ARRSIZE(edge1ARRAY) );
        int edge2ARRAY[] = {2, 2, 4, 5};
        vector <int> edge2( edge2ARRAY, edge2ARRAY+ARRSIZE(edge2ARRAY) );
        int weightARRAY[] = {4, 7, 4, 7};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        int retrunValueARRAY[] = {1, 5, 7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        LuckyCycle theObject;
        eq(1, theObject.getEdge(edge1, edge2, weight),retrunValue);
    }
    {
        int edge1ARRAY[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        vector <int> edge1( edge1ARRAY, edge1ARRAY+ARRSIZE(edge1ARRAY) );
        int edge2ARRAY[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
        vector <int> edge2( edge2ARRAY, edge2ARRAY+ARRSIZE(edge2ARRAY) );
        int weightARRAY[] = {4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        int retrunValueARRAY[] = {1, 12, 7 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        LuckyCycle theObject;
        eq(2, theObject.getEdge(edge1, edge2, weight),retrunValue);
    }
    {
        int edge1ARRAY[] = {1, 2, 3, 5, 6};
        vector <int> edge1( edge1ARRAY, edge1ARRAY+ARRSIZE(edge1ARRAY) );
        int edge2ARRAY[] = {2, 3, 4, 3, 5};
        vector <int> edge2( edge2ARRAY, edge2ARRAY+ARRSIZE(edge2ARRAY) );
        int weightARRAY[] = {4, 7, 7, 7, 7};
        vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
        int retrunValueARRAY[] = {1, 4, 4 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        LuckyCycle theObject;
        eq(3, theObject.getEdge(edge1, edge2, weight),retrunValue);
    }
	return 0;
}
// END CUT HERE
