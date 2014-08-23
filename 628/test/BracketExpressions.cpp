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

class BracketExpressions {
public:
	vector <int> xpos;
	bool check(const vector <int> & exp)
	{
		stack <int> st;
		for (int i = 0; i < exp.size(); i++) {
			if (exp[i] == 0) {
				cout << "error" << endl;
			}
			if (st.empty()) {
				if (exp[i] < 0) {
					return false;
				} else {
					st.push(exp[i]);
				}
				
			} else {
				if ( st.top() > 0 && st.top() + exp[i] == 0 ) {
					st.pop();
				} else {
					if (exp[i] < 0) {
						return false;
					}
					st.push(exp[i]);
				}
			}
		}
		return (st.empty());
	}
	bool backtrack(int p, vector <int> & exp)
	{
		if (p == xpos.size()) {
			return check(exp);
		} else {
			for (int i = -3; i <= 3; i++) {
				if (0 == i) {
					continue;
				}
				exp[ xpos[p] ] = i;
				if (backtrack(p + 1, exp)) {
					return true;
				}
			}
			return false;
		}
	}
	string ifPossible(string expression) {
		vector <int> exp;
		for (int i = 0; i < expression.size(); i++) {
			switch (expression[i]) {
			case '(':
				exp.push_back(1);
				break;
			case ')':
				exp.push_back(-1);
				break;
			case '[':
				exp.push_back(2);
				break;
			case ']':
				exp.push_back(-2);
				break;
			case '{':
				exp.push_back(3);
				break;
			case '}':
				exp.push_back(-3);
				break;
			case 'X':
				exp.push_back(0);
				xpos.push_back(i);
				break;
			default:
				break;
			}
		}

		return (backtrack(0, exp) ? "possible" : "impossible");
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		BracketExpressions theObject;
		eq(0, theObject.ifPossible("(][)"),"impossible");
	}
	{
		BracketExpressions theObject;
		eq(1, theObject.ifPossible("(())[]"),"possible");
	}
	{
		BracketExpressions theObject;
		eq(2, theObject.ifPossible("({])"),"impossible");
	}
	{
		BracketExpressions theObject;
		eq(3, theObject.ifPossible("[]X"),"impossible");
	}
	{
		BracketExpressions theObject;
		eq(4, theObject.ifPossible("([]X()[()]XX}[])X{{}}]"),"possible");
	}
}
// END CUT HERE
