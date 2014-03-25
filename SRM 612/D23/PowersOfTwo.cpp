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
long long dp[65][55];
vector <long long> X(60);
class PowersOfTwo {
public:
	long long rec(int k, int b)
	{
		long long & res = dp[k][b];
		if (res != -1) {
			return res;
		}
		// base case
		if (k == X.size()) {
			res = 1;
			return res;
		}
		res = 0;
		int x_k = X[k] + b;
		res += rec(k + 1, x_k / 2);
		if (x_k > 0) {
			res += rec(k + 1, (x_k - 1) / 2);
		}

		return res;
	}
	long long count(vector <long long> powers) {
		long long res = 0LL;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < X.size(); i++) {
			X[i] = std::count(powers.begin(), powers.end(), 1LL << i);
		}
		res = rec(0, 0);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		long long powersARRAY[] = {1L,2L};
		vector<long long> powers( powersARRAY, powersARRAY+ARRSIZE(powersARRAY) );
		PowersOfTwo theObject;
		eq(0, theObject.count(powers),4LL);
	}
	{
		long long powersARRAY[] = {1L,1L,1L,1L};
		vector<long long> powers( powersARRAY, powersARRAY+ARRSIZE(powersARRAY) );
		PowersOfTwo theObject;
		eq(1, theObject.count(powers),5LL);
	}
	{
		long long powersARRAY[] = {1L,2L,2L,2L,4L,4L,16L};
		vector<long long> powers( powersARRAY, powersARRAY+ARRSIZE(powersARRAY) );
		PowersOfTwo theObject;
		eq(2, theObject.count(powers),32LL);
	}
	{
		long long powersARRAY[] = {1L,32L,1L,16L,32L};
		vector<long long> powers( powersARRAY, powersARRAY+ARRSIZE(powersARRAY) );
		PowersOfTwo theObject;
		eq(3, theObject.count(powers),18LL);
	}
	{
		long long powersARRAY[] = {1048576LL,1073741824LL,549755813888LL,70368744177664LL,4398046511104LL,262144LL,1048576LL,2097152LL,8796093022208LL,
			1048576LL,1048576LL,35184372088832LL,2097152LL,256LL,256LL,256LL,262144L,1048576LL,1048576LL,70368744177664LL,262144LL,1048576LL};
		vector<long long> powers( powersARRAY, powersARRAY+ARRSIZE(powersARRAY) );
		PowersOfTwo theObject;
		eq(4, theObject.count(powers),18432LL);
	}
}
// END CUT HERE
