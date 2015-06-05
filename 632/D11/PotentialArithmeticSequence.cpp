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

class PotentialArithmeticSequence {
public:
	vector <int> d;
	bool isIncreS(vector <int> v)
	{
		int n = v.size();
		vector <int> temp;
		if (1 == n) {
			return true;
		}
		int p = 0;
		if (v[0] == 0) {
			p = 1;
		}
		for (int i = 0; i < n; i++) {
			if (i % 2 == p && v[i] == 0) {
				return false;
			}
			if (i % 2 != p && v[i] != 0) {
				return false;
			}
			if (v[i] != 0) {
				temp.push_back(v[i] - 1);
			}
		}
		return isIncreS(temp);
	}
    int numberOfSubsequences(vector <int> d) {
        int res = 0;
	int N = d.size();
	this->d = d;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			v.clear();
			for (int k = i; k <= j; k++) {
				v.push_back(d[k]);
			}
			if (isIncreS(v)) {
				++res;
			}
		}
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
        int dARRAY[] = {0,1,0,2,0,1,0};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialArithmeticSequence theObject;
        eq(0, theObject.numberOfSubsequences(d),28);
    }
    {
        int dARRAY[] = {0,0,0,0,0,0,0};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialArithmeticSequence theObject;
	eq(1, theObject.numberOfSubsequences(d),7);
    }
    {
        int dARRAY[] = {0,0,0,0,1,1,1};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialArithmeticSequence theObject;
	eq(2, theObject.numberOfSubsequences(d),8);
    }
    {
        int dARRAY[] = {0,100,0,2,0};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialArithmeticSequence theObject;
	eq(3, theObject.numberOfSubsequences(d),11);
    }
    {
        int dARRAY[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20};
        vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
        PotentialArithmeticSequence theObject;
	eq(4, theObject.numberOfSubsequences(d),49);
    }
	return 0;
}
// END CUT HERE
