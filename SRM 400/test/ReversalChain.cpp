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
const int INF = 10000000;
class ReversalChain {
public:
	map <string, int> dp;
	int rec(string s1, string s2)
	{
		if (s1 == s2) {
			return 0;
		}
		int L = s1.size();

		if (dp.find(s1 + s2) != dp.end()) {
			return dp[s1 + s2];
		}
		int & res = dp[s1 + s2];
		res = INF;
		if (s1[0] == s2[0]) {
			res = min(res, rec( s1.substr(1), s2.substr(1)) );
		}
		if (s1[L-1] == s2[L-1]) {
			res = min(res, rec(s1.substr(0, L-1), s2.substr(0, L-1)) );
		}
		reverse(s1.begin(), s1.end());
		if (s1[0] == s2[0]) {
			res = min(res, 1 + rec( s1.substr(1), s2.substr(1)) );
		}
		if (s1[L-1] == s2[L-1]) {
			res = min(res, 1 + rec(s1.substr(0, L-1), s2.substr(0, L-1)) );
		}
		return res;
	}
	int minReversal(string init, string goal) {
		int res = 0;
		dp.clear();
		res = rec(init, goal);
		res = (res == INF ? -1 : res);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		ReversalChain theObject;
		eq(0, theObject.minReversal("1100", "0110"),1);
	}
	{
		ReversalChain theObject;
		eq(1, theObject.minReversal("111000", "101010"),2);
	}
	{
		ReversalChain theObject;
		eq(2, theObject.minReversal("0", "1"),-1);
	}
	{
		ReversalChain theObject;
		eq(3, theObject.minReversal("10101", "10101"),0);
	}
	{
		ReversalChain theObject;
		eq(4, theObject.minReversal("111000111000", "001100110011"),4);
	}
}
// END CUT HERE
