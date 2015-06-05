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

class UnsortedSequence {
public:
    vector <int> getUnsorted(vector <int> s) {
        vector <int> res;
	sort(s.begin(), s.end());
	bool ok = false;
	for (int i = s.size() - 2; i >= 0; i--) {
		if (s[i] != s[i + 1]) {
			swap(s[i], s[i + 1]);
			ok = true;
			break;
		}
	}
	if (ok) {
		res = s;
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
        int sARRAY[] = {1,2};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int retrunValueARRAY[] = {2, 1 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        UnsortedSequence theObject;
        eq(0, theObject.getUnsorted(s),retrunValue);
    }
    {
        int sARRAY[] = {1,2,3};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int retrunValueARRAY[] = {1, 3, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        UnsortedSequence theObject;
        eq(1, theObject.getUnsorted(s),retrunValue);
    }
    {
        int sARRAY[] = {7,2,2};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int retrunValueARRAY[] = {2, 7, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        UnsortedSequence theObject;
        eq(2, theObject.getUnsorted(s),retrunValue);
    }
    {
        int sARRAY[] = {1000};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        UnsortedSequence theObject;
        eq(3, theObject.getUnsorted(s),vector <int>());
    }
    {
        int sARRAY[] = {1,1};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        UnsortedSequence theObject;
        eq(4, theObject.getUnsorted(s),vector <int>());
    }
    {
        int sARRAY[] = {1,2,4,3};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int retrunValueARRAY[] = {1, 2, 4, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        UnsortedSequence theObject;
        eq(5, theObject.getUnsorted(s),retrunValue);
    }
    {
        int sARRAY[] = {2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10};
        vector <int> s( sARRAY, sARRAY+ARRSIZE(sARRAY) );
        int retrunValueARRAY[] = {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        UnsortedSequence theObject;
        eq(6, theObject.getUnsorted(s),retrunValue);
    }
    return 0;
}
// END CUT HERE
