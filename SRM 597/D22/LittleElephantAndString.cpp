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
#include <cassert>


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

class LittleElephantAndString {
public:		
	// 判断 seastr 是否是 str 的子序列
	bool searchstr(string str, string seastr)
	{
		int p1, p2;
		p1 = p2 = 0;
		for (; p2 < seastr.size(); p2++, p1++) {
			for (; p1 < str.size(); p1++) {
				if (seastr[p2] == str[p1]) {
					break;
				}
			}
			if (p1 == str.size()) {
				return false;
			}
		}
		return true;
	}
	int getNumber(string A, string B) {
		int res = 0;
		if ( multiset <char> (A.begin(), A.end()) != multiset <char> (B.begin(), B.end()) ) {
			return -1;
		}
		int n = A.size();
		res = n;
		string nextB;
		for (int i = 0; i < n; i++) {
			nextB = B.substr(i, n - i);
			if (searchstr(A, nextB)) {
				res = i;
				break;
			}
		}

		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		LittleElephantAndString theObject;
		eq(0, theObject.getNumber("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZAAAAAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZ"),19);
	}
	{
		LittleElephantAndString theObject;
		eq(1, theObject.getNumber("DCABA", "DACBA"),2);
	}
	{
		LittleElephantAndString theObject;
		eq(2, theObject.getNumber("AAABBB", "BBBAAA"),3);
	}
	{
		LittleElephantAndString theObject;
		eq(3, theObject.getNumber("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "ZYXWVUTSRQPONMLKJIHGFEDCBA"),25);
	}
	{
		LittleElephantAndString theObject;
		eq(4, theObject.getNumber("A", "A"),0);
	}
	{
		LittleElephantAndString theObject;
		eq(5, theObject.getNumber("DCA", "DAC"),2);
	}
}
// END CUT HERE
