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
class ORSolitaireDiv2 {
public:
	int goal, n;
	vector <int> valid;
	int mininum;

	int backtrack(int cur, int X, int removed)
	{
		if (cur == n) {
			if (X != goal) {
				mininum = min(mininum, removed);
			}
			return 0;
		}
		backtrack(cur + 1, X, removed + 1);
		backtrack(cur + 1, X | valid[cur], removed);
		return 0;
	}
	int getMinimum(vector <int> numbers, int goal) {
		this->goal = goal;
		mininum = 20;
		vector <int> valid;
		for (int i = 0; i < numbers.size(); i++) {
			if (goal == (goal | numbers[i])) {
				valid.push_back(numbers[i]);
			}
		}
		this->valid = valid;
		this->n = valid.size();
		backtrack(0, 0, 0);

		return mininum;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		int numbersARRAY[] = {1, 2, 4};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		ORSolitaireDiv2 theObject;
		eq(0, theObject.getMinimum(numbers, 7),1);
	}
	{
		int numbersARRAY[] = {1, 2, 4, 7, 8};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		ORSolitaireDiv2 theObject;
		eq(1, theObject.getMinimum(numbers, 7),2);
	}
	{
		int numbersARRAY[] = {12571295, 2174218, 2015120};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		ORSolitaireDiv2 theObject;
		eq(2, theObject.getMinimum(numbers, 1),0);
	}
	{
		int numbersARRAY[] = {5, 2, 4, 52, 62, 9, 8, 3, 1, 11, 6};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		ORSolitaireDiv2 theObject;
		eq(3, theObject.getMinimum(numbers, 11),3);
	}
	{
		int numbersARRAY[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
		vector <int> numbers( numbersARRAY, numbersARRAY+ARRSIZE(numbersARRAY) );
		ORSolitaireDiv2 theObject;
		eq(4, theObject.getMinimum(numbers, 510),5);
	}
}
// END CUT HERE
