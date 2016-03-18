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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

inline double distance(double x1, double y1, double x2 = 0.0, double y2 = 0.0) {
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

struct point {
	int x, y;
};

bool same(point p1, point p2, point p3) {
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y) < 0;
}

bool isInsideTriangle(const vector <int> &x, const vector <int> &y) {
	point pt{0, 0};
	point v1{x[0], y[0]}, v2{x[1], y[1]}, v3{x[2], y[2]};
	bool b1 = same(pt, v1, v2);
	bool b2 = same(pt, v2, v3);
	bool b3 = same(pt, v3, v1);
    return (b1==b2) && (b2==b3);
}

class Flee {
public:
    double maximalSafetyLevel(vector <int> x, vector <int> y) {
        double res = 0.0;
		set <pii> p;
		for (int i = 0; i < (int)x.size(); i++) {
			p.insert(mkp(x[i], y[i]));
		}
		x.clear();
		y.clear();
		for (auto s : p) {
			x.push_back(s.first);
			y.push_back(s.second);
		}

		if (x.size() == 1) {
			return distance(x[0], y[0]);
		} else if (x.size() == 2) {
			return min(distance(x[0], y[0]), distance(x[1], y[1]));
		} else {
			res = min(distance(x[0], y[0]), distance(x[1], y[1]));
			res = min(res, distance(x[2], y[2]));

			double m = 0;
			for (int i = 0; i < 3; i++) {
				int j = (i + 1 > 2) ? 0 : i + 1;
				m = max(m, distance(x[i], y[i], x[j], y[j]));
			}
			m /= 2;
			if (isInsideTriangle(x, y)) {
				res = min(res, m);
			}
		}
        return res;
    }

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
    {
        int xARRAY[] = {1,1,-7};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {5,-5,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Flee theObject;
        eq(0, theObject.maximalSafetyLevel(x, y),5.0);
    }
    {
        int xARRAY[] = {1,1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-5,-5};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Flee theObject;
        eq(1, theObject.maximalSafetyLevel(x, y),5.0990195135927845);
    }
    {
        int xARRAY[] = {1,1,-8};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {5,-5,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Flee theObject;
        eq(2, theObject.maximalSafetyLevel(x, y),5.0990195135927845);
    }
    {
        int xARRAY[] = {232,312,-432};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {498,-374,24};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Flee theObject;
        eq(3, theObject.maximalSafetyLevel(x, y),432.6661530556787);
    }
    {
        int xARRAY[] = {0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Flee theObject;
        eq(4, theObject.maximalSafetyLevel(x, y),0.0);
    }
	return 0;
}
// END CUT HERE
