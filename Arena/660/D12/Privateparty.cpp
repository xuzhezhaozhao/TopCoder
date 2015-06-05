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

class Privateparty {
public:
    double getexp(vector <int> a) {
        double res = 0.0;
		int n = a.size();

		for (int i = 0; i < n; i++) {
			set <int> s;
			int pre = a[i];
			s.insert(i);
			while (true) {
				if (s.find(pre) != s.end()) { break; }
				s.insert(pre);
				pre = a[pre];
			}
			int sz = s.size();
			double x = 1.0, y = 1.0;
			for (int j = 2; j <= sz; j++) {
				y *= -1.0 / j;
				x += y;
			}
			res += x;
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
        int aARRAY[] = /* {0,1}; */{47, 11, 38, 14, 1, 21, 13, 7, 19, 9, 32, 3, 20, 44, 26, 0, 41, 10, 37, 18, 35, 47, 4, 34, 0, 24, 29, 43, 29, 14, 9, 41, 14, 15, 36, 8, 8, 31, 14, 18, 24, 7, 23, 20, 7, 24, 32, 37, 16, 8};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        Privateparty theObject;
        eq(0, theObject.getexp(a),32.10916974807605);
    }
    {
        int aARRAY[] = /* {0,0}; */{1, 2, 3, 4, 5, 6, 2, 8, 3, 10, 11, 6};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        Privateparty theObject;
        eq(1, theObject.getexp(a),7.591046626984128);
    }
    {
        int aARRAY[] = {0,1,1};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        Privateparty theObject;
        eq(2, theObject.getexp(a),2.5);
    }
    {
        int aARRAY[] = {0,1,1,2};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        Privateparty theObject;
        eq(3, theObject.getexp(a),3.166666666666667);
    }
    {
        int aARRAY[] = {3,2,1,0};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        Privateparty theObject;
        eq(4, theObject.getexp(a),2.0);
    }
	return 0;
}
// END CUT HERE
