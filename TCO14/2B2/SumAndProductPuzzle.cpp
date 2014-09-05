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
const int MAX = 5000001;
bool isPrime[MAX];
bool isGood[MAX];
class SumAndProductPuzzle {
public:
	long long getSum(int A, int B) {
		long long res = 0;

		for (int i = 0; i < MAX; i++) {
			isGood[i] = true;
			isPrime[i] = true;
		}
		isPrime[0] = false;
		isPrime[1] = false;
		//for (int x = 2; x * x <= B; x++) {
		//	for (int y = x; x * y <= B; y++) {
		//		isPrime[x * y] = false;
		//	}
		//}
		// Sieve of Eratosthenes, 比上面更快
		for (int x = 2; x * x <= B; x++) {
			if (isPrime[x]) {
				for (int y = 2 * x; y <= B; y += x) {
					isPrime[y] = false;
				}
			}
		}

		
		for (int x = 2; x * x + 1 <= B; x++) {
			for (int y = x; x * y + 1 <= B; y++) {
				if (!isPrime[x + y - 1]) {
					isGood[x * y + 1] = false;
				}
			}
		}
		for (int S = A; S <= B; S++) {
			if (isPrime[S - 1]) {
				isGood[S] = false;
			}
		}
		isGood[1] = isGood[2] = false;
		for (int S = A; S <= B; S++) {
			if (isGood[S]) {
				res += S;
			}
		}

		return res;
	}

};

/************** Program End ************************/

// BEGIN CUT HERE
void main( int argc, char* argv[] ) {
	{
		SumAndProductPuzzle theObject;
		eq(0, theObject.getSum(30, 33),33LL);
	}
	{
		SumAndProductPuzzle theObject;
		eq(1, theObject.getSum(8, 11),19LL);
	}
	{
		SumAndProductPuzzle theObject;
		eq(2, theObject.getSum(40, 43),0LL);
	}
	{
		SumAndProductPuzzle theObject;
		eq(3, theObject.getSum(47, 74),168LL);
	}
	{
		SumAndProductPuzzle theObject;
		eq(4, theObject.getSum(1, 2),0LL);
	}
}
// END CUT HERE
