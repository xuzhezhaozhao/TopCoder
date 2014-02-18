#include <algorithm>
#include <iostream>
#include <sstream>
#include <functional>

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
const int INF = 100000;
class MysticAndCandies {
public:
    int minBoxes(int C, int X, vector <int> low, vector <int> high) {
        int res = 0;
	int n = low.size();
	sort(low.begin(), low.end(), greater<int>());
	int res1 = INF, eat1 = 0;
	for (int i = 0; i < n; i++) {
		eat1 += low[i];
		if (eat1 >= X) {
			res1 = i + 1;
			break;
		}
	}
	sort(high.begin(), high.end());
	int res2 = INF, eat2 = 0;
	for (int i = 0; i < n; i++) {
		eat2 += high[i];
		if (C - eat2 < X) {
			res2 = n - i;
			break;
		}
	}
	res = min(res1, res2);

        return res;
    }
};


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int lowARRAY[] = {1, 2, 3, 4, 5};
        vector <int> low( lowARRAY, lowARRAY+ARRSIZE(lowARRAY) );
        int highARRAY[] = {1, 2, 3, 4, 5};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandies theObject;
        eq(0, theObject.minBoxes(15, 12, low, high),3);
    }
    {
        int lowARRAY[] = {5, 2, 3};
        vector <int> low( lowARRAY, lowARRAY+ARRSIZE(lowARRAY) );
        int highARRAY[] = {49, 48, 47};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandies theObject;
        eq(1, theObject.minBoxes(60, 8, low, high),2);
    }
    {
        int lowARRAY[] = {3, 9, 12, 6, 15};
        vector <int> low( lowARRAY, lowARRAY+ARRSIZE(lowARRAY) );
        int highARRAY[] = {8, 12, 20, 8, 15};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandies theObject;
        eq(2, theObject.minBoxes(58, 30, low, high),2);
    }
    {
        int lowARRAY[] = {4725448, 2753824, 6019698, 4199708, 4070001, 3589497, 5358499, 3637585, 5393667, 2837466,
           2747807, 2918199, 3638042, 5199002, 3072044, 3858909, 3762101, 3657754, 3218704, 3888861,
           3195689, 4768935, 3137633, 4124272, 4125056, 6087486, 3632970, 3620489, 2748765, 5917493,
           3958996, 3335021, 3517186, 5543440, 2951006, 3403270, 3299481, 3093204, 4092331};
        vector <int> low( lowARRAY, lowARRAY+ARRSIZE(lowARRAY) );
        int highARRAY[] = {5702812, 6805664, 6823687, 5337687, 4286533, 4999849, 6567411, 4563235, 6618139, 6260135,
           6249469, 3821449, 5963157, 6385012, 4255959, 5786920, 6112817, 4103918, 6371537, 4231698,
           3409172, 6806782, 5623563, 4511221, 6407338, 6491490, 5209517, 6076093, 6530132, 6111464,
           5833839, 6253088, 5595160, 6236805, 5772388, 5285713, 5617002, 4650978, 5234740};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandies theObject;
        eq(3, theObject.minBoxes(207581165, 172146543, low, high),31);
    }
    {
        int lowARRAY[] = {2053198, 2175819, 4260803, 1542497, 1418952, 5000015, 1381849, 2462882, 6466891, 1827580, 6943641, 5775477};
        vector <int> low( lowARRAY, lowARRAY+ARRSIZE(lowARRAY) );
        int highARRAY[] = {2827461, 3726335, 5410505, 4781355, 4925909, 5621160, 7325774, 5025476, 7876037, 8072075, 6979462, 6647628};
        vector <int> high( highARRAY, highARRAY+ARRSIZE(highARRAY) );
        MysticAndCandies theObject;
        eq(4, theObject.minBoxes(43873566, 32789748, low, high),7);
    }
}
// END CUT HERE
