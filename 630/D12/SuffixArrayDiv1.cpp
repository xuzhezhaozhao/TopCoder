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

/*************** Program Begin **********************/

class SuffixArrayDiv1 {
public:
	int minimalCharacters(vector <int> SA) {
		int res = 1;
		int N = SA.size();
		vector <int> rank(N);
		for (int i = 0; i < N; i++) {
			rank[ SA[i] ] = i;
		}
		// 方法与Div2相同，构造最小S
		for (int i = 1; i < N; i++) {
			int pos1 = SA[i - 1] + 1;
			int pos2 = SA[i] + 1;
			if (pos2 >= N) {
				++res;
			} else {
				if (pos1 < N && rank[pos1] > rank[pos2]) {
					++res;
				}
			}
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int SAARRAY[] = {3,0,1,2};
		vector <int> SA( SAARRAY, SAARRAY+ARRSIZE(SAARRAY) );
		SuffixArrayDiv1 theObject;
		eq(0, theObject.minimalCharacters(SA),2);
	}
	{
		int SAARRAY[] = {3,2,1,0};
		vector <int> SA( SAARRAY, SAARRAY+ARRSIZE(SAARRAY) );
		SuffixArrayDiv1 theObject;
		eq(1, theObject.minimalCharacters(SA),1);
	}
	{
		int SAARRAY[] = {0,1,2,3};
		vector <int> SA( SAARRAY, SAARRAY+ARRSIZE(SAARRAY) );
		SuffixArrayDiv1 theObject;
		eq(2, theObject.minimalCharacters(SA),2);
	}
	{
		int SAARRAY[] = {7,4,8,6,1,5,2,9,3,0};
		vector <int> SA( SAARRAY, SAARRAY+ARRSIZE(SAARRAY) );
		SuffixArrayDiv1 theObject;
		eq(3, theObject.minimalCharacters(SA),4);
	}
	{
		int SAARRAY[] = {0};
		vector <int> SA( SAARRAY, SAARRAY+ARRSIZE(SAARRAY) );
		SuffixArrayDiv1 theObject;
		eq(4, theObject.minimalCharacters(SA),1);
	}
}
// END CUT HERE
