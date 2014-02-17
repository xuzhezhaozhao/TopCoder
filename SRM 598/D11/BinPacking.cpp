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

/*************** Program Begin **********************/

class BinPacking {
public:
    int minBins(vector <int> item) {
        int ans = 1000;
	int n = item.size();
	sort(item.begin(), item.end());
	int cnt_100 = count(item.begin(), item.end(), 100);
	int t = cnt_100 / 3;
	for (int k = 0; k <= t; k++) {
		int i = k * 3, j = n - 1;
		int res = k;
		while (i < j) {
			if (item[i] + item[j] <= 300) {
				++i; --j;
				++res;
			} else {
				--j;
				++res;
			}
		}
		if (i == j) {
			++res;
		}
		ans = min(ans, res);
	}

        return ans;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int itemARRAY[] = {150, 150, 150, 150, 150};
        vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
        BinPacking theObject;
        eq(0, theObject.minBins(item),3);
    }
    {
        int itemARRAY[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 189, 126, 158, 181, 132};
        vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
        BinPacking theObject;
        eq(1, theObject.minBins(item),9);
    }
    {
        int itemARRAY[] = {100, 100, 100, 100, 100, 100, 100, 100, 100};
        vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
        BinPacking theObject;
        eq(2, theObject.minBins(item),3);
    }
    {
        int itemARRAY[] = {100, 200, 100, 100, 100, 100, 200, 100, 200};
        vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
        BinPacking theObject;
        eq(3, theObject.minBins(item),4);
    }
    {
        int itemARRAY[] = {157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152};
        vector <int> item( itemARRAY, itemARRAY+ARRSIZE(itemARRAY) );
        BinPacking theObject;
        eq(4, theObject.minBins(item),8);
    }
}
// END CUT HERE
