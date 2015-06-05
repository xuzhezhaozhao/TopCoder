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
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)

/*************** Program Begin **********************/

class BoxesDiv2 {
public:
	int findSize(vector <int> candyCounts) {
		int res = 0;
		sort(candyCounts.begin(), candyCounts.end());
		int n = candyCounts.size();
		vector <int> boxes;
		for (int i = 0; i < n; i++) {
			int e = 0;
			for (e = 0; (1 << e) < candyCounts[i]; e++) {
			}
			boxes.push_back(e);
		}
		int same[11];
		memset(same, 0, sizeof(same));
		for (int i = 0; i < n; i++) {
			++same[boxes[i]];
		}
		int h = 0;
		for (int i = 10; i >= 0; i--) {
			if (same[i] != 0) {
				h = i;			
				break;
			}
		}
		for (int i = 0; i < h; i++) {
			same[i + 1] += (same[i] + 1) / 2;
		}
		res = (1 << h);
		int t = same[h];
		while (t != 1) {
			t = (t + 1) / 2;
			res *= 2;
		}
		
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		int candyCountsARRAY[] = {8,8};
		vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
		BoxesDiv2 theObject;
		eq(0, theObject.findSize(candyCounts),16);
	}
	{
		int candyCountsARRAY[] = {5,6};
		vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
		BoxesDiv2 theObject;
		eq(1, theObject.findSize(candyCounts),16);
	}
	{
		int candyCountsARRAY[] = {1,7};
		vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
		BoxesDiv2 theObject;
		eq(2, theObject.findSize(candyCounts),16);
	}
	{
		int candyCountsARRAY[] = {1,1,13,1,1};
		vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
		BoxesDiv2 theObject;
		eq(3, theObject.findSize(candyCounts),32);
	}
	{
		int candyCountsARRAY[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
		vector <int> candyCounts( candyCountsARRAY, candyCountsARRAY+ARRSIZE(candyCountsARRAY) );
		BoxesDiv2 theObject;
		eq(4, theObject.findSize(candyCounts),1024);
	}
	return 0;
}
// END CUT HERE
