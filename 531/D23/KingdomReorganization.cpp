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
const int INF = 10000000;
const int MAX_N = 50;
int g[MAX_N + 1][MAX_N + 1];
int b[MAX_N + 1][MAX_N + 1];
int d[MAX_N + 1][MAX_N + 1];

class KingdomReorganization {
public:
	int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
		int res = 0;
		int N = kingdom.size();
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

		vector <int> added;
		added.push_back(0);

		bool visited[MAX_N + 1];
		memset(visited, 0, sizeof(visited));
		visited[0] = true;

		int mst[MAX_N + 1][MAX_N + 1];
		memset(mst, 0, sizeof(mst));

		while ((int)added.size() != N) {
			int max_des = 0;
			bool have = false;
			pii max_edge, min_edge;
			int min_bul = INF;
			for (auto x : added) {
				for (int i = 0; i < N; i++) {
					if (visited[i]) {
						continue;
					}
					if (g[x][i]) {
						have = true;
						if (max_des < d[x][i]) {
							max_des = d[x][i];
							max_edge = mkp(x, i);
						}
					} else {
						if (min_bul > b[x][i]) {
							min_bul = b[x][i];
							min_edge = mkp(x, i);
						}
					}
				}
			}
			int new_v = -1;
			if (have) {
				mst[max_edge.first][max_edge.second] = mst[max_edge.second][max_edge.first] = 1;
				new_v = max_edge.second;
			} else {
				mst[min_edge.first][min_edge.second] = mst[min_edge.second][min_edge.first] = 1;
				new_v = min_edge.second;
			}
			added.push_back(new_v);
			visited[new_v] = true;
		}

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (mst[i][j]) {
					if (!g[i][j]) {
						res += b[i][j];
					}
				} else {
					if (g[i][j]) {
						res += d[i][j];
					}
				}
			}
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
