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

class SlimeXSlimonadeTycoon {
public:
    int sell(vector <int> morning, vector <int> customers, int stale_limit) {
        int res = 0;
        int N = morning.size();
        vector <int> q;
        for (int i = 0; i < N; i++) {
                q.push_back(morning[i]);
                int s = q.size();
                int sell = 0;
                for (int j = max(0, i - stale_limit + 1); j < s; j++) {
                       if (sell + q[j] <= customers[i]) {
                              sell += q[j];
                              q[j] = 0; } else {
                                int temp = customers[i] - sell;
                                sell += temp;
                                q[j] -= temp;
                                break;
                        }
                }
                res += sell;
        }
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int morningARRAY[] = {5, 1, 1};
        vector <int> morning( morningARRAY, morningARRAY+ARRSIZE(morningARRAY) );
        int customersARRAY[] = {1, 2, 3};
        vector <int> customers( customersARRAY, customersARRAY+ARRSIZE(customersARRAY) );
        SlimeXSlimonadeTycoon theObject;
        eq(0, theObject.sell(morning, customers, 2),5);
    }
    {
        int morningARRAY[] = {10, 20, 30};
        vector <int> morning( morningARRAY, morningARRAY+ARRSIZE(morningARRAY) );
        int customersARRAY[] = {30, 20, 10};
        vector <int> customers( customersARRAY, customersARRAY+ARRSIZE(customersARRAY) );
        SlimeXSlimonadeTycoon theObject;
        eq(1, theObject.sell(morning, customers, 1),40);
    }
    {
        int morningARRAY[] = {1, 2, 3, 4, 5};
        vector <int> morning( morningARRAY, morningARRAY+ARRSIZE(morningARRAY) );
        int customersARRAY[] = {5, 5, 5, 5, 5};
        vector <int> customers( customersARRAY, customersARRAY+ARRSIZE(customersARRAY) );
        SlimeXSlimonadeTycoon theObject;
        eq(2, theObject.sell(morning, customers, 5),15);
    }
    {
        int morningARRAY[] = {10000, 0, 0, 0, 0, 0, 0};
        vector <int> morning( morningARRAY, morningARRAY+ARRSIZE(morningARRAY) );
        int customersARRAY[] = {1, 2, 4, 8, 16, 32, 64};
        vector <int> customers( customersARRAY, customersARRAY+ARRSIZE(customersARRAY) );
        SlimeXSlimonadeTycoon theObject;
        eq(3, theObject.sell(morning, customers, 4),15);
    }
	return 0;
}
// END CUT HERE
