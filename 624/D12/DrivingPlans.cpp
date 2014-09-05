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
const int MOD = 1000000009;
const int INF = 1000000000;
int ways[2001], dist[2001];
bool visited[2001];	// 防止重复访问0边

typedef pair<int, int> Node;

class DrivingPlans {
public:
	int count(int N, vector <int> A, vector <int> B, vector <int> C) {
		int res = 0;
		int E = A.size();

		memset(ways, 0, sizeof(ways));
		ways[1] = 1;
		for (int i = 1; i <= N; i++) {
			dist[i] = INF;
		}
		dist[1] = 0;
		memset(visited, 0, sizeof(visited));

		set <Node> S;
		for (int i = 0; i < E; i++) {
			int u = A[i], v = B[i], w = C[i];
			if (0 == w) {
				ways[u] = ways[v] = -1;
			}
			if (1 == v) {
				swap(A[i], B[i]);
				swap(u, v);	
			}
			if (1 == u) {
				dist[v] = w;
				visited[i] = true;
				S.insert(mkp(w, i));
			}
		}

		while (!S.empty()) {
			int shortest = (*S.begin()).first;
			int k = (*S.begin()).second;
			S.erase(S.begin());
			int cur = B[k];
			if (shortest == dist[cur]) {	// 若该条路径为最短路径，则更新ways[]
				// update ways
				if (C[k] != 0 && ways[A[k]] != -1 && ways[cur] != -1) {
					ways[cur] += ways[A[k]];
					ways[cur] %= MOD;
				} else {
					ways[cur] = -1;
				}
			} else {
				continue;
			}

			// update
			for (int i = 0; i < E; i++) {
				if (visited[i]) {
					continue;
				}
				int u = A[i], v = B[i], w = C[i];
				if (v == cur) {
					swap(A[i], B[i]);
					swap(u, v);
				}
				if (u == cur && shortest + w <= dist[v]) {
					set <Node>::iterator it = S.find(mkp(dist[v], i));
					if (it != S.end()) {
						S.erase(it);
					}
					dist[v] = shortest + w;
					S.insert(mkp(dist[v], i));
					visited[i] = true;
				}
			}
		}
		res = ways[N];
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int AARRAY[] = {4, 2, 9, 1, 1, 5, 2, 1, 10};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {8, 7, 1, 4, 3, 1, 6, 7, 5};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		int CARRAY[] = {1, 0, 0, 1, 1, 1, 0, 0, 1};
		vector <int> C( CARRAY, CARRAY+ARRSIZE(CARRAY) );
		DrivingPlans theObject;
		eq(0, theObject.count(10, A, B, C),-1);
	}
	{
		int AARRAY[] = {1,1,2,3};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4,4};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		int CARRAY[] = {1,1,1,0};
		vector <int> C( CARRAY, CARRAY+ARRSIZE(CARRAY) );
		DrivingPlans theObject;
		eq(1, theObject.count(4, A, B, C),-1);
	}
	{
		int AARRAY[] = {1,1,2,3,4,4,5,6};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4,4,5,6,7,7};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		int CARRAY[] = {1,1,2,2,3,3,4,4};
		vector <int> C( CARRAY, CARRAY+ARRSIZE(CARRAY) );
		DrivingPlans theObject;
		eq(2, theObject.count(7, A, B, C),4);
	}
}
// END CUT HERE
