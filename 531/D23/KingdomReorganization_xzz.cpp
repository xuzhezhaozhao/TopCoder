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
const int INF = 10000000;
int g[MAX_N + 1][MAX_N + 1];
int b[MAX_N + 1][MAX_N + 1];
int d[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];


class KingdomReorganization {
public:
	int N;
	vector <int> component, path;
	int min_destroy;
	bool loop_destroy(int first, int v)
	{
		// DFS
		for (int i = 0; i < N; i++) {
			if (!g[v][i]) {
				continue;
			}
			if (i != first) {
				if (visited[i]) {
					continue;
				}
				visited[i] = true;
				path.push_back(i);
				if (loop_destroy(first, i)) {
					return true;
				} else {
					path.pop_back();
				}
			} else {
				// i == first
				if (path.size() > 2) {
					path.push_back(i);
					return true;
				}
			}
		}
		return false;
	}
	void dfs(int v)
	{
		for (int i = 0; i < N; i++) {
			if (!g[v][i]) {
				continue;
			}
			if (visited[i]) {
				continue;
			}
			visited[i] = true;
			component.push_back(i);
			dfs(i);
		}
	}
	int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
		int res = 0;
		N = kingdom.size();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				g[i][j] = kingdom[i][j] - '0';
				if (build[i][j] >= 'A' && build[i][j] <= 'Z') {
					b[i][j] = build[i][j] - 'A';
				} else {
					b[i][j] = build[i][j] - 'a' + 26;
				}

