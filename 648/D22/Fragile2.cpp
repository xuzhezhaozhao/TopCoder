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

const int MAX_N = 20;
bool visited[MAX_N];

class Fragile2 {
public:
	vector <string> graph;
	int N;
    int countPairs(vector <string> graph) {
		this->graph = graph;
		this->N = graph.size();
        int res = 0;
		int comp = countComponents(N + 1, N + 2);

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int comp2 = countComponents(i, j);
				if (comp2 > comp) {
					++res;
				}
			}
		}

        return res;
    }

	int countComponents(int d1, int d2) {
		int ans = 0;
		memset(visited, 0, sizeof(visited));
		for (int v = 0; v < N; v++) {
			if (v == d1 || v == d2) {
				continue;
			}
			if (!visited[v]) {
				++ans;
				dfs(v, d1, d2);
			}
		}
		return ans;
	}

	void dfs(int v, int d1, int d2) {
		visited[v] = true;
		for (int i = 0; i < N; i++) {
			if (i == d1 || i == d2) {
				continue;
			}
			if (visited[i]) {
				continue;
			}
			if ('Y' == graph[v][i]) {
				dfs(i, d1, d2);
			}
		}
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
        string graphARRAY[] = {"NYNN", "YNYN", "NYNY", "NNYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        Fragile2 theObject;
        eq(0, theObject.countPairs(graph),3);
    }
    {
        string graphARRAY[] = {"NYNNNN", "YNYNNN", "NYNNNN", "NNNNYN", "NNNYNY", "NNNNYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        Fragile2 theObject;
        eq(1, theObject.countPairs(graph),5);
    }
    {
        string graphARRAY[] = {"NNN", "NNN", "NNN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        Fragile2 theObject;
        eq(2, theObject.countPairs(graph),0);
    }
    {
        string graphARRAY[] = {"NYNYNNYYNN", "YNNNYNYYNN", "NNNNYNNNYN", "YNNNYYNNNN", "NYYYNNNNYN",
            "NNNYNNNNYN", "YYNNNNNNNN", "YYNNNNNNYN", "NNYNYYNYNY", "NNNNNNNNYN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        Fragile2 theObject;
        eq(3, theObject.countPairs(graph),9);
    }
    {
        string graphARRAY[] = {"NNNYNNYNNNNNNNYYNNNY", "NNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNYNNNNNNNNN", "NNNNNNNYNNNNNYNNNNYN",
            "NNNNNNNNNNNNNNNNYNNY", "YNNNNNNNNNNNNYYYNYNN", "NNNNYNNNNNNNNYYNNNNN", "NYNNNNNNNYNNNNNNNNNN", "NNNNNNNNYNNNYNNNNNYN",
            "NNNYNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNYNNNNNNNYNN", "NNNNYNYYNNNNNNNNNNNN", "YNNNNNYYNNYNNNNNNNNN",
            "YNNNNNYNNNNNNNNNYNNN", "NNNNNYNNNNNNNNNYNYNN", "NNNNNNYNNNNNYNNNYNNN", "NNNNYNNNNYNNNNNNNNNN", "YNNNNYNNNNNNNNNNNNNN"};
        vector <string> graph( graphARRAY, graphARRAY+ARRSIZE(graphARRAY) );
        Fragile2 theObject;
        eq(4, theObject.countPairs(graph),42);
    }
	return 0;
}
// END CUT HERE
