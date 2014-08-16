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
const int INF =  1000000001;
class RectangleCovering {
public:
    int minimumNumber(int holeH, int holeW, vector <int> boardH, vector <int> boardW) {
        int res = 51;
	int N = boardW.size();
	vector <int> W, H;
	for (int i = 0; i < N; i++) {
		int ans = -1;
		if (boardH[i] > holeH) {
			ans = boardW[i];
		}
		if (boardW[i] > holeH) {
			ans = max(ans, boardH[i]);
		}
		if (ans != -1) {
			W.push_back(ans);
		}
		ans = -1;
		if (boardH[i] > holeW) {
			ans = boardW[i];
		}
		if (boardW[i] > holeW) {
			ans = max(ans, boardH[i]);
		}
		if (ans != -1) {
			H.push_back(ans);
		}
	}
	sort(H.begin(), H.end(), greater<int>());
	sort(W.begin(), W.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < H.size(); i++) {
		sum += H[i];
		if (sum >= holeH) {
			res = i + 1;
			break;
		}
	}
	sum = 0;
	for (int i = 0; i < W.size(); i++) {
		sum += W[i];
		if (sum >= holeW) {
			res = min(res, i + 1);
			break;
		}
	}
        return ((res == 51) ? -1 : res);
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int boardHARRAY[] = {8,8,8};
        vector <int> boardH( boardHARRAY, boardHARRAY+ARRSIZE(boardHARRAY) );
        int boardWARRAY[] = {2,3,4};
        vector <int> boardW( boardWARRAY, boardWARRAY+ARRSIZE(boardWARRAY) );
        RectangleCovering theObject;
        eq(0, theObject.minimumNumber(5, 5, boardH, boardW),2);
    }
    {
        int boardHARRAY[] = {6,6,6,6};
        vector <int> boardH( boardHARRAY, boardHARRAY+ARRSIZE(boardHARRAY) );
        int boardWARRAY[] = {6,6,6,6};
        vector <int> boardW( boardWARRAY, boardWARRAY+ARRSIZE(boardWARRAY) );
        RectangleCovering theObject;
        eq(1, theObject.minimumNumber(10, 10, boardH, boardW),-1);
    }
    {
        int boardHARRAY[] = {5};
        vector <int> boardH( boardHARRAY, boardHARRAY+ARRSIZE(boardHARRAY) );
        int boardWARRAY[] = {5};
        vector <int> boardW( boardWARRAY, boardWARRAY+ARRSIZE(boardWARRAY) );
        RectangleCovering theObject;
        eq(2, theObject.minimumNumber(5, 5, boardH, boardW),-1);
    }
    {
        int boardHARRAY[] = {6};
        vector <int> boardH( boardHARRAY, boardHARRAY+ARRSIZE(boardHARRAY) );
        int boardWARRAY[] = {4};
        vector <int> boardW( boardWARRAY, boardWARRAY+ARRSIZE(boardWARRAY) );
        RectangleCovering theObject;
        eq(3, theObject.minimumNumber(3, 5, boardH, boardW),1);
    }
    {
        int boardHARRAY[] = {12345,12343,12323,12424,1515,6666,6789,1424,11111,25};
        vector <int> boardH( boardHARRAY, boardHARRAY+ARRSIZE(boardHARRAY) );
        int boardWARRAY[] = {1442,2448,42,1818,3535,3333,3456,7890,1,52};
        vector <int> boardW( boardWARRAY, boardWARRAY+ARRSIZE(boardWARRAY) );
        RectangleCovering theObject;
        eq(4, theObject.minimumNumber(10000, 5000, boardH, boardW),3);
    }
}
// END CUT HERE