				if (destroy[i][j] >= 'A' && destroy[i][j] <= 'Z') {
					d[i][j] = destroy[i][j] - 'A';
				} else {
					d[i][j] = destroy[i][j] - 'a' + 26;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			memset(visited, 0, sizeof(visited));
			visited[i] = true;
			path.clear();
			path.push_back(i);
			if (loop_destroy(i, i)) {
				int index = -1;
				int min_d = INF;
				for (int i = 0; i < (int)path.size() - 1; i++) {
					if (min_d > d[ path[i] ][ path[i + 1] ]) {
						min_d = d[ path[i] ][ path[i + 1] ];
						index = i;
					}
				}
				g[ path[index] ][ path[index + 1] ] = g[ path[index + 1] ][ path[index] ] = 0;
				res += min_d;
				--i; 	// 重新从该点出发检测环, 一次检测只能移除一条边, 对于环数大于 N 的稠密图, 必有一些点对应多个环
			}
		}
		vector< vector<int> > comps;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				component.clear();
				component.push_back(i);
				visited[i] = true;
				dfs(i);
				comps.push_back(component);
			}
		}
		// 求最小生成树
		int T[MAX_N + 1][MAX_N + 1];
		int s = comps.size();
		for (int i = 0; i < s; i++) {
			T[i][i] = 0;
			for (int j = i + 1; j < s; j++) {
				int min_b = INF;
				for (int x = 0; x < (int)comps[i].size(); x++) {
					for (int y = 0; y < (int)comps[j].size(); y++) {
						min_b = min(min_b, b[ comps[i][x] ][ comps[j][y] ]);
					}
				}
				T[i][j] = T[j][i] = min_b;
			}
		}

		// 选第一个点作为起始点
		memset(visited, 0, sizeof(visited));
		visited[0] = true;
		vector <int> added;
		added.push_back(0);
		while ((int)added.size() != s) {
			int min_edge = INF;
			int v = -1;
			for (auto x : added) {
				for (int i = 0; i < s; i++) {
					if (visited[i]) {
						continue;
					}
					if (T[x][i] < min_edge) {
						v = i;
						min_edge = T[x][i];
					}
				}
			}
			added.push_back(v);
			visited[v] = true;
			res += min_edge;
		}

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
		string kingdomARRAY[] = {"0111111", "1011111", "1101111", "1110111", "1111011", "1111101", "1111110"};
		vector <string> kingdom( kingdomARRAY, kingdomARRAY+ARRSIZE(kingdomARRAY) );
		string buildARRAY[] = {"AzvpNrk", "zAFfVLm", "vFAaDFn", "pfaAESX", "NVDEAco", "rLFScAx", "kmnXoxA"};
		vector <string> build( buildARRAY, buildARRAY+ARRSIZE(buildARRAY) );
		string destroyARRAY[] ={"AzeGcYA", "zAgCTsQ", "egAPSNK", "GCPANfu", "cTSNAIz", "YsNfIAt", "AQKuztA"};
		vector <string> destroy( destroyARRAY, destroyARRAY+ARRSIZE(destroyARRAY) );
		KingdomReorganization theObject;
		eq(0, theObject.getCost(kingdom, build, destroy),233);
	}
	{
		string kingdomARRAY[] = {"011","101","110"};
		vector <string> kingdom( kingdomARRAY, kingdomARRAY+ARRSIZE(kingdomARRAY) );
		string buildARRAY[] = {"ABD","BAC","DCA"};
		vector <string> build( buildARRAY, buildARRAY+ARRSIZE(buildARRAY) );
		string destroyARRAY[] = {"ABD","BAC","DCA"};
		vector <string> destroy( destroyARRAY, destroyARRAY+ARRSIZE(destroyARRAY) );
		KingdomReorganization theObject;
		eq(1, theObject.getCost(kingdom, build, destroy),1);
	}
	{
		string kingdomARRAY[] = {"011000","101000","110000","000011","000101","000110"};
		vector <string> kingdom( kingdomARRAY, kingdomARRAY+ARRSIZE(kingdomARRAY) );
		string buildARRAY[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
		vector <string> build( buildARRAY, buildARRAY+ARRSIZE(buildARRAY) );
		string destroyARRAY[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
		vector <string> destroy( destroyARRAY, destroyARRAY+ARRSIZE(destroyARRAY) );
		KingdomReorganization theObject;
		eq(2, theObject.getCost(kingdom, build, destroy),7);
	}
	{
		string kingdomARRAY[] = {"0"};
		vector <string> kingdom( kingdomARRAY, kingdomARRAY+ARRSIZE(kingdomARRAY) );
		string buildARRAY[] = {"A"};
		vector <string> build( buildARRAY, buildARRAY+ARRSIZE(buildARRAY) );
		string destroyARRAY[] = {"A"};
		vector <string> destroy( destroyARRAY, destroyARRAY+ARRSIZE(destroyARRAY) );
		KingdomReorganization theObject;
		eq(3, theObject.getCost(kingdom, build, destroy),0);
	}
	{
		string kingdomARRAY[] = {"0001","0001","0001","1110"};
		vector <string> kingdom( kingdomARRAY, kingdomARRAY+ARRSIZE(kingdomARRAY) );
		string buildARRAY[] = {"AfOj","fAcC","OcAP","jCPA"};
		vector <string> build( buildARRAY, buildARRAY+ARRSIZE(buildARRAY) );
		string destroyARRAY[] = {"AWFH","WAxU","FxAV","HUVA"};
		vector <string> destroy( destroyARRAY, destroyARRAY+ARRSIZE(destroyARRAY) );
		KingdomReorganization theObject;
		eq(4, theObject.getCost(kingdom, build, destroy),0);
	}
	{
		string kingdomARRAY[] = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
		vector <string> kingdom( kingdomARRAY, kingdomARRAY+ARRSIZE(kingdomARRAY) );
		string buildARRAY[] = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
		vector <string> build( buildARRAY, buildARRAY+ARRSIZE(buildARRAY) );
		string destroyARRAY[] = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
		vector <string> destroy( destroyARRAY, destroyARRAY+ARRSIZE(destroyARRAY) );
		KingdomReorganization theObject;
		eq(5, theObject.getCost(kingdom, build, destroy),65);
	}
	return 0;
}
// END CUT HERE
