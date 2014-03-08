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

class LCMSet {
public:
	vector <int> getPrimeFactor(int n)
	{
		vector <int> prime_factor;

		int lim = floor( sqrt(n * 1.0 + 0.5) );
		for (int i = 2; i <= lim; i++) {
			while (n % i == 0) {
				prime_factor.push_back(i);
				n /= i;
			}
		}
		if (n != 1) {
			prime_factor.push_back(n);
		}
		return prime_factor;
	}
	bool include(vector <int> S, int x) {
		string res;
		vector <int> v;
		for (int i = 0; i < S.size(); i++) {
			if (x % S[i] == 0) {
				v.push_back(S[i]);
			}
		}
		vector <int> prime_factor = getPrimeFactor(x);
		for (int i = 0; i < prime_factor.size(); i++) {
			int t = x / prime_factor[i];
			// 判断t能否整除v所有
			bool f = true;
			for (int j = 0; j < v.size(); j++) {
				if (t % v[j] != 0) {
					f = false;
					break;
				}
			}
			if (f) {
				return false;
			}
		}
		return true;
	}
	string equal(vector <int> A, vector <int> B) {
		for (int i = 0; i < A.size(); i++) {
			if (!include(B, A[i])) {
				return "Not equal";
			}
		}
		for (int i = 0; i < B.size(); i++) {
			if (!include(A, B[i])) {
				return "Not equal";
			}
		}
		return "Equal";
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int AARRAY[] = {2,3,4,12};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,4,6};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		LCMSet theObject;
		eq(0, theObject.equal(A, B),"Equal");
	}
	{
		int AARRAY[] = {4,9};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {6,36};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		LCMSet theObject;
		eq(1, theObject.equal(A, B),"Not equal");
	}
	{
		int AARRAY[] = {2,3,5,7,14,105};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,5,6,7,30,35};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		LCMSet theObject;
		eq(2, theObject.equal(A, B),"Equal");
	}
	{
		int AARRAY[] = {2,3,5,7,14,105};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,5,6,7,30,36};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		LCMSet theObject;
		eq(3, theObject.equal(A, B),"Not equal");
	}
	{
		int AARRAY[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		LCMSet theObject;
		eq(4, theObject.equal(A, B),"Equal");
	}
	{
		int AARRAY[] = {999999999,1953125,512,1000000000};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {999999999,1953125,512};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		LCMSet theObject;
		eq(5, theObject.equal(A, B),"Equal");
	}
	{
		int AARRAY[] = {999999998,999999999,1000000000};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {999999999,1000000000};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		LCMSet theObject;
		eq(6, theObject.equal(A, B),"Not equal");
	}
}
// END CUT HERE
