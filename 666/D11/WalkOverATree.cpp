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

int dp[51][51][101][2];
class WalkOverATree {
public:
	vector<vector<int>> subtree;
	int N;


	int solve(int x, int c, int s, int m) {
		int &ans = dp[x][c][s][m];
		if (ans != -1) {
			return ans;
		}

		ans = 0;
		if (c == 0) {
			ans = 1;
			return ans;
		}

		// 不考虑子树 c-1
		ans = solve(x, c-1, s, m);
		// 考虑子树 c-1
		for (int i = 1; i <= s; i++) {
			// 第 c-1 棵子树给 i 步
			int v= subtree[x][c-1];

			// 返回 x
			if (i >= 2) {
				ans = max(ans, solve(x, c-1, s-i, m) + solve(v, subtree[v].size(), i-2, 1));
			}

			// 不返回 x, 此时 m 必须为 0
			if (m == 0) {
				ans = max(ans, solve(x, c-1, s-i, 1) + solve(v, subtree[v].size(), i-1, 0));
			}
		}
		return ans;
	}

    int maxNodesVisited(vector <int> parent, int L) {
		this->N = parent.size() + 1;

		vector<vector<int>> adj(N+1);
		subtree.resize(N+1);

		for (int i = 0; i < N-1; i++) {
			adj[ i+1 ].push_back( parent[i] );
			adj[ parent[i] ].push_back( i+1 );
		}
		queue <int> Q;
		bool visited[51] = {false};
		Q.push(0);
		visited[0] = true;
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			for (auto x : adj[cur]) {
				if (!visited[x]) {
					visited[x] = true;
					Q.push(x);
					subtree[cur].push_back(x);
				}
			}
		}

		memset(dp, -1, sizeof(dp));
        return solve(0, adj[0].size(), L, 0);
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
        int parentARRAY[] = {0, 0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        WalkOverATree theObject;
        eq(0, theObject.maxNodesVisited(parent, 2),2);
    }
    {
        int parentARRAY[] = {0, 0};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        WalkOverATree theObject;
        eq(1, theObject.maxNodesVisited(parent, 3),3);
    }
    {
        int parentARRAY[] = {0, 1, 2, 3};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        WalkOverATree theObject;
        eq(2, theObject.maxNodesVisited(parent, 2),3);
    }
    {
        int parentARRAY[] = {0,0,0,0,2,4,2,3,1};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        WalkOverATree theObject;
        eq(3, theObject.maxNodesVisited(parent, 1),2);
    }
    {
        int parentARRAY[] = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        WalkOverATree theObject;
        eq(4, theObject.maxNodesVisited(parent, 4),5);
    }
    {
        int parentARRAY[] = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        WalkOverATree theObject;
        eq(5, theObject.maxNodesVisited(parent, 26),17);
    }
    {
        int parentARRAY[] = {0, 0, 2, 0}
           ;
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        WalkOverATree theObject;
        eq(6, theObject.maxNodesVisited(parent, 100),5);
    }
    {
        int parentARRAY[] = {0, 0, 2};
        vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
        WalkOverATree theObject;
        eq(7, theObject.maxNodesVisited(parent, 4),4);
    }
	return 0;
}
// END CUT HERE
