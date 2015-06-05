#include <algorithm>
#include <iostream>
#include <sstream>

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

/*************** Program Begin **********************/
long long dp[31][2][2][2];
vector <int> dA, dB, dC;
class LittleElephantAndXor {
public:
	long long rec(int t, int eqA, int eqB, int eqC)
	{

		if (t == -1) {
			return 1;
		}

		long long & res = dp[t][eqA][eqB][eqC];
		if (res != -1) {
			return res;
		}
		res = 0;
		for (int a = 0; a <= 1; a++) {
			for (int b = 0; b <= 1; b++) {
				int eqA2, eqB2, eqC2;
				if (eqA == 1) {
					if (a > dA[t]) {
						continue;
					} else if (a == dA[t]) {
						eqA2 = 1;
					} else {
						eqA2 = 0;
					}
				} else {
					eqA2 = 0;
				}
				if (eqB == 1) {
					if (b > dB[t]) {
						continue;
					} else if (b == dB[t]) {
						eqB2 = 1;
					} else {
						eqB2 = 0;
					}
				} else {
					eqB2 = 0;
				}

				int c = a ^ b;

				if (eqC == 1) {
					if (c > dC[t]) {
						continue;
					} else if (c == dC[t]) {
						eqC2 = 1;
					} else {
						eqC2 = 0;
					}
				} else {
					eqC2 = 0;
				}
				res += rec(t - 1, eqA2, eqB2, eqC2);
			}
		}
		return res;
	}
	long long getNumber(int A, int B, int C) {
		long long res = 0;
		memset(dp, -1, sizeof(dp));
		dA.clear(); dB.clear(); dC.clear();
		for (int i = 0; i < 31; i++) {
			dA.push_back(A & 1);
			dB.push_back(B & 1);
			dC.push_back(C & 1);
			A >>= 1; B >>= 1; C >>= 1;
		}

		res = rec(30, 1, 1, 1);
		return res;
	}

};


/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		LittleElephantAndXor theObject;
		eq(0, theObject.getNumber(2, 2, 1),5LL);
	}
	{
		LittleElephantAndXor theObject;
		eq(1, theObject.getNumber(4, 7, 3),20LL);
	}
	{
		LittleElephantAndXor theObject;
		eq(2, theObject.getNumber(10, 10, 5),57LL);
	}
	{
		LittleElephantAndXor theObject;
		eq(3, theObject.getNumber(774, 477, 447),214144LL);
	}
	{
		LittleElephantAndXor theObject;
		eq(4, theObject.getNumber(1000000000, 1000000000, 500000000),468566946385621507LL);
	}
}
// END CUT HERE
