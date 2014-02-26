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
int dp[55][55][55];
class MiningGoldEasy {
public:
	int N, M, endays;
	vector <int> event_i, event_j;
	 
	int rec(int cur, int x, int y)		// 已过天数cur，此时所在位置为 ( event_i[x], event_j[y] )，
						// 返回最小距离。
	{
		if (cur == endays) {
			return 0;
		}
		int & res = dp[cur][x][y];
		if (res != -1) {
			return res;
		}
		res = INT_MAX;
		int dis = abs(event_i[cur] - event_i[x]) + abs(event_j[cur] - event_j[y]);
		for (int i = 0; i < endays; i++) {
			// 竖直方向
			res = min(res, dis + rec(cur + 1, x, i));
			// 水平方向
			res = min(res, dis + rec(cur + 1, i, y));
		}
		return res;
	}

	int GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j) {
		int res = 0;
		this->N = N;
		this->M = M;
		this->event_i = event_i;
		this->event_j = event_j;
		this->endays = event_i.size();
		res = INT_MAX;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < endays; i++) {
			for (int j = 0; j < endays; j++) {
				res = min(res, rec(0, i, j));
			}
		}
		res = (N + M) * endays - res; 
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int event_iARRAY[] = {0};
		vector <int> event_i( event_iARRAY, event_iARRAY+ARRSIZE(event_iARRAY) );
		int event_jARRAY[] = {0};
		vector <int> event_j( event_jARRAY, event_jARRAY+ARRSIZE(event_jARRAY) );
		MiningGoldEasy theObject;
		eq(0, theObject.GetMaximumGold(2, 2, event_i, event_j),4);
	}
	{
		int event_iARRAY[] = {0, 2};
		vector <int> event_i( event_iARRAY, event_iARRAY+ARRSIZE(event_iARRAY) );
		int event_jARRAY[] = {0, 1};
		vector <int> event_j( event_jARRAY, event_jARRAY+ARRSIZE(event_jARRAY) );
		MiningGoldEasy theObject;
		eq(1, theObject.GetMaximumGold(2, 2, event_i, event_j),7);
	}
	{
		int event_iARRAY[] = {0, 3, 3};
		vector <int> event_i( event_iARRAY, event_iARRAY+ARRSIZE(event_iARRAY) );
		int event_jARRAY[] = {0, 3, 0};
		vector <int> event_j( event_jARRAY, event_jARRAY+ARRSIZE(event_jARRAY) );
		MiningGoldEasy theObject;
		eq(2, theObject.GetMaximumGold(3, 3, event_i, event_j),15);
	}
	{
		int event_iARRAY[] = {0, 3};
		vector <int> event_i( event_iARRAY, event_iARRAY+ARRSIZE(event_iARRAY) );
		int event_jARRAY[] = {4, 1};
		vector <int> event_j( event_jARRAY, event_jARRAY+ARRSIZE(event_jARRAY) );
		MiningGoldEasy theObject;
		eq(3, theObject.GetMaximumGold(3, 4, event_i, event_j),11);
	}
	{
		int event_iARRAY[] = {0, 4, 2, 5, 0};
		vector <int> event_i( event_iARRAY, event_iARRAY+ARRSIZE(event_iARRAY) );
		int event_jARRAY[] = {3, 4, 5, 6, 0};
		vector <int> event_j( event_jARRAY, event_jARRAY+ARRSIZE(event_jARRAY) );
		MiningGoldEasy theObject;
		eq(4, theObject.GetMaximumGold(5, 6, event_i, event_j),48);
	}
	{
		int event_iARRAY[] = {81, 509, 428, 6, 448, 149, 77, 142, 40, 405, 109, 247};
		vector <int> event_i( event_iARRAY, event_iARRAY+ARRSIZE(event_iARRAY) );
		int event_jARRAY[] = {653, 887, 770, 477, 53, 637, 201, 863, 576, 393, 512, 243};
		vector <int> event_j( event_jARRAY, event_jARRAY+ARRSIZE(event_jARRAY) );
		MiningGoldEasy theObject;
		eq(5, theObject.GetMaximumGold(557, 919, event_i, event_j),16255);
	}
}
// END CUT HERE
