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

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)
typedef pair<int, int> pii;
#define mkp make_pair

/*************** Program Begin **********************/
map <long long, long long> dp;
const int MOD = 1000000007;

class GoodSubset {
public:
	int numberOfSubsets(int goodValue, vector <int> d) {
		dp.clear();
		map <long long, long long> temp;
		for (int i = 0; i < (int)d.size(); i++) {
			temp = dp;
			for (auto x : temp) {
				long long div = x.first;
				if ((long long)goodValue % (d[i] * div) == 0) {
					dp[ d[i] * div ] += temp[ div  ];
					dp[ d[i] * div  ] %= MOD;
				}
			}
			++dp[ d[i]  ];
			dp[ d[i] ] %= MOD;
		}

		return dp[goodValue];
	}

};

/************** Program End ************************/
// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))
template<typename T> void print( T a ) { cerr << a; }
static void print( long long a ) { cerr << a << "L"; }
static void print( string a ) { cerr << '"' << a << '"'; }
template<typename T> void print( vector<T> a ) {
	cerr << "{";
	for ( int i = 0 ; i != a.size() ; i++ ) {
		if ( i != 0 ) cerr << ", ";
		print( a[i] );
	}
	cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl; } 
	else {
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
		print( have ); print( need ); return;
	}
	for( int i= 0; i < have.size(); i++ ) {
		if( have[i] != need[i] ) {
			cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
			print( have ); print( need ); return;
		}
	}
	cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
	if ( have == need ) { cerr << "Case " << n << " passed." << endl;
	} else {
		cerr << "Case " << n << " failed: expected ";
		print( need ); cerr << " received "; print( have );
		cerr << "." << endl;
	}
}

int main( int argc, char* argv[] ) {
	{
		int dARRAY[] = {2,3,4,5};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		GoodSubset theObject;
		eq(0, theObject.numberOfSubsets(10, d),1);
	}
	{
		int dARRAY[] = {2,3,4,5,6};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		GoodSubset theObject;
		eq(1, theObject.numberOfSubsets(6, d),2);
	}
	{
		int dARRAY[] = {1,1,1};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		GoodSubset theObject;
		eq(2, theObject.numberOfSubsets(1, d),7);
	}
	{
		int dARRAY[] = {1,2,3,4,5,6,7,8,9,10,11,12};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		GoodSubset theObject;
		eq(3, theObject.numberOfSubsets(12, d),6);
	}
	{
		int dARRAY[] = {1,2,3,4};
		vector <int> d( dARRAY, dARRAY+ARRSIZE(dARRAY) );
		GoodSubset theObject;
		eq(4, theObject.numberOfSubsets(5, d),0);
	}
	return 0;
}
// END CUT HERE
