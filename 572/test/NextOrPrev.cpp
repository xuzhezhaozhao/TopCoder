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

class NextOrPrev {
public:
    int getMinimum(int nextCost, int prevCost, string start, string goal) {
	int n = start.size();
        int cost = 0;
	for (int i = 0; i < n - 1; i++) {
		if (start[i] > goal[i]) {
			cost += prevCost * (start[i] - goal[i]);
		} else {
			cost += nextCost * (goal[i] - start[i]);
		}
		for (int j = i + 1; j < n; j++) {
			int t1 = min(start[i], goal[i]);
			int t2 = max(start[i], goal[i]);
			int t3 = min(start[j], goal[j]);
			int t4 = max(start[j], goal[j]);
			if ( (start[i] - goal[i]) * (start[j] - goal[j]) >= 0) {
				if ( (t1 >= t3 && t2 <= t4) || (t3 >= t1 && t4 <= t2) ) {
					return -1;
				}
			} else {
				if ( (t2 >= t3 && t1 <= t4) || (t3 >= t2 && t4 <= t1) ) {
					return -1;
				}
			}
		}
	}
	if (start[n-1] > goal[n-1]) {
		cost += prevCost * (start[n-1] - goal[n-1]);
	} else {
		cost += nextCost * (goal[n-1] - start[n-1]);
	}
	return cost;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
    {
        NextOrPrev theObject;
        eq(0, theObject.getMinimum(5, 8, "ae", "bc"),21);
    }
    {
        NextOrPrev theObject;
        eq(1, theObject.getMinimum(5, 8, "ae", "cb"),-1);
    }
    {
        NextOrPrev theObject;
        eq(2, theObject.getMinimum(1, 1, "srm", "srm"),0);
    }
    {
        NextOrPrev theObject;
        eq(3, theObject.getMinimum(10, 1, "acb", "bdc"),30);
    }
    {
        NextOrPrev theObject;
        eq(4, theObject.getMinimum(10, 1, "zyxw", "vuts"),16);
    }
    {
        NextOrPrev theObject;
        eq(5, theObject.getMinimum(563, 440, "ptrbgcnlaizo", "rtscedkiahul"),10295);
    }
    {
        NextOrPrev theObject;
        eq(6, theObject.getMinimum(126, 311, "yovlkwpjgsna", "zpwnkytjisob"),-1);
    }
}
// END CUT HERE
