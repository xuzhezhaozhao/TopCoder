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

class SwitchingGame {
public:
	int timeToWin(vector <string> states) {
		int res = 0;
		int N = states.size();
		int M = states[0].size();
		int final[51][51];
		memset(final, 0, sizeof(final));

		// final[i] 中保存通过i关后状态，final[0]为初试状态，未通过一关
		for (int level = 0; level < N; level++) {
			bool on = false, off = false;
			for (int pos = 0; pos < M; pos++) {
				char c = states[level][pos];
				// 是否需要打开操作
				if (0 == final[level][pos] && '+' == c) {
					on = true;
				}

				// 是否需要关闭操作
				if (1 == final[level][pos] && '-' == c) {
					off = true;
				}
			}
			for (int pos = 0; pos < M; pos++) {
				char c = states[level][pos];
				if ('+' == c) {
					final[level + 1][pos] = 1;
				} else if ('-' == c) {
					final[level + 1][pos] = 0;
				} else {	// c = '?'
					if (0 == final[level][pos] && on) {
						final[level + 1][pos] = 2;
					} else if (1 == final[level][pos] && off) {
						final[level + 1][pos] = 2;
					} else if (2 == final[level][pos]) {
						final[level + 1][pos] = 2;
					} else {
						final[level + 1][pos] = final[level][pos];
					}
				}
			}
			res += 1 + off + on;
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		string statesARRAY[] = {"++--",
			"--++"};
		vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
		SwitchingGame theObject;
		eq(0, theObject.timeToWin(states),5);
	}
	{
		string statesARRAY[] = {"+-++",
			"+-++"};
		vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
		SwitchingGame theObject;
		eq(1, theObject.timeToWin(states),3);
	}
	{
		string statesARRAY[] = {"++",
			"+?",
			"?+",
			"++"};
		vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
		SwitchingGame theObject;
		eq(2, theObject.timeToWin(states),5);
	}
	{
		string statesARRAY[] = {"+", 
			"?",
			"?",
			"?",
			"-"};
		vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
		SwitchingGame theObject;
		eq(3, theObject.timeToWin(states),7);
	}
	{
		string statesARRAY[] = {"+??+++",
			"++??+-",
			"?++??+",
			"?-+-??",
			"??+?++",
			"++-?+?",
			"?++?-+",
			"?--+++",
			"-??-?+"}
		;
		vector <string> states( statesARRAY, statesARRAY+ARRSIZE(statesARRAY) );
		SwitchingGame theObject;
		eq(4, theObject.timeToWin(states),20);
	}
}
// END CUT HERE
