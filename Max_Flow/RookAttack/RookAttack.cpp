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
bool cut[305][305];	// 位置是否可放置
int col_match[305];	// col_match[i] 表示与i列匹配的行
bool v[305];		// 访问数组

class RookAttack {
public:
	int rows, cols;
	int find_path(int where)
	{
		if (-1 == where) {		// 找到一条增广路
			return 1;
		}
		for (int i = 0; i < cols; i++) {
			if (cut[where][i] || v[i]) {
				continue;
			}
			//if (col_match[i] == where) {	// 不用加这个判断，实际上这个条件永远不会成立
			//	continue;
			//}
			v[i] = true;
			if (find_path(col_match[i])) {
				col_match[i] = where;		// 相当于更新残留图
				return 1;
			}
		}
		return 0;
	}

	int howMany(int rows, int cols, vector <string> cutouts) {
		int res = 0;
		this->rows = rows;
		this->cols = cols;
		memset(cut, 0, sizeof(cut));
		// 对字符串进行处理
		string S;
		for (int i = 0; i < cutouts.size(); i++) {
			S += cutouts[i] + ", ";
		}			
		for (int i = 0; i < S.size(); i++) {
			if (',' == S[i]) {
				S[i] = ' ';
			}
		}
		int r, c;
		stringstream ss(S);
		while (ss >> r >> c) {
			cut[r][c] = true;
		}
		memset(col_match, -1, sizeof(col_match));
		for (int i = 0; i < rows; i++) {
			memset(v, 0, sizeof(v));
			res += find_path(i);		// dfs找增广路径
		}
		return res;
	}
};
/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		RookAttack theObject;
		eq(0, theObject.howMany(8, 8, vector <string>()),8);
	}
	{
		string cutoutsARRAY[] = {"0 0","0 1","1 1","1 0"};
		vector <string> cutouts( cutoutsARRAY, cutoutsARRAY+ARRSIZE(cutoutsARRAY) );
		RookAttack theObject;
		eq(1, theObject.howMany(2, 2, cutouts),0);
	}
	{
		string cutoutsARRAY[] = {"0 0","1 0","1 1","2 0","2 1","2 2"};
		vector <string> cutouts( cutoutsARRAY, cutoutsARRAY+ARRSIZE(cutoutsARRAY) );
		RookAttack theObject;
		eq(2, theObject.howMany(3, 3, cutouts),2);
	}
	{
		string cutoutsARRAY[] = {"0 0","1 2","2 2"};
		vector <string> cutouts( cutoutsARRAY, cutoutsARRAY+ARRSIZE(cutoutsARRAY) );
		RookAttack theObject;
		eq(3, theObject.howMany(3, 3, cutouts),3);
	}
	{
		RookAttack theObject;
		eq(4, theObject.howMany(300, 300, vector <string>()),300);
	}
}
// END CUT HERE
