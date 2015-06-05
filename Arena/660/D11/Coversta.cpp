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

int g[101][101];
int used[101][101];
int rows[10001], cols[10001];
class Coversta {
public:
    int place(vector <string> a, vector <int> x, vector <int> y) {
        int res = 0;
		int n = a.size();
		int m = a[0].size();
		int sx = x.size();
		
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				g[i][j] = a[i][j] - '0';
			}
		}

		int total = n * m;
		for (int i = 0; i < total; i++) {
			rows[i] = i / m;
			cols[i] = i % m;
		}

		for (int t = 0; t < total; t++) {
			int x1 = rows[t], y1 = cols[t];
			memset(used, 0, sizeof(used));
			int sum = 0;
			for (int k = 0; k < sx; k++) {
				int nx = x1 + x[k], ny = y1 + y[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					continue;
				}
				sum += g[nx][ny];
				used[nx][ny] = 1;
			}
			int pre = sum;
			for (int tt = t + 1; tt < total; tt++) {
				int x2 = rows[tt], y2 = cols[tt];
					for (int k = 0; k < sx; k++) {
						int nx = x2 + x[k], ny = y2 + y[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || used[nx][ny]) {
							continue;
						}
						sum += g[nx][ny];
					}
					res = max(res, sum);
					sum = pre;
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
        string aARRAY[] = {"11",
            "11"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int xARRAY[] = {0,0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Coversta theObject;
        eq(0, theObject.place(a, x, y),4);
    }
    {
        string aARRAY[] = {"11",
            "11"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int xARRAY[] = {0,1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Coversta theObject;
        eq(1, theObject.place(a, x, y),3);
    }
    {
        string aARRAY[] = {"15",
            "61"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int xARRAY[] = {0};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Coversta theObject;
        eq(2, theObject.place(a, x, y),11);
    }
    {
        string aARRAY[] = {"151",
            "655",
            "661"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int xARRAY[] = {0,0,-1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,1,0};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Coversta theObject;
        eq(3, theObject.place(a, x, y),33);
    }
    {
        string aARRAY[] = {"303",
            "333",
            "000"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int xARRAY[] = {-1,-1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-1,1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Coversta theObject;
        eq(4, theObject.place(a, x, y),12);
    }
    {
        string aARRAY[] = {"0000000",
            "1010101"}
           ;
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int xARRAY[] = {-1,-1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {-1,1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Coversta theObject;
        eq(5, theObject.place(a, x, y),0);
    }
    {
        string aARRAY[] = {"111", "191", "111"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int xARRAY[] = {1,-1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {1,-1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Coversta theObject;
        eq(6, theObject.place(a, x, y),11);
    }
    {
        string aARRAY[] = {"11", "19"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        int xARRAY[] = {0,1};
        vector <int> x( xARRAY, xARRAY+ARRSIZE(xARRAY) );
        int yARRAY[] = {0,1};
        vector <int> y( yARRAY, yARRAY+ARRSIZE(yARRAY) );
        Coversta theObject;
        eq(6, theObject.place(a, x, y),11);
    }
	return 0;
}
// END CUT HERE
