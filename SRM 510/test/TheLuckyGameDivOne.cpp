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

class TheLuckyGameDivOne {
public:
	vector <long long> luckyNum;
	long long a, b;
	void getLuckyNum(long long cur)
	{
		if (cur <= b) {
			if (cur >= a) {
				luckyNum.push_back(cur);
			}
			getLuckyNum(cur * 10 + 4);
			getLuckyNum(cur * 10 + 7);
		}
	}
	int find(long long a, long long b, long long jLen, long long bLen) {
		int res = 0;
		this->a = a;
		this->b = b;
		getLuckyNum(0);
		sort(luckyNum.begin(), luckyNum.end());
		int n = luckyNum.size();
		for (int i = -1; i < n; i++) {		// John's turn
			long long jStart;
			if (-1 == i) {
				jStart = a;
			} else {
				jStart = luckyNum[i] + 1 - jLen;
			}
			if (jStart < a) { continue; }
			int jL = lower_bound(luckyNum.begin(), luckyNum.end(), jStart) - luckyNum.begin();
			int bmin = 100000000;
			for (int j = jL - 1; j <= i; j++) {	// Brus's turn
				long long bEnd;
				if (j == jL - 1) {
					bEnd = jStart + bLen - 1;
				} else {
					bEnd = luckyNum[j] + 1 + bLen - 1;
				}
				
				if (bEnd > b) { continue; }
				int bL = upper_bound(luckyNum.begin(), luckyNum.end(), bEnd) - luckyNum.begin();
				int cnt = bL - j - 1;
				bmin = min(cnt, bmin);
			}
			res = max(res, bmin);
		}

		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		TheLuckyGameDivOne theObject;
		eq(0, theObject.find(1L, 10L, 2L, 1L),0);
	}
	{
		TheLuckyGameDivOne theObject;
		eq(1, theObject.find(1L, 100L, 100L, 100L),6);
	}
	{
		TheLuckyGameDivOne theObject;
		eq(2, theObject.find(4L, 8L, 3L, 2L),1);
	}
	{
		TheLuckyGameDivOne theObject;
		eq(3, theObject.find(1L, 100L, 75L, 50L),2);
	}
}
// END CUT HERE
