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
int dp[51][5001];
class AlbertoTheAviator {
public:
	vector <pii> v;
	int n;
	int rec(int cur, int f)
	{
		if (n == cur) {
			return 0;
		}
		int & res = dp[cur][f];
		if (res != -1) {
			return res;
		}
		res = 0;
		// do it
		if (f >= v[cur].second) {
			res = 1 + rec(cur + 1, f - v[cur].second + v[cur].first);
		}
		// ignore it
		res = max(res, rec(cur + 1, f));
		return res;
	}
	int MaximumFlights(int F, vector <int> duration, vector <int> refuel) {
		int res = 0;
		n = duration.size();
		for (int i = 0; i < n; i++) {
			v.push_back( mkp(refuel[i], duration[i]) );
		}
		sort(v.begin(), v.end(), greater <pii>());
		memset(dp, -1, sizeof(dp));
		res = rec(0, F);
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int durationARRAY[] = {10};
		vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
		int refuelARRAY[] = {0};
		vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
		AlbertoTheAviator theObject;
		eq(0, theObject.MaximumFlights(10, duration, refuel),1);
	}
	{
		int durationARRAY[] = {8, 4};
		vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
		int refuelARRAY[] = {0, 2};
		vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
		AlbertoTheAviator theObject;
		eq(1, theObject.MaximumFlights(10, duration, refuel),2);
	}
	{
		int durationARRAY[] = {4, 8, 2, 1};
		vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
		int refuelARRAY[] = {2, 0, 0, 0};
		vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
		AlbertoTheAviator theObject;
		eq(2, theObject.MaximumFlights(12, duration, refuel),3);
	}
	{
		int durationARRAY[] = {4, 6};
		vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
		int refuelARRAY[] = {0, 1};
		vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
		AlbertoTheAviator theObject;
		eq(3, theObject.MaximumFlights(9, duration, refuel),2);
	}
	{
		int durationARRAY[] = {101};
		vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
		int refuelARRAY[] = {100};
		vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
		AlbertoTheAviator theObject;
		eq(4, theObject.MaximumFlights(100, duration, refuel),0);
	}
	{
		int durationARRAY[] = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365};
		vector <int> duration( durationARRAY, durationARRAY+ARRSIZE(durationARRAY) );
		int refuelARRAY[] = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364};
		vector <int> refuel( refuelARRAY, refuelARRAY+ARRSIZE(refuelARRAY) );
		AlbertoTheAviator theObject;
		eq(5, theObject.MaximumFlights(1947, duration, refuel),3);
	}
}
// END CUT HERE
