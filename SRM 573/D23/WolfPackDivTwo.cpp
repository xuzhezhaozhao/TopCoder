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
const int MAX_C = 55;
long long C[MAX_C][MAX_C];
class WolfPackDivTwo {
public:
	// 求 C[N][k]
	void calcBi()
	{
		memset(C, 0, sizeof(C));
		C[0][0] = 1;
		for (int i = 1; i < MAX_C; i++) {
			C[i][0] = 1;
			if (i < 501) {
				C[i][i] = 1;
			}
			for (int j = 1; j < i; j++) {
				C[i][j] = C[i-1][j] + C[i-1][j-1];
				C[i][j] %= MOD;
			}
		}
	}
	// 总共m步，a，b分别表示向着目的地方向需移动的最小步数，返回移动方法数
	long long solve(int a, int b, int m)
	{
		long long res = 0;
		int lim = (m + a + b) / 2;
		for (int u = a; u <= m - b; u++) {
			for (int v = b; v <= m - a; v++) {
				if (u + v != lim) {
					continue;
				}
				res += ( (C[m][u] * C[m - u][u-a])%MOD ) *( (C[m - u - u + a][v] * C[m - u - u + a -v][v - b])%MOD );
				res %= MOD;
			}
		}
		res %= MOD;
		return res;
	}
	int calc(vector <int> x, vector <int> y, int m) {
		long long sum = 0;
		int n = x.size();
		int max_x = *max_element(x.begin(), x.begin() + n) + m;
		int min_x = *min_element(x.begin(), x.begin() + n) - m;
		int max_y = *max_element(y.begin(), y.begin() + n) + m;
		int min_y = *min_element(y.begin(), y.begin() + n) - m;
		calcBi();
		for (int i = min_x; i <= max_x; i++) {
			for (int j = min_y; j <= max_y; j++) {
				bool ok = true;
				for (int k = 0; k < n; k++) {
					int dis = abs(i - x[k]) + abs(j - y[k]);
					if ( m < dis || (m - dis) % 2 != 0 ) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					continue;
				}
				long long res = 1;
				for (int k = 0; k < n; k++) {
					res *= solve(abs(i - x[k]), abs(j - y[k]), m);
					res %= MOD;
				}
				sum += res;
				sum %= MOD; 
			}
		}

		return sum;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int xARRAY[] = {3,5};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {0,0};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		WolfPackDivTwo theObject;
		eq(0, theObject.calc(x, y, 1),1);
	}
	{
		int xARRAY[] = {0,1};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {0,0};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		WolfPackDivTwo theObject;
		eq(1, theObject.calc(x, y, 1),0);
	}
	{
		int xARRAY[] = {0,2,4};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {0,0,0};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		WolfPackDivTwo theObject;
		eq(2, theObject.calc(x, y, 2),4);
	}
	{
		int xARRAY[] = {7,8};
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {8,7};
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		WolfPackDivTwo theObject;
		eq(3, theObject.calc(x, y, 1),2);
	}
	{
		int xARRAY[] = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8}
		;
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18}
		;
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		WolfPackDivTwo theObject;
		eq(4, theObject.calc(x, y, 12),0);
	}
	{
		int xARRAY[] = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8}
		;
		vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
		int yARRAY[] = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18}
		;
		vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
		WolfPackDivTwo theObject;
		eq(5, theObject.calc(x, y, 31),573748580);
	}
}
// END CUT HERE
