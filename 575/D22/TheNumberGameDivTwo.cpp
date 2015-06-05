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

/*************** Program Begin **********************/
bool win[1001];
class TheNumberGameDivTwo {
private:
	vector <int> getNext(int n)
	{
		vector <int> next;
		int lim = n / 2;
		for (int i = 2; i <= lim; i++) {
			if (n % i == 0) {
				next.push_back(n - i);
			}
		}
		return next;
	}
public:
	string find(int n) {
		memset(win, 0, sizeof(win));
		vector <int> next;
		for (int i = 1; i <= 1000; i++) {
			next = getNext(i);
			if (next.empty()) {
				win[i] = false;
				continue;
			}
			for (int j = 0; j < next.size(); j++) {
				if ( !win[ next[j] ]) {
					win[i] = true;
					break;
				}
			}
		}
		return win[n] ? "John" : "Brus";
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		TheNumberGameDivTwo theObject;
		eq(0, theObject.find(6),"John");
	}
	{
		TheNumberGameDivTwo theObject;
		eq(1, theObject.find(2),"Brus");
	}
	{
		TheNumberGameDivTwo theObject;
		eq(2, theObject.find(747),"Brus");
	}
	{
		TheNumberGameDivTwo theObject;
		eq(3, theObject.find(128),"Brus");
	}
}
// END CUT HERE
