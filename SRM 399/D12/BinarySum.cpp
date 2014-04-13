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
long long dp[32][32][32][32][2];
const long long INF = (1LL << 40); 
class BinarySum {
public:
	int a_ones, b_ones, c_ones, all;
	vector <int> extractBit(int a)
	{
		vector <int> res;
		bool flag = false;
		for (int i = 30; i >= 0; i--) {
			if ( 1 & (a >> i) ) {
				flag = true;
			}
			if (!flag) {
				continue;
			}
			res.push_back( 1 & (a >> i) );
		}
		return res;
	}

	long long rec(int k1, int k2, int k3, int k, int carry)
	{	
		// base case
		if (0 == k || k1 < 0 || k2 < 0 || k3 < 0) {
			if (k1 == 0 && k2 == 0 && k3 == 0 && carry == 0) {
				return 0;
			} else {
				return INF;
			}
		}

		long long & res = dp[k1][k2][k3][k][carry];
		if (res != -1) {
			return res;
		}
		res = INF;
		for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
		for (int cc = 0; cc < 2; cc++) {
			int next_k1, next_k2;
			next_k1 = k1 - i; next_k2 = k2 - j;
			int temp = i + j + cc;
			if (temp / 2 != carry) {
				continue;
			}
			switch (temp) {
			case 0: res = min(res, rec(next_k1, next_k2, k3, k - 1, cc) ); break;
			case 1: res = min(res, (1 << (k-1) ) + rec(next_k1, next_k2, k3 - 1, k - 1, cc)); break;
			case 2: res = min(res, rec(next_k1, next_k2, k3, k - 1, cc)); break;
			case 3: res = min(res, (1 << (k-1) ) + rec(next_k1, next_k2, k3 - 1, k - 1, cc)); break;
			}
		}}}
		return res;
	}

	int rearrange(int a, int b, int c) {
		long long res = 0;
		vector <int> a_bits = extractBit(a);
		vector <int> b_bits = extractBit(b);
		vector <int> c_bits = extractBit(c);
		all = max <int>(a_bits.size(), b_bits.size());
		all = max <int> (all, c_bits.size());
		a_ones = count(a_bits.begin(), a_bits.end(), 1);
		b_ones = count(b_bits.begin(), b_bits.end(), 1);
		c_ones = count(c_bits.begin(), c_bits.end(), 1);
		memset(dp, -1, sizeof(dp));
		res = rec(a_ones, b_ones, c_ones, all, 0);
		res = (res == INF ? -1LL : res);

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		BinarySum theObject;
		eq(0, theObject.rearrange(7, 6, 9),10);
	}
	{
		BinarySum theObject;
		eq(1, theObject.rearrange(1, 1, 2),2);
	}
	{
		BinarySum theObject;
		eq(2, theObject.rearrange(1, 1, 4),2);
	}
	{
		BinarySum theObject;
		eq(3, theObject.rearrange(3, 3, 9),6);
	}
	{
		BinarySum theObject;
		eq(4, theObject.rearrange(1, 1, 1),-1);
	}
	{
		BinarySum theObject;
		eq(5, theObject.rearrange(32517565, 204650420, 4096),-1);
	}
}
// END CUT HERE
