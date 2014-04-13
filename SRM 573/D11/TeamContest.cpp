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
bool v[55];
class TeamContest {
public:
    int worstRank(vector <int> strength) {
        int res = 1;
	int n = strength.size();
	int cur = *max_element(strength.begin(), strength.begin() + 3) + *min_element(strength.begin(), strength.begin() + 3);
        if (3 == n) {
		return 1;
        }
	memset(v, 0, sizeof(v));
	sort(strength.begin() + 3, strength.begin() + n);
	for (int i = 3; i < n; i++) {
		if (v[i]) {
			continue;
		}
		v[i] = true;
		int k = i + 1;
		while (v[k]) {
			++k;
		}
		v[k] = true;
		bool f = false;
		for (int j = i + 2; j < n; j++) {
			if (v[j]) {
				continue;
			}
			if (strength[i] + strength[j] > cur) {
				v[j] = true;
				f = true;
				++res;
				break;
			}
		}
		if (!f) {
			v[i + 2] = true;
		}

	}
	return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        int strengthARRAY[] = {230988, 692473, 829904, 810585, 841281, 869742, 205319, 182994, 745583, 710632, 364907, 150624, 131777, 393757, 983482};
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContest theObject;
        eq(0, theObject.worstRank(strength),4);
    }
    {
        int strengthARRAY[] = {728935, 126966, 196117, 70933, 652538, 230031, 220008, 170949, 207149, 748007, 156919, 368745, 750029, 485044, 640194, 40651, 631911, 446187, 692659, 483043, 525705, 661121, 632025, 309374, 526758, 5873, 683669, 768970, 258119, 414688, 203321, 54599, 632996, 572509, 686361, 396855, 310078, 596968, 799631}
           ;
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContest theObject;
        eq(1, theObject.worstRank(strength),12);
    }
    {
        int strengthARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContest theObject;
        eq(2, theObject.worstRank(strength),1);
    }
    {
        int strengthARRAY[] = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}
           ;
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContest theObject;
        eq(3, theObject.worstRank(strength),3);
    }
    {
        int strengthARRAY[] = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}
           ;
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContest theObject;
        eq(4, theObject.worstRank(strength),3);
    }
}
// END CUT HERE
