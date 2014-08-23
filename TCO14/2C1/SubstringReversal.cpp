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

class SubstringReversal {
public:
	vector <int> solve(string S) {
		vector <int> res(2, 0);
		int N = S.size();
		string minStr = S;
		for (int i = 0; i < N; i++) {
			char minChar = *min_element(S.begin() + i, S.end());
			if (S[i] == minChar) {
				continue;
			}
			// S[i] != minChar
			string temp;
			for (int j = i + 1; j < N; j++) {
				if (minChar == S[j]) {
					temp = S;
					// reverse S[i ... j]
					reverse(temp.begin() + i, temp.begin() + j + 1);
					if (temp < minStr) {
						minStr = temp;
						res[0] = i;
						res[1] = j;
					}
				}
			}
			break;
		}

		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int retrunValueARRAY[] = {0, 0 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		SubstringReversal theObject;
		eq(0, theObject.solve("aaaa"),retrunValue);
	}
	{
		int retrunValueARRAY[] = {0, 0 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		SubstringReversal theObject;
		eq(1, theObject.solve("aabbcc"),retrunValue);
	}
	{
		int retrunValueARRAY[] = {0, 4 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		SubstringReversal theObject;
		eq(2, theObject.solve("misof"),retrunValue);
	}
	{
		int retrunValueARRAY[] = {0, 2 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		SubstringReversal theObject;
		eq(3, theObject.solve("ivan"),retrunValue);
	}
	{
		int retrunValueARRAY[] = {0, 13 };
		vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
		SubstringReversal theObject;
		eq(4, theObject.solve("thisseemstobeaneasyproblem"),retrunValue);
	}
}
// END CUT HERE
