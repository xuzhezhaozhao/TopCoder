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

double dp[51][51][51];
bool solved[51][51][51];

class RandomGraph {
public:
	int n;
	double p;
	double rec(int a, int b, int c)
	{
		double & res = dp[a][b][c];
		if (solved[a][b][c]) {
			return res;
		}
		int r = n - (a + 2 * b + 3 * c);
		// base case
		if (0 == r) {
			res = 1.0;
			solved[a][b][c] = true;
			return res;
		}
		res = 0.0;
		// r != 0
		res += pow(1 - p, a + 2 * b + 3 * c) * rec(a + 1, b, c);
		if (a >= 1) {
			res += pow(1 - p, a + 2 * b + 3 * c - 1) * a * p * rec(a - 1, b + 1, c);
		}
		if (a >= 2) {
			res += pow(1 - p, a + 2 * b + 3 * c - 2) * p * p * a * (a - 1) / 2 * rec(a - 2, b, c + 1);
		}
		if (b >= 1) {
			res += pow(1 - p, a + 2 * b + 3 * c - 1) * p * 2 * b * rec(a, b - 1, c + 1);
			res += pow(1 - p, a + 2 * b + 3 * c - 2) * p * p * b * rec(a, b - 1, c + 1);
		}
		solved[a][b][c] = true;

		return res;
	}
	double probability(int n, int p) {
		double res = 0;
		this->n = n;
		this->p = p / 1000.0;

		memset(solved, 0, sizeof(solved));
		res = 1 - rec(0, 0, 0);

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		RandomGraph theObject;
		eq(0, theObject.probability(7, 0),0.0);
	}
	{
		RandomGraph theObject;
		eq(1, theObject.probability(3, 620),0.0);
	}
	{
		RandomGraph theObject;
		eq(2, theObject.probability(4, 500),0.59375);
	}
	{
		RandomGraph theObject;
		eq(3, theObject.probability(8, 100),0.33566851611343496);
	}
	{
		RandomGraph theObject;
		eq(4, theObject.probability(15, 50),0.5686761670525845);
	}
	{
		RandomGraph theObject;
		eq(5, theObject.probability(50, 10),0.7494276522159893);
	}
	{
		RandomGraph theObject;
		eq(6, theObject.probability(50, 1000),1.0);
	}
	return 0;
}
// END CUT HERE
