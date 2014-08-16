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
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/
int dp[51][51];
int xpairs[51]; 	// x位置对swap的贡献数
int revpairs[51][51]; 	// 保存位置x到y reverse后这些位置对swap的贡献数
class BubbleSortWithReversals {
public:
	int N, K;
	int rec(int x, int p) 		// x及x之后位置在最大可以交换p次的情况下对swap的最小贡献数
	{
		if (N == x) {
			return 0;
		}
		int & res = dp[x][p];
		if (-1 != res) {
			return res;
		}
		// position x is not a reversal
		res = xpairs[x] + rec(x + 1, p);	

		// position x is the begin of a reversal
		if (p > 0) {
			for (int y = x + 1; y < N; y++) { 	// right end of reversal
				res = min(res, revpairs[x][y] + rec(y + 1, p - 1));	
			}
		}
		return res;
	}
	int getMinSwaps(vector <int> A, int K) {
		int res = 0;
		this->N = A.size();
		this->K = K;
		memset(xpairs, 0, sizeof(xpairs));
		memset(revpairs, 0, sizeof(revpairs));
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < i; j++) {
				if (A[j] > A[i]) {
					++xpairs[i];
				}
			}
		}
		for (int x = 0; x < N; x++) {
			for (int y = x + 1; y < N; y++) {
				for (int i = x; i <= y; i++) {
					for (int j = 0; j < x; j++) {
						if (A[j] > A[i]) {
							++revpairs[x][y];
						}
					}
					for (int j = i + 1; j <= y ; j++) {
						if (A[j] > A[i]) {
							++revpairs[x][y];	
						}
					}
				}
			}
		}
		res = rec(0, K);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		int AARRAY[] = {6,8,8,7,7};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		BubbleSortWithReversals theObject;
		eq(0, theObject.getMinSwaps(A, 1),0);
	}
	{
		int AARRAY[] = {7,2,2,13,5,5,2};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		BubbleSortWithReversals theObject;
		eq(1, theObject.getMinSwaps(A, 2),3);
	}
	{
		int AARRAY[] = {12,5,1,10,12,6,6,10,6,8};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		BubbleSortWithReversals theObject;
		eq(2, theObject.getMinSwaps(A, 2),12);
	}
	{
		int AARRAY[] = {2,3,1};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		BubbleSortWithReversals theObject;
		eq(3, theObject.getMinSwaps(A, 2),1);
	}
	{
		int AARRAY[] = {482,619,619,601,660,660,691,691,77,77,96,77};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		BubbleSortWithReversals theObject;
		eq(4, theObject.getMinSwaps(A, 9),22);
	}
	return 0;
}
// END CUT HERE
