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

class CliqueParty {
public:
    int maxsize(vector <int> a, int k) {
        int res = 2;
		int N = a.size();
		sort(a.begin(), a.end());
		for (int i = 0; i < N - 2; i++) {
			for (int j = i + 2; j < N; j++) {
				long long mx = a[j] - a[i];
				int p = i;
				int t = 2;
				for (int r = i+1; r <= j-1; r++ ) {
					if (mx > (a[j]-a[r]) * (long long)k) {
						break;
					} else if ( mx <= (a[r]-a[p]) * (long long)k ) {
						++t;
						p = r;
					}
				}
				res = max(res, t);
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
        int aARRAY[] = {1,2,3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CliqueParty theObject;
        eq(0, theObject.maxsize(a, 2),3);
    }
    {
        int aARRAY[] = {1,2,3};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CliqueParty theObject;
        eq(1, theObject.maxsize(a, 1),2);
    }
    {
        int aARRAY[] = {4,10,5,6};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CliqueParty theObject;
        eq(2, theObject.maxsize(a, 2),3);
    }
    {
        int aARRAY[] = {1,2,3,4,5,6};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CliqueParty theObject;
        eq(3, theObject.maxsize(a, 3),4);
    }
    {
        int aARRAY[] = {10,9,25,24,23,30};
        vector <int> a( aARRAY, aARRAY+ARRSIZE(aARRAY) );
        CliqueParty theObject;
        eq(4, theObject.maxsize(a, 7),4);
    }
	return 0;
}
// END CUT HERE
