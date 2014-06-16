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

class GoodCompanyDivOne {
public:
	int minimumCost(vector <int> superior, vector <int> training) {
		int res = 0;
		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		int superiorARRAY[] = {-1};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int trainingARRAY[] = {1, 2};
		vector <int> training( trainingARRAY, trainingARRAY+ARRSIZE(trainingARRAY) );
		GoodCompanyDivOne theObject;
		eq(0, theObject.minimumCost(superior, training),3);
	}
	{
		int superiorARRAY[] = {-1, 0, 0};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int trainingARRAY[] = {1, 2, 3};
		vector <int> training( trainingARRAY, trainingARRAY+ARRSIZE(trainingARRAY) );
		GoodCompanyDivOne theObject;
		eq(1, theObject.minimumCost(superior, training),10);
	}
	{
		int superiorARRAY[] = {-1, 0, 0, 0};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int trainingARRAY[] = {1, 2, 3};
		vector <int> training( trainingARRAY, trainingARRAY+ARRSIZE(trainingARRAY) );
		GoodCompanyDivOne theObject;
		eq(2, theObject.minimumCost(superior, training),-1);
	}
	{
		int superiorARRAY[] = {-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3};
		vector <int> superior( superiorARRAY, superiorARRAY+ARRSIZE(superiorARRAY) );
		int trainingARRAY[] = {4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4};
		vector <int> training( trainingARRAY, trainingARRAY+ARRSIZE(trainingARRAY) );
		GoodCompanyDivOne theObject;
		eq(3, theObject.minimumCost(superior, training),71);
	}
	return 0;
}
// END CUT HERE
