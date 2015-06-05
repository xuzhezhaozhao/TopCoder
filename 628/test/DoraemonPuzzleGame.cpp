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
const int MAX_N = 2001;
double dp[MAX_N][MAX_N];
class DoraemonPuzzleGame {
public:
	int N;
	vector <pair<double, double>> prob;
	double rec(int t, int r)
	{
		double & res = dp[t][r];
		// base case
		if (0 == t) {
			res = 0;
			return res;
		}
		if (res > -0.5) {
			return res;
		}
		res = 0.0;
		double p1 = prob[N - t].second;
		double p2 = prob[N - t].first;
		if (t != r) {	// get one or two stars int this level
			res = (1 + p1 * rec(t-1, r) + p2 * rec(t-1, max(0, r-1))) / (p1 + p2);
		} else {	// must get two stars
			res = (1 + p2 * rec(t-1, max(0, r-1))) / p2;
		}
		return res;
	}
	double solve(vector <int> X, vector <int> Y, int m) {
		N = X.size();
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				dp[i][j] = -1.0;
			}
		}

		for (int i = 0; i < X.size(); i++) {
			prob.push_back(mkp(Y[i] / 1000.0, X[i] / 1000.0));
		}
		sort(prob.begin(), prob.end());
		
		return rec(N, m - N);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int XARRAY[] = {800};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {200};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		DoraemonPuzzleGame theObject;
		eq(0, theObject.solve(X, Y, 2),5.0);
	}
	{
		int XARRAY[] = {1,999,999};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {999,1,1};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		DoraemonPuzzleGame theObject;
		eq(1, theObject.solve(X, Y, 3),3.0);
	}
	{
		int XARRAY[] = {500,500};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {500,500};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		DoraemonPuzzleGame theObject;
		eq(2, theObject.solve(X, Y, 3),2.5);
	}
	{
		int XARRAY[] = {250,250,250,250};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {250,250,250,250};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		DoraemonPuzzleGame theObject;
		eq(3, theObject.solve(X, Y, 5),8.25);
	}
	{
		int XARRAY[] = {250,500,250};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {500,250,500};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		DoraemonPuzzleGame theObject;
		eq(4, theObject.solve(X, Y, 5),4.962962962962963);
	}
	{
		int XARRAY[] = {600,900,800,500,900,200,400,100,800,300,900,300,800,700,800,600,800,900,400,100,100,700,600,100,500,
			800,700,600,900,600,300,100,300,100,700,500,900,200,800,400,300,700,300,400,700,300,400,800,300,200};
		vector <int> X( XARRAY, XARRAY+ARRSIZE(XARRAY) );
		int YARRAY[] = {400,100,200,500,100,800,600,900,200,700,100,700,200,300,200,400,200,100,600,900,900,300,400,900,500,
			200,300,400,100,400,700,900,700,900,300,500,100,800,200,600,700,300,700,600,300,700,600,200,700,800};
		vector <int> Y( YARRAY, YARRAY+ARRSIZE(YARRAY) );
		DoraemonPuzzleGame theObject;
		eq(5, theObject.solve(X, Y, 95),119.33578280666175);
	}
}
// END CUT HERE
