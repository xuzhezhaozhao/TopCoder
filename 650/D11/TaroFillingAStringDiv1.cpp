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

const int MOD = 1000000007;

class TaroFillingAStringDiv1 {
public:
    int getNumber(int N, vector <int> position, string value) {
		int sz = position.size();
		vector<pair<int, char>> v;
		for (int i = 0; i < sz; i++) {
			v.push_back(mkp(position[i], value[i]));
		}
		sort(v.begin(), v.end());


		long long res = 1;
		for (int i = 0; i < sz-1; i++) {
			int d = v[i+1].first - v[i].first - 1;
			if (v[i+1].second == v[i].second) {
				if (d % 2 == 0) {
					res *= (d + 2 - 1);
					res %= MOD;
				}
			} else {
				if (d % 2 != 0) {
					res *= (d + 2 - 1);
					res %= MOD;
				}
			}
		}

        return (int)res;
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
        int positionARRAY[] = {1, 3};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        TaroFillingAStringDiv1 theObject;
        eq(0, theObject.getNumber(3, position, "AB"),2);
    }
    {
        int positionARRAY[] = {2, 1, 3, 4};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        TaroFillingAStringDiv1 theObject;
        eq(1, theObject.getNumber(4, position, "ABBA"),1);
    }
    {
        int positionARRAY[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        TaroFillingAStringDiv1 theObject;
        eq(2, theObject.getNumber(25, position, "ABBBBABABBAAABA"),1);
    }
    {
        int positionARRAY[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246};
        vector <int> position( positionARRAY, positionARRAY+ARRSIZE(positionARRAY) );
        TaroFillingAStringDiv1 theObject;
        eq(3, theObject.getNumber(305, position, "ABAABBABBAABABBBBAAAABBABBBA"),43068480);
    }
	return 0;
}
// END CUT HERE
