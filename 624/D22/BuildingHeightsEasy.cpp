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

class BuildingHeightsEasy {
public:
    int minimum(int M, vector <int> heights) {
        int res = 100000000;
	int N = heights.size();
	sort(heights.begin(), heights.end(), greater<int>());
	for (int i = 0; i < N - M + 1; i++) {
		res = min(res, M * heights[i] - accumulate(heights.begin() + i, heights.begin() + i + M, 0));
	}
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int heightsARRAY[] = {1, 2, 1, 4, 3};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(0, theObject.minimum(2, heights),0);
    }
    {
        int heightsARRAY[] = {1, 3, 5, 2, 1};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(1, theObject.minimum(3, heights),2);
    }
    {
        int heightsARRAY[] = {43, 19, 15};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(2, theObject.minimum(1, heights),0);
    }
    {
        int heightsARRAY[] = {19, 23, 9, 12};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(3, theObject.minimum(3, heights),15);
    }
    {
        int heightsARRAY[] = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4};
        vector <int> heights( heightsARRAY, heightsARRAY+ARRSIZE(heightsARRAY) );
        BuildingHeightsEasy theObject;
        eq(4, theObject.minimum(12, heights),47);
    }
	return 0;
}
// END CUT HERE
