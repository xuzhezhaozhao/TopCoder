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
int g[55][55];
const long long INF = (1LL << 60);
long long dist[51][51]; // dist[i][j] 表示 节点(0, 0) 至 (i, j)的最短距离
class SkiResorts {
public:
	vector <int> altitude;
	inline int distance(int i, int j) {return abs(altitude[i] - altitude[j]);}
	long long minCost(vector <string> road, vector <int> altitude) {
		long long res = INF;
		this->altitude = altitude;
		int n = road.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (road[i][j] == 'Y') {
					g[i][j] = 1;
				} else {
					g[i][j] = 0;
				}
				dist[i][j] = INF;
			}
		}
		// Dijk 算法
		set < pair<int, pii> > S;
		for (int i = 0; i < n; i++) {
			// add start nodes
			dist[0][i] = distance(0, i);
			S.insert( mkp(dist[0][i], mkp(0, i)) );
		}
		pair<int, pii> cur;
		while (!S.empty()) {
			cur = *S.begin();
			S.erase(S.begin());
			int p = cur.second.first;
			int h = cur.second.second;
			for (int i = 0; i < n; i++) {
				// 更新相邻节点 i
				if (!g[p][i]) { continue; }
				for (int j = 0; j < n; j++) {	// (p, h) -> (i, j)
					if (altitude[h] >= altitude[j] && 
					    dist[i][j] > dist[p][h] + distance(i, j) ) {
						S.erase(mkp(dist[i][j], mkp(i, j)));
						dist[i][j] = dist[p][h] + distance(i, j);
						S.insert(mkp(dist[i][j], mkp(i, j)));
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			res = min(res, dist[n-1][i]);
		}
		res = (res == INF ? -1 : res);
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string roadARRAY[] = {"NYN",
			"YNY",
			"NYN"};
		vector <string> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
		int altitudeARRAY[] = {30, 20, 10};
		vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
		SkiResorts theObject;
		eq(0, theObject.minCost(road, altitude),0LL);
	}
	{
		string roadARRAY[] = {"NY",
			"YN"};
		vector <string> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
		int altitudeARRAY[] = {10, 20};
		vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
		SkiResorts theObject;
		eq(1, theObject.minCost(road, altitude),10LL);
	}
	{
		string roadARRAY[] = {"NYN",
			"YNN",
			"NNN"};
		vector <string> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
		int altitudeARRAY[] = {573, 573, 573};
		vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
		SkiResorts theObject;
		eq(2, theObject.minCost(road, altitude),-1LL);
	}
	{
		string roadARRAY[] = {"NNYNNYYYNN",
			"NNNNYNYNNN",
			"YNNNNYYNNN",
			"NNNNNNYNYY",
			"NYNNNNNNYY",
			"YNYNNNNYNN",
			"YYYYNNNYNN",
			"YNNNNYYNNN",
			"NNNYYNNNNN",
			"NNNYYNNNNN"};
		vector <string> road( roadARRAY, roadARRAY+ARRSIZE(roadARRAY) );
		int altitudeARRAY[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
		vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
		SkiResorts theObject;
		eq(3, theObject.minCost(road, altitude),12LL);
	}
}
// END CUT HERE
