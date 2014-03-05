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
int lucky[4748];
class TheLuckyGameDivTwo {
public:
	bool isLucky(int n)
	{
		while (n) {
			int t = n % 10;
			n /= 10;
			if (t != 4 && t != 7) {
				return false;
			}
		}
		return true;
	}
	int find(int a, int b, int jLen, int bLen) {
		int res = 0;
		memset(lucky, 0, sizeof(lucky));
		int cnt = 0;
		for (int i = a; i <= b; i++) {
			if (isLucky(i)) {
				++cnt;
			}
			lucky[i] = cnt;
		}
		for (int i = a; i <= b - jLen + 1; i++) {	// John chooses
			int br = 10000000;
			for (int j = i; j <= i + jLen - 1 - bLen + 1; j++) {	// Brus  chooses
				br = min(br, lucky[j + bLen - 1] - lucky[j - 1]);
			}
			res = max(res, br);
		}
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		TheLuckyGameDivTwo theObject;
		eq(0, theObject.find(533, 4627, 2047, 1023),0);
		CHECKTIME();
	}
	{
		TheLuckyGameDivTwo theObject;
		eq(1, theObject.find(1, 100, 100, 100),6);
	}
	{
		TheLuckyGameDivTwo theObject;
		eq(2, theObject.find(4, 8, 3, 2),1);
	}
	{
		TheLuckyGameDivTwo theObject;
		eq(3, theObject.find(1, 4747, 199, 20),2);
	}
}
// END CUT HERE
