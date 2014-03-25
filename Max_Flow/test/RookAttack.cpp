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
bool cut[605][605];	// 位置是否可放置
int cap[605][605];	// 每条边的容量
int from[605];		// 保留最短路径上到达该点的上一个顶点
bool v[605];		// 访问数组
const int INF = 1000000;
class RookAttack {
public:
	int rows, cols;

	// 使用增广路径法求最大流，返回值为0时说明残留图中不存在增广路径
	int bfs()
	{		
		memset(v, 0, sizeof(v));
		memset(from, -1, sizeof(from));
		queue <int> Q;
		int start = rows, end = rows + cols + 1;	// 添加两个超级顶点，将问题转化为单源单汇
		Q.push(start);
		v[start] = true;
		int where;
		// bfs 求最短路径
		bool ok = false;
		while (!Q.empty()) {
			where = Q.front();
			Q.pop();
			for (int i = 0; i <= rows + cols + 1; i++) {
				if (cap[where][i] > 0 && !v[i]) {	// 有边且点未被访问
					from[i] = where;
					v[i] = true;
					if (i == end) {
						ok = true;
						break;
					}
					Q.push(i);
				}
			}
			if (ok) {
				break;
			}
		}
		// 求最短路径上的最小容量
		int path_cap = INF;
		where = end;
		while (from[where] != -1) {
			int pre = from[where];
			path_cap = min(path_cap, cap[pre][where]);
			where = pre;
		}
		// 更新残留图，cap[]数组
		where = end;
		while (from[where] != -1) {
			int pre = from[where];
			cap[pre][where] -= path_cap;
			cap[where][pre] += path_cap;
			where = pre;
		}
		
		return (path_cap == INF ? 0 : path_cap);
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
		// 每行、每列代表一个顶点，行顶点编号为0...rows - 1，超级源点为rows；
		// 列顶点编号为rows + 1 ... rows + cols，超级汇点为rows + cols + 1.
		while (ss >> r >> c) {
			cut[r][c + rows + 1] = true;
		}

		memset(cap, 0, sizeof(cap));
		for (int i = 0; i < rows; i++) {
			for (int j = rows + 1; j < rows + cols + 1; j++) {
				if (!cut[i][j]) {
					cap[i][j] = 1;		// 有边，容量为1
				}
				cap[j][rows + cols + 1] = 1;	// 每个汇点到超级汇点的容量为1
			}
			cap[rows][i] = 1;	// 超级源点到每个源点的容量为1
		}
		int add;
		while ( (add = bfs()) != 0 ) {	// 不断调用BFS，直到没有残留图中没有增广路径为止
			res += add;
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
