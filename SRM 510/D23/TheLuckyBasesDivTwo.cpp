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

class TheLuckyBasesDivTwo {
public:
	bool isLucky(long long n, long long base)
	{
		while (n) {
			long long t = n % base;
			n /= base;
			if (t != 4 && t != 7) {
				return false;
			}
		}
		return true;
	}
	long long find(long long n) {
		long long res = 0;
		if (4 == n || 7 == n) {
			return -1;
		}
		int lim = floor(sqrt(n * 1.0 + 0.5));
		for (int i = 5; i <= lim; i++) {
			if (isLucky(n, i)) {
				++res;
			}
		}
		int L[] = {4, 7};
		int R[] = {4, 7};
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				if ( (n - L[i]) % R[j] == 0 ) {
					long long base = (n - L[i]) / R[j];
					if (base > lim) {
						++res;
					}
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
		TheLuckyBasesDivTwo theObject;
		eq(0, theObject.find(255L),1LL);
	}
	{
		TheLuckyBasesDivTwo theObject;
		eq(1, theObject.find(4L),-1LL);
	}
	{
		TheLuckyBasesDivTwo theObject;
		eq(2, theObject.find(13L),0LL);
	}
	{
		TheLuckyBasesDivTwo theObject;
		eq(3, theObject.find(60L),2LL);
	}
}
// END CUT HERE
