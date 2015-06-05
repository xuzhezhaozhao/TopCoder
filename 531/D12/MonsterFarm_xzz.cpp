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

const int MAX_N = 50;
const int MOD = 1000000007;
int g[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];
bool isLeafs[MAX_N + 1];
long long dp[MAX_N + 1];

class MonsterFarm {
public:
	vector <vector<int>> tf;
	int N;
	void DFS(int v)
	{
		for (int i = 0; i < N; i++) {
			if (!g[v][i]) {
				continue;
			}
			if (visited[i]) {
				continue;
			}
			visited[i] = true;
			DFS(i);
		}
	}
	bool check_loop(int first, int v, vector <int> & path)
	{
		for (int i = 0; i < N; i++) {
			if (!g[v][i]) {
				continue;
			}
			if (visited[i]) {
				if (i == first) {
					return true;
				} else {
					continue;
				}
			}
			visited[i] = true;
			path.push_back(i);
			if (check_loop(first, i, path)) {
				return true;
			}
			path.pop_back();
		}
		return false;
	}
	int solve(int v)
	{
		// base case
		if (isLeafs[v]) {
			return 1;
		}
		long long & res = dp[v];
		if (res != -1) {
			return res;
		}
		res = 0;
		for (auto x : tf[v]) {
			res += solve(x);
			res %= MOD;
		}
		return res;
	}
	int numMonsters(vector <string> transforms) {
		int res = 0;
		N = transforms.size();
		tf.resize(N);
		for (int i = 0; i < N; i++) {
			stringstream sstr(transforms[i]);
			int temp;
			while (sstr >> temp) {
				tf[i].push_back(temp - 1);
			}
		}

		memset(g, 0, sizeof(g));
		for (int x = 0; x < N; x++) {
			for (auto y : tf[x]) {
				g[x][y] = 1;
			}
		}

		memset(visited, 0, sizeof(visited));
		visited[0] = true;
		DFS(0);

		vector <int> R;
		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				R.push_back(i);
			}
		}

		memset(isLeafs, 0, sizeof(isLeafs));
		vector <int> path;
		for (auto x : R) {
			path.clear();
			path.push_back(x);
			memset(visited, 0, sizeof(visited));
			visited[x] = true;
			if (check_loop(x, x, path)) {
				if ((int)tf[x].size() > 1) {
					return -1;
				}	
				for (auto x : path) {
					isLeafs[x] = true;
				}
			}
		}
		
		memset(dp, -1, sizeof(dp));
		res = solve(0);
		
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
		string transformsARRAY[] = {"1"};
		vector <string> transforms( transformsARRAY, transformsARRAY+ARRSIZE(transformsARRAY) );
		MonsterFarm theObject;
		eq(0, theObject.numMonsters(transforms),1);
	}
	{
		string transformsARRAY[] = {"1 1"};
		vector <string> transforms( transformsARRAY, transformsARRAY+ARRSIZE(transformsARRAY) );
		MonsterFarm theObject;
		eq(1, theObject.numMonsters(transforms),-1);
	}
	{
		string transformsARRAY[] = {"2", "3", "1"};
		vector <string> transforms( transformsARRAY, transformsARRAY+ARRSIZE(transformsARRAY) );
		MonsterFarm theObject;
		eq(2, theObject.numMonsters(transforms),1);
	}
	{
		string transformsARRAY[] = {"1", "3 4", "2", "2"};
		vector <string> transforms( transformsARRAY, transformsARRAY+ARRSIZE(transformsARRAY) );
		MonsterFarm theObject;
		eq(3, theObject.numMonsters(transforms),1);
	}
	{
		string transformsARRAY[] = {"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"};
		vector <string> transforms( transformsARRAY, transformsARRAY+ARRSIZE(transformsARRAY) );
		MonsterFarm theObject;
		eq(4, theObject.numMonsters(transforms),24);
	}
	{
		string transformsARRAY[] = {"2 3","5 7","2 4","5","6","4","7"};
		vector <string> transforms( transformsARRAY, transformsARRAY+ARRSIZE(transformsARRAY) );
		MonsterFarm theObject;
		eq(5, theObject.numMonsters(transforms),5);
	}
	return 0;
}
// END CUT HERE
