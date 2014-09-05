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
int dist[51][51];
int xdist[1001][51];
int INF = 100000001;

class NegativeGraphDiv2 {
public:
	long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
		long long res = 0LL;
		int E = s.size();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = INF;
			}
			dist[i][i] = 0;
		}

		for (int i = 0; i < E; i++) {
			int u = s[i] - 1, v = t[i] - 1, w = weight[i];
			dist[u][v] = min(dist[u][v], w);
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dist[i][j] = min(dist[i][j], dist[i][k] +dist[k][j]);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			xdist[0][i] = dist[i][N - 1];
		}
		for (int i = 1; i <= charges; i++) {
			for (int j = 0; j < N; j++) {
				xdist[i][j] = xdist[i - 1][j];
				for (int k = 0; k < E; k++) {
					int u = s[k] - 1, v = t[k] - 1, w = -weight[k];
					xdist[i][j] = min(xdist[i][j], dist[j][u] + w + xdist[i - 1][v]);
				}
			}
		}
		res = xdist[charges][0];
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int sARRAY[] = {1,1,2,2,3,3};
		vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
		int tARRAY[] = {2,3,1,3,1,2};
		vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
		int weightARRAY[] = {1,5,1,10,1,1};
		vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
		NegativeGraphDiv2 theObject;
		eq(0, theObject.findMin(3, s, t, weight, 1),-9LL);
	}
	{
		int sARRAY[] = {1};
		vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
		int tARRAY[] = {1};
		vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
		int weightARRAY[] = {100};
		vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
		NegativeGraphDiv2 theObject;
		eq(1, theObject.findMin(1, s, t, weight, 1000),-100000LL);
	}
	{
		int sARRAY[] = {1,1,2};
		vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
		int tARRAY[] = {2,2,1};
		vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
		int weightARRAY[] = {6,1,4};
		vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
		NegativeGraphDiv2 theObject;
		eq(2, theObject.findMin(2, s, t, weight, 2),-9LL);
	}
	{
		int sARRAY[] = {1};
		vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
		int tARRAY[] = {2};
		vector <int> t( tARRAY, tARRAY+ARRSIZE(tARRAY) );
		int weightARRAY[] = {98765};
		vector <int> weight( weightARRAY, weightARRAY+ARRSIZE(weightARRAY) );
		NegativeGraphDiv2 theObject;
		eq(3, theObject.findMin(2, s, t, weight, 100),-98765LL);
	}
}
// END CUT HERE
