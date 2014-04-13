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


class TheNumberGameDiv2 {
public:
	int reverseNum(int A)
	{
		int res = 0;
		while (A != 0) {
			res = res * 10 + (A % 10);
			A /= 10;
		}
		return res;
	}
	int minimumMoves(int A, int B) {
		int res = -1;
		set <int> mid;
		queue <pii> q;
		mid.insert(A);
		q.push( mkp(A, 0) );
		int moves = 0;
		pii cur;
		while (!q.empty()) {
			cur = q.front();
			moves = cur.second;
			if (cur.first == B) {
				res = moves;
				break;
			}
			q.pop();

			// reverse
			int rv = reverseNum(cur.first);
			if (mid.find(rv) == mid.end()) {
				mid.insert(rv);
				q.push(mkp(rv, moves + 1));
			}
			// division
			int di = cur.first / 10;
			if (mid.find(di) == mid.end()) {
				mid.insert(di);
				q.push(mkp(di, moves + 1));
			}
		} 
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		TheNumberGameDiv2 theObject;
		eq(0, theObject.minimumMoves(25, 5),2);
	}
	{
		TheNumberGameDiv2 theObject;
		eq(1, theObject.minimumMoves(5162, 16),4);
	}
	{
		TheNumberGameDiv2 theObject;
		eq(2, theObject.minimumMoves(334, 12),-1);
	}
	{
		TheNumberGameDiv2 theObject;
		eq(3, theObject.minimumMoves(218181918, 9181),6);
	}
	{
		TheNumberGameDiv2 theObject;
		eq(4, theObject.minimumMoves( 123456789, 79817),-1);
	}
}
// END CUT HERE
