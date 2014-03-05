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

class PolygonTraversal2 {
public:
	vector <int> points;
	set <int> have;
	int n, start;
	int cnt;
	bool isIntersect(int p)
	{
		int s = points.size();
		int pre = points[s - 1];
		int mx = max(p, pre);
		int mi = min(p, pre);
		for (int i = 0; i < s - 1; i++) {
			int p1 = points[i], p2 = points[i + 1];
			if ( ( (p1 > mi && p1 < mx) && (p2 < mi || p2 > mx) )
			  || ( (p2 > mi && p2 < mx) && (p1 < mi || p1 > mx) )) {
				return true;
			}
		}
		return false;
	}
	void backtrack()
	{
		// base case
		if (points.size() == n) {
			if (isIntersect(start)) {
				++cnt;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (have.find(i) == have.end()) {
				// 未加入点
				if (isIntersect(i)) {
					// 符合条件，加入
					points.push_back(i);
					have.insert(i);
					backtrack();
					points.pop_back();	// 恢复
					have.erase(i);
				}
			}
		}
	}
	int count(int N, vector <int> points) {
		int res = 0;
		this->n = N;
		this->points = points;
		this->have = set<int>(points.begin(), points.end());
		this->start = points[0];	
		cnt = 0;
		backtrack();
		res = cnt;
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int pointsARRAY[] = {1, 3, 5};
		vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
		PolygonTraversal2 theObject;
		eq(0, theObject.count(5, points),1);
	}
	{
		int pointsARRAY[] = {1, 4, 2};
		vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
		PolygonTraversal2 theObject;
		eq(1, theObject.count(6, points),1);
	}
	{
		int pointsARRAY[] = {2, 4, 7};
		vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
		PolygonTraversal2 theObject;
		eq(2, theObject.count(7, points),2);
	}
	{
		int pointsARRAY[] = {1, 2, 3, 4, 6, 5};
		vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
		PolygonTraversal2 theObject;
		eq(3, theObject.count(7, points),0);
	}
	{
		int pointsARRAY[] = {1, 5, 10};
		vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
		PolygonTraversal2 theObject;
		eq(4, theObject.count(13, points),1412);
	}
}
// END CUT HERE
