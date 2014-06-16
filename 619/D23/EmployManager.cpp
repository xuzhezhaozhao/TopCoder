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

class EmployManager {
public:
    int maximumEarnings(vector <int> value, vector <string> earning) {
        int res = 0;
	int N = value.size();
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			res -= earning[i][j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += earning[i][j] - '0';
		}
		if (sum > value[i]) {
			res += sum - value[i];
		}
	}

        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int valueARRAY[] = {1, 1};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        string earningARRAY[] = {"02", "20"};
        vector <string> earning( earningARRAY, earningARRAY+ARRSIZE(earningARRAY) );
        EmployManager theObject;
        eq(0, theObject.maximumEarnings(value, earning),0);
    }
    {
        int valueARRAY[] = {2, 2};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        string earningARRAY[] = {"01", "10"};
        vector <string> earning( earningARRAY, earningARRAY+ARRSIZE(earningARRAY) );
        EmployManager theObject;
        eq(1, theObject.maximumEarnings(value, earning),-1);
    }
    {
        int valueARRAY[] = {1, 2, 3, 4};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        string earningARRAY[] = {"0121", "1021", "2201", "1110"};
        vector <string> earning( earningARRAY, earningARRAY+ARRSIZE(earningARRAY) );
        EmployManager theObject;
        eq(2, theObject.maximumEarnings(value, earning),-1);
    }
    {
        int valueARRAY[] = {2, 2, 0, 1, 4, 0, 1, 0, 0, 4};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        string earningARRAY[] = {"0100451253",  "1010518123",  "0102989242",  "0020093171",  "4590045480",  "5189400676",  "1893500826",  "2121468008",  "5247872007",  "3321066870"};
        vector <string> earning( earningARRAY, earningARRAY+ARRSIZE(earningARRAY) );
        EmployManager theObject;
        eq(3, theObject.maximumEarnings(value, earning),156);
    }
	return 0;
}
// END CUT HERE
