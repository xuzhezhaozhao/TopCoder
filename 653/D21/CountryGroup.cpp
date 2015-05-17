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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/

class CountryGroup {
public:
    int solve(vector <int> a) {
        int res = 0;
		int N = a.size();
		for (int i = 0; i < N;) {
			++res;
			int cnt = a[i];
			int tmp = cnt;
			int j = i;
			while (tmp-- > 0) {
				if (a[j] != cnt) {
					return -1;
				}
				++j;
			}
			i += cnt;
		}
        return res;
    }

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
    {
        int aARRAY[] = {2,2,3,3,3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroup theObject;
        eq(0, theObject.solve(a),2);
    }
    {
        int aARRAY[] = {1,1,1,1,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroup theObject;
        eq(1, theObject.solve(a),5);
    }
    {
        int aARRAY[] = {3,3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroup theObject;
        eq(2, theObject.solve(a),-1);
    }
    {
        int aARRAY[] = {4,4,4,4,1,1,2,2,3,3,3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroup theObject;
        eq(3, theObject.solve(a),5);
    }
    {
        int aARRAY[] = {2,1,2,2,1,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CountryGroup theObject;
        eq(4, theObject.solve(a),-1);
    }
	return 0;
}
// END CUT HERE
