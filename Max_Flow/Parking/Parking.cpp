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
int g[105][105];
bool v_bfs[105][105];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int INF = INT_MAX;
int D = 0;
const int MAX = 10000;
int park_match[105];
bool v_dfs[105];

class Parking {
public:
	vector <string> park;
	map <pii, int> car_mp;
	map <pii, int> park_mp;

	void BFS(pii start)
	{
		queue <pair<pii, int>> Q;
		v_bfs[start.first][start.second] = true;
		Q.push(mkp(start, 0));
		while (!Q.empty()) {
			pii where = Q.front().first;
			int dist = Q.front().second;
			Q.pop();
			if (park_mp.find(where) != park_mp.end()) {
				g[ car_mp[start] ][ park_mp[where] ] = dist;
			}
			for (int i = 0; i < 4; i++) {
				int nx = where.first + dx[i];
				int ny = where.second + dy[i];
				if (nx < 0 || nx >= park.size() || ny < 0 || ny >= park[0].size()) {
					continue;
				}
				if (v_bfs[nx][ny] || 'X' == park[nx][ny]) {
					continue;
				}
				v_bfs[nx][ny] = true;
				Q.push(mkp( mkp(nx, ny), dist + 1 ));
			}
		}
	}

	bool DFS(int where)
	{
		if (-1 == where) {
			return true;
		}

		for (int i = 0; i < park_mp.size(); i++) {
			if (g[where][i] > D || v_dfs[i]) {
				continue;
			}
			v_dfs[i] = true;
			if (DFS(park_match[i])) {
				park_match[i] = where;
				return true;
			}
		}
		return false;
	}

	int minTime(vector <string> park) {
		int res = 0;
		this->park = park;
		int cnt1 = 0, cnt2 = 0;

		for (int i = 0; i < park.size(); i++) {
			for (int j = 0; j < park[0].size(); j++) {
				if ('C' == park[i][j]) {
					car_mp[mkp(i, j)] = cnt1;
					++cnt1;
				} else if ('P' == park[i][j]) {
					park_mp[mkp(i, j)] = cnt2;
					++cnt2;
				}
			}
		}
		for (int i = 0; i < 105; i++) {
			for (int j = 0; j < 105; j++) {
				g[i][j] = INF;
			}
		}

		for (map<pii, int>::iterator it = car_mp.begin(); it != car_mp.end(); it++) {
			memset(v_bfs, 0, sizeof(v_bfs));
			BFS( (*it).first );
		}

		D = 0;
		memset(park_match, -1, sizeof(park_match));
		for (int i = 0; i < car_mp.size(); i++) {
			memset(v_dfs, 0, sizeof(v_dfs));
			while (D < MAX && !DFS(i)) {
				++D;
				memset(v_dfs, 0, sizeof(v_dfs));
			}
			if (D >= MAX) {
				break;
			}
		}
		res = (D >= MAX ? -1 : D);
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string parkARRAY[] = {"C.....P",
			"C.....P",
			"C.....P"};
		vector <string> park( parkARRAY, parkARRAY+ARRSIZE(parkARRAY) );
		Parking theObject;
		eq(0, theObject.minTime(park),6);
	}
	{
		string parkARRAY[] = {"C.X.....",
			"..X..X..",
			"..X..X..",
			".....X.P"};
		vector <string> park( parkARRAY, parkARRAY+ARRSIZE(parkARRAY) );
		Parking theObject;
		eq(1, theObject.minTime(park),16);
	}
	{
		string parkARRAY[] = {"XXXXXXXXXXX",
			"X......XPPX",
			"XC...P.XPPX",
			"X......X..X",
			"X....C....X",
			"XXXXXXXXXXX"}
		;
		vector <string> park( parkARRAY, parkARRAY+ARRSIZE(parkARRAY) );
		Parking theObject;
		eq(2, theObject.minTime(park),5);
	}
	{
		string parkARRAY[] = {".C.",
			"...",
			"C.C",
			"X.X",
			"PPP"};
		vector <string> park( parkARRAY, parkARRAY+ARRSIZE(parkARRAY) );
		Parking theObject;
		eq(3, theObject.minTime(park),4);
	}
	{
		string parkARRAY[] = {"CCCCC",
			".....",
			"PXPXP"}
		;
		vector <string> park( parkARRAY, parkARRAY+ARRSIZE(parkARRAY) );
		Parking theObject;
		eq(4, theObject.minTime(park),-1);
	}
	{
		string parkARRAY[] = {"..X..",
			"C.X.P",
			"..X.."};
		vector <string> park( parkARRAY, parkARRAY+ARRSIZE(parkARRAY) );
		Parking theObject;
		eq(5, theObject.minTime(park),-1);
	}
}
// END CUT HERE
