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

class PilingRectsDiv1 {
public:
    long long getmax(int N, vector <int> XS, vector <int> YS, int XA, int XB, int XC, int YA, int YB, int YC) {
        long long res = 0;
	vector <long long> X, Y;
	for (int i = 0; i < XS.size(); i++) {
		X.push_back(XS[i]);
		Y.push_back(YS[i]);
	}
	for (int i = XS.size(); i < 2 * N; i++) {
		X.push_back( (X[i-1]*XA + XB) % XC + 1 );
		Y.push_back( (Y[i-1]*YA + YB) % YC + 1 );
	}
	for (int i = 0; i < 2 * N; i++) {
		if (X[i] > Y[i]) {
			swap(X[i], Y[i]);
		}
	}
	
	if (1 == N) {
		return (X[0] * Y[0] + X[1] * Y[1]);	
	}

	vector < pll > sortedR;
	for (int i = 0; i < 2 * N; i++) {
		sortedR.push_back( mkp(X[i], Y[i]) );
	}
	sort(sortedR.begin(), sortedR.end());
	long long x0 = sortedR[0].first;
	long long x1, y0, y1;
	vector <long long> remainY;
	for (int i = 1; i <= N; i++) {
		remainY.clear();
		x1 = sortedR[i].first;
		for (int j = i + 1; j < 2 * N; j++) {
			remainY.push_back( sortedR[j].second );
		}
		sort(remainY.begin(), remainY.end());
		// add remaiY[0] to set 0
		y0 = remainY[0];
		for (int j = 0; j < i; j++) {
			y0 = min( y0, sortedR[j].second );
		}
		y1 = min( sortedR[i].second, remainY[N - i] );
		res = max(res, x0 * y0 + x1 * y1);

		// add remainY[0] to set 1
		y1 = min(remainY[0], sortedR[i].second);
		y0 = remainY[N - i];
		for (int j = 0; j < i; j++) {
			y0 = min( y0, sortedR[j].second );
		}
		res = max(res, x0 * y0 + x1 * y1);
	}

        return res;
    }
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int XSARRAY[] = {1,2,3,4};
        vector <int> XS( XSARRAY, XSARRAY+ARRSIZE(XSARRAY) );
        int YSARRAY[] = {10,5,3,5};
        vector <int> YS( YSARRAY, YSARRAY+ARRSIZE(YSARRAY) );
        PilingRectsDiv1 theObject;
        eq(0, theObject.getmax(2, XS, YS, 0, 0, 1, 0, 0, 1),14LL);
    }
    {
        int XSARRAY[] = {7,7};
        vector <int> XS( XSARRAY, XSARRAY+ARRSIZE(XSARRAY) );
        int YSARRAY[] = {4,4};
        vector <int> YS( YSARRAY, YSARRAY+ARRSIZE(YSARRAY) );
        PilingRectsDiv1 theObject;
        eq(1, theObject.getmax(2, XS, YS, 9, 0, 10, 2, 7, 9),56LL);
    }
    {
        int XSARRAY[] = {5,6,9,10,4,7};
        vector <int> XS( XSARRAY, XSARRAY+ARRSIZE(XSARRAY) );
        int YSARRAY[] = {9,5,8,6,8,7};
        vector <int> YS( YSARRAY, YSARRAY+ARRSIZE(YSARRAY) );
        PilingRectsDiv1 theObject;
        eq(2, theObject.getmax(3, XS, YS, 0, 0, 1, 0, 0, 1),69LL);
    }
    {
        int XSARRAY[] = {1000000000};
        vector <int> XS( XSARRAY, XSARRAY+ARRSIZE(XSARRAY) );
        int YSARRAY[] = {1000000000};
        vector <int> YS( YSARRAY, YSARRAY+ARRSIZE(YSARRAY) );
        PilingRectsDiv1 theObject;
        //eq(3, theObject.getmax(10000, XS, YS, 93827162, 91238127, 98231267, 92138287, 98563732, 99381279),1240119561532788LL);
    }
    {
        int XSARRAY[] = {375,571,973,896,460,930,583,530,657,590};
        vector <int> XS( XSARRAY, XSARRAY+ARRSIZE(XSARRAY) );
        int YSARRAY[] = {284,37,994,699,941,745,166,884,270,708};
        vector <int> YS( YSARRAY, YSARRAY+ARRSIZE(YSARRAY) );
        PilingRectsDiv1 theObject;
        eq(4, theObject.getmax(5, XS, YS, 428, 1000, 788, 851, 125, 894),420515LL);
    }
    {
        int XSARRAY[] = {898,579,465,665,875,391,583,901,326,133,656,562,701,707,492,617,455,441,382,952,689,656,334,877,120,318,497,25,569,962,845,562,632,898,882,498,595,889,382,507,791,548,810,606,105,869,569,970,322,974};
        vector <int> XS( XSARRAY, XSARRAY+ARRSIZE(XSARRAY) );
        int YSARRAY[] = {83,18,492,27,339,622,851,915,464,347,287,210,282,166,976,167,968,769,14,383,454,983,319,165,185,315,795,851,124,287,846,745,19,639,894,828,540,420,147,452,501,670,466,554,166,1,446,808,508,172};
        vector <int> YS( YSARRAY, YSARRAY+ARRSIZE(YSARRAY) );
        PilingRectsDiv1 theObject;
        eq(5, theObject.getmax(34734, XS, YS, 569, 185, 285, 741, 304, 296),10050LL);
    }
}
// END CUT HERE
