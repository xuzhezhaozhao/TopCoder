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

class NumbersChallenge {
public:
    int MinNumber(vector <int> S) {
        int res = 0;

	int n = S.size();
	sort(S.begin(), S.end());
	set <int> sums, temp;
	for (int i = 0; i < n; i++) {
		temp = sums;
		sums.insert(S[i]);
		FOREACH(it, temp) {
			sums.insert((*it) + S[i]);
		}
	}
	if (*sums.begin() != 1) {
		return 1;
	}
	set <int>::iterator pre_it, it;
	pre_it = it = sums.begin();
	++it;
	for (; it != sums.end(); ++it) {
		if ((*it) - 1 != *pre_it) {
			return ((*pre_it) + 1);
		}
		pre_it = it;
	}
	res = (*pre_it) + 1;
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int SARRAY[] = {5, 1, 2};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
        eq(0, theObject.MinNumber(S),4);
    }
    {
        int SARRAY[] = {2, 1, 4};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
       eq(1, theObject.MinNumber(S),8);
    }
    {
        int SARRAY[] = {2, 1, 2, 7};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
       eq(2, theObject.MinNumber(S),6);
    }
    {
        int SARRAY[] = {94512, 2, 87654, 81316, 6, 5, 6, 37151, 6, 139, 1, 36, 307, 1, 377, 101, 8, 37, 58, 1};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
       eq(3, theObject.MinNumber(S),1092);
    }
    {
        int SARRAY[] = {883, 66392, 3531, 28257, 1, 14131, 57, 1, 25, 88474, 4, 1, 110, 6, 1769, 220, 442, 7064, 7, 13};
        vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
        NumbersChallenge theObject;
        eq(4, theObject.MinNumber(S),56523);
    }
	return 0;
}
// END CUT HERE
