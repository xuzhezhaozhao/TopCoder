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

bool dist[51][51];
class Autohamil {
public:
    string check(vector <int> z0, vector <int> z1) {
		memset(dist, 0, sizeof(dist));
		int N = z0.size();
		for (int i = 0; i < N; i++) {
			dist[i][ z0[i] ] = true;
			dist[i][ z1[i] ] = true;
			dist[i][i] = true;
		}

		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dist[i][j] = ( dist[i][j] || (dist[i][k] && dist[k][j]) );
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (!dist[0][i]) {
				return "Does not exist";
			}
			for (int j = 0; j < N; j++) {
				if (i != j && !dist[i][j] && !dist[j][i]) {
					return "Does not exist";
				}
			}
		}
		return "Exists";
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
        int z0ARRAY[] = {0,1};
        vector <int> z0( z0ARRAY, z0ARRAY+ARRSIZE(z0ARRAY) );
        int z1ARRAY[] = {0,1};
        vector <int> z1( z1ARRAY, z1ARRAY+ARRSIZE(z1ARRAY) );
        Autohamil theObject;
        eq(0, theObject.check(z0, z1),"Does not exist");
    }
    {
        int z0ARRAY[] = {1,1};
        vector <int> z0( z0ARRAY, z0ARRAY+ARRSIZE(z0ARRAY) );
        int z1ARRAY[] = {1,1};
        vector <int> z1( z1ARRAY, z1ARRAY+ARRSIZE(z1ARRAY) );
        Autohamil theObject;
        eq(1, theObject.check(z0, z1),"Exists");
    }
    {
        int z0ARRAY[] = {1,2,2};
        vector <int> z0( z0ARRAY, z0ARRAY+ARRSIZE(z0ARRAY) );
        int z1ARRAY[] = {2,2,2};
        vector <int> z1( z1ARRAY, z1ARRAY+ARRSIZE(z1ARRAY) );
        Autohamil theObject;
        eq(2, theObject.check(z0, z1),"Exists");
    }
    {
        int z0ARRAY[] = {2,2,2};
        vector <int> z0( z0ARRAY, z0ARRAY+ARRSIZE(z0ARRAY) );
        int z1ARRAY[] = {2,2,2};
        vector <int> z1( z1ARRAY, z1ARRAY+ARRSIZE(z1ARRAY) );
        Autohamil theObject;
        eq(3, theObject.check(z0, z1),"Does not exist");
    }
    {
        int z0ARRAY[] = {1,2,0,3};
        vector <int> z0( z0ARRAY, z0ARRAY+ARRSIZE(z0ARRAY) );
        int z1ARRAY[] = {3,2,0,3};
        vector <int> z1( z1ARRAY, z1ARRAY+ARRSIZE(z1ARRAY) );
        Autohamil theObject;
        eq(4, theObject.check(z0, z1),"Exists");
    }
    {
        int z0ARRAY[] = {1,2,0,4,3,5};
        vector <int> z0( z0ARRAY, z0ARRAY+ARRSIZE(z0ARRAY) );
        int z1ARRAY[] = {1,2,3,5,4,5};
        vector <int> z1( z1ARRAY, z1ARRAY+ARRSIZE(z1ARRAY) );
        Autohamil theObject;
        eq(5, theObject.check(z0, z1),"Exists");
    }
    {
        int z0ARRAY[] = {1,2,0,4,4,5};
        vector <int> z0( z0ARRAY, z0ARRAY+ARRSIZE(z0ARRAY) );
        int z1ARRAY[] = {1,2,3,5,4,5};
        vector <int> z1( z1ARRAY, z1ARRAY+ARRSIZE(z1ARRAY) );
        Autohamil theObject;
        eq(6, theObject.check(z0, z1),"Does not exist");
    }
	return 0;
}
// END CUT HERE
