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
const int MAX_N = 16;
int xsheeps[MAX_N][MAX_N][MAX_N][MAX_N]; // 点（i,j )到点（x, y）的矩形区域没wolf和sheep的数量
int xwolfs[MAX_N][MAX_N][MAX_N][MAX_N];

class WolvesAndSheep {
public:
	int getmin(vector <string> field) {
		int res = 1000;
		int R = field.size(), C = field[0].size();
		// calculate xsheeps, xwolfs
		memset(xwolfs, 0, sizeof(xwolfs));
		memset(xsheeps, 0, sizeof(xsheeps));
		// 求从点（i,j )到点（x, y）的矩形区域没wolf和sheep的数量
		for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			for (int x = i; x < R; x++) {
			for (int y = j; y < C; y++) {
				for (int p = i; p <= x; p++) {
				for (int q = j; q <= y; q++) {
					if ('W' == field[p][q]) {
						++xwolfs[i][j][x][y];
					} else if ('S' == field[p][q]) {
						++xsheeps[i][j][x][y];
					}
				}
				}
			}
			}
		}
		}

		// brute force
		for (int k = 0; k < (1 << (R - 1)); k++) {
			vector <int> v;
			for (int i = 1; i <= R; i++) {
				if (k & (1 << (i - 1))) {
					v.push_back(i);
				}
			}

			int ans = v.size();
			v.push_back(R);

			// 求最少的竖直fence数
			int left = 0, right;
			bool ok = true;		// 水平划分是否有解
			while (left < C && ok) {
				for (right = C; right > left; right--) {
					int up = 0;
					bool piece = ok;
					for (int j = 0; j < v.size(); j++) {
						int down = v[j];
						if (0 != xwolfs[up][left][down-1][right-1]
							&& 0 != xsheeps[up][left][down-1][right-1]) {
						// 这片区域不行
							piece = false;
							break;
						}
						up = down;
					}
					if (piece) {	// 这样划分所有区域都可以
						break;
					}
				}
				if (left == right) {
					ok = false;
				} else {
					left = right;
					if (right != C) {
						++ans;
					}
				}
			}
			if (ok) {	// 这样的水平划分有解
				res = min(res, ans);
			}
			
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string fieldARRAY[] = {"W.WSS",
			"WW.S.",
			".SSS.",
			"SSS.S",
			".SS.S"};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		WolvesAndSheep theObject;
		eq(0, theObject.getmin(field),2);
	}
	{
		string fieldARRAY[] = {".....",
			".....",
			"....."};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		WolvesAndSheep theObject;
		eq(1, theObject.getmin(field),0);
	}
	{
		string fieldARRAY[] = {".SS",
			"...",
			"S..",
			"W.W"};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		WolvesAndSheep theObject;
		eq(2, theObject.getmin(field),1);
	}
	{
		string fieldARRAY[] = {"WWWSWWSSWWW",
			"WWSWW.SSWWW",
			"WS.WSWWWWS."};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		WolvesAndSheep theObject;
		eq(3, theObject.getmin(field),10);
	}
	{
		string fieldARRAY[] = {".W.S.W.W",
			"W.W.S.W.",
			".S.S.W.W",
			"S.S.S.W.",
			".S.W.W.S",
			"S.S.W.W.",
			".W.W.W.S",
			"W.W.S.S."};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		WolvesAndSheep theObject;
		eq(4, theObject.getmin(field),7);
	}
	{
		string fieldARRAY[] = {"W.SSWWSSSW.SS",
			".SSSSW.SSWWWW",
			".WWWWS.WSSWWS",
			"SS.WSS..W.WWS",
			"WSSS.SSWS.W.S",
			"WSS.WS...WWWS",
			"S.WW.S.SWWWSW",
			"WSSSS.SSW...S",
			"S.WWSW.WWSWSW",
			".WSSS.WWSWWWS",
			"..SSSS.WWWSSS",
			"SSWSWWS.W.SSW",
			"S.WSWS..WSSS.",
			"WS....W..WSS."};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		WolvesAndSheep theObject;
		eq(5, theObject.getmin(field),24);
	}
	{
		string fieldARRAY[] = {"WW..SS",
			"WW..SS",
			"......",
			"......",
			"SS..WW",
			"SS..WW"};
		vector <string> field( fieldARRAY, fieldARRAY+ARRSIZE(fieldARRAY) );
		WolvesAndSheep theObject;
		eq(6, theObject.getmin(field),2);
	}
}
// END CUT HERE
