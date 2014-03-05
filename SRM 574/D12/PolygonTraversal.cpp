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
long long dp[1 << 18][18];
class PolygonTraversal {
public:
	int N, start, end;
	inline int addPoint(int mask, int p)
	{
		return ( mask | (1 << p) );
	}
	bool isIntersect(int mask, int p1, int p2)
	{
		bool f1 = false, f2 = false;
		if (p1 > p2) {
			swap(p1, p2);
		}
		for (int i = 0; i < N; i++) {
			if ( mask & (1 << i) ) {
				if (i > p1 && i < p2) {
					f1 = true;
				} else if (i < p1 || i > p2) {
					f2 = true;
				}
			}
		}
		return f1 && f2;
	}
	long long rec(int mask, int p)
	{
		long long & res = dp[mask][p];
		if (res != -1) {
			return res;
		}
		if (mask == end) {	// base case
			if (isIntersect(mask, p, start) ) {
				res = 1;
				return 1;
			} else {
				res = 0;
				return 0;
			}
		}
		res = 0;
		for (int i = 0; i < N; i++) {
			if ( !( mask & (1 << i) ) ) {	// 若点未访问
				if (isIntersect(mask, p, i)) {
					// 若符合，加入该点
					res += rec( addPoint(mask, i), i );
				}
			}
		}
		return res;
	}
	long long count(int N, vector <int> points) {
		long long res = 0;
		this->N = N;
		end = (1 << N) - 1;
		start = points[0] - 1;
		int mask = 0;
		for (int i = 0; i < points.size(); i++) {
			--points[i];
			mask = addPoint(mask, points[i]);
		}
		memset(dp, -1, sizeof(dp));
		res = rec(mask, points[ points.size() - 1 ]);

		return res;
	}

};

/************** Program End ************************/
// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int pointsARRAY[] = {1, 4, 2, 5};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal theObject;
        eq(0, theObject.count(5, points),1LL);
    }
    {
        int pointsARRAY[] = {1, 4, 2};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal theObject;
        eq(1, theObject.count(6, points),1LL);
    }
    {
        int pointsARRAY[] = {2, 4, 7};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal theObject;
        eq(2, theObject.count(7, points),2LL);
    }
    {
        int pointsARRAY[] = {1, 2, 3, 4, 6, 5};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal theObject;
        eq(3, theObject.count(7, points),0LL);
    }
    {
        int pointsARRAY[] = {1, 7, 18};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal theObject;
        eq(4, theObject.count(18, points),4374612736LL);
    }
}
// END CUT HERE
