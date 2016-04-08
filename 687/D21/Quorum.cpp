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

class Quorum {
public:
    int count(vector <int> arr, int k) {
        int res = 0;
		sort(arr.begin(), arr.end());
		res = accumulate(arr.begin(), arr.begin()+k, 0);
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
        int arrARRAY[] = {5,2,3};
        vector <int> arr( arrARRAY, arrARRAY+ARRSIZE(arrARRAY) );
        Quorum theObject;
        eq(0, theObject.count(arr, 1),2);
    }
    {
        int arrARRAY[] = {1,1,1,1,1};
        vector <int> arr( arrARRAY, arrARRAY+ARRSIZE(arrARRAY) );
        Quorum theObject;
        eq(1, theObject.count(arr, 5),5);
    }
    {
        int arrARRAY[] = {50,2,9,49,38};
        vector <int> arr( arrARRAY, arrARRAY+ARRSIZE(arrARRAY) );
        Quorum theObject;
        eq(2, theObject.count(arr, 3),49);
    }
    {
        int arrARRAY[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
        vector <int> arr( arrARRAY, arrARRAY+ARRSIZE(arrARRAY) );
        Quorum theObject;
        eq(3, theObject.count(arr, 14),105);
    }
	return 0;
}
// END CUT HERE
