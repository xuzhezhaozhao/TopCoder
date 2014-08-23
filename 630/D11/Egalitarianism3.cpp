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
const int MAX_N = 50;
int D[MAX_N][MAX_N];
class Egalitarianism3 {
public:
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
		int res = 0;

		if (1 == n) {
			return 1;
		}

		res = 2;

		int sn = a.size();
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				D[i][j] = 123456789;
			}
		}

		for (int i = 0; i < sn; i++) {
			D[ a[i] - 1 ][ b[i] - 1 ] = D[ b[i] - 1 ][ a[i] - 1 ] = len[i];
		}
		for (int i = 0; i < n; i++) {
			D[i][i] = 0;
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
				}
			}
		}

		// 由于是一个树，树中没有环，所以当k > 2时，一定有一个中心的连接k个符合条件的点
		for (int center = 0; center < n; center++) {
			for (int x = 0; x < n; x++) {
				if (x == center) {
					continue;
				}
				vector <int> xset;	// 满足条件的点的集合
				xset.push_back(x);
				int d = 2 * D[center][x];
				// 尝试添加其他的点
				for (int i = 0; i < n; i++) {
					if (i == center || i == x) {
						continue;
					}
					// 符合条件的点到中心距离应该相等
					if (D[center][x] != D[center][i]) {
						continue;
					}
					// 是否与所有点距离相等
					bool ok = true;
					for (int j = 0; j < xset.size(); j++) {
						if (D[i][ xset[j] ] != d) {
							ok = false;
							break;
						}
					}
					if (ok) {
						xset.push_back(i);
					}
				}
				res = max<int>(res, xset.size());
			}
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int aARRAY[] = {15, 10, 16, 29, 1, 10, 12, 10, 27, 8, 10, 12, 27, 12, 7, 27, 9, 12, 27, 4, 16, 27, 4, 9, 27, 16, 29, 19};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int bARRAY[] = {22, 4, 8, 24, 23, 19, 27, 17, 21, 3, 5, 15, 9, 6, 16, 10, 13, 18, 1, 26, 14, 29, 25, 7, 2, 28, 20, 11};
		vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
		int lenARRAY[] = {8, 4, 9, 6, 5, 4, 1, 4, 5, 8, 10, 6, 2, 5, 5, 8, 3, 8, 7, 3, 3, 5, 10, 10, 9, 10, 7, 7};
		vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
		Egalitarianism3 theObject;
		eq(0, theObject.maxCities(29, a, b, len),4);
	}
	{
		int aARRAY[] = {1,2,3,2,3};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int bARRAY[] = {2,3,4,5,6};
		vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
		int lenARRAY[] = {2,1,3,2,3};
		vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
		Egalitarianism3 theObject;
		eq(1, theObject.maxCities(6, a, b, len),3);
	}
	{
		int aARRAY[] = {1,1,1,1,1,1,1,1,1};
		vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
		int bARRAY[] = {2,3,4,5,6,7,8,9,10};
		vector <int> b( bARRAY, bARRAY+ARRSIZE(bARRAY) );
		int lenARRAY[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
		vector <int> len( lenARRAY, lenARRAY+ARRSIZE(lenARRAY) );
		Egalitarianism3 theObject;
		eq(2, theObject.maxCities(10, a, b, len),9);
	}
	{
		Egalitarianism3 theObject;
		eq(3, theObject.maxCities(1, vector <int>(), vector <int>(), vector <int>()),1);
	}
}
// END CUT HERE
