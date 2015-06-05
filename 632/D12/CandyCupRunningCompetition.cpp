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
const int MOD = 1000000007;
bool used[2005];
bool visited[2005];

class CandyCupRunningCompetition {
public:
	vector <int> A, B;
	vector < vector<pii> > g;
	int my3Power (int p)
	{
		long long res = 1;
		for (int i = 1; i <= p; i++) {
			res *= 3;
			res %= MOD;
		}
		return res;
	}

	bool isReachable(int from, int des, int r)
	{
		if (from == des) {
			return true;
		}
		
		for ( auto z : g[from] ) {
			int i = z.second;
			int x = z.first;
			if (used[i]) {
				continue;
			}
			if (i < r) {
				continue;
			}
			if (visited[x]) {
				continue;
			}
			visited[x] = true;
			if (isReachable(x, des, r)) {
				return true;
			}
		}

		return false;
	}

	int findMaximum(int N, vector <int> A, vector <int> B) {
		long long res = 0;
		int M = A.size();
		this->A = A;
		this->B = B;

		g.resize(N);
		memset(used, 0, sizeof(used));
		for (int i = 0; i < M; i++) {
			g[ A[i] ].push_back( mkp(B[i], i) );
			g[ B[i] ].push_back( mkp(A[i], i) );
		}

		for (int i = M - 1; i >= 0; i--) {
			used[i] = true;

			memset(visited, 0, sizeof(visited));
			bool b1 = isReachable(A[i], 0, i);
			memset(visited, 0, sizeof(visited));
			bool b2 = isReachable(B[i], N - 1, i);
			memset(visited, 0, sizeof(visited));
			bool b3 = isReachable(A[i], N - 1, i);
			memset(visited, 0, sizeof(visited));
			bool b4 = isReachable(B[i], 0, i);
			
			if ( (b1 && b2) || (b3 && b4) ) {
				res += my3Power(i);			
				res %= MOD;
			} else {
				used[i] = false;
			}
		}

		return res;
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
		int AARRAY[] = {0,1};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {1,2};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		CandyCupRunningCompetition theObject;
		eq(0, theObject.findMaximum(3, A, B),1);
	}
	{
		int AARRAY[] = {0,1,0,2};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {1,3,2,3};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		CandyCupRunningCompetition theObject;
		eq(1, theObject.findMaximum(4, A, B),10);
	}
	{
		int AARRAY[] = {0};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {1};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		CandyCupRunningCompetition theObject;
		eq(2, theObject.findMaximum(3, A, B),0);
	}
	{
		CandyCupRunningCompetition theObject;
		eq(3, theObject.findMaximum(5, vector <int>(), vector <int>()),0);
	}
	{
		int AARRAY[] = {1,1,2,0,4,3,0,1,4};
		vector <int> A( AARRAY, AARRAY+ARRSIZE(AARRAY) );
		int BARRAY[] = {3,2,3,1,5,5,2,4,3};
		vector <int> B( BARRAY, BARRAY+ARRSIZE(BARRAY) );
		CandyCupRunningCompetition theObject;
		eq(4, theObject.findMaximum(6, A, B),39);
	}
	return 0;
}
// END CUT HERE
