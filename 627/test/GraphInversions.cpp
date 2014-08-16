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
const int INF = 1000000000;
class GraphInversions {
public:
	vector <int> V, A, B, adj[1001];
	bool visited[1005];	// 顶点的访问状态
	int R[1005];		// 用于计算 Inversions, R[weight] 表示当前路径上权值为weight的顶点的个数
	int N, K, ans;
	void DFS(int u, int d, int invs)
	{
		if (d == K) {
			ans = min(ans, invs);
		} else if (d < K) {
			for (int i = 0; i < adj[u].size(); i++) {
				int w = adj[u][i];
				if (visited[w]) {
					continue;
				}
				visited[w] = true;
				++R[ V[w] ];
				DFS(w, d + 1, invs + accumulate(R + V[w] + 1, R + 1001, 0));
				--R[ V[w] ];		// 将顶点从该路径排除
				visited[w] = false;	// 另一条路径依然可以使用该顶点
			}
		}

	}
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
		int res = INF;
		this->N = A.size();
		this->V = V;
		this->K = K;

		for (int i = 0; i < N; i++) {
			adj[ A[i] ].push_back(B[i]);
			adj[ B[i] ].push_back(A[i]);
		}

		for (int i = 0; i < N; i++) {	// 依次遍历所有顶点，以每个顶点为起始点进行DFS
			ans = INF;
			memset(visited, 0, sizeof(visited));
			memset(R, 0, sizeof(R));
			visited[i] = true;	// 这一步不要忘，起始点访问状态应为TRUE
			++R[ V[i] ];		// 将起始点加入到路径中
			DFS(i, 1, 0);
			res = min(res, ans);
		}
		return (res == INF ? -1 : res);
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int AARRAY[] = {0,1,2};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {1,2,0};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		int VARRAY[] = {40,50,60};
		vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
		GraphInversions theObject;
		eq(0, theObject.getMinimumInversions(A, B, V, 3),0);
	}
	{
		int AARRAY[] = {5, 2, 2, 5, 3, 5};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {1, 4, 0, 4, 4, 2};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		int VARRAY[] = {4, 6, 1, 3, 3, 9};
		vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
		GraphInversions theObject;
		eq(1, theObject.getMinimumInversions(A, B, V, 5),3);
	}
	{
		int AARRAY[] = {0,1,2,3,0};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {1,2,3,0,4};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		int VARRAY[] = {10,10,10,5,5};
		vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
		GraphInversions theObject;
		eq(2, theObject.getMinimumInversions(A, B, V, 5),1);
	}
	{
		int AARRAY[] = {0,1,2,3,0,2};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {1,2,3,0,4,5};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		int VARRAY[] = {10,2,5,3,7,1};
		vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
		GraphInversions theObject;
		eq(3, theObject.getMinimumInversions(A, B, V, 6),-1);
	}
	{
		int AARRAY[] = {5,7,7,5,5,7,6,4};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,0,2,0,1,4,7,3};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		int VARRAY[] = {15,10,5,30,22,10,5,2};
		vector <int> V( VARRAY, VARRAY+ARRSIZE(VARRAY) );
		GraphInversions theObject;
		eq(4, theObject.getMinimumInversions(A, B, V, 6),3);
	}
}
// END CUT HERE
