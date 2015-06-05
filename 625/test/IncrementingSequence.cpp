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

class IncrementingSequence {
public:
	string canItBeDone(int k, vector <int> A) {
		int N = A.size();
		sort(A.begin(), A.end());
		bool v[55];
		memset(v, 0, sizeof(v));
		for (int i = 0; i < N; i++) {
			bool ok = false;
			for (int j = 0; j < N; j++) {
				if (v[j]) {
					continue;
				}
				if (i + 1 >= A[j] && (i + 1 - A[j]) % k == 0) {
					v[j] = true;
					ok = true;
					break;
				}
			}
			if (!ok) {
				return "IMPOSSIBLE";
			}
		}

		return "POSSIBLE";
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int AARRAY[] = {22, 13, 19, 7, 2, 16, 16, 1, 10, 6, 10, 24, 15, 21, 4, 18, 10, 3, 11, 5, 20, 25, 5, 13, 25};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		IncrementingSequence theObject;
		eq(0, theObject.canItBeDone(2, A),"IMPOSSIBLE");
	}
	{
		int AARRAY[] = {2,2};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		IncrementingSequence theObject;
		eq(1, theObject.canItBeDone(5, A),"IMPOSSIBLE");
	}
	{
		int AARRAY[] = {1,1,1,1,1,1,1,1};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		IncrementingSequence theObject;
		eq(2, theObject.canItBeDone(1, A),"POSSIBLE");
	}
	{
		int AARRAY[] = {5,3,3,2,1};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		IncrementingSequence theObject;
		eq(3, theObject.canItBeDone(2, A),"IMPOSSIBLE");
	}
	{
		int AARRAY[] = {1,2,3,1,4,5,6,7,9,8};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		IncrementingSequence theObject;
		eq(4, theObject.canItBeDone(9, A),"POSSIBLE");
	}
	{
		int AARRAY[] = {1,1,1,1,1,1,2,2,2,2,2,2};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		IncrementingSequence theObject;
		eq(5, theObject.canItBeDone(2, A),"POSSIBLE");
	}
	{
		int AARRAY[] = {1};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		IncrementingSequence theObject;
		eq(6, theObject.canItBeDone(1, A),"POSSIBLE");
	}
}
// END CUT HERE
