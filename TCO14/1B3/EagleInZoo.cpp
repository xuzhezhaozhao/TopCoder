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
const int MAX_N = 51, MAX_K = 101;
double dp[MAX_N][MAX_K];
double C[MAX_K][MAX_K];		// 注意：用 long long 会溢出
class EagleInZoo {
public:
	vector < vector<int> > childs;
	double rec(int v, int t)
	{
		if (1 == t) {
			return 1.0;
		}
		double & res = dp[v][t];
		if (res > -0.5) {
			return res;
		}
		if (childs[v].size() == 0 && t > 1) {	// 该节点无 child 且t > 1，最后一只一定无法停留
			res = 0;
			return res;
		}
		res = 0;

		for (int i = 0; i < childs[v].size(); i++) {
			int x = childs[v][i];
			int c = childs[v].size();
			for (int j = 0; j <= t - 2; j++) {
				res += (1.0 / c) * C[t-2][j] * pow(1.0 / c, j) * pow( 1.0 * (c-1) / c, t-2-j) * rec(x, j + 1);
			}
		}

		return res;
	}
	double calc(vector <int> parent, int K) {
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_K; j++) {
				dp[i][j] = -1.0;
			}
		}
		childs.resize(parent.size() + 1);
		for (int i = 0; i < parent.size(); i++) {
			childs[ parent[i] ].push_back(i + 1);
		}
		// calculate C[]
		C[0][0] = 1;
		for (int i = 1; i <= K - 1; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++) {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
		return rec(0, K);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int parentARRAY[] = {0, 1, 2, 3, 4, 4, 6, 7, 6, 9, 4, 3, 0, 0};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		EagleInZoo theObject;
		eq(0, theObject.calc(parent, 96),0.029121983544255357);
	}
	{
		int parentARRAY[] = {0,0};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		EagleInZoo theObject;
		eq(1, theObject.calc(parent, 3),0.5);
	}
	{
		int parentARRAY[] = {0,1,0,3};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		EagleInZoo theObject;
		eq(2, theObject.calc(parent, 4),0.75);
	}
	{
		int parentARRAY[] = {0,0,1,1,2,4,4,4,5,5,6,6};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		EagleInZoo theObject;
		eq(3, theObject.calc(parent, 20),0.14595168754091617);
	}
	{
		int parentARRAY[] = {0,1,2,3,2,1,1,7,0,9,10,11,12,13,14,15,16,17,18,14,9};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		EagleInZoo theObject;
		eq(4, theObject.calc(parent, 24),0.3272154791654077);
	}
	{
		int parentARRAY[] = {0,1,2,3,4,5,6,7,8,9,10};
		vector <int> parent( parentARRAY, parentARRAY+ARRSIZE(parentARRAY) );
		EagleInZoo theObject;
		eq(5, theObject.calc(parent, 50),0.0);
	}
}
// END CUT HERE
