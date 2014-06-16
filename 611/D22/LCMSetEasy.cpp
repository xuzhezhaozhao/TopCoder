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

class LCMSetEasy {
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
	string include(vector <int> S, int x) {
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
				return "Impossible";
			}
		}
		res = "Possible";
		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int SARRAY[] = {1};
		vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
		LCMSetEasy theObject;
		eq(0, theObject.include(S, 2),"Possible");
	}
	{
		int SARRAY[] = {2,3,4};
		vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
		LCMSetEasy theObject;
		eq(1, theObject.include(S, 611),"Impossible");
	}
	{
		int SARRAY[] = {2,3,4};
		vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
		LCMSetEasy theObject;
		eq(2, theObject.include(S, 12),"Possible");
	}
	{
		int SARRAY[] = {1,2,3,4,5,6,7,8,9,10};
		vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
		LCMSetEasy theObject;
		eq(3, theObject.include(S, 24),"Possible");
	}
	{
		int SARRAY[] = {100,200,300,400,500,600};
		vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
		LCMSetEasy theObject;
		eq(4, theObject.include(S, 2000),"Possible");
	}
	{
		int SARRAY[] = {100,200,300,400,500,600};
		vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
		LCMSetEasy theObject;
		eq(5, theObject.include(S, 8000),"Impossible");
	}
	{
		int SARRAY[] = {1000000000,999999999,999999998};
		vector <int> S( SARRAY, SARRAY+ARRSIZE(SARRAY) );
		LCMSetEasy theObject;
		eq(6, theObject.include(S, 999999999),"Possible");
	}
}
// END CUT HERE
