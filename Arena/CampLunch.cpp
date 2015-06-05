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

class CampLunch {
public:
    int count(int N, int M, vector <string> a) {
        int res;
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
        string aARRAY[] = {"AB","AB"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CampLunch theObject;
        eq(0, theObject.count(2, 2, a),7);
    }
    {
        string aARRAY[] = {"ABC","ABC"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CampLunch theObject;
        eq(1, theObject.count(2, 3, a),22);
    }
    {
        string aARRAY[] = {"ABC","BAC"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CampLunch theObject;
        eq(2, theObject.count(2, 3, a),21);
    }
    {
        string aARRAY[] = {"A"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CampLunch theObject;
        eq(3, theObject.count(1, 1, a),1);
    }
    {
        string aARRAY[] = {"ABDEFHIGJC"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CampLunch theObject;
        eq(4, theObject.count(1, 10, a),89);
    }
    {
        string aARRAY[] = {"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"};
        vector <string> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CampLunch theObject;
        eq(5, theObject.count(16, 16, a),950052677);
    }
	return 0;
}
// END CUT HERE
