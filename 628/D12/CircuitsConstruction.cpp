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

class CircuitsConstruction {
public:
    int maximizeResistance(string circuit, vector <int> conductors) {
        int res = 0;
	stack <int> st;
	for (int i = circuit.size() - 1; i >= 0; i--) {
		if ('X' == circuit[i]) {
			st.push(1);
		} else if ('A' == circuit[i]) {
			int t = 0;
			t += st.top();
			st.pop();
			t += st.top();
			st.pop();
			st.push(t);
		} else {
			int t1, t2;
			t1 = st.top();
			st.pop();
			t2 = st.top();
			st.pop();
			int t = max(t1, t2);
			st.push(t);
		}
	}
	int K = st.top();
	sort(conductors.begin(), conductors.end(), greater<int>());
	res = accumulate(conductors.begin(), conductors.begin() + K, 0);
        return res;
    }

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        int conductorsARRAY[] = {8, 2, 3};
        vector <int> conductors( conductorsARRAY, conductorsARRAY+ARRSIZE(conductorsARRAY) );
        CircuitsConstruction theObject;
        eq(0, theObject.maximizeResistance("BXBXX", conductors),8);
    }
    {
        int conductorsARRAY[] = {1, 1, 2, 8, 10};
        vector <int> conductors( conductorsARRAY, conductorsARRAY+ARRSIZE(conductorsARRAY) );
        CircuitsConstruction theObject;
        eq(1, theObject.maximizeResistance("AAXXAXAXX", conductors),22);
    }
    {
        int conductorsARRAY[] = {8, 2, 3};
        vector <int> conductors( conductorsARRAY, conductorsARRAY+ARRSIZE(conductorsARRAY) );
        CircuitsConstruction theObject;
        eq(2, theObject.maximizeResistance("AXBXX", conductors),11);
    }
    {
        int conductorsARRAY[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
        vector <int> conductors( conductorsARRAY, conductorsARRAY+ARRSIZE(conductorsARRAY) );
        CircuitsConstruction theObject;
        eq(3, theObject.maximizeResistance("BAAXBXXBXAXXBBAXXBXXAAXXX", conductors),454);
    }
	return 0;
}
// END CUT HERE
