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
int dp[2501][2501][2];
int endC1[2501], endC2[2501];
const int INF = 100000000;
class WinterAndReindeers {
public:
	void calcEndC(const string & A, const string & C, int endC[])
	{
		int an = A.size(), cn = C.size();
		for (int k = 0; k < an; k++) {
			int i, j = 0;
			for (i = k; i < an && j < cn; i++) {
				if (A[i] == C[j]) {
					++j;
				}
			}
			if (j == cn) {
				endC[k] = i;
			} else {
				endC[k] = -1;
			}
		}
	}

	int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) {
		string A, B, C;
		A = accumulate(allA.begin(), allA.end(), string(""));
		B = accumulate(allB.begin(), allB.end(), string(""));
		C = accumulate(allC.begin(), allC.end(), string(""));

		memset(dp, 0, sizeof(dp));
		memset(endC1, -1, sizeof(endC1));
		memset(endC2, -1, sizeof(endC2));

		int an = A.size(), bn = B.size(), cn = C.size();
		calcEndC(A, C, endC1);
		calcEndC(B, C, endC2);

		for (int i = an; i >= 0; i--) {
			for (int j = bn; j >= 0; j--) {
				for (int d = 0; d < 2; d++) {
					int & res = dp[i][j][d];
					if (i == an || j == bn) {
						res = (d ? 0 : -INF);
						continue;
					}
					res = -INF;
					if (A[i] == B[j]) {
						res = 1 + dp[i+1][j+1][d];
					} else {
						res = max(res, dp[i][j+1][d]);
						res = max(res, dp[i+1][j][d]);
					}
					if (endC1[i] != -1 && endC2[j] != -1) {
						res = max(res, cn + dp[ endC1[i] ][ endC2[j] ][1]);
					}
				}
			}
		}
		return max(0, dp[0][0][0]);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string allAARRAY[] = {"X"};
		vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
		string allBARRAY[] = {"X", "Y"};
		vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
		string allCARRAY[] = {"X"};
		vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
		WinterAndReindeers theObject;
		eq(0, theObject.getNumber(allA, allB, allC),1);
	}
	{
		string allAARRAY[] = {"ABCXD"};
		vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
		string allBARRAY[] = {"BCDEF"};
		vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
		string allCARRAY[] = {"CD"};
		vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
		WinterAndReindeers theObject;
		eq(1, theObject.getNumber(allA, allB, allC),3);
	}
	{
		string allAARRAY[] = {"WE", "LOVE"};
		vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
		string allBARRAY[] = {"WORKING", "FOR", "SANTA"};
		vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
		string allCARRAY[] = {"JK"};
		vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
		WinterAndReindeers theObject;
		eq(2, theObject.getNumber(allA, allB, allC),0);
	}
	{
		string allAARRAY[] = {"ABCDE"};
		vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
		string allBARRAY[] = {"CDEAB"};
		vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
		string allCARRAY[] = {"B"};
		vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
		WinterAndReindeers theObject;
		eq(3, theObject.getNumber(allA, allB, allC),2);
	}
	{
		string allAARRAY[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"};
		vector <string> allA( allAARRAY, allAARRAY+ARRSIZE(allAARRAY) );
		string allBARRAY[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"};
		vector <string> allB( allBARRAY, allBARRAY+ARRSIZE(allBARRAY) );
		string allCARRAY[] = {"AXBADXBBAB", "CDD"};
		vector <string> allC( allCARRAY, allCARRAY+ARRSIZE(allCARRAY) );
		WinterAndReindeers theObject;
		eq(4, theObject.getNumber(allA, allB, allC),23);
	}
}
// END CUT HERE
