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
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/

class BuildingHeights {
public:
    int minimum(vector <int> heights) {
	int ans = 0;    
	int N = heights.size();
	sort(heights.begin(), heights.end(), greater<int>());

	int sum[4001];
	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + heights[i - 1];	
	}

	for (int M = 1; M <= N; M++) {
        	int res = 100000000;
		for (int i = 0; i < N - M + 1; i++) {
			res = min(res, M * heights[i] - (sum[i + M] - sum[i]));
		}
		ans ^= res;
	}
	return ans;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int heightsARRAY[] = {1, 5, 4, 3, 8};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeights theObject;
        eq(0, theObject.minimum(heights),22);
    }
    {
        int heightsARRAY[] = {1, 2, 3};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeights theObject;
        eq(1, theObject.minimum(heights),2);
    }
    {
        int heightsARRAY[] = {3, 4, 1, 6, 8, 1};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeights theObject;
        eq(2, theObject.minimum(heights),21);
    }
    {
        int heightsARRAY[] = {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
            2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
            929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
            1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
            1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
            1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeights theObject;
        eq(3, theObject.minimum(heights),56068);
    }
	return 0;
}
// END CUT HERE
