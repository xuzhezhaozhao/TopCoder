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
const int MOD = 1e9 + 7;
const int MAX = 55;
long long dp[MAX][MAX][MAX];	// dp[x][e][k] 表示以x为根的树，若不考虑其前e个孩子，能选出顶点数为k的且以x为根的子树的种数
int g[MAX][MAX];		// g[x][e] 表示顶点x的第e个孩子
int degree[MAX];		// degree[x] 表示顶点x的孩子数

class FoxConnection2 {
public:
	// 使用dfs构造树, 求出各顶点的孩子
	void dfsMakeTree(int x, int parent, vector <int> & A, vector <int> & B)
	{
		degree[x] = 0;
		for (int i = 0; i < A.size(); i++) {
			if (x == A[i] - 1 && parent != B[i] - 1) {	// B[i] - 1 是 x的孩子
				g[x][ degree[x] ] = B[i] - 1;		// 顶点从0开始编号
				++degree[x];
				dfsMakeTree( B[i] - 1, x, A, B );	// 构造孩子树
			}
			if (x == B[i] - 1 && parent != A[i] - 1) {
				g[x][ degree[x] ] = A[i] - 1;
				++degree[x];
				dfsMakeTree( A[i] - 1, x, A, B);
			}
		}
	}
	
	int rootedWays(int x, int e, int k)
	{
		long long & res = dp[x][e][k];
		if (e == degree[x]) {
			return (k == 1 ? 1 : 0);
		}
		if (res != -1) {
			return res;
		}
		
		res = rootedWays(x, e + 1, k);	// 第一颗子树不提供，全部由剩下的树提供
		for (int i = 1; i < k; i++) {	// 第一颗子树提供i个，剩下的树提供k-i个
			res += rootedWays(g[x][e], 0, i) * rootedWays(x, e + 1, k - i);
			res %= MOD;
		}
		return res;
	}

	int ways(vector <int> A, vector <int> B, int k) {
		long long res = 0;
		memset(dp, -1, sizeof(dp));
		memset(degree, 0, sizeof(degree));
		memset(g, 0, sizeof(g));
		dfsMakeTree(0, -1, A, B);
		for (int i = 0; i < A.size() + 1; i++) {
			res += rootedWays(i, 0, k);
			res %= MOD;
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int AARRAY[] = {1,2,3};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		FoxConnection2 theObject;
		eq(0, theObject.ways(A, B, 2),3);
	}
	{
		int AARRAY[] = {1,1,1,1};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4,5};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		FoxConnection2 theObject;
		eq(1, theObject.ways(A, B, 3),6);
	}
	{
		int AARRAY[] = {1,2,3,4};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4,5};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		FoxConnection2 theObject;
		eq(2, theObject.ways(A, B, 3),3);
	}
	{
		int AARRAY[] = {1,2,2,4,4};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4,5,6};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		FoxConnection2 theObject;
		eq(3, theObject.ways(A, B, 3),6);
	}
	{
		int AARRAY[] = {1,2,2,4,4};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4,5,6};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		FoxConnection2 theObject;
		eq(4, theObject.ways(A, B, 5),4);
	}
	{
		int AARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		FoxConnection2 theObject;
		eq(5, theObject.ways(A, B, 20),923263934);
	}
	{
		int AARRAY[] = {2};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {1};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		FoxConnection2 theObject;
		eq(6, theObject.ways(A, B, 1),2);
	}
}
// END CUT HERE
