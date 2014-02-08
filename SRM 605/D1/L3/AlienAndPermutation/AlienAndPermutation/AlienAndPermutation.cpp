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
const int MOD = 1000000007;
class AlienAndPermutation {
public:
	int getNumber(vector <int> P, int K) {
		int res = 0;

		return res;
	}
};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int PARRAY[] = {1, 2};
		vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
		AlienAndPermutation theObject;
		eq(0, theObject.getNumber(P, 1),2);
	}
	{
		int PARRAY[] = {3, 1, 2};
		vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
		AlienAndPermutation theObject;
		eq(1, theObject.getNumber(P, 2),4);
	}
	{
		int PARRAY[] = {4, 3, 2, 1};
		vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
		AlienAndPermutation theObject;
		eq(2, theObject.getNumber(P, 2),13);
	}
	{
		int PARRAY[] = {1, 7, 2, 3, 6, 4, 5};
		vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
		AlienAndPermutation theObject;
		eq(3, theObject.getNumber(P, 3),77);
	}
	{
		int PARRAY[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
		vector <int> P( PARRAY, PARRAY+ARRSIZE(PARRAY) );
		AlienAndPermutation theObject;
		eq(4, theObject.getNumber(P, 12),379796836);
	}
}
// END CUT HERE
