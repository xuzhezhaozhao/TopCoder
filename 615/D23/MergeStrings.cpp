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
const int MAX_N = 51;
string dp[MAX_N][MAX_N];
class MergeStrings {
public:
	string S, A, B;
	string rec(int a, int b)
	{
		string & res = dp[a][b];
		if (res != "#") {
			return res;
		}
		int cur = a + b;
		// base case
		if (cur == S.size()) {
			res = "";
			return "";
		}

		string tmp;
		tmp = (char)('Z' + 1);
		res = tmp;
		// select A
		if ( (a < A.size()) && (S[cur] == A[a] || '?' == S[cur]) ) {
			string rem = rec(a + 1, b);
			if (rem != "*") {
				res = min(res, A[a] + rem);
			}
		}

		// select B
		if ( (b < B.size() && (S[cur] == B[b] || '?' == S[cur]) ) ) {
			string rem = rec(a, b + 1);
			if (rem != "*") {
				res = min(res, B[b] + rem);
			}
		}
		if (res == tmp) {
			res = "*";
		}
		return res;
	}
	string getmin(string S, string A, string B) {
		this->S = S;
		this->A = A;
		this->B = B;
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				dp[i][j] = "#";
			}
		}
		string res = rec(0, 0);
		return (res == "*" ? "" : res);
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
	{
		MergeStrings theObject;
		eq(0, theObject.getmin("???????V?WV?O?W???V?W??", "OWOVOOOVOWVWOWWVWWVW", "OOW"),"OWOVOOOVOWVOOWWOWWVWWVW");
	} 
	{
		MergeStrings theObject;
		eq(1, theObject.getmin("WHAT?", "THE", "WA"),"");
	}
	{
		MergeStrings theObject;
		eq(2, theObject.getmin("PARROT", "PARROT", ""),"PARROT");
	}
	{
		MergeStrings theObject;
		eq(3, theObject.getmin("???????????", "AZZAA", "AZAZZA"),"AAZAZZAAZZA");
	}
	{
		MergeStrings theObject;
		eq(4, theObject.getmin("????K??????????????D???K???K????????K?????K???????", "KKKKKDKKKDKKDDKDDDKDKK", "KDKDDKKKDDKDDKKKDKDKKDDDDDDD"),"KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK");
	}
	return 0;
}
// END CUT HERE
